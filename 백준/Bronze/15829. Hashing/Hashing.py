n = int(input())
s = input()
r = 31 
rp = 1 
dap = 0
for i in s:
    dap += (ord(i) - ord('a') + 1) * rp % 1234567891
    rp *= r

print(dap)