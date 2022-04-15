#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Quiz.h"
#include "printResult.h"

using namespace std;

int main()
{
    fstream dater;
    int num = 0;
    int yup = 0;
    int oops = 0;

//Created a vector of Quiz objects//
    vector<Quiz> quizVector;

//Opened file database.txt//
    dater.open("BeatlesTriv.txt", ios :: in);

//check to see if file is open//
    if (dater.is_open())
    {
        string stringy; 

    //loop that counts how many lines there are in file//
        while (getline(dater, stringy))
        {
            num++;
        }
    //divides count by 2 to account for question and answer lines//
        num = num / 2; 
    }

//close file then reopen in order to getline again//
    dater.close();

    dater.open("BeatlesTriv.txt", ios :: in);
        
    if (dater.is_open())
    {
        string quesh, ansa;

    //loop that assigns questions and answers from txt file to two string variable//
    //deletes the '\n' character at the end and creates quiz object to activate the //
    //default constructor that sets question and answer//
    //then adds quiz object to vector//
        for (int i = 0; i < num; i++)
        {
            getline(dater, quesh);
            getline(dater, ansa);

            quesh.pop_back();
            ansa.pop_back();
            
            Quiz quizzy(quesh, ansa);
            quizVector.push_back(quizzy);

        }

    }

    srand(unsigned(time (0)));

//shuffling the quiz objects in the vector//
    random_shuffle(quizVector.begin(), quizVector.end());

//loop that prints the new order of questions with conditional statements that check if user input matches answer//
//also updates and prints static variable score//
    for (unsigned int i = 0; i < 20; i++)
        {
            string input;

            cout << quizVector[i].getQuestion() << endl;
            cout << "Type in your answer: ";
            getline(cin, input);

            if (quizVector[i].getAnswer() == input)
            {
                cout << "Correct!" << endl;
                quizVector[i].updateScore(1);
                yup++;
                cout << "Current score: " << quizVector[i].getScore() << endl;
            }

            else
            {
                cout << "Wrong! Correct answer: " << quizVector[i].getAnswer() << endl;
                quizVector[i].updateScore(-1);
                oops++;
                cout << "Current score: " << quizVector[i].getScore() << endl;
            }
            cout << endl;
        }

//calling print results function//
        printResult(yup, oops);

    return 0;
}
