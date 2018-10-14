class Solution:
	def groupAnagrams(self, strs):

		record = {}

		for str in strs:
			tp = ''.join(sorted(str))
			if tp in record:
				record[tp].append(str)
			else:
				record.setdefault(tp, [])
				record[tp].append(str)

		ans = []

		for k, v in record.items():
			ans.append(v)

		return ans	

sln = Solution()
input = ["eat", "tea", "tan", "ate", "nat", "bat"]
output = sln.groupAnagrams(input)
print(output)			