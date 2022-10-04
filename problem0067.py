
a = '1101'
b = '1011'
length_a = len(a)
length_b = len(b)

if (length_a > length_b):
    b = '0' * (length_a - length_b) + b
    length_b = len(b)
if (length_b > length_a):
    a = '0' * (length_b - length_a) + a
    length_a = len(a)
c = ''
carry = False
for i in range(length_a - 1, -1, -1):
    av = a[i] == '1'
    bv = b[i] == '1'
    c1 = av ^ bv
    c2 = c1 ^ carry
    if carry and (av or bv):
        carry = True
    elif (not carry) and (av and bv):
        carry = True
    else:
        carry = False

    if c2:
        c = '1' + c
    else:
        c = '0' + c
if carry:
    c = '1' + c
print(c)