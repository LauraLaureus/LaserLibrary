TARGET = distance

SRCDIR = ../lib/urg_library-1.2.0/src
URG_CPP_LIB = ../lib/urg_library-1.2.0/src/liburg_cpp.a

include ../lib/urg_library-1.2.0/build_rule.mk

CXXFLAGS = -O2 $(INCLUDES) -I../lib/urg_library-1.2.0/include/cpp
LDLIBS = -lm $(shell if test `echo $(OS) | grep Windows`; then echo "-lwsock32 -lsetupapi"; else if test `uname -s | grep Darwin`; then echo ""; else echo "-lrt"; fi; fi) -L$(SRCDIR)

#

all : $(TARGET)

clean :
	$(RM) *.o $(TARGET) *.exe

$(TARGET) : Connection_information.o $(URG_CPP_LIB)

$(URG_CPP_LIB) :
	cd $(@D)/ && $(MAKE) $(@F)
