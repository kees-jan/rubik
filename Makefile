SUBDIRS=src test

include master-dir.mk

silent-doxygen:
	@doxygen > doxygen.log 2>&1
