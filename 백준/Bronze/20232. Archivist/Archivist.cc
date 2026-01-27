#include<iostream>
#include<map>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int N[7] = {1996, 1997, 2000, 2007, 2008, 2013, 2018};
    for(int i = 0; i < 7; i++){
        if(n == N[i]){
            cout << "SPbSU";
            return 0;
        }
    }
    if(n == 2006) cout << "PetrSU, ITMO";
    else cout << "ITMO";
    return 0;
}