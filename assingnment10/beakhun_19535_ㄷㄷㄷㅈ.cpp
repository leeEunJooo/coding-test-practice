#include <bits/stdc++.h>

using namespace std;


vector<int> graph[300001];

long long Dnum=0;
long long Gnum=0;

// 1 <= v1,v2 <= N
void cal(int N){

    for(int i=1; i<=N; i++){

        for(int j=0; j<graph[i].size(); j++){
            if(graph[i][j]<i) continue;

            Dnum += ((long long)graph[i].size()-1)*((long long)graph[graph[i][j]].size()-1);

        }
        //5C3
        Gnum += ((long long)graph[i].size())*((long long)graph[i].size()-1)*((long long)graph[i].size()-2)/6;
    }
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;



	for(int i=1; i<N; i++){
        int v1, v2;
        cin >> v1 >>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
	}

    cal(N);


    if(Dnum > Gnum*3) cout<< "D"<< "\n";
    else if(Gnum*3 > Dnum) cout <<"G"<<"\n";
    else cout <<"DUDUDUNGA"<<"\n";
	return 0;
}
