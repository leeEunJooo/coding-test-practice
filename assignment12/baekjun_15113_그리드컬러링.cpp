#include <bits/stdc++.h>

using namespace std;

string line[35];

int N, M;
bool over;
long dp[35][35];
long result = 1;

void fill_color(int x, int y) {

	if(line[x][y]=='B'){

		for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) {
				if (line[i][j] == 'R'){
                  over = true;
                  return;
				}
				line[i][j] = 'B';
			}
		}

	}

	//blue가 못옴
	else if(line[x][y]=='R'){

		for (int i = x; i < N; i++) {
			for (int j = y; j < M; j++) {
				if (line[i][j] == 'B'){
                over = true;
				return;
				}
				line[i][j] = 'R';
			}
		}

	}
}

long dpcnt(int x, int y) {
//    cout << "(" << x << "," << y <<")"<<endl;
	if (dp[x][y] != 0) return dp[x][y];

	dp[x][y] = 1;
	//둘째줄인것부터
	for (int i=0; i<x; i++) {
        //오른쪽이 비어있으면 가능
		for (int j = y + 1; j<M; j++) {
			if (line[i][j] == '.') {
				dp[x][y] += dpcnt(i, j);
			}
		}
	}
//    cout<<endl;
	return dp[x][y];
}

void solve(){

    fill(&dp[0][0],&dp[34][35],0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (line[i][j] == '.') continue;

			fill_color(i, j);
			if(over){
                cout <<"0\n";
              return;
			}
		}
	}

//      for(int k=0; k<N; k++)
//            cout << line[k]<<"\n";
//            cout <<"\n";



//3 3
//...
//B..
//..R
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (line[i][j] == '.')
                dpcnt(i, j);
		}
	}

//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//            cout <<dp[i][j]<<" ";
//		}
//		cout <<endl;
//	}


    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            result+=dp[i][j];

    cout << result <<"\n";

}


int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> line[i];


    //solve
    solve();


	return 0;
}

