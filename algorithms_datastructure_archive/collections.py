'''
    This is the Collections for Small Short Algorithms
'''

# Euclidean Algorithm
# Getting the Greatest Common Divisor of positive Integers a & b
def gcd(a: int, b: int):
    assert(a > 0 and b >= 0)
    if b == 0:
        return a
    if a < b:
        a, b = b, a
    return gcd(b, a % b)


if __name__ == '__main__':
    print(gcd(10, 2302))