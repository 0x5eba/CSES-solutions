import bisect

input()
p = list(map(int, input().split()))

tower = [p[0]]

for i in range(1, len(p)):
    j = 0
    idx = bisect.bisect_right(tower, p[i])

    if idx >= len(tower):
        bisect.insort(tower, p[i])
    else:
        tower[idx] = p[i]

    # sostituisci = True
    # while p[i] > tower[j] or tower[j] == 1:
    #     j += 1
    #     if j >= len(tower):
    #         bisect.insort(tower, p[i])
    #         sostituisci = False
    #         break
    # if sostituisci:
    #     tower[j] = p[i]

print(len(tower))
