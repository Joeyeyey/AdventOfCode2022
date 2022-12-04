#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
A & X = Rock = 1 Point
B & Y = Paper = 2 Points
C & Z = Scissors = 3 points

Loss = 0 points
Draw = 3 points
Win = 6 points
*/


const string inputFileName = "input.txt";

int main() {

    ifstream inputFile(inputFileName);
    string line;
    
    int myPoints = 0;

    while(getline(inputFile, line)) {
        switch (line[2]) {
            case 'X' : 
                myPoints += 0;
                switch (line[0]) {
                    case 'A' :
                        myPoints += 3;
                        break;
                    case 'B' :
                        myPoints += 1;
                        break;
                    case 'C' :
                        myPoints += 2;
                        break;
                }
                break;
            case 'Y' : 
                myPoints += 3;
                switch (line[0]) {
                    case 'A' :
                        myPoints += 1;
                        break;
                    case 'B' :
                        myPoints += 2;
                        break;
                    case 'C' :
                        myPoints += 3;
                        break;
                }
                break;
            case 'Z' : 
                myPoints += 6;
                switch (line[0]) {
                    case 'A' :
                        myPoints += 2;
                        break;
                    case 'B' :
                        myPoints += 3;
                        break;
                    case 'C' :
                        myPoints += 1;
                        break;
                }
                break;
        }
    }

    cout << "Your score: " << myPoints << endl;

    return 0;
}