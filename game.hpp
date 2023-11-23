#pragma once
#include <SFML/Graphics.hpp>

#define N 96
#define M 54
#define C 20
class Game {
    private:
        int map[N][M];
        int setup_mode;
        int time;
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
        void Reset();
        void SaveMap();
        void LoadMap();
        int Get_Time();
        void Set_Time();


};