#include<iostream>
using namespace std;

int main(){
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        string s, S[1010];
        int N, M, dap = 0, t, sum = 0, C[55][26] = {};
        char daps[55] = {};
        cin >> N >> M;
        for(int i = 0; i < N; ++i) cin >> S[i];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                C[j][S[i][j] - 'A']++;
            }
        }
        for(int i = 0; i < M; ++i){
            t = 0; char ti;
            for(int j = 0; j < 26; ++j){
                if(t < C[i][j]){
                    t = C[i][j];
                    ti = j + 'A';
                }
            }
            daps[i] = ti;
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j) if(daps[j] != S[i][j]) ++dap;
        }
        for(int i = 0; i < M; ++i) cout << daps[i];
        cout << '\n' <<  dap;
    return 0;
}