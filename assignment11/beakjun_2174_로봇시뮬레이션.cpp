#include <bits/stdc++.h>

using namespace std;


struct{
    int x;
    int y;
    char dir;
}typedef Robot;

Robot robot[101];
int board[102][102];

int dirX[] = {0, 1,0,-1,0};
int dirY[] = {0, 0,-1,0,1};
int A,B;
int N,M;

bool solve(int r, char command, int T){

    if(command == 'F'){
        for(int t=0; t<T; t++){
            int nx = robot[r].x + dirX[robot[r].dir];
            int ny = robot[r].y + dirY[robot[r].dir];

            if(nx<1 || nx >A || ny<1 || ny>B){
                cout << "Robot " << r <<" crashes into the wall" << "\n";
                return false;
            }
            else if(board[nx][ny] != 0){
                cout << "Robot " << r <<" crashes into robot "<< board[nx][ny] << "\n";
                return false;
            }

            //move
            board[robot[r].x][robot[r].y] = 0;
            robot[r].x = nx; robot[r].y = ny;
            board[nx][ny] = r;
        }
    }

    //rotate
    else{
        for(int t=0; t<T; t++){
            if(command == 'L'){
                if(robot[r].dir == 1) robot[r].dir = 4;
                else robot[r].dir -=1;
            }
            else{
                if(robot[r].dir == 4) robot[r].dir = 1;
                else robot[r].dir +=1;
            }
        }

    }

    return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	 cin>>A>>B;
	 cin>>N>>M;

	for(int i=1; i<=N; i++){
        char command;
        cin >> robot[i].x >> robot[i].y >> command;
        board[robot[i].x][robot[i].y] = i;

        if(command == 'E') robot[i].dir = 1;
        if(command == 'S') robot[i].dir = 2;
        if(command == 'W') robot[i].dir = 3;
        if(command == 'N') robot[i].dir = 4;
	}


    bool ret = true;
    //·Îº¿ ÇÏ³ª¾¿
	for(int j=0; j<M; j++){
        int r, T; char command;
        cin >> r >> command >> T;
        ret = solve(r,command, T);
        if(ret == false) break;
	}
	if(ret) cout << "OK" <<"\n";

	return 0;
}
