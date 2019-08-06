input()
p = list(map(int, input().split()))
p.sort()

medio = p[len(p)//2]
min_ = 0

for elm in p:
    min_ += abs(elm-medio)

print(min_)
