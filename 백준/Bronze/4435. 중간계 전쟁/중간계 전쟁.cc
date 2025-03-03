#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, n1, n2; cin >> T;
    int z1, z2, z3, z4, z5, z6, z7;
    for(int i = 1; i <= T; ++i){
        cin >> z1 >> z2 >> z3 >> z4 >> z5 >> z6;
        n1 = z1 * 1 + z2 * 2 + z3 * 3 + z4 * 3 + z5 * 4 + z6 * 10;
        cin >> z1 >> z2 >> z3 >> z4 >> z5 >> z6 >> z7;
        n2 = z1 + z2 * 2 + z3 * 2 + z4 * 2 + z5 * 3 + z6 * 5 + z7 * 10;
        cout << "Battle " << i << ": ";
        if(n1 > n2) cout << "Good triumphs over Evil\n";
        else if(n2 > n1) cout << "Evil eradicates all trace of Good\n";
        else cout << "No victor on this battle field\n";
    }
    return 0;
}