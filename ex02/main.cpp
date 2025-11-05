#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void	printArray(const Array<T>& arr)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "]" << std::endl;
}

int main()
{
	std::cout << "=== TEST 1: Empty array ===" << std::endl;
	Array<int>	empty;
	std::cout << "Size: " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0] << std::endl; // should throw
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: Integer array ===" << std::endl;
	Array<int>	a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;
	printArray(a);

	std::cout << "Modify elements:" << std::endl;
	a[0] = 99;
	a[4] = 42;
	printArray(a);

	std::cout << "\n=== TEST 3: Copy constructor ===" << std::endl;
	Array<int>	b(a);
	std::cout << "Original: ";
	printArray(a);
	std::cout << "Copy:     ";
	printArray(b);

	std::cout << "Change copy's values:" << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] += 1;
	std::cout << "Original after modifying copy: ";
	printArray(a);
	std::cout << "Copy after modification:       ";
	printArray(b);

	std::cout << "\n=== TEST 4: Assignment operator ===" << std::endl;
	Array<int>	c(3);
	for (unsigned int i = 0; i < c.size(); i++)
		c[i] = -i;
	std::cout << "Before assignment, c = ";
	printArray(c);
	c = a;
	std::cout << "After assignment, c = ";
	printArray(c);

	std::cout << "\n=== TEST 5: Const array access ===" << std::endl;
	const Array<int>	constArr(a);
	std::cout << "constArr contents: ";
	printArray(constArr);
	std::cout << "First element: " << constArr[0] << std::endl;
	// constArr[0] = 10; // should not compile if uncommented

	std::cout << "\n=== TEST 6: Out-of-bounds checks ===" << std::endl;
	try
	{
		std::cout << a[a.size()] << std::endl; // invalid index
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << a[9999] << std::endl; // invalid index
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 7: String array ===" << std::endl;
	Array<std::string>	s(3);
	s[0] = "Hello";
	s[1] = "C++";
	s[2] = "Templates";
	printArray(s);

	Array<std::string>	copyS(s);
	copyS[1] = "World";
	std::cout << "Original: ";
	printArray(s);
	std::cout << "Modified copy: ";
	printArray(copyS);

	std::cout << "\n=== TEST 8: Large array ===" << std::endl;
	Array<int>	large(1000);
	for (unsigned int i = 0; i < large.size(); i++)
		large[i] = i;
	std::cout << "large[0] = " << large[0]
	          << ", large[999] = " << large[999] << std::endl;

	std::cout << "\n✅ All tests completed successfully!" << std::endl;
	return (0);
}
