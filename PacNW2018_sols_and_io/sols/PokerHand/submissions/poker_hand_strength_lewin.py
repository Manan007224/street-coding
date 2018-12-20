from collections import Counter
print max(Counter(map(lambda x: x[0], raw_input().split())).values())