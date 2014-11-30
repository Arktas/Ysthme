#include <cstdio>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "yMap/yMapStream.h"
#include "yMap/yMapGenerator.h"
#include "yMap/yMapRenderer.h"

/**
 * Print information in console about mapContext
 */
void printMapContext(const yMapContext* context)
{
    fprintf(stdout, "Tileset : %s\nTile IDs (%d) :\n", context->getTilesetFilename(), context->getTileLinkCount());

    for(unsigned char i=0; i<context->getTileLinkCount(); ++i)
    {
        const yMapContext::yTileLink* tileID = context->getTileLink(i);
        fprintf(stdout, "> [%d] - position : {%d; %d; %d; %d}\n", tileID->ID, tileID->x1, tileID->y1, tileID->x2, tileID->y2);
    }
}

/**
 * Save a yMap object to a .png file
 */
void saveMapAsPng(const yMap* map)
{
    yMapRenderer renderer(map);
    renderer.setFieldOfView(sf::IntRect(0,0,map->getWidth(), map->getHeight()));

    sf::RenderTexture renderTarget;
    renderTarget.create(map->getWidth()*32, map->getHeight()*32);
    renderTarget.draw(renderer);
    renderTarget.display();
    renderTarget.getTexture().copyToImage().saveToFile("test.png");
}

/**
 * Generate a new yMap object and save it to a .ymap file
 * @return generated yMap
 */
yMap* createNewMap(const char* filename)
{
    yMapGenerator gen;
    gen.initContext();
    yMap* map = gen.generateNewMap();

    yMapStream::saveToFile(filename,*map);

    return map;
}

/**
 * Open window as yMap viewer
 */
int visualizeMap(int argc, char* argv[])
{
    char* filename = NULL;
    if(argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        fprintf(stdout, "yError : invalid argument. Need yMap file.\n");
        return 0;
    }

    yMap* loadedMap = yMapStream::loadFromFile(filename);

    fprintf(stdout, "--- MapContext in file '%s' ---\n", filename);
    printMapContext(loadedMap->getContext());

    yMapRenderer renderer(loadedMap);
    renderer.setScale(sf::Vector2f(1.f,1.f));

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::Vector2i pos(0,0);
    sf::Vector2i tempPos(0,0);
    sf::Vector2i mousePos(0,0);
    bool pressed = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();

            if(event.type == sf::Event::MouseMoved)
            {
                if(pressed)
                {
                    tempPos.x = pos.x + (event.mouseMove.x-mousePos.x)/renderer.getScale().x;
                    tempPos.y = pos.y + (event.mouseMove.y-mousePos.y)/renderer.getScale().y;
                    renderer.setPosition(tempPos);

                    sf::IntRect fov = sf::IntRect(-(tempPos.x)/32, -(tempPos.y)/32, 800/(32*renderer.getScale().x), 600/(32*renderer.getScale().y));
                    renderer.setFieldOfView(fov);
                }
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                mousePos.x = event.mouseButton.x;
                mousePos.y = event.mouseButton.y;
                pressed = true;
            }

            if(event.type == sf::Event::MouseButtonReleased)
            {
                pos = tempPos;
                pressed = false;
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            {
                renderer.setScale(renderer.getScale()+sf::Vector2f(0.05f, 0.05f));
                sf::IntRect fov = sf::IntRect(-(pos.x)/32, -(pos.y)/32, 800/(32*renderer.getScale().x), 600/(32*renderer.getScale().y));
                renderer.setFieldOfView(fov);
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            {
                renderer.setScale(renderer.getScale()-sf::Vector2f(0.05f, 0.05f));
                sf::IntRect fov = sf::IntRect(-(pos.x)/32, -(pos.y)/32, 800/(32*renderer.getScale().x), 600/(32*renderer.getScale().y));
                renderer.setFieldOfView(fov);
            }

            if(event.type == sf::Event::MouseWheelMoved)
            {
                if(event.mouseWheel.delta > 0)
                {
                    renderer.setScale(renderer.getScale()+sf::Vector2f(0.05f, 0.05f));
                    sf::IntRect fov = sf::IntRect(-(pos.x)/32, -(pos.y)/32, 800/(32*renderer.getScale().x), 600/(32*renderer.getScale().y));
                    renderer.setFieldOfView(fov);
                }
                else if(event.mouseWheel.delta < 0)
                {
                    renderer.setScale(renderer.getScale()-sf::Vector2f(0.05f, 0.05f));
                    sf::IntRect fov = sf::IntRect(-(pos.x)/32, -(pos.y)/32, 800/(32*renderer.getScale().x), 600/(32*renderer.getScale().y));
                    renderer.setFieldOfView(fov);
                }
            }
        }

        window.clear();
        window.draw(renderer);
        window.display();
    }

    return 0;
}

int main(int argc, char* argv[])
{
    char* arg[2];
    arg[0] = argv[0];
    arg[1] = "test.bin.ymap";

    for(int i=0; i<2; ++i)
        fprintf(stdout, "> %s\n", arg[i]);
    return visualizeMap(2, arg);
}
