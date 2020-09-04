#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1,-1,-1,0,1,1,1, 0};
int dy[] = {-1,0, 1, 1,0,1,-1,-1};

int N;
string arr[301];
int mark[301][301];
int ans = 0;


void click(int i, int j){
//    cout<< i<<" "<<j<<endl;

    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(arr[cx][cy] == '.' && mark[cx][cy]==-1){
            int cnt = 0;


            for(int d=0; d<8; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(nx<0 || nx>N-1 ||ny<0 || ny>N-1) continue;

                if(arr[nx][ny] == '*'){
                    cnt+=1;
                }
            }

            mark[cx][cy] = cnt;
        }

    }
}

bool visited[301][301];

void click_bombed(int i, int j){

    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        visited[cx][cy]==true;

        int cnt = 0;

        for(int d=0; d<8; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(nx<0 || nx>N-1 ||ny<0 || ny>N-1) continue;

            if(visited[nx][ny]!=true){
                visited[nx][ny] = true;
                if(mark[nx][ny] == 0){
                    q.push({nx,ny});
                }
            }
        }

    }
}

void select(){

    int click_times=0;

    //first bomb
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == '.' && mark[i][j] == -1){
                click(i,j);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mark[i][j] == 0 && visited[i][j] == false){
                click_bombed(i,j);
                click_times++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mark[i][j] != 0 && mark[i][j]!=-1 && visited[i][j] == false){
                click_times++;
            }
        }
    }

    ans = click_times;

}

void solve(int N){

    //input
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }


    //select
    select();


    //print
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            cout << mark[i][j]<<" ";
//        }
//        cout <<endl;
//    }

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	int t = T;

    while(T--){
        cin >> N;
        fill(&arr[0], &arr[N], ' ');
        fill(&mark[0][0], &mark[N-1][N], -1);
        fill(&visited[0][0], &visited[N-1][N], false);
        solve(N);
        cout <<"#"<<t-T<<" "<<ans<<endl;
    }

	return 0;
}
