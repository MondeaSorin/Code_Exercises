#include <iostream>
#include <thread>
#include "thread_guard.h"

void functionA();
void functionB();
void test();

void functionA()
{
	std::thread threadC(test);
	threadC.join();
	std::cout << "Hello from functionA\n";
}

void functionB()
{
	std::cout << "Hello from functionB\n";
}

void test()
{
	std::cout << "Test() function called\n";
}

void my_function()
{
	std::cout << "My function" << std::endl;
	throw std::runtime_error("This is a runtime error");
}

int main()
{
	std::thread threadA(functionA);
	std::thread threadB(functionB);

	thread_guard tg1(threadA);
	thread_guard tg2(threadB);
	try
	{
		my_function();
	}
	catch (const std::runtime_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	threadA.join();
}