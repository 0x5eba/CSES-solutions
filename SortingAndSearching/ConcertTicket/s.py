n, m = list(map(int, input().split()))
h = list(map(int, input().split()))
t = list(map(int, input().split()))
h.sort()
used = {}

for i in t:
    # print("element ", i)
    idx = 0
    for elm in h:
        if elm > i:
            if idx-1 not in used:
                break
            else: 
                idx = 0
            break
        if elm == i and idx not in used:
            idx += 1
            break
        idx += 1

    idx -= 1

    # print("found ", idx)
    # print(used)
    used[idx] = 1
    if idx == -1:
        print(-1)
    if idx not in used:
        print(h[idx])
    else:
        print(-1)
