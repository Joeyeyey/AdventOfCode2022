#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string inputFileName = "input.txt";

struct moveOperation {
    int amount = 0;
    int fromIdx = 0;
    int toIdx = 0;
};

class CargoStack {
   public:
    CargoStack(const int stacks = 9);

    const int addStringToStack(const int stackIdx, const string crates);
    const int moveCrate(const int fromIdx, const int toIdx);
    const int moveCrates(const int amount, const int fromIdx, const int toIdx);

    const string printStack(const int idx);
    const string getTops();

    const int getNumStacks();

   private:
    const int m_numStacks;
    vector<string> m_crateStacks;
};

moveOperation parseLine(string line) {
    int idxNumber = line.find_first_of("1234567890");
    int idxNumberEnd = line.find(' ', idxNumber);
    int amount = stoi(line.substr(idxNumber, idxNumberEnd - idxNumber));

    idxNumber = line.find_first_of("1234567890", idxNumberEnd);
    idxNumberEnd = line.find(' ', idxNumber);
    int fromIdx = stoi(line.substr(idxNumber, idxNumberEnd - idxNumber)) - 1;

    idxNumber = line.find_first_of("1234567890", idxNumberEnd);
    idxNumberEnd = line.find(' ', idxNumber);
    int toIdx = stoi(line.substr(idxNumber, idxNumberEnd - idxNumber)) - 1;

    return {amount, fromIdx, toIdx};
}

int main() {
    vector<string> startingCrates = {
        "NCRTMZP",  "DNTSBZ",  "MHQRFCTG", "GRZ",   "ZNRH",
        "FHSWPZLD", "WDZRCGM", "SJFLHWZQ", "SQPWN",
    };

    cout << "Starting crates size: " << startingCrates.size() << endl;

    CargoStack myCargoStack(9);
    cout << "m_numStacks: " << myCargoStack.getNumStacks() << endl;

    for (int i = 0; i < startingCrates.size(); i++)
        myCargoStack.addStringToStack(i, startingCrates[i]);

    ifstream inputFile(inputFileName);

    string line;

    int oplimit = 10;

    int opNum = 1;
    while (getline(inputFile, line) && oplimit--) {
        moveOperation op = parseLine(line);
        cout << "===== Operation #" << opNum++ << "=====" << endl;
        cout << "move " << op.amount << " from " << op.fromIdx + 1 << " to "
             << op.toIdx + 1 << endl;
        cout << "From stack #" << op.fromIdx + 1 << ": "
             << myCargoStack.printStack(op.fromIdx) << endl;
        cout << "To stack #" << op.toIdx + 1 << ": "
             << myCargoStack.printStack(op.toIdx) << endl;
        myCargoStack.moveCrates(op.amount, op.fromIdx, op.toIdx);
    }

    cout << endl << "Crate tops: " << myCargoStack.getTops() << endl;
}

CargoStack::CargoStack(int stacks) : m_numStacks(stacks) {
    m_crateStacks.reserve(m_numStacks);
}

const int CargoStack::addStringToStack(const int stackIdx,
                                       const string crates) {
    assert(0 <= stackIdx && stackIdx < m_numStacks);

    cout << "Adding string \"" << crates << "\" to stack #" << stackIdx + 1
         << endl;

    for (int i = 0; i < crates.size(); i++) {
        m_crateStacks[stackIdx] += crates[i];
    }

    cout << "Stack #" << stackIdx + 1
         << " now contains: " << printStack(stackIdx) << endl;

    return m_crateStacks[stackIdx].size();
}

const int CargoStack::moveCrate(const int fromIdx, const int toIdx) {
    assert(0 <= fromIdx && fromIdx < m_numStacks);
    assert(0 <= toIdx && toIdx < m_numStacks);
    // assert(crateStacks[fromIdx].size() != 0);
    if (m_crateStacks[fromIdx].size() == 0) return;

    m_crateStacks[toIdx].push_back(m_crateStacks[fromIdx].back());
    m_crateStacks[fromIdx].pop_back();

    cout << "Moved a create from stack #" << fromIdx + 1 << " to stack #"
         << toIdx + 1 << endl;

    return m_crateStacks[toIdx].size();
}

const int CargoStack::moveCrates(const int amount, const int fromIdx,
                                 const int toIdx) {
    assert(0 <= fromIdx && fromIdx < m_numStacks);
    assert(0 <= toIdx && toIdx < m_numStacks);
    // assert(crateStacks[fromIdx].size() >= amount);

    int m = m_crateStacks[fromIdx].size();
    for (int i = 0; i < (amount <= m ? amount : m); i++) {
        moveCrate(fromIdx, toIdx);
    }

    return m_crateStacks[toIdx].size();
}

const string CargoStack::printStack(const int idx) {
    assert(0 <= idx && idx < m_numStacks);

    string strStack = "";
    for (int i = 0; i < m_crateStacks[idx].size(); i++) {
        strStack += m_crateStacks[idx][i];
    }
    return strStack;
}

const string CargoStack::getTops() {
    string tops = "";
    for (int i = 0; i < m_numStacks; i++) {
        tops += m_crateStacks[i].back();
    }

    return tops;
}

const int CargoStack::getNumStacks() { return m_numStacks; }
