#include <string>
#include <iostream>
#include <boost/program_options.hpp>
namespace po = boost::program_options;


int main(int argc, char** argv) {
  std::string inFASTQ;
  std::string outfile;


  // declare options
  po::options_description cmd1("CMD 1 Arguments");
  cmd1.add_options()
    ("help,h", "Prints the usage and argument descriptions.\n")
    ("test,t", po::value<std::string>(&inFASTQ)->required(), "Test argument for cmd 1")
  ;

  // parse arguments
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, cmd1), vm);

  // check help call
  if (vm.count("help")) {  
    std::cout << "\nUsage: dedupe_fastq --in_file <path_to_file.fastq> --out_file <file_to_write.fast(q/a)> --fasta --n <int>.\n" << std::endl;
    std::cout << cmd1 << "\n";
    return 0;
  }
  // check arguments
  try {

    po::notify(vm);
      if (!vm.count("out_file")) {  
        outfile = "deduped_"+inFASTQ;
      }
  } catch (std::exception& e) {
    std::cout << "\nError: " << e.what() << std::endl << "\n";
    std::cout << cmd1 << std::endl;
    return 1;
  }

  // program logic
  std::cout << "Hello " << vm["in_file"].as<std::string>() << std::endl;
  std::cout << "Hello " << outfile << std::endl;


  return 0;
}

