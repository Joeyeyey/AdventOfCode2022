#include "../stdc++.h"
#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string_view>
#include <fstream>

using namespace std;

const string input_file = "input.txt";

int main() {
    
    ifstream inputStream(input_file);

    // priority_queue<int, vector<int>, greater<int>> max_heap;
    priority_queue<int> min_heap;
    int k = 3;
    string curr_line = "";
    int curr_sum = 0;
    while (getline(inputStream, curr_line)) {
        if (curr_line == "\r") {
            min_heap.push(curr_sum);
            curr_sum = 0;
        } else {
            curr_sum += stoi(curr_line);
        }
    }

    if (curr_sum != 0)
        min_heap.push(curr_sum);

    // while (min_heap.size() > k) {
    //     min_heap.pop();
    // }

    int result = 0;
    while (k--) {
        result += min_heap.top();
        min_heap.pop();
    }

    cout << "Result: " << result << endl;

    return 0;
}
