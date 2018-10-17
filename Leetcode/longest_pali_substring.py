class Solution:
    def longestPalindrome(self, s):
    	ll = len(s)
    	if s == "":
    		return ""

    	ans = 0
    	anss = s[0]
    	for k in range(ll):
    		left = k
    		right = k
            i = 0
            while(i<2):
                if left>=0 and right<=ll-1 and s[left] == s[right]:
                    while(left-1>=0 and right+1<=ll-1 and s[left-1]==s[right+1]):
                       left=left-1
                       right=right+1
                    if ans<right-left:
                       ans = right-left
                       anss = s[left:right+1]
                left = k
                right = k+1
                i+=1

    	return anss

sln = Solution()
input="babad"
print(sln.longestPalindrome(input))    			
