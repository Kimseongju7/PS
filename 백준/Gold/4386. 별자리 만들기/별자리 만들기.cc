#include<iostream>
#include<queue>
#include<utility>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    vector<pair<int, double> > G[101];
    double a[101][2];
    int C[101] = {};
    cin >> N; 
    for(int i = 1; i <= N; ++i){
        double x, y; cin >> a[i][0] >> a[i][1];
    }
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        if(i == j) continue;
        double w = sqrt((a[i][0] - a[j][0])*(a[i][0] - a[j][0]) + (a[i][1] - a[j][1])*(a[i][1] - a[j][1]));
        G[i].emplace_back(j, w);
    }
    double dap = 0;
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<> > pq;
    C[1] = 1;
    for(auto [i, w] : G[1]) pq.emplace(w, i);
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(C[v]) continue;
        C[v] = 1; dap += c;
        for(auto [i, w] : G[v]) pq.emplace(w, i);
    }
    cout << setprecision(3) <<  dap;
    return 0;
    
}