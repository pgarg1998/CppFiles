#include<iostream>
using namespace std;

bool canPlace(int mat[][9],int x,int y,int val){
    ///Check along row
    for(int i=0;i<9;i++){
        if(mat[x][i]==val){
            return false;
        }
    }
    ///Check along col
    for(int i=0;i<9;i++){
        if(mat[i][y]==val){
            return false;
        }
    }
    ///Check along subgrid
    int sx = (x/3)*3;
    int sy = (y/3)*3;

    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(mat[i][j]==val){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j){
    if(i==9){
        return true;
    }
    if(j==9){
        return solveSudoku(mat,i+1,0);
    }
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1);
    }
    else{
        ///Hume fill krna
        for(int no=1;no<=9;no++){
            if(canPlace(mat,i,j,no)){
                mat[i][j] = no;
                bool solveHua = solveSudoku(mat,i,j+1);
                if(solveHua==true){
                    return true;
                }
            }

        }
        ///Backtracking
        mat[i][j]=0;
        return false;

    }
}




int main(){




        int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
        cout<<"Unsolved Sudoku:"<<endl<<endl;
           for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

        solveSudoku(mat,0,0);

        cout<<endl<<"Solved Sudoku: "<<endl<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }


return 0;
}
