# UnityStealer
Unity Stealer is a proof of concept of loading a c# payload into a signed process to allow it to be completely invisible without executing any code that could be deemed as malicious outside of the payload. Getting easy access to the signed process will allow you to execute any malicious things you might want, and communicate data off of the client all while being whitelisted in memory by a Unity game's security certificate.
<br>

# Why Does This Work?
If you read Windows internals you may know that each dll in an executable still maintains its certificate as well as the application itself having its certificate allowing you to monitor the actions of every library loaded into a program. This allows for a system where the anti-virus can easily scan through for untrusted memory. The issue with this is that it isn't compatible with managed models. As our dll is loaded into a Unity game we actuallly get allocated by the mono library into a massive pool of JIT memory where the actual module addresses are removed and instead represented through a dictionary in the mono library. Obviously the mono library isn't being used as a standard so anti viruses dont support this so they just see that all of this massive pool of jit memory is covered by the game's parent program UnityCrashHandler64.exe. So we are safely just recognised as UnityCrashHandler64.exe. A fully legit signed program.

<br>
# How Does It Work?
You compile a managed payload.dll with all of your malicious stuff in. 
Then you need to edit a referenced dll from a unity game and then place it into the base directory of the game.
Edit this file in dnspy, Add your dll as a byte array into the referenced dll and then call your initilizer function.
