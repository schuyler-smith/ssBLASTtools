CC:= gcc
CXX:= g++
CXXFLAGS:= -std=c++11 -g -Wall
CPPFLAGS= 
LDLIBS= -lboost_program_options -lz
LDFLAGS=

all: bin/fastq_derep bin/fasta_seq_names

bin:
	$(shell mkdir -p bin)

bin/fastq_derep: bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o bin/fastq_derep src/fastq_derep.cpp $(LDLIBS)

bin/fasta_seq_names: bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o bin/fasta_seq_names src/fasta_seq_names.cpp $(LDLIBS)

