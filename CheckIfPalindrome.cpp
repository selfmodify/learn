#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(const string& s) {
	if (s.empty()) {
		return true;
	}
	size_t left = 0;
	size_t right = s.length() - 1;
	while (left < right) {
		if (s[left] == s[right]) {
			++left;
			--right;
		}
		else {
			return false;
		}
	}
	return true;
}

void main_check_if_palindrome() {
	for (const string& s : { "malayalam", "" }) {
		cout << IsPalindrome(s) << "\n";
	}
}