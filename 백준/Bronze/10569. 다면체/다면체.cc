#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    int V, E; 
    while(T--){
        cin >> V >> E;
        cout << 2 - V + E << '\n';
    }
    return 0;
}