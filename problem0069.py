print('start')
x = 1
l = 0
r = 22
m = r // 2
result = -1

if x == 0:
    print(0)
    exit()

if x >= 484:
    print(22)
    exit()

while l != m:
    if m * m == x:
        result = m
        break
    elif m * m < x:
        result = m
        if l == m:
            break
        l = m
    else:
        if m * m > x:
            r = m
    m = (r - l) // 2 + l
print(m)