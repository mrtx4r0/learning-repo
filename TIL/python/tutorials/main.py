#!/usr/bin/env python3
import os
print(f'os.getcwd():{os.getcwd()}')

from class_sample import User

user = User("tetsutaro", 31, "Tokyo, Japan")

print(user.name)

print(user.age)

user.increment_age()
print(user.age)

user.start_name()


import fib
