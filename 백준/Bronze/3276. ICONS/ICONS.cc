#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    int r = 1000, c = 1000, i;
    cin >> N;
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= N; ++j){
            if(i * j >= N) {
                if(i + j < r + c) {
                    r = i;
                    c = j;
                }
            }
        }
    }

    cout << r << ' ' << c;
    return 0;
}