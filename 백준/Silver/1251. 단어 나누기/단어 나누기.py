word = list(input())


result = []

for i in range(1, len(word) - 1):
    for j in range(i+1, len(word)):
        first = word[:i]
        sec = word[i:j]
        third = word[j:]

        first.reverse()
        sec.reverse()
        third.reverse()

        result.append(''.join(first + sec + third))

print(sorted(result)[0])