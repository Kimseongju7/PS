#include<iostream>
using namespace std;
#define INF 1e9
int D[30][30], N, M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cin >> N;
    for(int i = 1; i <= 26; ++i) for(int j = 1; j <= 26; ++j) D[i][j] = INF;
    for(int i = 1; i <= 26; ++i) D[i][i] = 0;
    for(int i = 1; i <= N; ++i){
        char a, b; string str; int s, e;
        cin >> a >> str>> b;
        s = a - 'a' + 1; e = b - 'a' + 1;
        D[s][e] = 1;
        //cout << s << ' ' << e << endl;
    }
    for(int k = 1; k <= 26; ++k) for(int i = 1; i <= 26; ++i) for(int j = 1; j <= 26; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    cin >> M;
    while(M--){
        int s, e; char a, b; string str;
        cin >> a >> str >> b;
        s = a - 'a' + 1; e = b - 'a' + 1;
        cout << (D[s][e] != INF ? 'T' : 'F') << '\n';
        //cout << D[s][e] << '\n';
        //cout << s <<' '<< e << endl;
    } 
    return 0;
}