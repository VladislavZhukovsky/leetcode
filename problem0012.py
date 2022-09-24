
def intToRoman(n):
 
    dct = {
        1: 'I',
        5: 'V',
        10: 'X',
        50: 'L',
        100: 'C',
        500: 'D',
        1000: 'M'
    }

    result = ''

    t = n // 1000
    result += t * dct[1000]
    n = n % 1000

    h = n // 100
    if h == 4 or h == 9: # 4 5 9
        result += dct[100]
        result += dct[h*100 + 100]
    else:
        if h > 4: # 1 2 3
            result += dct[500]
            h = h - 5
        result += h * dct[100]
    n = n % 100
    
    d = n // 10
    if d == 4 or d == 9: # 4 5 9
        result += dct[10]
        result += dct[d*10 + 10]
    else:
        if d > 4: # 1 2 3
            result += dct[50]
            d = d - 5
        result += d * dct[10]
    n = n % 10

    if n == 4 or n == 9: # 4 5 9
        result += dct[1]
        result += dct[n + 1]
    else:
        if n > 4: # 1 2 3
            result += dct[5]
            n = n - 5
        result += n * dct[1]

    return result

def intToRomanMethod(n):
    result = ''

    t = n // 1000
    result += t * getLetter(1000)
    n = n % 1000

    h = n // 100
    if h == 4 or h == 9: # 4 5 9
        result += getLetter(100)
        result += getLetter(h*100 + 100)
    else:
        if h > 4: # 1 2 3
            result += getLetter(500)
            h = h - 5
        result += h * getLetter(100)
    n = n % 100
    
    d = n // 10
    if d == 4 or d == 9: # 4 5 9
        result += getLetter(10)
        result += getLetter(d*10 + 10)
    else:
        if d > 4: # 1 2 3
            result += getLetter(50)
            d = d - 5
        result += d * getLetter(10)
    n = n % 10

    if n == 4 or n == 9: # 4 5 9
        result += getLetter(1)
        result += getLetter(n + 1)
    else:
        if n > 4: # 1 2 3
            result += getLetter(5)
            n = n - 5
        result += n * getLetter(1)

    return result

def getLetter(n):
    if n == 0:
        return ''
    elif n == 1:
        return 'I'
    elif n == 5:
        return 'V'
    elif n == 10:
        return 'X'
    elif n == 50:
        return 'L'
    elif n == 100:
        return 'C'
    elif n == 500:
        return 'D'
    elif n == 1000:
        return 'M'
    
    
print(intToRomanMethod(444))