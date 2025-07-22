#include<iostream>
#include<cstring>
#include<utility>
#include<deque>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; 
    string s;
    int A[51][51] = {};
    int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
    deque<pair<int, int> > dq;

    while(true){
        cin >> N;
        if(!N) break;
        cin >> s;
        dq.clear();
        memset(A, 0, sizeof(A));
        for(int i = 11; i <= 30; i++) A[25][i] = 1, dq.emplace_front(25, i);
        for(int i = 0; i < s.length(); i++){
            int k;
            if(s[i] == 'E') k = 0;
            else if(s[i] == 'W') k = 1;
            else if(s[i] == 'S') k = 2;
            else if(s[i] == 'N') k = 3;
            pair<int, int> tail = dq.back(); dq.pop_back();
            A[tail.first][tail.second] = 0;

            pair<int, int> head = dq.front();
            head.first += di[k]; head.second += dj[k];

            if(head.first < 1 || head.second < 1 || head.first > 50 || head.second > 50) {
                cout << "The worm ran off the board on move " << i + 1 << ".\n";
                break;
            }
            else if(A[head.first][head.second]){
                cout << "The worm ran into itself on move " << i + 1 << ".\n";
                break;
            }
            else if(i == s.length() - 1){
                cout << "The worm successfully made all " << i + 1 << " moves.\n";
                break;
            }

            A[head.first][head.second] = 1;
            dq.emplace_front(head.first, head.second);
        }
    }
    return 0;   
}