#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, minv = 1e9, A[101010] = {};
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i]; 
        minv = min(minv, A[i]);
    }
    for(int i = 0; i < N; i++){
        if(A[i] == minv){
            cout << i;
            break;
        }
    }
    return 0;
}