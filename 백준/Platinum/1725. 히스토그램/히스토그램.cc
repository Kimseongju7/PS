#include<bits/stdc++.h>
using namespace std;
int dap = 0;
int a[101010];

void d(int l, int r){
    if(l == r) dap = max(dap, a[l]);
    else if(r < l) dap = max(dap, a[l]);
    else if (l > r) dap = max(dap, a[r]);
    else{
        int m = (l + r) / 2;
        int w = 1, h = a[m];
        int i = m - 1, j = m + 1;
        dap = max(dap, a[m]);
        while(l <= i && j <= r){
            ++w;
            if(a[i] >= a[j]){
                h = min(h, a[i]);
                --i;
            }
            else{
                h = min(h, a[j]);
                ++j;
            }
            dap = max(dap, h * w);
        }
        while(l <= i){
            ++w;
            h = min(a[i], h);
            dap = max(dap, h * w);
            --i;
        }
        while(j <= r){
            ++w;
            h = min(a[j], h);
            dap = max(dap, h * w);
            ++j;
        }
        d(l, m - 1);
        d(m + 1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> a[i];
    d(1, N);
    cout << dap;
    return 0;
}