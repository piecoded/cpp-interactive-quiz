# cpp-interactive-quiz
An interactive, command-line quiz application built in C++. It features programming-related questions, user input handling, and a scoring system. Great for testing your coding knowledge! 🚀

## Features
- Loads quiz questions from a file
- Interactive question-answer format
- Keeps track of your score
- Highlights correct and incorrect answers with colors

## Installation (may vary on different platforms)
1. Clone the repository:
   git clone https://github.com/piecoded/cpp-interactive-quiz.git

2. Go to root project directory:   
   cd cpp-interactive-quiz
   
3. Compile the project:
   make
   
4. Run the quiz:
   ./bin/quiz.exe

## Usage
- Answer questions by entering the option number.
- Your score updates in real time.
- At the end, you’ll see your total score.

## Adding Questions
To add new quiz questions, modify the questions file (`quiz_questions.txt`) following this format:

- Each question starts with `MC` (for multiple-choice).
- The next line is the question text.
- Then, specify the number of answer options.
- List the answer options, one per line.
- Finally, specify the correct answer's index (1-based).
- Use `---` as a separator between questions.
  
Example:
<p>MC
Which of the following is NOT a pillar of Object-Oriented Programming? <br>
4 <br>
Encapsulation <br>
Inheritance <br>
Compilation <br>
Polymorphism <br>
3 <br>
----</p>

## Future Improvements
- More question categories (like True/False)
- Dynamic selection of number of questions
