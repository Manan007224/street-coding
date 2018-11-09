# Code for the classes interval partioning algorithm

import heapq

def schedule(classes):

	finish = {} 
	count = 0
	h = []
	classrooms = {}

	# sort the classes according to their start time
	classes.sort()

	# insert the first class into the heap
	finish(0) = classes[0][1]
	heapq.heappush(h,classes[0][1])
	classrooms.setdefault(count,[])

	for k in range(1,len(classes)):
		cmp = h[0]
		# if class k is compatible with some clasroom
		if cmp <= classes[k][0]:
			classrooms[finish(cmp)].append(classes[k])
			finish(cmp) = classes[k][1]
			heapq.heappop(h)
			heapq.heappush(h,classes[k][1])

		# else allocate a new classroom
		else:
			count+=1
			classrooms.setdefault(count,[])
			finish(count)=classes[k][1]
			classrooms[count].append(classes[k])
			heapq.heappush(h,classes[k][1])

	return classrooms


classes = [()]
classrooms = schedule(classes)