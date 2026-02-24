#include<iostream>
#include<string>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N; long long A[40000] = {};
    string dap;
    cin >> T; cin.ignore(); 
    while(T--){
        N = 0; long long t;
        dap = "NAUTILUS";
        while(cin.peek() != '\n'){
            cin >> t; 
            A[N++] = t;
        }
        cin.ignore();

        for(int i = 0; i < N; i++){
            if(i < 4){
                if(i != A[i]) {
                    dap = "SNAIL";
                    break;
                }
            }
            else if(A[i] != (A[i - 1] + A[i - 2] + A[i - 3] + A[i - 4])){
                dap = "SNAIL";
                break;
            }
        }
        cout << dap << '\n';
    }
    return 0;
}