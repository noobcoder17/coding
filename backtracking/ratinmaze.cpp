#include<bits/stdc++.h>
using namespace std;
#define n 4

void printSol(int sol[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int maze[n][n],int x,int y){
    if(x>=0 && x <=n && y>=0 && y<=n && maze[x][y]==1){
        return true;
    }
    return false;
}

bool solveMazeUNtil(int maze[n][n],int x,int y,int sol[n][n]){
    if(x==n-1 && y==n-1){
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze,x,y)==true){
        sol[x][y] = 1;
        if(solveMazeUNtil(maze,x+1,y,sol)==true){
            return true;
        }
        if(solveMazeUNtil(maze,x,y+1,sol)==true){
            return true;
        }

        sol[x][y] = 0;
        return false;
    }
    return false;
}


void solveMaze(int maze[n][n]){
    int sol[n][n] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    if(solveMazeUNtil(maze,0,0,sol)==true){
        printSol(sol);
        return;
    }
    cout << "No solution" << endl;
    return;
}


int main() {
    int maze[n][n] = {
        {1, 0, 0, 0 }, 
        {1, 1, 1, 1 }, 
        {0, 1, 0, 1 }, 
        {0, 0, 1, 1 }
    };

    solveMaze(maze);
    return 0;

}