#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, D[1010101], arr[1010101], nge, t;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    stack<int> st;
    for(int i = N; i >= 1; --i){
        nge = -1;
        while(!st.empty()){
            if(st.top() > arr[i]){
                nge = st.top();
                break;
            }
            else st.pop();
        }
        D[i] = nge;
        st.push(arr[i]);
    }
    for(int i = 1; i <= N; ++i) cout << D[i] <<  ' ';
    return 0;
}