#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N;
    double n, p, sum = 0;
    string A; 
    cin >> T;
    while(T--){
        cin >> N;
        sum = 0.0;
        while(N--){
            cin >> A >> n >> p;
            sum += n * p;
        }
        cout << '$';
        cout << fixed << setprecision(2) << sum << '\n';
    }
    return 0;   
}