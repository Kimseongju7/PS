#include<iostream>
#define endl '\n'
using namespace std;


void A(int N){
    // bool b = true;
    // if(N == 1) cout << "*";
    // else if(N == 2) cout << "*" << endl << " * ";
    // else{
        if(N & 1){
            for(int i = 0; i < N / 2 + 1; i++) cout << "* ";
            cout << endl << ' ';
            for(int i = 0; i < N / 2; i++) cout << "* "; 
        }
        else {
            for(int i = 0; i < N / 2; i++) cout << "* ";
            cout << endl << ' ';
            for(int i = 0; i < N / 2; i++) cout << "* ";
        }
    // }   
}
void B(int N){
    for(int i = 0; i < N; i++) {
        A(N);
        cout << endl;
    }
}

int main(){
    cin.tie()->sync_with_stdio(0);
    int N; cin >> N;
    B(N);
    return 0;
}