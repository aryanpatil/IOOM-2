/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/


#include <exception>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <map>

#include "exceptions.h"

int main() {
    std::map<std::string, int> word_count;
    std::string filepath;
    std::ifstream file;
    std::cout << "Enter path to file: ";
    std::cin >> filepath;
    // Check if filepath exists or not
    try {
        access(filepath.c_str(), R_OK);
        if (errno == ENOENT) {
            throw file_not_found(filepath);             // Throw file not found exception
        } else if (errno == EACCES) {
            throw access_denied_exception(filepath);    // Throw access denied exception
        }
    } catch(std::exception& e) {
        std::cout << "Something went wrong\n";
        std::cout << e.what();
    } catch(file_not_found& e) {
        std::cout << "Something went wrong\n";
        std::cout << e.what();
    } catch(access_denied_exception& e) {
        std::cout << "Something went wrong\n";
        std::cout << e.what();
    } catch(...) {
        std::cout << "Something terrible happened\n";
    }
    // Try to open file
    try {
        file.open(filepath);
    } catch(io_exception& e) {
        std::cout << "IO Exception: \n";
        std::cout << e.what();
    } catch(...) {
        std::cout << "Something really bad happened\n";
    }
    // Extract all the words
    std::string word;
    // Iterate over all words
    while(file >> word) {
        // Map words to word counts
        word_count[word] += 1;
    }
    // Print the result
    for (const auto& record : word_count) {
        std::cout << record.first << " : " << record.second << std::endl;
    }
}