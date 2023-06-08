# Instructions On Loading

## Finding A Referenced DLL
1. Go to your unity folder. Example:```Program Files (x86)\Steam\steamapps\common\7 Days To Die```
2. Go to your managed folder. Example ```Program Files (x86)\Steam\steamapps\common\7DaysToDie_Data\Managed```
3. In here you will find many dlls, you need to find one that the game references but doesn't initilize with. System dlls and 3rd party dlls work well. I am using: ```0Harmony.dll```
4. Edit the dll for an entry point. Open it in dnspy and fully expand down to the module class:
