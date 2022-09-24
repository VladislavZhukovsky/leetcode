
def romanToInt(s: str) -> int:
    d = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    result = 0
    n = len(s)
    i = 0
    while i < n:
        c = s[i] 
        v = d[c] 
        if i < n - 1: 
            c2 = s[i + 1] 
            v2 = d[c2] 
            if v2 > v: 
                v = v2 - v 
                i = i + 1 
        result += v 
        i = i + 1

    return result

s = 'MCMXCIV'
print(romanToInt(s))