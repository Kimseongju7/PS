import sys

input = sys.stdin.readline

N = int(input().rstrip())
e = ""

for i in range(2 * N - 1):
    c = input().rstrip()
    e += c
e = e.replace("/", "//")

sys.stdout.write(str(eval(e)))