// wordcount.cpp
// Lisa Jacklin && Jewel Maldonado
// 2023-11-30
// For CS 311 Fall 2023
// This Program does the following
//  - Prompts the user for a filename.
//  - Reads words from the file.
//  - Counts the occurrences of each word using a map.
//  - Handles various edge cases and errors.

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
  // first, the file needs to be read in.
  std::string filename;
  std::cout << "Enter the filename: ";
  std::getline(std::cin, filename);

  // next, the file needs to be opened, with an error message if not oppened.
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

    // check for end of file
    if (!infile) {
      if (infile.eof()) {
        break; // end of file
      }
    }
  }
  // let the user know that the file is finished reading
  std::cerr << "Finished reading file." << std::endl;

  // Check for file read errors
  if (!infile.eof()) {
    std::cerr << "Error reading file: " << filename << std::endl;
    return 1;
  }

  // now that errors have been checked for, we can display the word count
  std::cout << "Number of distinct words: " << wordCount.size() << "\n\n";

  // and displaying each set of unique words and their counts
  for (const auto &pair : wordCount) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}