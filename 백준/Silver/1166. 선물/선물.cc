#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(10);
    long long N, L, W, H; cin >> N >> L >> W >> H;
    double V = L * W * H;
    double A = 0, left = 0, right = min(L, min(W, H));
    int T = 200;
    while(T--){
        double mid = (left + right) / 2.0;
        long long n = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);
        if(n >= N) {
            left = mid + 1e-9;
            A = max(A, mid);
        }
        else right = mid - 1e-9;
    }
    cout << A;
    return 0;
}