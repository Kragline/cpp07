#include "iter.hpp"

// Simple function to print values
template <typename T>
void printElement(const T &elem)
{
	std::cout << elem << " ";
}

// Function to modify non-const elements
template <typename T>
void increment(T &elem)
{
	elem += 1;
}

// Overload for std::string to demonstrate type flexibility
void toUpper(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

int main()
{
	std::cout << "=== Test 1: int array ===" << std::endl;
	int	arr1[] = {1, 2, 3, 4, 5};
	iter(arr1, 5, printElement<int>);
	std::cout << std::endl;

	iter(arr1, 5, increment<int>);
	iter(arr1, 5, printElement<int>);
	std::cout << std::endl << std::endl;

	// ----
	std::cout << "=== Test 2: double array ===" << std::endl;
	double	arr2[] = {1.1, 2.2, 3.3, 4.4};
	iter(arr2, 4, printElement<double>);
	std::cout << std::endl;

	iter(arr2, 4, increment<double>);
	iter(arr2, 4, printElement<double>);
	std::cout << std::endl << std::endl;

	// ----
	std::cout << "=== Test 3: std::string array ===" << std::endl;
	std::string	arr3[] = {"hello", "world", "cpp"};
	iter(arr3, 3, printElement<std::string>);
	std::cout << std::endl;

	iter(arr3, 3, toUpper);
	iter(arr3, 3, printElement<std::string>);
	std::cout << std::endl << std::endl;

	// ----
	std::cout << "=== Test 4: const int array ===" << std::endl;
	const int	arr4[] = {10, 20, 30, 40};
	iter(arr4, 4, printElement<int>);
	std::cout << std::endl;

	// cannot call increment on const array -> ensures const overload works
	// iter(arr4, 4, increment<int>); // should not compile, as intended

	std::cout << std::endl;

	// ----
	std::cout << "=== Test 5: Empty or null arrays ===" << std::endl;
	int	*nullArr = NULL;
	iter(nullArr, 0, printElement<int>);
	iter(nullArr, 5, printElement<int>);
	std::cout << "(No output expected)" << std::endl;

	return (0);
}
