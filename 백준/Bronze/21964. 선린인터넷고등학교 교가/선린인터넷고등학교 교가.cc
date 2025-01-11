#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; string s;
    cin >> N >> s;
    for(int i = N - 5; i < N; ++i) cout << s[i];
    return 0;
}