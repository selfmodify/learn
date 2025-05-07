#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

auto CreateTestVector(int count) {
	std::vector<long> items;
	for (int i = 0; i < count; ++i) {
		items.push_back(i);
	}
	return items;
}

void searchTestVector(const std::vector<long>& items) {
	for (int i = 0; i < items.size(); ++i) {
		auto it =std::find(items.begin(), items.end(), i);
		if (it != items.end()) {
			if (*it == items.size() + 1) {
				printf("Found element\n");
				return;
			}
		}
	}
}

int MapsVsVector_main() {
	auto items = CreateTestVector(100000);
	searchTestVector(items);
	for (int i = 0; i < 10; ++i) {
		searchTestVector(items);
	}
	return 0;
}