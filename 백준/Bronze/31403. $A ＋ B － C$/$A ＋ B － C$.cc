#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c <<endl;
    string A = to_string(a) + to_string(b);
    cout << stoi(A) - c << endl;
    return 0;
}