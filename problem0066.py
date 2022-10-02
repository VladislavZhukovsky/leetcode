
digits = [9,9]
n = len(digits)
digits[n - 1] = digits[n - 1] + 1
for i in range(1, n):
    if digits[n - i] > 9:
        digits[n - i] = 0
        digits[n - i - 1] = digits[n - i - 1] + 1
    else:
        break
if (digits[0] > 9):
    digits[0] = 0
    digits = [1] + digits
print(digits)