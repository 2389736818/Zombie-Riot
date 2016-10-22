/**
 * ====================
 *   Zombie:Riot
 *   File: menu.sp
 *   Author: Greyscale
 * ==================== 
 */

MainMenu(client)
{
    new Handle:menu_main = CreateMenu(MainMenuHandle);
    
    SetGlobalTransTarget(client);
    
    SetMenuTitle(menu_main, "%t\n ", "!zmenu title");
    
    decl String:zmenu[128];
    decl String:zmarket[128];
    decl String:zstuck[128];
    
    Format(zmenu, sizeof(zmenu), "%t", "!zmenu menu");
    Format(zmarket, sizeof(zmarket), "%t", "!zmenu market");
    Format(zstuck, sizeof(zstuck), "%t", "!zmenu stuck");
    
    AddMenuItem(menu_main, "zmenu", zmenu, ITEMDRAW_DISABLED);
    
    if (market)
    {
        AddMenuItem(menu_main, "zmarket", zmarket);
    }
    else
    {
        AddMenuItem(menu_main, "zmarket", zmarket, ITEMDRAW_DISABLED);
    }
    
    AddMenuItem(menu_main, "zstuck", zstuck);
    
    DisplayMenu(menu_main, client, MENU_TIME_FOREVER);
}

public MainMenuHandle(Handle:menu_main, MenuAction:action, client, slot)
{
    if (action == MenuAction_Select)
    {
        switch(slot)
        {
            }
            case 1:
            {
                if (!ZMarket(client))
                {
                    MainMenu(client);
                }
            }
            case 5:
            {
                ZStuck(client);
                MainMenu(client);
            }
        }
    }
    if (action == MenuAction_End)
    {
        CloseHandle(menu_main);
    }
}
