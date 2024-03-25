#include<iostream>
#define endl '\n'
using namespace std;
#define M 1000000

unsigned long long number[M + 1];
unsigned long long hap[M + 1];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, x;
    for(int i = 1; i <= M; ++i){
        number[i] += i;
        for(int j = 2; j * i <= M; ++j){
            number[i * j] += i;
        }
    }
    for(int i = 1; i < M; ++i){
        number[i + 1] += number[i];
    }
    cin >> N;
    while(N--){
        cin >> x;
        cout << number[x] << endl;
    }
    return 0;
}