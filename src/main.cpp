// // main.cpp - Interactive Quiz Program entry point

#include <iostream>
#include "../include/quiz.h"

using namespace std;

int main() {

    string filename = "./data/quiz_questions.txt"; 

    if (validateQuizFile(filename)) {
        cout << "Quiz file is valid!" << endl;
    } else {
        cout << "Quiz file is invalid!" << endl;
    }
    std::vector<Question> questions = loadQuestionsFromFile(filename);
    cout << "Welcome to the Interactive Quiz Program!\n" <<endl;
    
    displayQuestions(questions);

    return 0;
}
