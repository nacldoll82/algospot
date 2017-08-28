import bisect
import math

lg26 = math.log10(26)

def get_value(str):
	num_cnt = 0 
	for ch in str:
		if ch.isdigit():
			num_cnt += 1

	val = (len(str)-num_cnt)*lg26 + num_cnt

	return val 

def get_maxstr(dic):
	max_val = 0.0 
	for str in dic:
		val = get_value(str)
		if(val > max_val):
			max_val = val 
			max_str = str 

	return max_str


tcase = int(raw_input())
for i in range(tcase):
	dic_size = int(raw_input())
	dic = []
	for j in range(dic_size):
		bisect.insort(dic, raw_input())
	print get_maxstr(dic)
