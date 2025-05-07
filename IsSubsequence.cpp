/*
* Example 4: 392. Is Subsequence.

	Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

 A subsequence of a string is a sequence of characters that can be obtained by deleting some (or none) of the characters from the original string, while maintaining the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.
*/

#include <iostream>
#include <string>

using namespace std;

bool IsSubsequence(const string& s, const string& t) {
	size_t i = 0;
	size_t j = 0;

	if (s.empty() && t.empty()) {
		return true;
	}
	if (s.empty()) {
		return false;
	}

	while (i < s.length() && j < t.size()) {
		if (s[i] == t[j]) {
			++i;
		}
		++j;
	}

	if (i == s.length()) {
		return true;
	}
	return false;
}

void IsSubsequence_main() {
	struct input {
		string substring;
		string str;
	};
	cout << std::boolalpha;
	for (const input& i : {
			input{"", ""},
			input{"ace", "abcde"},
			input{"ace", "ac"}
		}) {
		cout << IsSubsequence(i.substring, i.str) << "\n";
	}
}