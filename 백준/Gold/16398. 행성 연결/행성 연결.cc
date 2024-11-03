#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int P[1010], N;
vector<tuple<long, int, int> > E;
void init(){for(int i = 1; i <= N; ++i) P[i] = i;}
int Find(int v){return v == P[v] ? v : P[v] = Find(P[v]);}
bool Union(int u, int v){return Find(u)!=Find(v) && (P[P[u]] = P[v], true);}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    init();
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            long long t; cin >> t;
            if(j < i) E.emplace_back(t, i, j);
        }
    }
    sort(E.begin(), E.end());
    long long dap = 0;
    for(auto [w, u, v] : E){
        if(Union(u, v)) dap += w;
    }
    cout << dap;
    return 0;
}