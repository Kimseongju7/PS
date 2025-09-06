#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, U, L; cin >> N >> U >> L;
    if(N >= 1000) {
        if(U >= 8000 || L >= 260) cout << "Very Good";
        else cout << "Good";
    }
    else cout << "Bad";
    return 0;
}