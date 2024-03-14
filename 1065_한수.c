#include <stdio.h>

int main(){
    int N, res;
    char arr[10];
    scanf("%d", &N);
    if(N < 100) printf("%d\n", N);
    else{
        res = 99;
        for(int i = 100; i <= N; ++i){
            sprintf(arr, "%d", i);
            if((arr[1] - arr[0]) == (arr[2] - arr[1])) ++res;
        }
        printf("%d\n", res);
    }
}