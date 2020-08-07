#include <bits/stdc++.h>

using namespace std;

set<string> s;

int sep_word(string t){

    int dp[20001];
    dp[t.size()] = 0;
    fill(&dp[0],&dp[t.size()], 987654321);

    for(int i=t.size()-1; i>=0 ; i--){
        string sep = "";
        for(int j=i; j<t.size(); j++){

            sep += t[j];
            if(j> i+5) break;
            //set에 있으면
            if(s.find(sep)!=s.end()){
                if(dp[j+1] !=987654321)
                    dp[i] = min(dp[i], dp[j+1]+1);
            }

        }
    }

    if(dp[0] == 987654321) return -1;
    else return dp[0];

}

int solution(vector<string> strs, string t){
    int answer = 0;

    for(auto i : strs)
        s.insert(i);

   answer = sep_word(t);


    return answer;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    //{"app","ap","p","l","e","ple","pp"}
    //"apple"

     //{"ba","na","n",a"}
    //"banana"

     //{"ba","an","nan","ban","n"}
    //"banana"


    vector<string> strs {"ba","an","nan","ban","n"};
    string t = "banana";
    cout << solution(strs,t);
	return 0;
}

//시간초과
//vector<string> str;
//string correct;
//int ans = 987654321;
//bool findans = false;
//
//void dfs(int index, int cnt, string nowstr){
//
//    string combined = nowstr + str[index];
//
//    if(combined.size() >= correct.size()){
//      if(combined.size() == correct.size()){
//        if(combined == correct){
//            ans = min(ans, cnt);
//            findans = true;
//            return;
//            }
//        }
//      return;
//    }
//
//    for(int i=0; i<str.size(); i++){
//        dfs(i, cnt+1, combined);
//    }
//
//}
//
//int solution(vector<string> strs, string t)
//{
//    int answer = 0;
//    str = strs;
//    correct = t;
//
//    for(int idx=0; idx<str.size(); idx++)
//        dfs(idx, 1,"");
//
//    // 문자 만들기
//    // 길이 비교
//    // 같은지 비교 -> 갯수가 min인지 비교
//    if(findans) answer = ans;
//    else answer = -1;
//
//
//
//    return answer;
//}
