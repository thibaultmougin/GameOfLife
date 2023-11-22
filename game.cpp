#include <iostream>
#include "game.hpp"
#include <vector>

using namespace std;
#define N 128


class Game{
    private:
        int map[N][N];


    public: 
        Game(){

        }
        int Get_Map_Element(int i, int j){
            return map[i][j];

        }
        void Set_Map_Element(int i, int j, int val){
            map[i][j]=val;

        }

        

};