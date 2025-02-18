#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i = 1; i <= 3; ++i){
        int h = 0, m, s, h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1;
        cin >> h2 >> m2 >> s2;
        if(s1 > s2){
            m2--;
            s2 += 60;
        }
        s = s2 - s1;
        if(m1 > m2){
            h2--;
            m2 += 60;
        }
        m = m2 - m1;
        h = h2 - h1;
        cout << h << ' ' << m << ' ' << s << '\n';
    }
    return 0;
}