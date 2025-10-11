#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, left, right, mid;
    long long dap = 0, index;
    int A[101010] = {};
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
    for(int i = 0; i < N; i++){
        //YYYYYNNN
        left = i; right = N - 1; index = i;
        while(left <= right){
            mid = (left + right) / 2;
             //Y
             if(A[i] >= A[mid] * 0.9){
                left = mid + 1;
                index = mid;
             }
             else right = mid - 1;
        }
        dap += (index - i);
        // cout << index << ' '; cout << endl;
    }
    cout << dap;
    return 0;
}