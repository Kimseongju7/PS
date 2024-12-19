#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int p1, s1, s2, p2;
    cin >> p1 >> s1 >> s2 >> p2;
    int s = s1 + s2, p = p1 + p2;
    if(s > p) cout << "Esteghlal";
    else if (p > s) cout << "Persepolis";
    else{
        if(s1 > p2) cout << "Esteghlal";
        else if(p2 > s1) cout << "Persepolis";
        else cout << "Penalty";
    }
    return 0;
}