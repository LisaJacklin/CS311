// wordcount.cpp
// Lisa Jacklin && Jewel Maldonado
// 2023-11-30
// For CS 311 Fall 2023
// This Program does the following
//  - Prompts the user for a filename.
//  - Reads words from the file.
//  - Counts the occurrences of each word using a map.
//  - Handles various edge cases and errors.

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string word;
    while (infile >> word) {
        // Increment the word count
        wordCount[word]++;
    }

    // Check for file read errors
    if (!infile.eof()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return 1;
    }

    std::cout << "Number of distinct words: " << wordCount.size() << "\n\n";
    for (const auto &pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}