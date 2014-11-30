#ifndef YMAPRENDERER_H
#define YMAPRENDERER_H

#include <SFML/Graphics.hpp>
#include "yMap.h"

class yMapRenderer : public sf::Drawable
{
    public:
        yMapRenderer();
        yMapRenderer(const yMap* map, const sf::IntRect& fieldOfView = sf::IntRect(0,0,600,400));
        virtual ~yMapRenderer();

        void setMap(const yMap* map);
        const yMap* getMap() const{return m_map;}

        void setFieldOfView(const sf::IntRect& fieldOfView);

        sf::Vector2i getPosition() const{return m_position;}
        void setPosition(const sf::Vector2i& position){m_position = position;}
        sf::Vector2f getScale() const{return m_scale;}
        void setScale(const sf::Vector2f scale){m_scale = scale;}

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    protected:
    private:

    const yMap* m_map;
    sf::IntRect m_fieldOfView;

	sf::Texture tileset;

	sf::Vector2i m_position;
	sf::Vector2f m_scale;
};

#endif // YMAPRENDERER_H
