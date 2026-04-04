#!/usr/bin/env python3

import unittest

class Sample(unittest.TestCase):
    def setup(self):
	self.target = 'foo'
 
    def test_upper(self):
	self.assertEqual(self.target.upper(), 'Foo')

