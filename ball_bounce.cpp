#include <SFML/Graphics.hpp>
#include<iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(sf::Vector2f(100.f, 100.f)); // Center of the shape
    shape.setPosition(sf::Vector2f(500.f, 100.f));
    sf::Vector2f velocity(1000.f, 0.f);
    sf::Vector2f acceleration(0.f, 4000.f);
    sf::Clock clock; // Before loop

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        
        velocity += acceleration * deltaTime;
        shape.move(velocity * deltaTime);
        if(shape.getPosition().y + 100.f>= 1000.f){
            velocity.y = 0.84*-velocity.y;
        }
        if(shape.getPosition().x +100.f >= 1000.f){
            velocity.x = 0.84 * -velocity.x;
        }
        if(shape.getPosition().x-100.f <= 0.f){
            velocity.x = 0.84 * -velocity.x;
        }
        
        //shape.move(velocity);
        window.clear();
        window.draw(shape);
        window.display();
    }
}