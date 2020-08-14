#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> topni(4,vector<int>(8));
int dir[4];
int K;

void rotate_topni(int idx, int mydir){
    vector<int> temp(8,0);
    copy(topni[idx].begin(), topni[idx].end(), temp.begin());

    //0 1 2 3 4 5 6
    // clock : 3->4
    // not clock : 0<-1, 1<-2, 2 <- 3, 3<- 4, 4<- 5

    if(mydir == 1){
        for(int i=0; i<8; i++){
            topni[idx][(i+1)%8] = temp[i];
        }
    }

    if(mydir == -1){
        for(int i=0; i<8; i++){
            topni[idx][i] = temp[(i+1)%8];
        }
    }

}



void topni_dir(int n, int mydir){

    fill(&dir[0],&dir[0]+4, 0);
    dir[n] = mydir;

    //left
    for(int i=n; i>0; i--){
        int prev = dir[i];
        if(topni[i][6] != topni[i-1][2]){
            dir[i-1] = prev*-1;
        }
    }

    //right
    for(int i=n; i<3; i++){
        int prev = dir[i];
        if(topni[i][2] != topni[i+1][6]){
            dir[i+1] = prev*-1;
        }

    }

    for(int i=0; i<4; i++)
        rotate_topni(i, dir[i]);

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//N±Ø 0 S±Ø 1
    for(int i=0; i<4; i++){
        string s;cin >> s;
        for(int j=0; j<8; j++){
            topni[i][j] = s[i]-'0';
        }
    }

    cin >>K;
    for(int i=0; i<K; i++){
        int number, dir;
        number-=1;
        cin >>number >> dir;

        topni_dir(number, dir);
    }

    int ans=0;

    if(topni[0][0] == 0) ans+=1;
    if(topni[1][0] == 0) ans+=2;
    if(topni[2][0] == 0) ans+=4;
    if(topni[3][0] == 0) ans+=8;

    cout << ans;

	return 0;
}
