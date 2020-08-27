#include <bits/stdc++.h>

using namespace std;

int board[200][200];
int timestore[200][200];
int R, C, N;
int dirX[] = {-1,0,1,0};
int dirY[] = {0,-1,0,1};

int main(){

    cin >> R >> C >> N;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char a; cin >>a;
            if(a=='O'){
                board[i][j] = 0;
                timestore[i][j] = 3;
            }
            else
                board[i][j] = -1;
        }
    }

    //solve

    int t = 1;

    while(1){

        if (t == N) break;
        t++;

        if (t % 2 == 0){
            for (int i=0; i<R; i++){
                for (int j=0; j<C; j++){
                    if (board[i][j] == 0) continue;
                    board[i][j] = 0;
                    timestore[i][j] = t + 3;
                }
            }
            continue;
        }



        for (int i=0; i<R; i++){
            for (int j = 0; j<C; j++){
                if (timestore[i][j] == t){
                    board[i][j] = '.';
                    timestore[i][j] = 0;

                    for (int k = 0; k<4; k++){
                        int nx = i + dirX[k];
                        int ny = j + dirY[k];

                        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                        if (board[nx][ny] == -1) continue;

                        board[nx][ny] = -1;
                    }

                }
            }
        }

    }


    //print answer
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(board[i][j] == 0)
            cout <<'O';
            else cout <<'.';
        }
        cout <<"\n";
    }



    return 0;
}
