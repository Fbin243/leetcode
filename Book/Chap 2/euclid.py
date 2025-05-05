def gcd_euclid_iterative(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def gcd_euclid_recursive(a, b):
    if b == 0:
        return a
    return gcd_euclid_recursive(b, a % b)
