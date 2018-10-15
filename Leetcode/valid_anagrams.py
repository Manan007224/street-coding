class Solution:
    def isAnagram(self, s, t):
    	
    	anagram1 = {}
    	anagram2 = {}

    	for str in s:
    		if str in anagram1:
    			anagram1[str].append(str)
    		else:
    			anagram1.setdefault(str, [])
    			anagram1[str].append(str)

    	for str in t:
    		if str in anagram2:
    			anagram2[str].append(str)
    		else:
    			anagram2.setdefault(str, [])
    			anagram2[str].append(str)

    	for k, v in anagram1.items():
    		if k not in anagram2:
    			return False
    		else:
    			if anagram1[k] != anagram2[k]:
    				return False

    	return True				



sln = Solution()
s = "anagram"
t = "nagaramm"
print(sln.isAnagram(s,t))  	
