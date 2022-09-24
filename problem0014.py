
import array


def longestCommonPrefix(strs: array):
    n = len(strs) // 2
    left = strs[:n]
    right = strs[n:]
    return longestCommonPrefix1(left, right)

def longestCommonPrefix1(left: array, right: array):
    m = len(left)
    n = len(right)
    pm = ''
    pn = ''

    if m == 1:
        pm = left[0]
    else:
        pm = longestCommonPrefix1(left[:m//2], left[m//2:])

    if n == 1:
        pn = right[0]
    else:
        pn = longestCommonPrefix1(right[:n//2], right[n//2:])
    
    return longestCommonPrefix2(pm, pn)

def longestCommonPrefix2(s1, s2):
    k = 0
    if len(s1) < len(s2):
        k = len(s1)
    else:
        k = len(s2)
    if k == 0:
        return ''
    for i in range(k):
        if s1[i] != s2[i]:
            return s1[:i]
    return s1[:i+1]

a = ["", ""]
print(longestCommonPrefix(a))