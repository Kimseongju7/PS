#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
using namespace std;

int di[6] = {0, 0, 0, 0, -1, 1}, dj[6] = {0, 0, -1, 1, 0, 0}, dk[6] = {1, -1, 0, 0, 0, 0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int M, N, H, A[101][101][101] = {}, C[101][101][101] = {}, dap = 0, tot = 0, num = 0, pnum = 0;
    cin >> M>> N >> H;
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= N; ++j){
            for(int k = 1; k <= M; ++k) {
                cin >> A[i][j][k];
                if(A[i][j][k] == 0) ++tot;
                else if(A[i][j][k] == 1) ++num;
            }
        }
    }
    tot += num;
    // cout << num << endl;
    // cout << tot << endl;
    queue<pair<pair<int, int>, pair<int, int> > > q;
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= N; ++j){
            for(int k = 1; k <= M; ++k) {
                if(A[i][j][k] == 1) {
                    q.emplace(make_pair(i, j), make_pair(k, 0));
                    C[i][j][k] = 1;
                }
            }
        }
    }
    while(!q.empty()){
        int i = q.front().first.first, j = q.front().first.second, k = q.front().second.first, day = q.front().second.second; q.pop();
        dap = max(dap, day);
        int ii, jj, kk;
        for(int l = 0; l < 6; ++l){
            ii = i + di[l]; jj = j + dj[l]; kk = k + dk[l];
            if(ii < 1 || ii > H || jj < 1 || jj > N || kk < 1 || kk > M) continue;
            if(A[ii][jj][kk] == 0) {
                A[ii][jj][kk] = 1;
                q.emplace(make_pair(ii, jj), make_pair(kk, day + 1));
                ++num;
            }
        }
        // cout << 2;
    }    
        // cout << "pnum : " << pnum << endl;
        // cout << "num : " << num << endl;
    if(num != tot) cout << -1;
    else cout << dap;
    return 0;
}