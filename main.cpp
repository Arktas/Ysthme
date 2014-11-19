#include "manager/MainManager.h"

int main()
{
   /* XMLparser parser;
    parser.parse("data/zombie.xml");*/
    //main manager creation (setting environment variables)
    MainManager mainManager;
    //loading main resources of the game
    mainManager.load();
    //Main loop of the game
    mainManager.CheckEvent();
    return 0;
}


