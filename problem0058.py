s = 'words '
n = len(s)
i = n - 1
while(s[i] == ' '):
    i = i - 1
i0 = i
while(s[i] != ' ' and i >= 0):
    i = i - 1

print(i0 - i)
