#include<iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr);

int main(){
    FASTIO
    int icnt = 1, dcnt = 1, n, num, pnum, imax = 1, dmax = 1;
    cin >> n >> pnum;
    for(int i = 1; i < n; ++i){
        cin >> num;
        if(pnum < num) {
            ++icnt;
            dmax = dcnt > dmax ? dcnt : dmax;
            dcnt = 1;
        }
        if(pnum > num){
            ++dcnt;
            imax = icnt > imax ? icnt : imax;
            icnt = 1;
        }
        if(pnum == num) {
            ++icnt;
            ++dcnt;
            imax = icnt > imax ? icnt : imax;
            dmax = dcnt > dmax ? dcnt : dmax;
        }
        pnum = num;
    }
    imax = icnt > imax ? icnt : imax;
    dmax = dcnt > dmax ? dcnt : dmax;
    cout << (imax > dmax ? imax : dmax) << endl;
    return 0;
}