#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A, B, T[111] = {}, dap = 0;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; ++i) cin >> T[i];
    sort(T + 1, T + N + 1);
    for(int k = 0; k <= N; ++k){
        for(int i = 0; i < A; ++i){
            int ta = A - i, ttime = 0, t = 0;
            for(int j = 0; j <= N; ++j){
                if(j <= k){
                    if(ttime + A <= T[j] && j != 0){
                        ++t;
                        ttime += A;
                    }
                }
                else {
                    if(ttime + ta <= T[j]) {
                        ++t;
                        ttime += ta;
                    }
                }
                if(j == k) ttime += i * B;
                
            }
            //cout << "i : " << i << ", k : " << k << ", t : " << t << endl;
            dap = max(t, dap);
        }
    }
    cout << dap;
    return 0;
}
