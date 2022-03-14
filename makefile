CC:= gcc
CXX:= g++
CXXFLAGS:= -std=c++11 -g -Wall
CPPFLAGS= 
LDLIBS= -lboost_program_options -lz
LDFLAGS=

all: bin/hello bin/fastq_derep

bin:
	$(shell mkdir -p bin)

bin/hello: bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o bin/hello src/hello.cpp $(LDLIBS)

bin/fastq_derep: bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o bin/fastq_derep src/fastq_derep.cpp $(LDLIBS)
