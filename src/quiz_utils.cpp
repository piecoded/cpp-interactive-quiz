#include "../include/quiz.h"
#include <iostream>

//defining ANSI escape codes for colored text
#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"

void displayQuestions(const std::vector<Question>& questions) {
    int score=0;
    for (size_t i = 0; i < questions.size(); i++) {
        // display current question
        std::cout << "Question " << (i + 1) << ": " << questions[i].questionText << std::endl;
        
        // display answer options
        for (size_t j = 0; j < questions[i].options.size(); j++) {
            std::cout << (j + 1) << ". " << questions[i].options[j] << std::endl;
        }

        int userChoice;
        std::cout << "Enter your answer (1-" << questions[i].options.size() << "): ";
        std::cin >> userChoice;

        // check answer validity
        if (userChoice < 1 || userChoice > static_cast<int>(questions[i].options.size())) {
    std::cout << RED << "Invalid choice. Skipping question.\n" << RESET;
} else if (userChoice - 1 == questions[i].correctAnswerIndex) {
    score++;
    std::cout << GREEN << "\nCorrect!\nCurrent Score: " << score << RESET << std::endl;
} else {
    std::cout << RED << "\nWrong answer.\nThe correct answer was: " 
              << questions[i].options[questions[i].correctAnswerIndex] 
              << "\nYour Score remains: " << score << RESET << std::endl;
}

if (i == (questions.size()) - 1) {
    std::cout << "\n*** Quiz has ended! ***\n";
    std::cout << "Your final score is:  " << score << " out of " << questions.size() << std::endl;
}


        std::cout << std::endl;  // line break between questions
    }
}

