class Solution:
    def maximumGap(self, nums):

    	if len(nums) == 0:
    		return 0

    	buckets = [None]*max(nums)
    	for num in nums:
    		buckets[num-1] = num

    	buckets = [k for k in buckets if k != None]

    	ll = len(buckets)		
    	diff = 0	
    	for k in range(1,ll):
    		diff = max(diff, buckets[k]-buckets[k-1])

    	return diff	
	

sln = Solution()
input = [3,6,9,1]
print(sln.maximumGap(input))    	