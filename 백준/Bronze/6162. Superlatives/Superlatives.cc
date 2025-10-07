#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, A, E;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cout << "Data Set " << i << ":\n";
        cin >> E >> A;
        if (E <= A) cout << "no ";
        for(int j = A * 5; j < E; j = j * 5) cout << "mega ";
        cout << "drought\n\n";
    }
    return 0;
}