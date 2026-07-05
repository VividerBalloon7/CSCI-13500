#include <iostream>
#include <vector>
#include <string>

void removeCopies(std::vector<int>& data) {

    // If the vector is empty, there is nothing to remove.
    if (data.size() == 0) {
        return;
    }

    // writeIndex keeps track of where the next unique value
    // should be placed.
    int writeIndex = 1;

    // Start reading from the second element since the first
    // element is always unique.
    for (int readIndex = 1; readIndex < data.size(); readIndex++) {

        // If the current number is different from the previous
        // unique number, copy it into the next available spot.
        if (data[readIndex] != data[writeIndex - 1]) {
            data[writeIndex] = data[readIndex];
            writeIndex++;
        }
    }

    // Remove the extra duplicate values from the end
    // of the vector.
    data.resize(writeIndex);
}

void isAnagram(std::string officer_name, std::string spy_name) {

    // If the strings are different lengths,
    // they cannot be anagrams.
    if (officer_name.length() != spy_name.length()) {
        std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
        return;
    }

    // Create a vector with 26 spaces, one for each letter
    // of the alphabet. Initialize everything to 0.
    std::vector<int> letters(26, 0);

    // Count each letter in officer_name.
    // Subtract each letter in spy_name.
    for (int i = 0; i < officer_name.length(); i++) {
        letters[officer_name[i] - 'a']++;
        letters[spy_name[i] - 'a']--;
    }

    // If any count is not zero, then the strings
    // do not contain the same letters.
    for (int count : letters) {
        if (count != 0) {
            std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
            return;
        }
    }

    // If every count is zero, the strings are anagrams.
    std::cout << "No imposter detected!" << std::endl;
}

int main() {

    // Test vector
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    // Print original vector
    for (auto data : server) {
        std::cout << data << " ";
    }

    std::cout << std::endl;

    // Remove duplicate values
    removeCopies(server);

    // Print modified vector
    for (auto data : server) {
        std::cout << data << " ";
    }

    std::cout << std::endl;

    // Test anagram function
    isAnagram("syeda", "aysed");
    isAnagram("angelo", "annabeth");

    return 0;
}