#include "../include/quiz.h"
#include <iostream>
#include <fstream>

std::vector<Question> loadQuestionsFromFile(const std::string& filename) {
    std::vector<Question> questions;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return questions;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "MC") {  // Only supports multiple-choice for now
            std::string questionText;
            std::getline(file, questionText);

            int optionCount;
            file >> optionCount;
            file.ignore();  // Ignore newline after number

            std::vector<std::string> options;
            for (int i = 0; i < optionCount; ++i) {
                std::string option;
                std::getline(file, option);
                options.push_back(option);
            }

            int correctIndex;
            file >> correctIndex;
            file.ignore();  // Ignore newline after correct index

            std::getline(file, line); // Read delimiter (----)

            questions.emplace_back(QuestionType::MULTIPLE_CHOICE, questionText, options, correctIndex - 1);
        }
    }
    std::cout<< "Questions loaded successfully!\n\n";
    return questions;
}
