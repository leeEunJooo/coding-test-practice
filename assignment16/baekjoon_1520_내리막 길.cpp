#include <bits/stdc++.h>

using namespace std;

int dirX[3] = {1,0,-1};
int dirY[3] = {0,1,0};

int arr[501][501];
int dp[501][501];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N; cin >>M >> N;

	for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
	}

	int cx=0,cy=0;
	for(int d=0; d<3; d++){
        int nx = cx + dirX[d];
        int ny = cy + dirY[d];
        if(nx<0 || nx>N-1 || ny<0 || ny>M-1) continue;


	}
	return 0;
}
