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
                myPoints += 1;
                switch (line[0]) {
                    case 'A' :
                        myPoints += 3;
                        break;
                    case 'B' :
                        myPoints += 0;
                        break;
                    case 'C' :
                        myPoints += 6;
                        break;
                }
                break;
            case 'Y' : 
                myPoints += 2;
                switch (line[0]) {
                    case 'A' :
                        myPoints += 6;
                        break;
                    case 'B' :
                        myPoints += 3;
                        break;
                    case 'C' :
                        myPoints += 0;
                        break;
                }
                break;
            case 'Z' : 
                myPoints += 3;
                switch (line[0]) {
                    case 'A' :
                        myPoints += 0;
                        break;
                    case 'B' :
                        myPoints += 6;
                        break;
                    case 'C' :
                        myPoints += 3;
                        break;
                }
                break;
        }
    }

    cout << "Your score: " << myPoints << endl;

    return 0;
}