#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Define the characters to use
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    // Define the length of strings to generate
    int N = 3;
    
    std::cout << "String List Generator" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Characters: " << characters << std::endl;
    std::cout << "Length: " << N << std::endl;
    
    // Calculate total number of strings
    long long totalStrings = 1;
    for (int i = 0; i < N; ++i) {
        totalStrings *= characters.length();
    }
    
    std::cout << "Total strings to generate: " << totalStrings << std::endl;
    
    // Open output file
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output.txt for writing" << std::endl;
        return 1;
    }
    
    std::cout << "Starting generation..." << std::endl;
    
    // Generate all strings using nested loops
    long long count = 0;
    
    for (int i = 0; i < characters.length(); ++i) {
        for (int j = 0; j < characters.length(); ++j) {
            for (int k = 0; k < characters.length(); ++k) {
                std::string result;
                result += characters[i];
                result += characters[j];
                result += characters[k];
                
                outputFile << result << std::endl;
                count++;
                
                if (count % 10000 == 0) {
                    std::cout << "Generated " << count << " strings..." << std::endl;
                }
            }
        }
    }
    
    outputFile.close();
    
    std::cout << "Generation complete!" << std::endl;
    std::cout << "Total generated: " << count << " strings" << std::endl;
    std::cout << "Check output.txt for the results." << std::endl;
    
    return 0;
}
