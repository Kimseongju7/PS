#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define endl '\n'

map<string, int> S;
map<string, string> P;
int F, T;

void Init(){
    S.clear();
    P.clear();
}

void init(string s){
    P[s] = s;
    S[s] = 1;
}

string Find(string v){
    if(v == P[v]) return v;
    else return Find(P[v]);
}

void Union(string u, string v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    if(S[u] > S[v]) swap(u, v);
    P[u] = v;
    S[v] += S[u];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> F;
        Init();
        while(F--){
            string u, v;
            cin >> u >> v;
            if(!S[u]) init(u); if(!S[v]) init(v);
            Union(u, v);
            u = Find(u);
            cout << S[u] << endl;
        }
    }
    return 0;   
}