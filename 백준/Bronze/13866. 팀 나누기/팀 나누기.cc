#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int A[4] = {};
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    sort(A, A + 4);
    cout << abs((A[0] + A[3]) - (A[1] + A[2]));
    return 0;
}
