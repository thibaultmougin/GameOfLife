#include <SFML/Graphics.hpp>
#include "game.cpp"
#include<vector>
#define N 192
#define M 108

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock clock;

    int mod = 0;
    int periode =1;

    Game game;
    float lastupdate= 0;

    game.Set_Map_Element(63,64,1);
    game.Set_Map_Element(64,64,1);
    game.Set_Map_Element(65,64,1);
    game.Set_Map_Element(65,65,1);
    game.Set_Map_Element(66,65,1);
    game.Set_Map_Element(66,66,1);
    game.Set_Map_Element(66,67,1);

    game.Set_Map_Element(86,65,1);
    game.Set_Map_Element(87,65,1);
    game.Set_Map_Element(88,65,1);
    

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        game.Display(window);

        if((((int)elapsed.asSeconds())%periode==0)&&(elapsed.asSeconds()-lastupdate>=1)){
            game.Update();
            lastupdate=elapsed.asSeconds();
        }
        
        window.display();
    }

    return 0;
}