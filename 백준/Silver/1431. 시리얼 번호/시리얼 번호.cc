#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.length() != b.length()) return a.length() < b.length();
    int asum = 0, bsum = 0;
    for(int i = 0; i < a.length(); i++){
        if('0' <= a[i] && a[i] <= '9') asum += a[i] - '0';
        if('0' <= b[i] && b[i] <= '9') bsum += b[i] - '0';
    }
    if(asum != bsum) return asum < bsum;
    return a < b;
}

int main(){
    cin.tie(0);
    int N; string s[55];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> s[i];
    sort(s, s + N, compare);
    for(int i = 0; i < N; i++) cout << s[i] << '\n';
    return 0;   
}