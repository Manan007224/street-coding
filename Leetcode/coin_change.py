class Solution:
	def coinChange(self, coins, amount):

		if amount == 0:
			return 0
			
		coins = sorted(coins)
		dp = {}
		for c in coins:
			dp[c] = 1

		def recur(val, dp, nums):

			if val < 0:
				return -1
			if val == 0:
				return 0
			if val in dp:
				return dp[val]

			mx = -1
			for num in nums:
				if num <= val:
					v = recur(val-num, dp, nums)
					if v != -1:
						if mx == -1:
							mx = v+1
						else:
							mx = min(mx, v+1)							

			dp[val] = mx
			return dp[val]

		recur(amount, dp, coins)

		return dp[amount]

coins = [2147483647]
amount = 2
sln = Solution()
print(sln.coinChange(coins,amount))