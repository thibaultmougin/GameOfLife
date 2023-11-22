#pragma once
#define N 192
#define M 108
class Game {
    private:
        int map[N][M];
    public:
        int Get_Map_Element(int i, int j);
        void Set_Map_Element(int i, int j, int val);




};