
def totient(n):          # n - unsigned int
    result = 1
    p = 2  # prime numbers - 'iterator'
    while p**2 <= n:
        if(n % p == 0):    # * (p-1)
            result *= (p-1)
            n //= p
        while(n % p == 0):  # * p^(k-1)
            result *= p
            n //= p
        p += 1
    if n != 1:
        result *= (n-1)
    return result         # in O(sqrt(n))

def modpow(p, z, b, c, m):  # (p^z)^(b^c) mod m
    cp = 0
    while m % p == 0:
        cp += 1
        m //= p              # m = m' now
    t = totient(m)
    exponent = ((pow(b, c, t)*z) % t + t - (cp % t)) % t
    # exponent = z*(b^c)-cp mod t
    return pow(p, cp) * pow(p, exponent, m)

def solve(a, b, c, m):  # split and solve
    result = 1
    p = 2            # primes
    while p**2 <= a:
        z = 0
        while a % p == 0: # calculate z
            a //= p
            z += 1
        if z != 0:
            result *= modpow(p, z, b, c, m)
            result %= m
        p += 1
    if a != 1:      # Possible last prime
        result *= modpow(a, 1, b, c, m)
    return result % m

N = int(input())
while(N > 0):
    a, b, c = input().split(' ')
    a = int(a)
    b = int(b)
    c = int(c)
    print(solve(a, b, c, 1000000007))
    N -= 1
