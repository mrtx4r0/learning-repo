#!/usr/bin/env python3

def FOR(iterator):
	try:
		while True:
			return next(iterator)
	except StopIteration:
		return "END"

list = ['tokyo', 'osaka', 'nagoya']

# while True:
# 	s = FOR(list)
# 	if s == "END":
# 		break
# 	print(s)
it = iter(list)
while True:
	ret = FOR(it)
	if ret == "END":
		break
	print(ret)
