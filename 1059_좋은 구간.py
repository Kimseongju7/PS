L = int(input())
arr = list(map(int, input().split()))
n = int(input())
arr.insert(0, 0)
arr.sort()
if(n in arr) : 
    cnt = 0
else :
    for i in range(L) :
        if arr[i] < n < arr[i + 1] :
            cnt = (n - arr[i]) * (arr[i + 1] - n) - 1
            break
print(cnt)
