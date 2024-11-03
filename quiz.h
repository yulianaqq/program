#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void startQuiz();

void startQuiz() {
    ifstream quizFile("quiz.txt");
    if (!quizFile) {
        cout << "Error opening quiz file.\n";
        return;
    }

    string question;
    int answer, correctAnswers = 0;

    while (getline(quizFile, question)) {
        cout << question << "\n";
        quizFile >> answer;
        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;
        if (userAnswer == answer) {
            cout << "Correct!\n";
            correctAnswers++;
        } else {
            cout << "Incorrect.\n";
        }
        quizFile.ignore(); 
    }

    cout << "You answered " << correctAnswers << " questions correctly.\n";
    quizFile.close();
}

#endif
