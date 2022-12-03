# ffp
___
![C++](https://camo.githubusercontent.com/c59efb57803dde7f352f4932a468a7f39fa2fb5f/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f632532422532422d31312f31342f31372f32302d626c75652e737667)
![License](https://camo.githubusercontent.com/890acbdcb87868b382af9a4b1fac507b9659d9bf/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)

[![Ubuntu CI Test](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/ubuntu.yml)
[![MacOS CI Test](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/macos.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/macos.yml)
[![Windows CI Test](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/windows.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/windows.yml)
[![Deploy static content to Pages](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/static.yml/badge.svg)](https://github.com/Mohamed-Nser-Said/ffp/actions/workflows/static.yml)

Very Fast, limited FASTA file processor


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

    // convert all the protein sequences in fasta file to 'ProteinsSequence' objects and put them in a vector container
    vector<ProteinsSequence> all_seq = FileIO::getProteinSequence(fasta_file);

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
