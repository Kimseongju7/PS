#include<iostream>
#include<unordered_set>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N, t;
    cin >> T;
    unordered_set<int> A;
    T++;
    while(--T){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> t;
            A.insert(t);
        }
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> t;
            if(A.count(t)) cout << 1;
            else cout << 0;
            cout << '\n';
            
        }
        A.clear();
    }
    return 0;
}