#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, *a, *b, sum = 0;
    cin >> N;
    a = new int[N];
    b = new int[N];
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < N; ++i) cin >> b[i];
    sort(a, a + N);
    sort(b, b + N);
    for(int i = 0; i < N; i++) sum += a[i] * b[N - i - 1];
    cout << sum << endl;
    delete[] a;
    delete[] b;
    return 0;
}