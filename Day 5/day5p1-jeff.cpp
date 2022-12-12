#include <bits/stdc++.h>

using namespace std;

void print_stack(stack<char>& in_stack) {
    // cout << "Printing stack..." << endl;
    stack<char> new_stack(in_stack);
    string stack_string = "";
    while (!new_stack.empty()) {
        stack_string += new_stack.top();
        new_stack.pop();
    }

    cout << stack_string << endl << endl;
}

void move_crates(vector<stack<char>>& stacks, vector<int>& quantities,
                 vector<int>& froms, vector<int>& tos) {
    if (quantities.size() != froms.size() || quantities.size() != tos.size()) {
        cout << "ERROR: Reading from input.txt FAILED" << endl;
    }

    cout << "starting move..." << endl;
    int n = quantities.size();
    for (int i = 0; i < n; ++i) {
        int quantity = quantities[i];
        int from = froms[i] - 1;
        int to = tos[i] - 1;

        // TODO
        cout << "Operation " << i << endl;
        while (quantity--) {
            if (stacks[from].size() == 0) {
                cout << "ERROR: Stack " << from << " is empty" << endl;
                break;
            }

            stacks[to].emplace(stacks[from].top());
            stacks[from].pop();
        }

        // TODO Checking
        cout << "Printing stack " << to + 1 << ": " << endl;
        print_stack(stacks[to]);
        cout << "Printing stack " << from + 1 << ": " << endl;
        print_stack(stacks[from]);
    }

    cout << "Ended move!" << endl;
}

int jeff_main() {
    // Init crates
    const string startingCrates[] = {
        "NCRTMZP",  "DNTSBZ",  "MHQRFCTG", "GRZ",   "ZNRH",
        "FHSWPZLD", "WDZRCGM", "SJFLHWZQ", "SQPWN",
    };

    vector<stack<char>> stacks;
    stack<char> stack1;
    stack<char> stack2;
    stack<char> stack3;
    stack<char> stack4;
    stack<char> stack5;
    stack<char> stack6;
    stack<char> stack7;
    stack<char> stack8;
    stack<char> stack9;
    stacks.emplace_back(stack1);
    stacks.emplace_back(stack2);
    stacks.emplace_back(stack3);
    stacks.emplace_back(stack4);
    stacks.emplace_back(stack5);
    stacks.emplace_back(stack6);
    stacks.emplace_back(stack7);
    stacks.emplace_back(stack8);
    stacks.emplace_back(stack9);

    int stack_idx = 0;
    for (auto& crate : startingCrates) {
        for (auto c : crate) {
            stacks[stack_idx].emplace(c);
        }

        // // TODO
        // cout << "Stack size: " << stacks[stack_idx].size() << endl;
        // if (!stacks[stack_idx].empty())
        //     print_stack(stacks[stack_idx]);

        ++stack_idx;
    }

    // Parse messages
    ifstream inputFile("input.txt");
    string line;

    vector<int> quantities;
    vector<int> froms;
    vector<int> tos;
    string move_string, from_string, to_string;
    int quantity, from, to;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        if (iss >> move_string >> quantity >> from_string >> from >>
            to_string >> to) {
            // TODO: Remove test statement
            // cout << "We got: " << quantity << ", " << from << ", " << to <<
            // endl;
            quantities.emplace_back(quantity);
            froms.emplace_back(from);
            tos.emplace_back(to);
        }
    }

    // Simulate
    move_crates(stacks, quantities, froms, tos);

    // // Printing all stacks
    // vector<stack<char>> print_stacks(final_stacks);
    // int curr_stack_idx = 0;
    // for (auto& stack : print_stacks) {
    //     cout << "Printing stack " << curr_stack_idx <<endl;
    //     string curr_stack_string = "";
    //     while (!stack.empty()) {
    //         curr_stack_string += stack.top();
    //         stack.pop();
    //     }

    //     reverse(curr_stack_string.begin(), curr_stack_string.end());
    //     cout << curr_stack_string << endl;

    //     ++curr_stack_idx;
    // }

    // Take tops of all stacks as result
    string result = "";

    for (auto& stack : stacks) {
        if (!stack.empty()) {
            result += stack.top();
        }
    }

    // Print result
    cout << "Result: " << result << endl;

    return 0;
}
