#include <bits/stdc++.h>

using namespace std;

char arr[31][31];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M,N; cin >> M>>N;

    vector<int> given_line(N+1) ;
     for (int i=0; i<=N; i++)
      given_line[i] = 1 ;

    for (int i=0; i<M; i++) {
        string strs; cin >>strs;
        vector<long long> renew_line(N+1) ;

        int lastB = 0 ;
        int lastRed = N ;

        for (int j=0; j<N; j++){
            if (strs[j] == 'R')
                lastRed = min(j, lastRed) ;
           else if (strs[j] == 'B')
                lastB = j ;
        }

        int s = 0;
        for (int j=N; j>=0; j--) {
         if (lastB <j && j<=lastRed)
            s += given_line[j] ;

         if (j <= lastRed)
            renew_line[j] += s ;
      }

      swap(renew_line, given_line) ;

   }

   cout << board[0] << endl ;


	return 0;
}
