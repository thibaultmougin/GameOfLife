#pragma once
#define N 128

class Game {
    private:
        int map[N][N];
    public:
        int Get_Map_Element(int i, int j);
        void Set_Map_Element(int i, int j, int val);




};