#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    char c1, c2, c3, c4; int n, n2;
    int N; cin >> N;
    while(N--){
        cin >> c1 >> c2 >> c3 >>c4 >> n;
        n2 = (c1 - 'A') * 26 * 26 + (c2 - 'A') * 26 + (c3 - 'A');
        if(abs(n - n2) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }
    return 0;
}