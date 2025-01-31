#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A[1010], t = 0; cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
        if(i & 1) t += A[i];
        else t -= A[i];
    }
    t /= 2;
    cout << t << '\n';
    for(int i = 2; i <= N; ++i){
        t = A[i - 1] - t;
        cout << t << '\n';
    }


    return 0;
}
