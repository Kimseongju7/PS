#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin >> a >> b;

    if(a >= 3 && b <= 4) cout << "TroyMartian\n";
    if(a <= 6 && b >= 2) cout << "VladSaturnian\n";
    if(a <= 2 && b <= 3) cout << "GraemeMercurian\n";

    return 0;
}