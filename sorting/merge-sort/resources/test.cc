#include <iostream>
#include <vector>

std::vector<int> bar() {
	std::vector<int> result;
	for(int i = 0; i < 5; i++)
		result.push_back(i);
	std::cout << "After placing items: " << std::endl;
	for(int i = 0; i < 5; i++)
		std::cout << result[i] << std::endl;
	return result;
}

int baz() {
	int n = 5;
	return n;
}

int *fod() {
	int k = 5;
	int *p = &k;
	return p;
}

int *foo() {
	int arr[5];
	for(int i = 0; i < 5; i++)
		arr[i] = i;
	return arr;
}

int main(int argc, char *argv[]) {
	std::cout << "Hello World" << std::endl;
	int k = baz();
	int *arr = foo();
	std::vector<int> v = bar();
	for(int i = 0; i < 5; i++)
		std::cout << v[i] << std::endl;
	return 0;
}