/*
* Given a sorted array of unique integers and a target integer
* return true if there exists a pair of numbers that sum to target, false otherwise.
* This problem is similar to Two Sum. (In Two Sum, the input is not sorted).
* For example, given nums = [1, 2, 4, 6, 8, 9, 14, 15] and target = 13, return true
* because 4 + 9 = 13.
*/

#include <vector>
#include <iostream>

using namespace std;

bool CheckIfTargetReached(const std::vector<int> input, int target) {
	cout << "\n";
	if (input.empty()) {
		return false;
	}
	size_t left = 0;
	size_t right = input.size() - 1;
	while (left < right) {
		const int sum = input[left] + input[right];
		if ( sum == target) {
			cout << " Found " << input[left] << " " << input[right] << " ";
			return true;
		} else if(input[right] > sum) {
			right--;
		}
		else {
			++left;
		}
	}
	return false;
}

void main_CheckIfTargetReached() {
	cout << CheckIfTargetReached({}, 10);
	cout << CheckIfTargetReached({ 1, 2, 4, 6, 8, 9, 14, 15 }, 13);
}