#include<stdio.h>

int len(char * s){
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; ++i) ++cnt;
    return cnt;
}

int min(int a, int b){
    if(a >= b) return b;
    return a;
}

int main(){
    char a[100], b[100]; 
    int cnt = 0, dap = 55, alen, blen;
    scanf("%s %s", a, b);
    alen = len(a); blen = len(b);
    for(int k =0; k <= blen - alen; ++k){
        cnt = 0;
        for(int i = 0 ;i < alen; ++i){
            if(a[i] != b[i + k]) ++cnt;
        }
        dap = min(dap, cnt);
    }
    printf("%d", dap);
    return 0;
}