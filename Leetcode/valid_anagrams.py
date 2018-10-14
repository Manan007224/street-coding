class Solution:
    def isAnagram(self, s, t):
    	tp1 = ''.join(sorted(s))
    	tp2 = ''.join(sorted(t))
    	return tp1 == tp2


sln = Solution()
s = "anagram"
t = "nagaram"
print(sln.isAnagram(s,t))    	
