/*
* Find the longest subarray with a sum less than or equal to k.
*/

#include <vector>
#include <iostream>

using namespace std;

void LessThanOrEqualToK(const vector<int>& nums, const int k) {
	size_t left = 0;
	size_t right = 0;
	size_t l =0, r = 0;
	size_t size = nums.size();
	int64_t sum = 0;
	int64_t max = 0;
	while (right < size) {
		if (sum <= k) {
			sum += nums[right++];
		} else {
			sum -= nums[left++];
		}
		if (sum > max && sum <= k) {
			max = sum;
			l = left;
			r = right - 1;
		}
	}
	cout << "l=" << l << " r=" << r << " max=" << max << "\n";
}

void LessThanOrEqualToK_main() {
	LessThanOrEqualToK({ 3, 1, 2, 7, 4, 2, 1, 1, 5 }, 8);
	LessThanOrEqualToK({ 3, 2, 1, 3, 1, 1 }, 5);
}

void main() {
	LessThanOrEqualToK_main();
}