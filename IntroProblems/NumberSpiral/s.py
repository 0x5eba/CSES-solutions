def f(a, b): 
    M = max(a, b) 
    return(a-b)*(-1)**M+M*M-M+1
N = int(input())
for _ in range(N):
    a, b = input().split(' ')
    a = int(a)
    b = int(b)
    print(f(a, b))