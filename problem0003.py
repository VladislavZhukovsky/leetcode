
def lengthOfLongestSubstring(s: str) -> int:
    d = {}
    res = 0
    j = 0
    i = 0
    length = len(s)
    while j < len(s):
        c = s[j]
        if c in d:
            i = max(d[c] + 1, i)
        d[c] = j
        res = max(res, j - i + 1)
        j = j + 1
    return res

def lengthOfLongestSubstringSlidingWindow(s: str) -> int:
    chars = [0] * 128

    left = right = 0

    res = 0
    while right < len(s):
        r = s[right]
        chars[ord(r)] += 1

        while chars[ord(r)] > 1:
            l = s[left]
            chars[ord(l)] -= 1
            left += 1

        res = max(res, right - left + 1)

        right += 1
    return res

def lengthOfLongestSubstringSlidingWindowOptimized(s: str) -> int:
    n = len(s)
    ans = 0
    # mp stores the current index of a character
    mp = {}

    i = 0
    # try to extend the range [i, j]
    for j in range(n):
        if s[j] in mp:
            i = max(mp[s[j]], i)

        ans = max(ans, j - i + 1)
        mp[s[j]] = j + 1

    return ans

s = "abcabcacedeabcd"
print(lengthOfLongestSubstring(s))