#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>

class collision 
{
    sf::IntRect rect;
    sf::IntRect Player_radius;
protected:
    sf::FloatRect collisionBox;
    sf::FloatRect radiusCollisionBox;
    sf::RectangleShape hitboxDebug;
    sf::RectangleShape radiusHitboxDebug;
public:
    collision() {}
    collision(sf::IntRect r, sf::IntRect p) { rect = r; Player_radius = p; }
    collision(int x, int y, int w, int h) { rect = sf::IntRect(x, y, w, h); }

    sf::IntRect getRect() { return rect; }
    void setRect(sf::IntRect r) { rect = r; }

    sf::IntRect getPlayerRaidus() { return Player_radius; }
    void setPosition(sf::Vector2f position) {
        rect.left = position.x;
        rect.top = position.y;
    }
   // void getPosition()
   // {
    //    return rect.left;
     
   // }

    void setPosition(int x, int y) {
        rect.left = x;
        rect.top = y;
    }
    void setPlayerRadiusPosition(int x, int y)
    {
        Player_radius.left = x;
        Player_radius.top = y;
    }
    void setPlayerRadiusPosition(sf::Vector2f position)
    {
        Player_radius.left = position.x;
        Player_radius.top = position.y;
    }
    void setCollisionBox(sf::FloatRect fr) {
        collisionBox = fr;
        setDebugCollision(fr.left, fr.top, fr.width, fr.height);
    };
    void setPlayerRadius(sf::IntRect p) {
        Player_radius = p;
    }
    void setPlayerRadiusCollisionBox(sf::FloatRect radius)
    {
        radiusCollisionBox = radius;
        setPlayerRadiusDebugCollision(radius.left, radius.top, radius.width, radius.height);
    }

    void setPlayerRadiusDebugCollision(float x, float y, float w, float h)
    {
        radiusHitboxDebug.setPosition(sf::Vector2f(x, y));
        radiusHitboxDebug.setSize(sf::Vector2f(w, h));
        radiusHitboxDebug.setFillColor(sf::Color::Transparent);
        radiusHitboxDebug.setOutlineColor(sf::Color::Blue);
        radiusHitboxDebug.setOutlineThickness(1.f);
    }
    void setDebugCollision(float x, float y, float w, float h) {
        hitboxDebug.setPosition(sf::Vector2f(x, y));
        hitboxDebug.setSize(sf::Vector2f(w, h));
        hitboxDebug.setFillColor(sf::Color::Transparent);
        hitboxDebug.setOutlineColor(sf::Color::Red);
        hitboxDebug.setOutlineThickness(1.f);
    }
    void drawPlayerRadiusDebugCollision(sf::RenderWindow* w)
    {
        radiusHitboxDebug.setPosition(sf::Vector2f(getPlayerCollisionBox().left, getPlayerCollisionBox().top));
        w->draw(radiusHitboxDebug);
    }
    void drawDebugCollision(sf::RenderWindow* w) {
        hitboxDebug.setPosition(sf::Vector2f(getCollisionBox().left, getCollisionBox().top));
        w->draw(hitboxDebug);
    }
    sf::FloatRect getPlayerCollisionBox()
    {
        return sf::FloatRect(radiusCollisionBox.left + Player_radius.left, radiusCollisionBox.top + Player_radius.top, radiusCollisionBox.width, radiusCollisionBox.height);
    }
    
    sf::FloatRect getCollisionBox() 
    {

        return sf::FloatRect(collisionBox.left + rect.left, collisionBox.top + rect.top, collisionBox.width, collisionBox.height);
    }
    bool checkCollision(sf::IntRect otherRect) {
        return rect.intersects(otherRect);
    }
    bool checkPlayerRadiusCollision(sf::IntRect other)
    {
        return Player_radius.intersects(other);
    }
};