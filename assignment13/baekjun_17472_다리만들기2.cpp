#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int check[10][10];
int N, M;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int parent[100001];
int ran[100001];
int ans = 1;

vector<pair<pair<int,int>,int>> v;

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second < b.second;
}

int find(int u){
    if(parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

void union1(int x, int y){
    int u = find(x);
    int v = find(y);

    if(ran[u] > ran[v]) swap(u,v);
    parent[u] = v;  //작은쪽에 parent값을 바꿔줌

    if(ran[u] == ran[v]) ++ran[v];
}

bool root(int u, int v){
    if(find(u)==find(v)) return true;
    return false;
}

void dist(int curland, int targetland){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            if(board[i][j] == curland){

                int longer = max(N,M);
                for(int dist = 2; dist <longer; dist++){
                    for(int d=0; d<4; d++){
                        int nx = i + dx[d]*dist;
                        int ny = j + dy[d]*dist;

                        if(nx<0 || nx>N-1 || ny<0 || ny>M-1) break;
                        if(board[nx][ny] == curland) break;
                        if(board[nx][ny] == targetland)
                            v.push_back({{curland, targetland},dist});

                    }
                }
            }
        }
    }

}

void land(int x, int y, int landNum){
    check[x][y] = true;
    board[x][y] = landNum;

    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy +dy[i];

            if(nx<0 || nx >N-1 || ny<0 || ny >M-1) continue;
            if(board[nx][ny]==0) continue;
            if(check[nx][ny] == true) continue;

            board[nx][ny] = landNum;
            check[nx][ny] = true;
            q.push({nx,ny});
        }
    }

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
	}

	// 섬을 연결
	// 연결됏는지 확인 - 연결 가능한 모든 경우의수로 연결
	queue<pair<int,int>> q;

	//find outline
	int landNum = 1;
	for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] != 0 && check[i][j]!=true){
                land(i,j, landNum);
                landNum +=1;
            }
        }
	}

    for(int i=1; i<=landNum; i++){
        for(int j=1; j<=landNum; j++){
            dist(i,j);
        }
    }

//     for(int i=0; i<v.size(); i++)
//        cout << v[i].first.first <<" " << v[i].first.second <<" " <<v[i].second<<endl;

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<v.size(); i++)
        cout << v[i].first.first <<" " << v[i].first.second <<" " <<v[i].second<<endl;


    for (int i = 0; i<v.size(); i++){
        int land1 = v[i].first.first;
        int land2 = v[i].first.second;
        int dist = v[i].second;

         if(!root(land1,land2)){

            ans += dist;
            union1(land1,land2);

        }

	}

	cout << ans << endl;


	//connect
	for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout <<board[i][j]<<" ";
        }
        cout << endl;
	}

	return 0;
}
