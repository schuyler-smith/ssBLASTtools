/*
 *
 * Author:  Schuyler D. Smith
 * Function:  fasta_seq_names
 * Purpose: Inputs fasta file(s) and returns just the read 
 * IDs without any sequence associated with them.
 *
 */

#include <iostream>
#include <string>
#include <regex>
#include "helpcheck.hpp"
#include "get_fa_line.hpp"

int main(int argc, char * argv[])
{
    int eval = EXIT_SUCCESS;
    try{
        if(!askforhelp(argc, argv, "./fasta_seq_names [input.fasta] ..."))
        {
            for(int i=1;i < argc;i++){
                get_fa_line(argv[i]);
            }
        }
    } catch(std::exception const &err) {
         /* update eval on throwed exceptions */
         eval = EXIT_FAILURE;
         std::cerr << "error: " << err.what() << std::endl;
    }
    return eval;
}
