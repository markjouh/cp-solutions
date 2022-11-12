t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
 
    # Minimum index for element with value at least [i]
    suf = []
    for i in range(n * 2 + 1):
        suf.append(1e6)
    for i in range(n):
        suf[b[i]] = min(suf[b[i]], i)
    for i in reversed(range(n * 2)):
        suf[i] = min(suf[i], suf[i + 1]);
 
    ans = 1e6
    for i in range(n):
        ans = min(ans, i + suf[a[i]])
 
    print(ans)