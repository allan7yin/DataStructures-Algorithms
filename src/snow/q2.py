def compute_f(exp, length):
    MOD = int(1e9 + 7)
    return (pow(length - 1, exp, MOD) - pow(-1, exp)) * pow(length, -1, MOD)

def getNumWays(source, target, exp):
    MOD = 10**9 + 7
    length = len(source)
    
    result = 0
    if source == target:
        result += (length - 1) * compute_f(exp - 1, length)
    count = kmp_search(target[1:] + target[:-1], source)
    result += count * compute_f(exp, length)
    return result % MOD

def kmp_search(text, pattern):
    count = 0
    z_values = compute_z(pattern)
    i, j = 0, 0
    while i < len(text):
        if pattern[j] != text[i]:
            j = z_values[j]
            if j < 0:
                i += 1
                j += 1
            continue
        i += 1
        j += 1
        if j == len(pattern):
            count += 1
            j = z_values[j]
    return count

def compute_z(s):
    z = [None for _ in range(len(s) + 1)]
    z[0] = -1
    i, j = 1, 0
    while i < len(s):
        if s[i] == s[j]:
            z[i] = z[j]
        else:
            z[i] = j
            while j >= 0 and s[i] != s[j]:
                j = z[j]
        i += 1
        j += 1
    z[i] = j
    return z