#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<int, int> > v;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first && a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; 
    cin >> N;
    for(int i = 0; i < N; ++i){
        int h, w;
        cin >> w >> h;
        v.emplace_back(w, h);
    }
    for(int i = 0; i < N; ++i){
        int dap = 1;
        for(int j = 0; j < N; ++j) dap += compare(v[i], v[j]);
        cout << dap << ' ';
    }
    return 0;
}