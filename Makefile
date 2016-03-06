all :
	cd lib/urg_library-1.2.0/ && $(MAKE)
	cd src/ && $(MAKE)

clean :
	cd lib/urg_library-1.2.0/ && $(MAKE) clean
	cd src/ && $(MAKE) clean

.PHONY : all clean
