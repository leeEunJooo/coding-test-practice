#include <bits/stdc++.h>

using namespace std;

int dirX[] = {0,1,1};
int dirY[] = {1,0,1};


int M;
int N;

int mini[4];   //up right down left
vector<vector<pair<int,int>>> v;

//i,j를 기준으로 4개 방문
void check(vector<string> &board, int i, int j){



    int x = i;
    int y = j;
    char pattern = board[x][y];

    vector<pair<int,int>> temp;
    temp.push_back({x,y});
    vector<char> k;
    bool allsame = true;

    int cnt = 0;
    for(int d=0; d<3; d++){
        int nx = x + dirX[d];
        int ny = y + dirY[d];

        if(nx<0 ||nx>M-1 || ny<0 || ny>N-1) continue;

        if(board[nx][ny] != pattern){
           return;
        }
        else{
            cnt+=1;
            temp.push_back({nx,ny});
//            k.push_back(pattern);
        }

    }

    if(cnt == 3 && temp.size()>0)
        v.push_back(temp);

//    for(auto a: k){
//        cout <<a;
//    }
//    cout <<endl;

}

bool turn(vector<string> &board){
    //check
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(board[i][j] != '0')
                check(board, i,j);
        }
    }
    return v.size()>0;

}

void bomb(vector<string> &board){
    //bomb
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            board[v[i][j].first][v[i][j].second] = '0';
        }
    }

//    for(int i=0; i<v.size(); i++){
//        for(int j=0; j<v[i].size(); j++){
//            cout <<"("<< v[i][j].first <<" "<<v[i][j].second <<") ";
//        }
//        cout <<endl;
//    }
}

void rearrange(vector<string> &board){

    for(int i=0; i<N; i++){

        vector<char> notzero;
        for(int j=M-1; j>=0; j--){
            if(board[j][i] != '0'){
                notzero.push_back(board[j][i]);
            }
        }

        for(int j=notzero.size()-1; j<M; j++)
            notzero.push_back('0');

        for(int j=M-1; j>=0; j--){
            board[j][i] = notzero[M-1-j];
        }

    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;

    M = m; N = n;


    while(turn(board)>0){
        bomb(board);
        rearrange(board);
        v.clear();
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){

            cout <<board[i][j]<<" ";
        }
        cout <<endl;
    }


    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '0') answer+=1;
        }
    }


    return answer;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

//	cout << solution(4,5,{"CCBDE", "AAADE", "AAABF", "CCBBF"});
//	cout << solution(6,6,{"TTTANT", "RRFACC", "RRRFCC", "TRRRAA","TTMMMF","TMMTTJ"});

	return 0;
}
