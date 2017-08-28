import bisect

Tcase = input()
for i in range(Tcase):
	n, a, b = map(int, raw_input().split())

	list = []
	cur = 1983
	med = 0

	for j in range(n):
		bisect.insort(list, cur)
		med += list[(len(list)-1)/2]
		cur = (cur*a + b)%20090711

	print(med % 20090711)
