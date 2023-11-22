#include <iostream>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;
#define N 192
#define M 108

class Game{
    private:
        int map[N][M];


    public: 
        Game(){
            for(int i=0;i<N;i++){
                for(int j =0;j<N;j++){
                    map[i][j]=0;
                }
            }
        }

        Game(int inimap[N][M]){
            for(int i=0;i<N;i++){
                for(int j =0;j<N;j++){
                    map[i][j]=inimap[i][j];
                }
            }
        }

        int Get_Map_Element(int i, int j){
            return map[i][j];

        }
        void Set_Map_Element(int i, int j, int val){
            map[i][j]=val;

        }

        void Display(sf::RenderWindow &w){

            sf::RectangleShape carre (sf::Vector2f(10, 10));
        
            for(int i =0;i<N;i++){
                for(int j=0;j<M;j++){
                    if (Get_Map_Element(i,j)){
                        carre.setPosition(10*i, 10*j);
                        w.draw(carre);

                    }
                    }
            }
            }

        int NumberOfNeighbors(int i,int j){
            int res = 0;
            for(int k=-1;k<=1;k++){
                for(int l =-1;l<=1;l++){
                    res += Get_Map_Element(i+k,j+l);
                }
            }
            return res - Get_Map_Element(i,j);
        
        }
        void Update(){
            vector<int> I, J;
            
            for(int i =0;i<N;i++){
                for(int j=0;j<M;j++){
                    int neighbors = NumberOfNeighbors(i,j);
                    if (Get_Map_Element(i,j)){
                        if((neighbors<2)||(neighbors>3)){
                            I.push_back(i);
                            J.push_back(j);

                        }

                    }
                    else{
                        if(neighbors==3){
                            I.push_back(i);
                            J.push_back(j);
                        }
                    }
                    }
            }
            for (int k =0;k<I.size();k++){
                int i=I[k];
                int j=J[k];

                int val = Get_Map_Element(i,j);
                Set_Map_Element(i,j,1-val);
            }
        }
        

};