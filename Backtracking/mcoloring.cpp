#include<iostream>
using namespace std;

#define v 4

bool graph[v][v] = {
   {0, 1, 1, 1},
   {1, 0, 1, 0},
   {1, 1, 0, 1},
   {1, 0, 1, 0},
};

void showColor(int color[]){
    for(int i=0; i<v; i++){
        cout<<color[i]<<" ";
    }
}

bool isValid(int vertex, int color[], int c){
    for(int i=0; i<v; i++){
        if(graph[vertex][i] && c==color[i]){
            return false;
        }
    }
    return true;
}

bool graphColor(int colors, int color[], int vertex){
    if(vertex == v){
        return true;
    }
    for(int k=1; k<=colors; k++){
        if(isValid(vertex, color, k)){
            color[vertex] = k;
            if(graphColor(colors, color, vertex+1)){
                return true;
            }
            color[vertex] = 0;
        }
    }
    return false;
}

bool checkSol(int m){
    int *color = new int[v];
    for(int i=0; i<v; i++){
        color[i] = 0;
    }
    if(!graphColor(m, color, 0)){
        cout<<"No solution";
        return false;
    }
    showColor(color);
    return true;
}

int main() {
   int colors = 3;   
   checkSol(colors);
}
