#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Quiz.h"
#include "printResult.h"

void printResult(int correct, int wrong)
{
    Quiz quizzy;

    std :: stringstream stringy;

    stringy << correct << wrong << quizzy.score;

    std :: cout << "Number correct answers: " << correct << std :: endl;
    std :: cout << "Number wrong answers: " << wrong << std :: endl;
    std :: cout << "Final score: " << quizzy.score << std :: endl;

    
}