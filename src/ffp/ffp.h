#pragma once //FFP

#include <vector>
#include <iostream>
#include <fstream>

/****************************************************************************************
 * @brief FFP namespace contains all the classes and methods used in the project
 ****************************************************************************************/
namespace FFP{
    /**************************************************************************
     * @brief FFP::Types namespace contains all the types used in the project
     **************************************************************************/
namespace Types {
    static uint32_t PROTEIN_ID, PEPTIDE_ID;

    struct Peptide{
        const uint32_t PROTEIN_ID, PEPTIDE_ID;
        const std::string PEPTIDE_SEQUENCE;
        const uint32_t START_IDX, END_IDX;
    };

/** ****************************************************************************************
* @brief The ProteinsSequence class is used to store the information of each protein sequence in the Fasta file
*
*
* Construct a new Proteins Sequence object
*
* @param PROTEIN_ID the id of the protein
* @param PROTEIN_IDENTIFIER the identifier of the protein
* @param PROTEIN_SEQUENCE the sequence of the protein
* @note The constructor will automatically extract all the peptides from the protein sequence
 ****************************************************************************************/
    class Protein{

    public:
        const uint32_t PROTEIN_ID{};
        const std::string PROTEIN_IDENTIFIER;
        const std::string PROTEIN_SEQUENCE;

        std::vector<Peptide> peptides;
        uint32_t peptides_count{};

        Protein(std::string PROTEIN_IDENTIFIER, std::string PROTEIN_SEQUENCE);
        void splitPeptides();
    };


}
/****************************************************************************************
 * @brief utility Namespace
 *
 *  This namespace contains all the utility functions
 *  @attention This namespace is not intended to be used by the user
 ****************************************************************************************/
namespace util{


    /****************************************************************************************
     * @brief Log enum class type
     *****************************************************************************************/
    enum class LogType{
        Info, Error, Warning
    };



    /****************************************************************************************
     * @brief log info to the console with a timestamp
     * @param mes message to be logged
     * @param t type of the log message (info, warning, error) LogType
     *
     ****************************************************************************************/
    inline void log_info(std::string_view mes, LogType t);



}


/****************************************************************************************
 * @brief this function reads the fasta file and converts the protein sequences to 'ProteinsSequence' objects
 *
 * @param fasta_file_stream ifstream reference to the FASTA file
 *
 * @return the function return a vector of ProteinsSequence object std::vector<ProteinsSequence>
 ****************************************************************************************/
std::vector<Types::Protein> getProteinSequence(std::ifstream& fasta_file_stream);



/****************************************************************************************
 * @brief FileIO namespace
 *
 * This namespace contains all the functions related to file input and output
 ****************************************************************************************/
namespace FileIO {


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
bool writeProteinsCSV(const std::string& csv_file_path, const std::vector<Types::Protein>& all_seq);


/**
 * @brief writeProteinsCSV writes the peptides sequences to a csv file
 *
 * @param csv_file_path the path to the csv file
 * @param all_seq the vector of ProteinsSequence objects
 */
bool writePeptidesCSV(const std::string& csv_file_path, const std::vector<Types::Protein>& all_seq);


/**
 * @brief writeMappingsCSV writes the Mapping peptides sequences with protein ID to a csv file
 *
 * @param csv_file_path the path to the csv file
 * @param all_seq the vector of ProteinsSequence objects
 */
bool writeMappingsCSV(const std::string& csv_file_path, const std::vector<Types::Protein>& all_seq);

}


}

