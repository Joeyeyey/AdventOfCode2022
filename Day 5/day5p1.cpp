#include <cassert>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class CargoStack {
   public:
    CargoStack() = default;
    int addStringToStack(int stackIdx, string crates);
    int moveCrate(int fromIdx, int toIdx);
    int moveCrates(int amount, int fromIdx, int toIdx);
    string getTops();

   private:
    stack<char> crateStacks[9];
};

int main() {
    const string startingCrates[] = {
        "NCRTMZP",  "DNTSBZ",  "MHQRFCTG", "GRZ",   "ZNRH",
        "FHSWPZLD", "WDZRCGM", "SJFLHWZQ", "SQPWN",
    };

    CargoStack myCargoStack;
    for (int i = 0; i < 9; i++)
        myCargoStack.addStringToStack(i, startingCrates[i]);
}

int CargoStack::addStringToStack(int stackIdx, string crates) {
    for (int i = 0; i < crates.size(); i++) {
        crateStacks[stackIdx].push(crates[i]);
    }

    return crateStacks[stackIdx].size();
}

int CargoStack::moveCrate(int fromIdx, int toIdx) {
    assert(crateStacks[fromIdx].size() > 0);

    crateStacks[toIdx].push(crateStacks[fromIdx].top());
    crateStacks[fromIdx].pop();

    return crateStacks[toIdx].size();
}

int CargoStack::moveCrates(int amount, int fromIdx, int toIdx) {
    assert(crateStacks[fromIdx].size() > amount);

    for (int i = 0; i < amount; i++) {
        moveCrate(fromIdx, toIdx);
    }

    return crateStacks[toIdx].size();
}

string CargoStack::getTops() {
    string tops = "";
    for (int i = 0; i < 9; i++) {
        tops.push_back(crateStacks[i].top());
    }

    return tops;
}
