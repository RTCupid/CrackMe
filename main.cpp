#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    sf::CircleShape shape(10.f);

    shape.setFillColor(sf::Color::Green);

    // Устанавливаем позицию круга в центр окна
    shape.setPosition(75.f, 75.f);  // (200-100*2)/2 = 50

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                break;}
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
