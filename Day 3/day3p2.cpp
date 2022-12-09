#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string inputFileName = "input.txt";

int main() {
    ifstream inputFile(inputFileName);

    int prioritiesSum = 0;

    string elf1;
    string elf2;
    string elf3;
    while (getline(inputFile, elf1) && getline(inputFile, elf2) &&
           getline(inputFile, elf3)) {
        bool commonFound = false;
        for (int i = 0; i < elf1.size(); i++) {
            if (commonFound) break;
            for (int j = 0; j < elf2.size(); j++) {
                if (commonFound) break;
                if (elf1[i] == elf2[j]) {
                    for (int k = 0; k < elf3.size(); k++) {
                        if (elf1[i] == elf3[k]) {
                            if ('a' <= elf1[i] && elf1[i] <= 'z')
                                prioritiesSum += elf1[i] - 'a' + 1;
                            else if ('A' <= elf1[i] && elf1[i] <= 'Z')
                                prioritiesSum += elf1[i] - 'A' + 27;
                            commonFound = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << "Sum of priorities: " << prioritiesSum << endl;

    return 0;
}
