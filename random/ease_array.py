def ease_array(nums):
	ll = len(nums)

	for k in range(ll-1):
		if nums[k+1]!=0 and nums[k]==nums[k+1]:
			nums[k]=nums[k]*2
			nums[k+1]=0

	i,j = 0, 0
	for k in range(ll):
		if nums[k]==0:
			j+=1
		else:
			nums[i]=nums[j]
			j+=1 
			i+=1
		
	while(i<ll):
		nums[i]=0
		i+=1			

	return nums


lst = [0,2,2,2,0,6,6,0,0,8]
print(ease_array(lst))				