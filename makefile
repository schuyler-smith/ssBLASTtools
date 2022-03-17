CC:= gcc
CXX:= g++
CXXFLAGS:= -std=c++11 -g -Wall
CPPFLAGS= 
LDLIBS= -lboost_program_options -lz
LDFLAGS= -I ./include
HDRS:= $(wildcard include/*) 
SRCS:=

all:	bin \
		bin/fastq_derep \
		bin/fasta_seq_names \
		bin/fasta_seq_reads \
		bin/fasta_merge

bin:
	$(shell mkdir -p $@)

bin/fastq_derep: src/fastq_derep.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $? $(HDRS) $(LDLIBS)

bin/fasta_seq_names: src/fasta_seq_names.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $? $(HDRS) $(LDLIBS)

bin/fasta_seq_reads: src/fasta_seq_reads.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $? $(HDRS) $(LDLIBS)

bin/fasta_merge: src/fasta_merge.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $? $(HDRS) $(LDLIBS)


# clean:

# install:
