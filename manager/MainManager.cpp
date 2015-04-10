#include "MainManager.h"

MainManager::MainManager()
{
    //move flag
    left = false;
    right = false;
    top = false;
    down = false;
    dirTop = false;
    dirDown = false;
    dirRight = false;
    dirLeft = false;
    mousePressed = false;
    spell = true;
    dataContainer = new Data();
    window = new sf::RenderWindow(sf::VideoMode(XMAX, YMAX), "Ysthme"/*,sf::Style::Fullscreen*/);
    sf::Image icon;
    icon.loadFromFile("data/ysthme.png");

    window->setIcon(128,128,icon.getPixelsPtr());
    this->clock = new Clock();
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y;
    X=0.0;
    Y=0.0;

}

MainManager::~MainManager()
{

}

void MainManager::load()
{
   /* initialize random seed: */
   srand (time(NULL));
   window->clear(sf::Color(0,0,0));
   sf::Font loadTxtFont;
    sf::Text loadTxt;
    loadTxtFont.loadFromFile("data/font/arial.ttf");
    loadTxt.setFont(loadTxtFont);
    loadTxt.setColor(sf::Color::White);
    loadTxt.setCharacterSize(50);
    loadTxt.setStyle(sf::Text::Bold);
    loadTxt.setPosition(5,5);
    loadTxt.setString("Chargement de la faune...");
    window->draw(loadTxt);
    window->display();


   dataContainer->load("test.xml");

   Inventory* inventory = new Inventory();
   player = new Player(dataContainer,"player",0,0,96,110,0,0,100,8,10,&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC);
   itemManager = new ItemManager(&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC,dataContainer,player,inventory);
   for(int i=0;i<NB_MONSTER;i++)
   {
       //Monsters load text
       float i_f = i;
       float nbMonster_f = NB_MONSTER;
       float loading = (i_f/nbMonster_f)*100.0;
       std::stringstream ss;
        ss <<  loading << "%";
        loadTxt.setPosition(650,5);
        loadTxt.setString(ss.str());
        window->draw(loadTxt);
        loadTxt.setPosition(5,5);
        loadTxt.setString("Naissance des créatures...");
        window->draw(loadTxt);
        loadTxt.setPosition(5,60);
        if(loading<20)
            loadTxt.setString("     Structuration moléculaire...");
        else if(loading<40)
            loadTxt.setString("     Création du squelette...");
        else if(loading<60)
            loadTxt.setString("     Couverture musculaire...");
        else if(loading<80)
            loadTxt.setString("     Pigmentation...");
        else if(loading<100)
            loadTxt.setString("     Démarrage de l'intelligence...");
        window->draw(loadTxt);
        window->display();
        window->clear(sf::Color(0,0,0));
        //Monster load text

       float rand_x = ((rand() % MAP_SIZE_X) - (MAP_SIZE_X/2))*80;
       float rand_y = ((rand() % MAP_SIZE_Y) - (MAP_SIZE_Y/2))*80;
       //std::cout << rand_x <<" | "<< rand_y <<std::endl;
       monsterList.push_back(new Monster(itemManager,dataContainer,"zombie",0,0,96,110,rand_x,rand_y,600.0,10,400,8,10,&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC));
   }




    playerManager = new PlayerManager(dataContainer,player,&left,&right,&top,&down,&dirTop,&dirDown,&dirRight,&dirLeft,&mousePressed,&spell,&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC);
    monsterManager = new MonsterManager(dataContainer,player,&monsterList,&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC);
    spellManager = new SpellManager(player,&monsterList,&spell,dataContainer,&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC);
    uiManager = new UIManager(&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC);

    window->clear(sf::Color(0,0,0));
    loadTxt.setString("Chargement du monde...");
    window->draw(loadTxt);
    window->display();

    environementManager = new EnvironementManager(dataContainer,player,&ORIGIN_DIFF_X_DYNAMIC,&ORIGIN_DIFF_Y_DYNAMIC);
}

void MainManager::CheckEvent()
{
    sf::Font fpsFont;
    sf::Text fps;
    fpsFont.loadFromFile("data/font/arial.ttf");
    fps.setFont(fpsFont);
    fps.setColor(sf::Color::White);
    fps.setCharacterSize(20);
    fps.setStyle(sf::Text::Bold);
    fps.setPosition(5,5);


    this->clock->start();
    while (window->isOpen())
    {
            this->clock->start();

            window->clear(sf::Color(0,0,0));
            window->pollEvent(event);
            environementManager->checkEvent(event,window);
            itemManager->checkEvent(event,window);
            playerManager->checkEvent(event,window);
            monsterManager->checkEvent(event,window);
            spellManager->CheckEvent(event,window);
            uiManager->checkEvent(event,window,this);
            //window->display();
            this->clock->stop();
            while(this->clock->difftime()<(1000/FPS))
            {
                this->clock->stop();
            }
            int realFps = round(1000/this->clock->difftime());
            std::stringstream fps_ss;
            fps_ss << realFps;
            fps.setString(fps_ss.str());
            window->draw(fps);
            window->display();
          // std::cout << this->clock->difftime() << std::endl;
    }
}

void MainManager::quit()
{
    delete(player);
    window->close();
}
