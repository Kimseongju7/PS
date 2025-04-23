#include<iostream>
#include<map>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> M >> N;
    map<string, int> m;
    string s, s2;
    for(int i = M; i <= N; ++i){
        int t = i;
        s = "";
        while(t > 0){
            int n = t % 10;

            if(n == 0) s2 = "zero";
            else if(n == 1) s2 = "one";
            else if(n == 2) s2 = "two";
            else if (n == 3) s2 = "three";
            else if(n == 4) s2 = "four";
            else if(n == 5) s2 = "five";
            else if(n == 6) s2 = "six";
            else if(n == 7) s2 = "seven";
            else if(n == 8) s2 = "eight";
            else if(n == 9) s2 = "nine";
 
            t /= 10;
            s = s2 + s;
        }
        m[s] = i;
    }

    int cnt = 0;
    for(auto i = m.begin(); i != m.end(); i++ ){
        cout << i->second << ' ';
        ++cnt;
        if(cnt % 10 == 0) cout << '\n';
    }

    return 0;
}