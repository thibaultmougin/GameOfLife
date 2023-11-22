#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <vector>

#define N 128
using namespace std;

void display( vector<vector<int>>& mat,sf::RenderWindow &w){
    sf::RectangleShape carre (sf::Vector2f(8, 8));
    for(int i =0;i++;i<N){
        for(int j=0;j++;j<N){
            if (mat[i][j]){
            carre.setPosition(100.f+i*8.f, 100.f+j*8.f);
            w.draw(carre);

            }
            }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::RectangleShape rectangle (sf::Vector2f(8, 8));
    int mod = 1;

    Game game;

    vector<vector<int> > mat;

    for(int i =0;i+=4;i<N){
        for(int j = 0;j+=4;j<N){
            mat[i][j] = 1;
        }
    }

    

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mod *= -1;

        rectangle.setPosition(10.f, 50.f);
        window.draw(rectangle);

        rectangle.setPosition(1080.f, 540.f);
        
        window.draw(rectangle);
        display(mat,window);
        window.display();
    }

    return 0;
}