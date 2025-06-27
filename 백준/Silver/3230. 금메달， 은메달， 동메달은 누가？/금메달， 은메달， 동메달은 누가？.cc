#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define endl '\n'
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    vector<int> v;
    vector<int> dap;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int t; cin >> t;
        v.emplace(v.begin() + (t - 1), (i + 1));
    }
    for(int i = 0; i < M; i++){
        int t; cin >> t;
        dap.emplace(dap.begin() + (t - 1), v[M - i - 1]);
    }
    cout << dap[0] << endl << dap[1] << endl << dap[2];
    return 0;
}