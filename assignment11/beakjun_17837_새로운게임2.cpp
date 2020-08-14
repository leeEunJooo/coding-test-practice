#include <bits/stdc++.h>

using namespace std;


int N, K;
int dirX[] = {0,0,-1,1};
int dirY[] = {1,-1,0,0};


struct{
    int x;
    int y;
    int floor;
    int dir;
}typedef Info;

struct{
    int color;
    vector<int> stacks;
}typedef Board;


//red = reverse
Info info[10];
Board board[12][12];

int turn(int cnt){
    if(cnt >=1000) return -1;

    //모든 말에 대해서
    for(int h=0; h<K; h++){

        int x = info[h].x;
        int y = info[h].y;
        int myFloor = info[h].floor;
        int dir = info[h].dir;

        //현재자리에 몇개의 말이 있는지 확인
        //자기 위에 말이 있으면 같이 움직여야함


        int nx = x + dirX[dir];
        int ny = y + dirY[dir];

        //blue
        if(nx<0 || nx>N-1 || ny<0 || ny>N-1 || board[nx][ny].color == 2){


            int reversed_dir = (dir+1)%2==0? dir-1 : dir+1;
            info[h].dir = reversed_dir;
            int newnx = x + dirX[reversed_dir];
            int newny = y + dirY[reversed_dir];

            //새로 가는 곳이 벽이거나 파랑
            if(newnx<0 || newnx>N-1 || newny<0 || newny>N-1 || board[newnx][newny].color == 2){
               continue;
            }

            nx = newnx;
            ny = newny;

        }


        //red
       if(board[nx][ny].color == 1){
            //reverse
            reverse(board[x][y].stacks.begin()+myFloor, board[x][y].stacks.end());

        }

        //white


        //move to next
        int nxtFloor = board[nx][ny].stacks.size();

         for(int k=myFloor; k<board[x][y].stacks.size(); k++){

            int stacked_h = board[x][y].stacks[k];
            info[stacked_h] = {nx, ny, nxtFloor, info[stacked_h].dir};
            board[nx][ny].stacks.push_back(stacked_h);
            nxtFloor+=1;
            if(board[nx][ny].stacks.size() == 4) return cnt;
         }

         board[x][y].stacks.erase(board[x][y].stacks.begin()+myFloor, board[x][y].stacks.end());
    }


    turn(cnt+1);

}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for(int i=0; i<N; i++)
        for(int j=0; j<N ;j++)
            cin >> board[i][j].color;

	for(int k=0; k<K; k++){
	    int a, b, c;cin >>a>>b>>c;
	    a-=1; b-=1; c-=1;
        info[k] = {a,b,0,c};
        board[a][b].stacks.push_back(k);
	}



	cout << turn(1);






	return 0;
}
