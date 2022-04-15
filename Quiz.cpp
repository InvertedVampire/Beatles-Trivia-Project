#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Quiz.h"

int Quiz :: score = 0;

std :: string Quiz :: getQuestion()
{
    return question;
}
std :: string Quiz :: getAnswer()
{
    return answer;
}
int Quiz :: getScore()
{
    return score;
}
void Quiz :: updateScore(int val)
{
    score = score + val;

    if (score < 0)
    {score = 0;}
    
}