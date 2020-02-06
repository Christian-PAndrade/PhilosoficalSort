#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>

// Function Headers
std::vector<int> fillVector(int size);
void doTheSort(std::vector<int> v);

/*
 * Main method
 * Locale setup
 * Creates a vec and fills it
 * shuffle and checks if sorted
 */
int main() {

	int size = 1;
	do
	{
		// locale info
		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale());

		// Creates a vector and fills it with as many numbers as needed
		std::vector<int> vec = fillVector(size);
		// Try shuffle sort, check to see if sorted
		doTheSort(vec);

		// increment size
		++size;
	} while (size <= 20);
}

/*
 * Makes a vector of a given size
 * fills it with as many ints as passed (arg)
 * randomly shuffles it and returns that vec
 */
std::vector<int> fillVector(int size) {
	// Logs size
	std::cout << "Size: " << size << std::endl;
	
	// makes new empty vec
	std::vector<int> vec;

	// fills it
	for (int i = 1; i <= size; ++i)
		vec.push_back(i);

	// Random shuffles
	std::random_shuffle(vec.begin(), vec.end());

	// returns it
	return vec;
}

/*
 * Random shuffle, check to see if sorted
 * keep going until sorted
 * Print info once done
 */
void doTheSort(std::vector<int> v) {
	// counter
	long long counter = 0;
	// Prints to screen
	std::cout << "Trying" << std::endl;

	// Keep going while not sorted
	while (!std::is_sorted(v.begin(), v.end()))
	{
		//shuffle, increment counter
		std::random_shuffle(v.begin(), v.end());
		++counter;

		// For visualization purposes, log to screen every 1'000'000
		if (counter % 1000000 == 0)
			std::wcout << counter << std::endl;
	}
	// if sorted, print to screen number of tries needed
	std::wcout << "Tries: " << counter << std::endl << std::endl;
}