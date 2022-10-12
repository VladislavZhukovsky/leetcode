
#2147483648 = 2^31

def reverse(x: int) -> int:
    if x == 0: 
            return 0
    sign = 1
    if x < 0:
        sign = -1
        x = abs(x)
    s = str(x)[::-1]
    s.lstrip('0')
    result = int(s) * sign
    if result > pow(2, 31) - 1 or result < -pow(2, 31):
        return 0
    return result

res = reverse(2_463_847_412)
print('Result: ' + str(res))