#include "fileio.h"
#include<iostream>
#include <vector>
#include <regex>

inline void clean(string& str){
    for(auto &s: str ){
        if(s==','){
            s='-';
        }
    }
}


vector<ProteinsSequence> FileIO::getProteinSequence(ifstream& fasta_file_stream){
        vector<ProteinsSequence> vectorSeq;
        vector<string> PROTEIN_SEQUENCE;
        vector<string> PROTEIN_IDENTIFIER;

        string seq_string_buffer;
        string line, line_string_buffer;

        // parsing the fasta file and spilt the input by the identifier '>'
        while(getline(fasta_file_stream, line_string_buffer)) {
            if (line_string_buffer[0] == ';') continue;

            else if (line_string_buffer[0] == '>') {
                clean(line_string_buffer);

                PROTEIN_IDENTIFIER.push_back(line_string_buffer.substr(1));

                if (!seq_string_buffer.empty()) {
                    PROTEIN_SEQUENCE.push_back(seq_string_buffer);
                    seq_string_buffer.clear();
                }
            } else seq_string_buffer+=line_string_buffer;

        }
        PROTEIN_SEQUENCE.push_back(seq_string_buffer);


        // creating the protein objects vector
        for (int i = 0; i <PROTEIN_IDENTIFIER.size() ; ++i) {
            vectorSeq.emplace_back(i+1, PROTEIN_IDENTIFIER[i], PROTEIN_SEQUENCE[i]);

        }

        return vectorSeq;

    }

ifstream FileIO::openFastaFile(const string& file_path){
    auto file = ifstream (file_path);

//        checking the Condition state of the file
    if(file.fail()) {

        cerr<<"Error: "<<__FILE__<<": in function "<<__FUNCTION__ <<" at line "<<__LINE__<<endl
            <<"The fasta file '"<<file_path<<"' Was not Found!, Please check your *.fasta file name or file location"<<endl;

        exit(-1);

    }else if(file.good()) {
//            return the ifstream if the file opened correctly
        return file;
    }
    else {
        cerr<<"Error: "<<__FILE__<<": in function "<<__FUNCTION__ <<" at line "<<__LINE__<<endl;
        exit(-1);
    }}

bool FileIO::writeProteinsCSV(const string& filename, const vector<ProteinsSequence>& data){
    auto file = ofstream(filename);
    if(file.good()){
        cout<<"started -- writing "<<filename<<endl;

        file<<"PROTEIN_ID, PROTEIN_SEQUENCE, PROTEIN_IDENTIFIER"<<endl;
        for (const auto& seq: data) {
            file<<seq.PROTEIN_ID<<", "<<seq.PROTEIN_SEQUENCE<<", "<<seq.PROTEIN_IDENTIFIER<<endl;

        }

        file.close();
        cout<<"Done"<<endl;

        return true;
    }else{
        cerr<<"Error: "<<__FILE__<<": in function "<<__FUNCTION__ <<" at line "<<__LINE__<<endl;

        exit(-1);
    }


}

bool FileIO::writePeptidesCSV(const string& filename, const vector<ProteinsSequence>& data){
    auto file = ofstream(filename);
    if(file.good()){
        cout<<"started -- writing "<<filename<<endl;

        file<<"PEPTIDE_ID, PEPTIDE_SEQUENCE"<<endl;
        int index=0;
        for (const auto& seq: data) {
            for (const auto& peptide: seq.peptides) {
                file<<++index<<", "<<peptide.PEPTIDE_SEQUENCE<<endl;
            }

        }


        file.close();
        cout<<"Done !"<<endl;

        return true;
    }else{
        cerr<<"Error: "<<__FILE__<<": in function "<<__FUNCTION__ <<" at line "<<__LINE__<<endl;

        exit(-1);
    }


}

bool FileIO::writeMappingsCSV(const string& filename, const vector<ProteinsSequence>& data){
    auto file = ofstream(filename);
    if(file.good()){
        cout<<"started -- writing "<<filename<<endl;

        file<<"MAPPING_ID, PEPTIDE_ID, PROTEIN_ID, START_IDX, END_IDX"<<endl;
        int index=1;
        for (const auto& seq: data) {
            for (const auto& peptide: seq.peptides) {
                file<<index<<", "<<index<<", "<<peptide.PROTEIN_ID<<", "
                    <<peptide.START_IDX<<", "<<peptide.END_IDX<<endl;
                ++index;
            }
        }


        file.close();
        cout<<"Done !"<<endl;

        return true;
    }else{
        cerr<<"Error: "<<__FILE__<<": in function "<<__FUNCTION__ <<" at line "<<__LINE__<<endl;

        exit(-1);
    }


}




