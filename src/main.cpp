// // main.cpp - Interactive Quiz Program entry point

// #include "quiz.h"
// #include <iostream>
// #include <string>
// using namespace std;

// int main(int argc, char* argv[]) {
//     cout << "Welcome to the Interactive Quiz Program!" <<endl;
    
//     // TODO: Add call to function that loads questions from file
//     // TODO: Add call to function that starts the quiz
    
//     return 0;
// }

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

    
    displayQuestions(questions);  // Use the new function

    return 0;
}
