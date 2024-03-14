#include <iostream>
#include <map>
using namespace std;

int main(){
    int A, B, tmp, cnt = 0, *a, *b;
    map<int, int> m;
    cin >> A >> B;
    a = new int[A];
    b = new int[B];
    for(int i = 0; i < A; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    for(int i = 0; i < B; ++i) {
        cin >> b[i];
        m[b[i]]++;
    }
    for(int i = 0; i < A; ++i) if(m[a[i]] == 1) ++cnt;
    for(int i = 0; i < B; ++i) if(m[b[i]] == 1) ++cnt;
    cout << cnt << endl; 
    delete[] a;
    delete[] b;
    return 0;
}