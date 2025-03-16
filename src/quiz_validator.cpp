#include "../include/quiz.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream> // For debugging output

using namespace std;

bool validateQuizFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File not found!" << endl;
        return false;
    }

    string line;
    vector<string> sections;

    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        // Debug: Print each line being read
        // cout << "Reading line: " << line << endl;

        // Check for the delimiter "----"
        if (line == "----") {
            // cout << "Found separator ----" << endl;

            // Debug: Print collected sections
            // cout << "Collected sections size: " << sections.size() << endl;
            // for (size_t i = 0; i < sections.size(); ++i) {
            //     cout << "Section[" << i << "]: " << sections[i] << endl;
            //  }

            // Validate the completed question block
            if (sections.size() != 8) { 
                cout << "Error: Incorrect number of sections!" << endl;
                return false;
            }

            // Validate question type
            if (sections[0] != "MC") { 
                cout << "Error: Invalid question type!" << endl;
                return false;
            }

            // Validate the number of options
            int numOptions;
            try {
                numOptions = stoi(sections[2]); 
            } catch (...) {
                cout << "Error: Invalid number of options format!" << endl;
                return false;
            }

            if (numOptions != 4) { 
                cout << "Error: Must have exactly 4 options!" << endl;
                return false;
            }

            // Validate correct answer index (should be at index 5)
            int correctAnswer;
            try {
                correctAnswer = stoi(sections[7]); // Corrected index
            } catch (...) {
                cout << "Error: Invalid answer index format!" << endl;
                return false;
            }

            if (correctAnswer < 1 || correctAnswer > 4) {
                cout << "Error: Correct answer index out of range!" << endl;
                return false;
            }

            sections.clear(); // Reset for the next question block
            continue;
        }

        sections.push_back(line);
    }

    // Ensure the last question block was properly closed with "----"
    if (!sections.empty()) {
        cout << "Error: Last question block not closed with ----!" << endl;
        return false;
    }

    // cout << "Quiz file is valid!" << endl;
    return true;
}
