#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;
#define N 96
#define M 54
#define C 20

class Game{
    private:
        int map[N][M];
        int setup_mode;

    public: 
        Game(){
            for(int i=0;i<N;i++){
                for(int j =0;j<N;j++){
                    map[i][j]=0;
                }
            }
            setup_mode =1;
        }

        Game(int inimap[N][M]){
            for(int i=0;i<N;i++){
                for(int j =0;j<N;j++){
                    map[i][j]=inimap[i][j];
                }
            }
            setup_mode =0;

        }

        int Get_Map_Element(int i, int j){
            return map[i][j];

        }
        void Set_Map_Element(int i, int j, int val){
            map[i][j]=val;

        }

        void Display(sf::RenderWindow &w){

            sf::RectangleShape carre (sf::Vector2f(C, C));
            sf::RectangleShape ligne (sf::Vector2f(1920,2));
            sf::RectangleShape col (sf::Vector2f(2,1080));
            col.setFillColor(sf::Color(32, 32, 32));
            ligne.setFillColor(sf::Color(32, 32, 32));

            for(int i =0;i<N;i++){
                
                for(int j=0;j<M;j++){
                    if (Get_Map_Element(i,j)){
                        carre.setPosition(C*i, C*j);
                        w.draw(carre);

                    }
                    }
            }
            for(int i =0;i<N;i++){

                col.setPosition(C*i-1, 0);
                w.draw(col);
                if(i<M){
                    ligne.setPosition(0,C*i-1);
                    w.draw(ligne);

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
        
        int Get_setup_mode(){
            return setup_mode;
        }
        
        void Set_setup_mode(int val){
            setup_mode = val;
        }

        void Reset(){
            for(int i=0;i<N;i++){
                for(int j =0;j<N;j++){
                    map[i][j]=0;
                }
            }
            setup_mode =1;
        }

        void LoadMap(){
            char ch;
            fstream fin("pattern.txt", fstream::in);
            int i = 0;
            int j =0;
            while (fin >> noskipws >> ch) {
                if(ch == '1'){
                    map[i][j] = 1;
                    j++;
                }
                else if(ch == '0'){
                    map[i][j] = 0;
                    j++;

                }
                else if (ch == '\n'){
                    i++;
                    j =0;
                }
                    
                
            }
        }

        void SaveMap(){
            ofstream myfile;
            myfile.open ("pattern.txt");
            for(int i =0;i<N;i++){
                for(int j=0;j<M;j++){
                    myfile << map[i][j];
                }
                myfile << "\n";
            }
            myfile.close();
        }

};