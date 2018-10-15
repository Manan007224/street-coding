def max_array(nums):
	record = {}
	record1 = {}
	sum = 0
	k = 0
	largest = 0
	# An dict for maintaining indices of all the values in the original array
	for num in nums:
		record[num] = k
		k+=1

	# Start evaluating the sum
	for num in nums:
		sum+=num
		if sum in record1:
			idx = record1[sum]
			largest = max(largest, abs(record[num]-record[idx]))
		else:
			record1[sum] = num

	print(largest)


lst = [1,3,2]
max_array(lst)		
