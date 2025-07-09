#include<iostream>
#include<set>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, t, A[3030]; 
    while(cin >> N){
        set<int> s;
        // if(N == 1) cout << "Jolly\n";
        // else{ 
            for(int i = 0; i < N; i++) cin >> A[i];
            for(int i = 1; i < N; i++){
                t = abs(A[i] - A[i - 1]);
                if(t > 0 && t < N) s.insert(t);
            }
            if(s.size() == (N - 1)) cout << "Jolly\n";
            else cout << "Not jolly\n";
        // }   
    }
    return 0;
}