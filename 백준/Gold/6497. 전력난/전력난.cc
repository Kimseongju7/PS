#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;
vector<tuple<int, int, int> > E;
int N, M, weightSum;
int P[202020];
void init(){for(int i = 0; i<= N; ++i) P[i] = i;}
int Find(int v){return v == P[v]? v:P[v] = Find(P[v]);}
bool Union(int u, int v){return Find(u)!= Find(v) && (P[P[u]] = P[v], true);}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        init();
        weightSum = 0;
        E.clear();
        for(int i = 1; i <= M; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            E.emplace_back(w, u, v);
            weightSum += w;
        }
        sort(E.begin(), E.end());
        int mst = 0;
        for(auto [w, u, v] : E){
            if(Union(u, v)) mst += w;
        }
        cout << weightSum - mst << '\n';
    }
    return 0;
}