#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> board(21, vector<int>(21));
int boardSum;
int answer = 987654321;

pair<int,int> point[4];

void calculate_sum(int x, int y){

    vector<int> sum(5,0);

    //district 1
    int decrease1 = 0;
    for(int y=0; y<point[1].first; y++){
        if(y>=point[0].first) decrease1+=1;
        for(int x=0; x<=point[0].second - decrease1; x++){
            sum[0]+=board[y][x];
        }
    }

    //district 2
    int decrease2 = 0;
    for(int y=0; y<=point[2].first; y++){
        if(y > point[0].first) decrease2++;
        for(int x = point[0].second + decrease2 +1; x<N; x++){
            sum[1]+=board[y][x];
        }
    }

    //district3
    int decrease3=0;
    for(int y=N-1; y>=point[1].first; y--){
        if(y<point[3].first) decrease3+=1;
        for(int x=0; x<point[3].second - decrease3; x++){
            sum[2]+=board[y][x];
        }
    }

    //district4
    int decrease4=0;
    for(int y=N-1; y>point[2].first; y--){
        if(y<=point[3].first) decrease4+=1;
        for(int x=point[3].second +decrease4; x<N; x++){
            sum[3]+=board[y][x];
        }
    }

    sum[4] = boardSum - (sum[0]+sum[1]+sum[2]+sum[3]);


    sort(sum.begin(), sum.end());
    int mindiff = sum[4] - sum[0];

    answer = min(answer, mindiff);
}

void make_border(int x, int y){

    //왼족위에서 오른쪽 아래로
    for(int d1 = 1; d1<=x; d1++){
        //왼쪽 밑에서 오른쪽 위로
        //현재 y좌표부터 판의 가로길이 끝까지
        for(int d2=1; d2 <=N-x; d2++){
            //boundary
            //2, 3, 4
            if(y+d2>N-1 || x+d2>N-1) continue;
            if(y+d1>N || x-d1<0) continue;
            if(y+d1+d2>N-1 || x-d1+d2<0) continue;

            point[0] = {y, x};
            point[1] = {y+d1, x-d1};
            point[2] = {y+d2, x+d2};
            point[3] = {y+d1+d2, x-d1+d2};

            //calculate sum
            calculate_sum(x, y);
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N;


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            boardSum += board[i][j];
        }
    }

    for(int y=0; y<N; y++)
        for(int x=0; x<N; x++)
            make_border(x, y);
    cout << answer;

	return 0;
}
