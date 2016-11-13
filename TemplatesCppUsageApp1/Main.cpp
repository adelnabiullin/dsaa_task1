// Main.cpp

#include "List.hpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
	List<int> first, second;
	srand(time(NULL));
	for (int i = 0; i < rand() % 20 + 1; i++) {
		first.push(rand() % 100 + 1);
	}
	for (int i = 0; i < rand() % 30 + 1; i++) {
		second.push(rand() % 120 + 1);
	}

	printf("First list (size: %d):\n", first.getSize());
	for (int i = 0; i < first.getSize(); i++) {
		printf("%d ", first[i]);
	}
	printf("\nSecond list (size: %d):\n", second.getSize());
	for (int i = 0; i < second.getSize(); i++) {
		printf("%d ", second[i]);
	}
	printf("\n");

	first.unshift(second.pop());

	printf("First list (size: %d):\n", first.getSize());
	for (int i = 0; i < first.getSize(); i++) {
		printf("%d ", first[i]);
	}
	printf("\nSecond list (size: %d):\n", second.getSize());
	for (int i = 0; i < second.getSize(); i++) {
		printf("%d ", second[i]);
	}
	printf("\n");

	return 0;
}