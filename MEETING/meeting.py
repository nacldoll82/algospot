tcase = int(raw_input())
for i in range(tcase):
	raw_input()

	boy = sorted(map(int, raw_input().split()))
	girl = sorted(map(int, raw_input().split()))

	score = sum(abs(a-b) for a,b in zip(boy, girl));
	print score
