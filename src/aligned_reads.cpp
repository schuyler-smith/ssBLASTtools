/*
 *
 *	Author: Schuyler D. Smith
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <zlib.h>
#include <unordered_map>
#include "helpcheck.hpp"



int main(
    std::string FASTQ_file_path,
    Rcpp::StringVector aligned_reads,
    const char * output_path,
    bool aligned = false
){
    std::unordered_map<std::string, int> aligned_map;
    std::size_t num_aligned = aligned_reads.length();
    for(size_t i=0; i < num_aligned; ++i){
        aligned_map[Rcpp::as<std::string>(aligned_reads(i))] = 0;
    }
    
    bool compressed = {false};
    std::string ext = FASTQ_file_path.substr(FASTQ_file_path.rfind('.'));
    if(strcmp(ext.c_str(), ".gz") == 0){ compressed = true; } 
    else if(strcmp(ext.c_str(), ".bz2") == 0) { // bzip2 FASTQ_file_path
        Rcpp::Rcout << "bz file-type encription not supported.";
    } 
    if((strcmp(ext.c_str(), ".fastq") == 0) | (strcmp(ext.c_str(), ".fq") == 0) | compressed) {
        search_BLAST(FASTQ_file_path, aligned_map, output_path, aligned, compressed);
    }
    return(0);
}