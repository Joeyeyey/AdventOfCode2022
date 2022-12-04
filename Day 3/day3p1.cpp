#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string inputFileName = "input.txt";

int main() {

    ifstream inputFile(inputFileName);

    int prioritiesSum = 0;

    string line;
    while(getline(inputFile, line)) {

        bool errorFound = false;
        for (int i = 0; i < line.size() / 2; i++) {
            if (errorFound)
                break;
            for (int j = line.size() / 2; j < line.size(); j++) {
                if (line[i] == line[j]) {
                    if ('a' <= line[i] && line[i] <= 'z')
                        prioritiesSum += line[i] - 'a' + 1;
                    else if ('A' <= line[i] && line[i] <= 'Z')
                        prioritiesSum += line[i] - 'A' + 27;
                    errorFound = true;
                    break;
                }
            }
        }
    }

    cout << "Sum of priorities: " << prioritiesSum << endl;

    return 0;
}