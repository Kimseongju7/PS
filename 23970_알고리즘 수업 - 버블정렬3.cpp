#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);

class CMP{
    private :
        bool cmp[505050]; 
        int cmpArr[505050];
        int cnt; //다른 것의 개수
    public :
        int N;
        CMP(int n = 0) : N(n) { cnt = 0; }
        ~CMP() { }
        void cmpInit(int * arr);
        int size() { return cnt; }
        void inputArr(int n, int i) { cmpArr[i] = n; }
        void update(int *ary, int i); //배열과 인덱스를 주고 같아졌으면 true로 바꾼 뒤 size 줄이기, 달라졌으면 그 반대
};

void CMP::update(int *ary, int i){
    if(ary[i] == cmpArr[i] && !cmp[i]){
        cmp[i] = true;
        --cnt;
    }
    else if(ary[i] != cmpArr[i] && cmp[i]){
        cmp[i] = false;
        ++cnt;
    }
}

void CMP::cmpInit(int *arr){
    for(int i = 1; i <= N; ++i){
        if(cmpArr[i] != arr[i]) cmp[i] = false, ++cnt;
        else cmp[i] = true;
    }
}

int N;
CMP cmp;

inline void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void bubble(int *arr, int N){
    for(int i = N; i >= 2; --i){
        for(int j = 1; j <= i - 1; ++j){
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cmp.update(arr, j + 1);
                cmp.update(arr, j);
                if(!cmp.size()){
                    cout << 1;
                    exit(0);
                }
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int *arr, num;
    cin >> N;
    arr = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    cmp.N = N;
    for(int i = 1; i <= N; ++i) {
        cin >> num;
        cmp.inputArr(num, i);
    }
    cmp.cmpInit(arr);
    if(!cmp.size()) {
        cout << 1 << endl;
        return 0;
    }
    bubble(arr, N);
    cout << 0 << endl;
    delete[] arr;
    return 0;
}