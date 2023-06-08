# UnityStealer
Unity Stealer is a proof of concept of loading a c# payload into a signed process to allow it to be completely invisible without executing any code that could be deemed as malicious outside of the payload. Getting easy access to the signed process will allow you to execute any malicious things you might want, and communicate data off of the client all while being whitelisted in memory by a Unity game's security certificate.
<br>

## Why Does This Work?
If you read Windows internals you may know that each dll in an executable still maintains its certificate as well as the application itself having its certificate allowing you to monitor the actions of every library loaded into a program. This allows for a system where the anti-virus can easily scan through for untrusted memory. The issue with this is that it isn't compatible with managed models. As our dll is loaded into a Unity game we actuallly get allocated by the mono library into a massive pool of JIT memory where the actual module addresses are removed and instead represented through a dictionary in the mono library. Obviously the mono library isn't being used as a standard so anti viruses dont support this so they just see that all of this massive pool of jit memory is covered by the game's parent program UnityCrashHandler64.exe. So we are safely just recognised as UnityCrashHandler64.exe. A fully legit signed program.
<br>

## How Does It Work?
1. You compile a managed payload.dll with all of your malicious stuff in. 
2. Then you need to edit a referenced dll from a unity game and then place it into the base directory of the game.
3. Edit this file in dnspy, Add your dll as a byte array into the referenced dll and then call your initilizer function.
<br>
To avoid agrovating any game integrity checks we load the dll from the base address which is a .Net 7 feature to load reference assemblies from the base address of any .Net executable. This means that no game will stop us opening it and prevent the payload from getting loaded into memory. It doesn't matter if further integrity checks happen once in a server or in a game lobby. As long as the module can get access to memory then it will be able to attack the user and the damage is already done. 

* [Installing Guide](./Instructions.md)

## Proper Usage
This is just a POC to show how a harmless program can drop a much more harmfull program that is completely undetected at runtime by an anti virus. If you can bypass the basic scan heuristics then this will allow your dll to be fully executed undetected from any anti vurses. This can reach 100s of thousands of users with ease if you can drop a file on a computer. This could cause absolute havoc using a javascript website exploit to be able to set custom download paths for files or any other web attack that can alter file paths on a download.
<br>
Each game uses a different set of references with different versions. You should change the reference dll that you will be attacking with on each game. 
