n, x = list(map(int, input().split()))
p = list(map(int, input().split()))
p.sort()
# print(p)

a = 0
b = len(p)-1
c = 0
while a <= b:
    calc = p[b] + p[a]
    if calc <= x:
        a += 1
        b -= 1
    else:  # calc > x
        b -= 1
    c += 1
print(c)
