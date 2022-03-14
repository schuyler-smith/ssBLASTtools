#ifndef GET_FA_LINE
#define GET_FA_LINE

#include <iostream>
#include <fstream>
#include <string>
#include <regex>


void get_fa_line(std::string input_fasta_file, bool id = true){
    std::string     line;
    std::string 	fasta_line;
    std::ifstream   fasta_file(input_fasta_file);

    while(std::getline(fasta_file, line))
    {
        std::stringstream line_(line);
        std::getline(line_, fasta_line, '\t');
        if(fasta_line[0] == '>' && id)
        {
            std::cout << fasta_line.erase(0, 1) << std::endl;
        }
        if(fasta_line[0] != '>' && !id)
        {
            std::cout << fasta_line << std::endl;
        }
    }
}

#endif