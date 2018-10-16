class Solution:
    def countSubstrings(self, s):
    	palindromes = 0
    	ll = len(s)
    	for k in range(ll):
    		left = k
    		right = k
    		i = 0
    		while(i<2):
    			while(left>=0 and right<=ll-1 and s[left]==s[right]):
	    			left=left-1
	    			right=right+1
	    			palindromes+=1
	    		right=k+1
	    		left=k
	    		i=i+1

    	return palindromes		

sln = Solution()
input = "maanakn"
output = sln.countSubstrings(input)
print(output)				