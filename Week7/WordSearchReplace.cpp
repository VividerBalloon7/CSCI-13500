#include <fstream>
#include <iostream>
#include <string>

int main() {

    std::ifstream fileReader("./Week7/story.txt");
    std::ofstream fileWriter("output.txt");

    if (!fileReader.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 0;
    }

    int replaceCount = 0;

    //word to search for
    std::string word;
    std::cout << "Enter a word to search for: ";
    std::cin >> word;

    //word to replace it worth
    std::string replacementWord;
    std::cout << "Replacement word: ";
    std::cin >> replacementWord;


    std::string the_line = {};
    //find all instances of the word per line and replacing them with replacement word
    while (getline(fileReader, the_line)) {
      int position = the_line.find(word);
        if (position != -1) {
            the_line.replace(position, word.length(), replacementWord);
            replaceCount++;
        }


        fileWriter << the_line << std::endl;
    }

    //replacement count
    std::cout << "Replacements made: " << replaceCount << std::endl;

    //closing both files
    fileReader.close();
    fileWriter.close();




}
