#include<iostream>
#include<cstring>
#include<string>
#include<vector> 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, num = 1; 
    vector<string> str;
    while(true){
        cin >> N;
        if(N == 0) break;
        
        str.clear();
        int A[101] = {};
        memset(A, 0, sizeof(A));
        string s;
        cin.ignore();
        for(int i = 1; i <= N; ++i){
            getline(cin, s, '\n');
            str.emplace_back(s);
        }
        int n; char c;
        for(int i = 1; i <= 2 * N - 1; ++i){
            cin >> n >> c;
            A[n]++;
        }
        for(int i = 1; i <= N; ++i){
            if(A[i] != 2){
                cout << num << ' ' << str[i - 1] << '\n';
                ++num;
                break;
            }
        }
    }
    return 0;
}