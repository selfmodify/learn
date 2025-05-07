/*
* Write a function that reverses a string. The input string is given as an array of characters s.

 You must do this by modifying the input array in-place with O(1) extra memory.

*/

#include <string>
#include <iostream>

using namespace std;

const char* StringReverse(char* s) {
	if (s == nullptr) {
		return s;
	}
	size_t len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
	return s;
}

void StringReverse_main() {
	char s[] = "Hello";
	cout << StringReverse(s) << "\n";
	StringReverse(nullptr);
	char s1[] = "malayalam";
	cout << StringReverse(s1) << "\n";
	// cout << StringReverse("malayalam") << "\n";
}