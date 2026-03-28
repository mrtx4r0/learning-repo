#!/usr/bin/env python3

def scope_test():
	def do_global():
		global spam
		spam = 'this is global'

	do_global()

scope_test()
print("In global scope:", spam)

