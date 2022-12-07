#pragma FILEIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <Protein.h>



/** @brief utility Namespace
 *
 *  This namespace contains all the utility functions
 *  @attention This namespace is not intended to be used by the user
 */
namespace util{


    /** @brief Log enum class type
     */
    enum class LogType{
        Info, Error, Warning
    };



    /**
     * @brief log info to the console with a timestamp
     * @param mes message to be logged
     * @param t type of the log message (info, warning, error) LogType
     *
     */
    inline void log_info(std::string_view mes, LogType t);



}



/** @brief FileIO namespace
 *
 * This namespace contains all the functions related to file input and output
 */
namespace FileIO {


/**
 * @brief this function reads the fasta file and converts the protein sequences to 'ProteinsSequence' objects
 *
 * @param fasta_file_stream ifstream reference to the FASTA file
 *
 * @return the function return a vector of ProteinsSequence object std::vector<ProteinsSequence>
 */
std::vector<ProteinsSequence> getProteinSequence(std::ifstream& fasta_file_stream);


/**
 * @brief this function open the fasta file, if the file was not found, the program will terminate
 * @param file_path reference to the FASTA file string
 * @return std::ifstream object
 */
std::ifstream openFastaFile(const std::string& file_path);


/**
 * @brief this function writes the protein sequences to a csv file
 *
 * @param csv_file_path the path to the csv file
 * @param all_seq the vector of ProteinsSequence objects
 */
bool writeProteinsCSV(const std::string& csv_file_path, const std::vector<ProteinsSequence>& all_seq);


/**
 * @brief writeProteinsCSV writes the peptides sequences to a csv file
 *
 * @param csv_file_path the path to the csv file
 * @param all_seq the vector of ProteinsSequence objects
 */
bool writePeptidesCSV(const std::string& csv_file_path, const std::vector<ProteinsSequence>& all_seq);


/**
 * @brief writeMappingsCSV writes the Mapping peptides sequences with protein ID to a csv file
 *
 * @param csv_file_path the path to the csv file
 * @param all_seq the vector of ProteinsSequence objects
 */
bool writeMappingsCSV(const std::string& csv_file_path, const std::vector<ProteinsSequence>& all_seq);

}




