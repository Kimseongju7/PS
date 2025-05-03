#include<iostream>
using namespace std;
#include<set>

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N, A[303], mx = 0;
    set<int> s;
    int m = 1;
    cin >> T;
    while(T--){
        cin >> N;
        mx = 0;
        for(int i = 1; i <= N; ++i) cin >> A[i], mx = max(mx, A[i]);
        for(int i = 1; i <= mx + 1; ++i){
            s.clear();
            for(int j = 1; j <= N; ++j){
                s.insert(A[j] % i);
            }
            if(s.size() == N){
                m = i;
                break;
            }

        }
        cout << m << '\n';
        
    }

}