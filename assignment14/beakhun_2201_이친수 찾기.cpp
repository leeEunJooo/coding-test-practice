#include <bits/stdc++.h>

using namespace std;

int dp[100];

int solve(int n){
    if(dp[n]!=0) return dp[n];

//    return dp[n] = dp[n]<<
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    long long K;
    cin >>K;

//1 2 4 5 8 9 10 11
    int arr[] = {1, 2, 4, 5, 8, 9, 10, 16, 17,18};
    for(int i=0; i<10; i++)
    cout << bitset<16>(arr[i])<<endl;


    dp[1] = 1;

    solve(K);

//    int cnt=0;
//    while(K>0){
//        K/=2;
//        cnt+=1;
//    }
//
//    cout <<cnt;
	return 0;
}


