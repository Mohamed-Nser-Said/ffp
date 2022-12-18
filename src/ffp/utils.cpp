#include "ffp.h"
#include<iostream>
#include <vector>
#include <regex>
#include <chrono>
#include <string>
#include <string_view>
#include <format>
#include <tuple>

inline void FFP::util::log_info(std::string_view mes, LogType t) {

    std::cout<<
    std::format("{}[{}][{}]\t{}",
                std::string(120, '-'),
                t==LogType::Info ? "info": "warning",
                std::format("{:%H:%M}", std::chrono::system_clock::now()),
                mes)
                <<std::endl;

}



std::ifstream FFP::FileIO::openFastaFile(const std::string& file_path){
    auto file = std::ifstream (file_path);

    if(file.fail()) {
        std::cerr<<
        std::format(
                "Error: in file: '{}', in function: '{}' at line:{}\n\nCould not open the file '{}'\nPlease check your *.fasta file name or file location",
                __FILE__, __FUNCTION__, __LINE__, file_path)<<std::endl;

        exit(-1);

    }else if(file.good()) {
        util::log_info( std::format("opening file '{}'", file_path), FFP::util::LogType::Info);
        return file;
    }
    exit(1);
    }

bool FFP::FileIO::writeProteinsCSV(const std::string& filename, const std::vector<FFP::Types::Protein>& data){
    auto file = std::ofstream(filename);
    if(file.good()){


        file<<"PROTEIN_ID, PROTEIN_SEQUENCE, PROTEIN_IDENTIFIER"<<std::endl;
        for (const auto& seq: data) {
            file<<seq.PROTEIN_ID<<", "<<seq.PROTEIN_SEQUENCE<<", "<<seq.PROTEIN_IDENTIFIER<<std::endl;

        }

        file.close();
        util::log_info( std::format("Writing to file '{}' finished", filename), util::LogType::Info);

        return true;
    }else{
        std::cerr<<std::format("Error: in file '{}' : in function '{}'  at line {}\n\nCould not open the file '{}'\n{}",
                               __FILE__, __FUNCTION__, __LINE__, filename, std::string(120, '-'))<<std::endl;
        return false;

    }


}

bool FFP::FileIO::writePeptidesCSV(const std::string& filename, const std::vector<FFP::Types::Protein>& data){

    auto file = std::ofstream(filename);
    if(file.good()){

        file<<"PEPTIDE_ID, PEPTIDE_SEQUENCE"<<std::endl;
        for (const auto& seq: data) {
            for (const auto& peptide: seq.peptides) {
                file<<peptide.PEPTIDE_ID<<", "<<peptide.PEPTIDE_SEQUENCE<<std::endl;
            }

        }


        file.close();
        util::log_info( std::format("Writing to file '{}' finished", filename), util::LogType::Info);

        return true;
    }else{
        std::cerr<<std::format("Error: in file '{}' : in function '{}'  at line {}\n\nCould not open the file '{}'\n{}",
                               __FILE__, __FUNCTION__, __LINE__, filename, std::string(120, '-'))<<std::endl;
        return false;
    }


}

bool FFP::FileIO::writeMappingsCSV(const std::string& filename, const std::vector<FFP::Types::Protein>& data){

    auto file = std::ofstream(filename);
    if(file.good()){

        file<<"MAPPING_ID, PEPTIDE_ID, PROTEIN_ID, START_IDX, END_IDX"<<std::endl;
        int index=1;
        for (const auto& seq: data) {
            for (const auto& peptide: seq.peptides) {
                file<<index<<", "<<peptide.PEPTIDE_ID<<", "<<peptide.PROTEIN_ID<<", "
                    <<peptide.START_IDX<<", "<<peptide.END_IDX<<std::endl;
                ++index;
            }
        }

        file.close();
        util::log_info( std::format("Writing to file '{}' finished", filename), util::LogType::Info);

        return true;
    }else{
        std::cerr<<std::format("Error: in file '{}' : in function '{}'  at line {}\n\nCould not open the file '{}'\n{}",
                               __FILE__, __FUNCTION__, __LINE__, filename, std::string(120, '-'))<<std::endl;
        return false;
    }


}


