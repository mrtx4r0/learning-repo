# Top level Makefile

UNAME_OS := $(shell uname -s)

all: 
	@echo $(MAKE); echo $(SHELL)
	@echo $(UNAME_OS)
	-cd subdir4 # - をつけるとエラーが起きても止まらない
	cd subdir2 && pwd
# 	$(MAKE) -C subdir1
# 	$(MAKE) -C subdir2
# 	$(MAKE) -C subdir3

	@echo $$SHELL # $$をつけるとシェル変数として扱われる
	@echo $(PATH)

.PHONY: clean
clean:
	@echo "clean up success!"
