#include<iostream>
#include<algorithm>
using namespace std;

int B[2020][2020] = {};

typedef struct{
    int score;
    int cnt;
    int id;
} Paricipant;

bool compare(Paricipant &a, Paricipant &b){
    if(a.score == b.score && a.cnt == b.cnt) return a.id < b.id;
    else if(a.score == b.score) return a.cnt > b.cnt;
    else return a.score > b.score;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T, P;
    Paricipant A[2020] = {};
    int score[2020] = {};
    
    cin >> N >> T >> P;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= T; ++j){
            cin >> B[i][j];
            A[i].cnt += B[i][j];
            score[j] += !B[i][j];
        }
        A[i].id = i;
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= T; ++j){
            if(B[i][j]) A[i].score += score[j];
        }
    }

    sort(A + 1, A + N + 1, compare);
    for(int i = 1; i <= N; ++i){
        if(A[i].id == P){
           cout << A[i].score << ' ' << i;
        }
    }
    return 0;
}