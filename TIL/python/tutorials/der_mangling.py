#!/usr/bin/env python3

class Mapping():
	def __init__(self, iterable):
		self.items_list = []
		self.__update(iterable)  # __updateにコピーした自身のupdate()をコール
	
	def update(self, iterable):
		for item in iterable:
			self.items_list.append(item)
    
	# __updateに自身のupdate()をコピー。
	# これにより子クラスでupdateがオーバーライドされてもMappingの__init__は影響を受けない
	__update = update 

class MappingSubClass(Mapping):
	def update(self, keys, values):
		for item in zip(keys, values):
			self.items_list.append(item)

 
