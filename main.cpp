#include <SFML/Graphics.hpp>
#include "game.hpp"

#define N 192
#define M 108

using namespace std;


void display( int mat[N][M],sf::RenderWindow &w){
    sf::RectangleShape carre (sf::Vector2f(10, 10));
    

    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            if (mat[i][j]==1){
                carre.setPosition(10*i, 10*j);
                w.draw(carre);

            }
            }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::RectangleShape rectangle (sf::Vector2f(10, 10));
    int mod = 1;

    Game game;

    int mat[N][M]={0};

    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            if(i-j==0){
                mat[i][j]=1;
            }
        }}

    

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

    
        display(mat,window);
        window.display();
    }

    return 0;
}