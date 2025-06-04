#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N; 
    cin >> T;
    while(T--)
    {
        cin >> N;
        int p = ceil(N / 2.0);
        cout << "Pairs for " << N << ": ";
        for(int i = 1; i < p; i++){
            cout << i << ' ' << N - i;
            if(i != p - 1) cout << ", ";
        }
        cout << '\n';
    }
    return 0;
}