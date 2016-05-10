class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        map = {}
        ret = bgn = 0
        for i in range(len(s)):
            if s[i] in map:
                ret = max(ret, i - bgn)
                bgn = max(bgn, map[s[i]] + 1)
            map[s[i]] = i
        return max(ret, len(s) - bgn)