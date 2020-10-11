#include <bits/stdc++.h>

using namespace std;

int W[101];
int V[101];
int dp[101][100001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;

	for(int i=1; i<=N; i++){
        cin >> W[i] >> V[i];
	}


	for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            dp[i][j] = dp[i-1][j];
            if(j - W[i] >=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]] + V[i]);
            }

        }
	}

//	cout <<"   ";
//    for(int i=1; i<=K; i++)
//        cout <<i<<" ";
//        cout <<endl;
//	for(int i=1; i<=N; i++){
//        cout << i <<"] ";
//        for(int j=1; j<=K; j++){
//            cout << dp[i][j] <<" ";
//        }
//        cout <<"\n";
//	}
	return 0;
}
