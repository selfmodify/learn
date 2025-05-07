/*
* Given two sorted integer arrays arr1 and arr2, return a new array that combines both of them and is also sorted.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> MergeArrays(const vector<int> vec1, const vector<int> vec2) {
    vector<int> merged;
    int vec1_index = 0;
    int vec2_index = 0;

    while (true) {
        if (vec1_index < vec1.size() && vec2_index < vec2.size()) {
            if (vec1[vec1_index] <= vec2[vec2_index]) {
                merged.push_back(vec1[vec1_index]);
                ++vec1_index;
            } else {
                merged.push_back(vec2[vec2_index]);
                ++vec2_index;
            }
        } else if (vec1_index < vec1.size()) {
            merged.push_back(vec1[vec1_index]);
            ++vec1_index;
        } else if (vec2_index < vec2.size()) {
            merged.push_back(vec2[vec2_index]);
            ++vec2_index;
        } else {
            break;
        }
    }

    return merged;
}

void Print(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << ", ";
    }
    cout << "\n";
}

void MergeTwoSortedArrays_main() {
    Print(MergeArrays({}, {}));
    Print(MergeArrays({2, 3}, {1, 2}));
    Print(MergeArrays({1, 4, 7, 20}, {3, 5, 6}));
}