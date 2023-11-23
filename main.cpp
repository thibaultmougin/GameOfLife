#include <SFML/Graphics.hpp>
#include "game.cpp"
#include<vector>
#define N 96
#define M 54
#define C 20

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "The Game of Life");
    sf::Clock clock;

    sf::Font boldfont;
    if (!boldfont.loadFromFile("SpaceMono-Bold.ttf"))
    {
        cout << "font loading error" << endl;
    }

    sf::Text text;
    sf::Text infos;

    // select the font
    text.setFont(boldfont); // font is a sf::Font
    infos.setFont(boldfont);

    // set the string to display
    text.setString("Setup Mode ON");
    infos.setString("Spacebar to clear\nS to save pattern\nL to load pattern");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    infos.setCharacterSize(16); // in pixels, not points!

    text.setPosition(20,14);
    infos.setPosition(20,938);

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
                    if ((game.Get_setup_mode())&& (event.key.code == sf::Keyboard::Space)){
                        game.Reset();
                    }
                    if ((game.Get_setup_mode())&& (event.key.code == sf::Keyboard::S)){
                        game.SaveMap();
                    }
                    if ((game.Get_setup_mode())&& (event.key.code == sf::Keyboard::L)){
                        game.LoadMap();
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
        
        if(game.Get_setup_mode()==1){
            
            text.setFillColor(sf::Color::Red);
            text.setString("Setup Mode ON - Press Enter to play");
            window.draw(infos);
        }
        else{    
            text.setFillColor(sf::Color::Green);
            text.setString("Setup Mode OFF - Press Escape to edit");

        }
        window.draw(text);

        
        window.display();
    }

    return 0;
}