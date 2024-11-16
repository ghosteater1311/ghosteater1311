"""
Given a string "abcbabcc"
print out the longest substring without duplicate character
-> only lowercase english
-> if s = "" print out nothing
-> string length upto 10^6

Solution 1: Brute Force
2 For Loops
Time Complexity: O(N^2)
Space: O(1) (Constant)
-> Good but not really optimized

Solution 2: Sliding Window
"""
from collections import defaultdict

def longestSubStringNoDublicate(s: str) -> str:
    lastIndex = defaultdict(lambda : -1)
    l = 0
    ansSize = 0
    ansStartIdx = 0
    for r, ch in enumerate(s): 
        if lastIndex[ch] >= l:
            l = lastIndex[ch] + 1
        lastIndex[ch] = r    
        windowSize = r - l + 1
        if windowSize > ansSize:
            ansSize = windowSize
            ansStartIdx = l
    
    return s[ansStartIdx : ansStartIdx + ansSize]

print(longestSubStringNoDublicate("abcba"))
print(longestSubStringNoDublicate("aaa"))
print(longestSubStringNoDublicate(""))
print(longestSubStringNoDublicate("aabaa"))
