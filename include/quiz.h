#ifndef QUIZ_H
#define QUIZ_H


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

enum class QuestionType {
    MULTIPLE_CHOICE
};

struct Question {
    QuestionType type;
    std::string questionText;
    std::vector<std::string> options;
    int correctAnswerIndex;

    Question(QuestionType t, const std::string& text, const std::vector<std::string>& opts, int correct)
        : type(t), questionText(text), options(opts), correctAnswerIndex(correct) {}

    void displayQuestion() const {
        std::cout << questionText << std::endl;
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << (i + 1) << ". " << options[i] << std::endl;
        }
    }
};

std::vector<Question> loadQuestionsFromFile(const std::string& filename);
void displayQuestions(const std::vector<Question>& questions);

bool validateQuizFile(const std::string& filename);

// Function to load questions from the data file
vector<string> loadQuestions(const string& filename);

// Function to display a question and return user's answer
string displayQuestion(const string& question);

// Function to check if the answer is correct
bool checkAnswer(const string& answer, const string& correctAnswer);

// Global variable to keep track of the score
extern int score;

// Global variable to store all questions
extern vector<string> questions;

#endif  // QUIZ_H
