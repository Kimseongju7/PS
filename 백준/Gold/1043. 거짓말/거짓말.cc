#include<iostream>
#include<vector>
using namespace std;
#define TROOT 54
#define FROOT 53

int N, M, T, dap;
int P[56];
vector<int> v[55];

void init(){
    for(int i = 0; i <= 54; ++i) P[i] = i;
}

int Find(int v){
    if(v == P[v]) return v;
    else return P[v] = Find(P[v]);
}

void Union(int u, int v){
    u = Find(u); v = Find(v);
    P[u] = v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t = 0, a;
    init();
    cin >> N >> M;
    cin >> T;
    if(T) cin >> t;
    for(int i = 1; i < T; ++i){
        cin >> n;
        Union(t, n);
    }
    for(int i = 0; i < M; ++i){
        cin >> T;
        if(T >= 1) {
            cin >> a;
            v[i].emplace_back(a);
        };
        for(int j = 1; j < T; ++j){
            cin >> n;
            Union(n, a);
            v[i].emplace_back(n);
        }
    }
    for(int i = 0; i < M; ++i){
        bool allUnknown = true;
        for(auto j : v[i]){
            if(Find(j) == Find(t)) {
                allUnknown = false; 
                break;
            }
        }
        if(allUnknown) ++dap;
    }
    //for(int i = 1; i <= N; ++i) cout << P[i] << ' ';
    //cout << endl; 
    //cout << t << ' ' << Find(t) << endl;
    cout << dap;
    return 0;
}