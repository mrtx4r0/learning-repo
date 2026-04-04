#!/usr/bin/env python3

class baseClass():
	def a(self):
		print('this is baseClass\'s a')
		self.b()

	def b(self):
		print('this is baseClass\'s b, deriveClass.b overrides me')

class deriveClass(baseClass):
	def b(self):
		baseClass.b(self)  
		# ↑↑ baseのbをただ上書きするのではなく、baseの処理も実行したい(=拡張したい)場合、このように呼び出す
		print('this derives from baseClass, overrides base\'s b')


