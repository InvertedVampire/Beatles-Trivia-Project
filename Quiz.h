#ifndef QUIZ_
#define QUIZ_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Quiz
{
    private:
    std::string question {""};
    std::string answer {""};
    static int score;

    public:
    Quiz() = default;
    Quiz(std::string q, std::string a)
    {
        question = q;
        answer = a; 
    }
    std::string getQuestion();
    std::string getAnswer();
    static int getScore();
    static void updateScore(int val);
    friend void printResult(int correct, int wrong);
};

#endif