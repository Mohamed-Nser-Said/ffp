#pragma FILEIO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <Protein.h>


namespace util{
    enum class LogType{
        Info, Error, Warning
    };

    inline void log_info(std::string_view mes, LogType t);


}




namespace FileIO {
/**
 * @brief FileIO handles the input and output files format including CSV FASTA files.
 *
 */


std::vector<ProteinsSequence> getProteinSequence(std::ifstream& fasta_file_stream);

std::ifstream openFastaFile(const std::string& file_path);

bool writeProteinsCSV(const std::string& filename, const std::vector<ProteinsSequence>& data);

bool writePeptidesCSV(const std::string& filename, const std::vector<ProteinsSequence>& data);

bool writeMappingsCSV(const std::string& filename, const std::vector<ProteinsSequence>& data);

}




