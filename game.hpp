#pragma once
#include <SFML/Graphics.hpp>

#define N 192
#define M 108
class Game {
    private:
        int map[N][M];
    public:
        Game();
        Game(int inimap[N][M]);

        int Get_Map_Element(int i, int j);
        void Set_Map_Element(int i, int j,int val);

        void Display(sf::RenderWindow &w);
        int NumberOfNeighbors(int i,int j);
        void Update();
        int Get_setup_mode();
        void Set_setup_mode(int val);
        void SetUp();
        void Reset();

};