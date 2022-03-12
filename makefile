APP:= fastq_derep
SRCS:= fastq_derep.cpp

CC:= gcc
CXX:= g++
CXXFLAGS:= -std=c++11 -g -Wall
CPPFLAGS= 
LDLIBS= -lboost_program_options -lz
LDFLAGS=

OBJS:= $(subst .cc,.o,$(SRCS))
RM:= rm -f
PREFIX:= /usr/local

all: $(APP)

$(APP): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(APP) $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend

# install:
# 	install -m 755 tool $(DESTDIR)$(PREFIX)/bin