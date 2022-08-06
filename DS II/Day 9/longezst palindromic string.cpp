class Solution(object):

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return None
        if len(s) == 1:
            return s

        P = [[False]*len(s) for i in range(len(s))]

        for i in range(len(s)):
            P[i][i]   = True

        for i in range(len(s)-1):
            P[i][i+1] = (s[i]==s[i+1])

        for s_len in range(3,len(s)+1):
            for i in range(len(s)+1-s_len):
                P[i][i+s_len-1] = P[i+1][i+s_len-2] and (s[i]==s[i+s_len-1])

        ip = 0
        jp = 0
        max_len = 1

        for i in range(len(s)):
            for j in range(len(s)):
                if P[i][j] and j+1-i > max_len:
                    max_len = j+1-i
                    ip = i
                    jp = j 
                    continue

        return s[ip:jp+1]