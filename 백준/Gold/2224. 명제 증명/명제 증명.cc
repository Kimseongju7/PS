#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#define INF 1e9
using namespace std;
#define N 53
int D[55][55], n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> v; vector<int> v2;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    cin >> n;
    while(n--){
        char a, b; string str; cin >> a >> str >> b;
        int s = a <= 'Z' ? a - 'A' + 1 : a - 'a' + 28, e = b <= 'Z' ? b - 'A' + 1 : b - 'a' + 28;
        D[s][e] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            if(D[i][j] != INF){
                char a = i <= 27 ? i + 'A' - 1: i + 'a' - 28 ,b = j <= 27 ? j + 'A' - 1: j + 'a' - 28;
                v.emplace_back(a);
                v2.emplace_back(b);
            }
        }
    }
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); ++i) cout << char(v[i]) << " => " << char(v2[i]) << '\n';
    return 0;
}