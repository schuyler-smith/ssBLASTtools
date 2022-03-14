/*
 *
 *	Author: Schuyler D. Smith
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <boost/program_options.hpp>
#include "helpcheck.hpp"

namespace po = boost::program_options;

int main(int argc, char * argv[])
{
    int eval = EXIT_SUCCESS;
    std::string     input_fasta_file;
    std::string 	seq_ID;
	std::string		not_seq_ID;
	std::string		line;

    try{
        if(!askforhelp(argv))
        {
            for(int i=1;i < argc;i++){
                input_fasta_file = argv[i];
                std::ifstream fasta_file(input_fasta_file);
                while(std::getline(fasta_file, line))
                {
                    std::stringstream   line_(line);
                    std::getline(line_, seq_ID, '\t');
                    line_ >> not_seq_ID;
                    if(seq_ID[0] == '>')
                    {
                        std::cout << seq_ID.erase(0, 1) << std::endl;
                    }
                }
            }
        }
    } catch(std::exception const &err) {
         /* update eval on throwed exceptions */
         eval = EXIT_FAILURE;
         std::cerr << "error: " << err.what() << std::endl;
    }
    return eval;
}
