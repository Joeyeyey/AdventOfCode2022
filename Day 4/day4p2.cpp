#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string inputFileName = "input.txt";

vector<string> lineSplit(string line)
{
    vector<string> result;

    int start = 0;
    int end = line.find_first_of("-,", 0);
    result.push_back(line.substr(start, end - start));
    start = end + 1;
    end = line.find_first_of("-,", start);
    result.push_back(line.substr(start, end - start));
    start = end + 1;
    end = line.find_first_of("-,", start);
    result.push_back(line.substr(start, end - start));
    start = end + 1;
    end = line.size();
    result.push_back(line.substr(start, end - start));

    return result;
}

int main()
{

    ifstream inputFile(inputFileName);

    int counter = 0;

    string line;
    while (getline(inputFile, line))
    {
        vector<string> split = lineSplit(line);

        if (stoi(split[0]) >= stoi(split[2]) && stoi(split[0]) <= stoi(split[3]))
            counter++;
        else if (stoi(split[1]) >= stoi(split[2]) && stoi(split[1]) <= stoi(split[3]))
            counter++;
        else if (stoi(split[2]) >= stoi(split[0]) && stoi(split[2]) <= stoi(split[1]))
            counter++;
        else if (stoi(split[3]) >= stoi(split[0]) && stoi(split[3]) <= stoi(split[1]))
            counter++;
    }

    cout << "Counter: " << counter << endl;

    return 0;
}
