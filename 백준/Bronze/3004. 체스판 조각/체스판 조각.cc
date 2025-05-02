#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, r = 1, c = 1;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        if(i & 1) ++c;
        else ++r;
    }
    cout << r * c; 
    return 0;
}