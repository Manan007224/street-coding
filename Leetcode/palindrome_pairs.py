class Solution:
    def palindromePairs(self, words):

    	def is_valid(str):
    		ll = len(str)
    		for k in range(1,ll//2):
    			if str[k] != str[len-1-k]:
    				return False
    		return True
    
    				
