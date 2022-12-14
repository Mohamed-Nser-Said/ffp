@mainpage
@tableofcontents
# ffp
___
[![Ubuntu CI Test](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/ubuntu.yml)
[![MacOS CI Test](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/macos.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/macos.yml)
[![Windows CI Test](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/windows.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/windows.yml)
[![Deploy static content to Pages](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/static.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/static.yml)

Very Fast, limited FASTA file processor

### This Project Requires:
- C++20 or higher
- CMake 3.16 or higher

#### Building
```console
$ git clone https://github.com/Mohamed-Nser-Said/ffp.git ffp
$ cd ffp && mkdir build && cd build
$ cmake .. && cmake --build .
```

### This Project features
- Unit testing using [Catch2](https://github.com/catchorg/Catch2), installed by CMake's FetchContent.
- Libraries, executable and test code separated in distinct folders.
- Use of modern CMake for building and compiling.



## Usage samples

#### Basic usage
```c++
#include "fileio.h"


int main(){
    
    string FASTA_FILE_PATH="PATH/input.fasta" ;
    
    string PROTEIN_CSV_FILENAME = "/proteins.csv" ;
    string PEPTIDE_CSV_FILENAME = "/data/peptides.csv";
    string MAPPINGS_CSV_FILENAME = "/data/mappings.csv";

    // open the fasta file, if the file was not found, the program will terminate
    ifstream fasta_file = FileIO::openFastaFile(FASTA_FILE_PATH);

    // convert all the protein sequences in fasta file to 'Protein' objects and put them in a vector container
    vector<Protein> all_seq = FileIO::getProteinSequence(fasta_file);

    // close the original *.fasta file
    fasta_file.close();

    


    // creating protein csv file
    FileIO::writeProteinsCSV(PROTEIN_CSV_FILENAME, all_seq);

    // creating peptides csv file
    FileIO::writePeptidesCSV(PEPTIDE_CSV_FILENAME, all_seq);

    // creating mapping csv file
    FileIO::writeMappingsCSV(MAPPINGS_CSV_FILENAME, all_seq);




    return 0;
}
```
