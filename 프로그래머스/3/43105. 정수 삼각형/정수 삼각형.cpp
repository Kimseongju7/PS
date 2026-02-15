#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int D[1010][1010];
    int R = triangle.size();
    int C = triangle[R - 1].size();
    D[0][0] = triangle[0][0]; 
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j <= i; j++) cout << triangle[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "--------------" << endl;
    for(int i = 1; i < R; i++){
        for(int j = 0; j <= i; j++){
            for(int k = j - 1; k <= j; k++){
                if(k < 0 || k >= i) continue;
                D[i][j] = max(D[i][j], triangle[i][j] + D[i - 1][k]);
            }
        }
    }
    int dap = 0; 
    for(int i = 0; i < C; i++) dap = max(dap, D[R - 1][i]);
    
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j <= i; j++) cout << D[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "--------------" << endl;
    return dap;
}