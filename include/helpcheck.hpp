#ifndef HELPCALL_SDS
#define HELPCALL_SDS

bool askforhelp(char * argv[])
{
    bool usage = (!strcmp(argv[1], "-h") | !strcmp(argv[1], "--help"));
    if(usage){
        std::cout << "\nUsage: fasta_seq_names <path_to_file.fasta>\n" << std::endl;
    }
    return usage;
}

#endif