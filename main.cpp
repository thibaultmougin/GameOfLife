#include <SFML/Graphics.hpp>
#include "game.cpp"
#include<vector>
#define N 96
#define M 54
#define C 20

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock clock;

    int mod = 0;
    int periode =1;

    Game game;
    float lastupdate= 0;

    
    
    game.Set_setup_mode(1);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        game.Set_setup_mode(1);

                    }
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        game.Set_setup_mode(0);

                    }
                }
            if ((event.type == sf::Event::MouseButtonPressed)&&(game.Get_setup_mode())){
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    game.Set_Map_Element((int)event.mouseButton.x/C,(int)event.mouseButton.y/C,0);
                }
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    game.Set_Map_Element((int)event.mouseButton.x/C,(int)event.mouseButton.y/C,1);

                }
                    }
        }

        window.clear();
        
        game.Display(window);

        if(game.Get_setup_mode()==0){
            if((((int)elapsed.asSeconds())%periode==0)&&(elapsed.asSeconds()-lastupdate>=1)){
                game.Update();
                lastupdate=elapsed.asSeconds();
            }}
        
        
        window.display();
    }

    return 0;
}