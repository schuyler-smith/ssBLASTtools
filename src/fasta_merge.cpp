/*
 *
 * Author:  Schuyler D. Smith
 * Function:  fasta_merge
 * Purpose: Merges fasta files so that there are not duplicate sequence IDs.
 * This is mostly useful, for example, if you want to combine unmerged reads
 * from a raw file with merged reads that kept the original ID. Or maybe multiple
 * candidate target fasta files and you want to remove redundancy.
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include "helpcheck.hpp"

std::vector<std::string> extract_keys(std::unordered_map<std::string, std::string> const& input_map) 
{
	std::vector<std::string> values;
	for (auto const& element : input_map) 
	{
  		values.push_back(element.first);
  	}
  return values;
}

std::vector<std::string> extract_values(std::unordered_map<std::string, std::string> const& input_map) 
{
	std::vector<std::string> values;
	for (auto const& element : input_map) 
	{
		values.push_back(element.second);
	}
	return values;
}

int main(int argc, char *argv[])
{
	std::string		line;
	std::string		fasta_line;
	std::string 	read_ID;
	std::string		seq;
	std::unordered_map<std::string, std::string> reads;
    std::vector<std::string> read_IDs; 
    std::vector<std::string> read_seqs;

    int eval = EXIT_SUCCESS;
    try{
        if(!askforhelp(argc, argv, "./fasta_merge [input.fasta] ..."))
        {
            for(int i=1;i < argc;i++){
                std::ifstream 	fasta_file(argv[i]);
                while(std::getline(fasta_file, line))
                {
                    std::stringstream   line_(line);
                        std::getline(line_, fasta_line, '\t');
                        if(fasta_line[0] == '>')
                        {	  
                            if(read_ID.compare("") != 0){ reads[read_ID] = seq; }
                            read_ID = fasta_line;
                            seq = "";
                        } else {
                            seq = seq + fasta_line;	    			
                        }
                }
                reads[read_ID] = seq;
            }
            read_IDs = extract_keys(reads);	
            read_seqs = extract_values(reads);

            size_t n_reads = read_IDs.size();
            for(size_t i=0; i < n_reads; ++i){
                std::cout << read_IDs[i] << "\n" << read_seqs[i] << "\n" ;
            }
        }
    } catch(std::exception const &err) {
         /* update eval on throwed exceptions */
         eval = EXIT_FAILURE;
         std::cerr << "error: " << err.what() << std::endl;
    }
    return eval;
}