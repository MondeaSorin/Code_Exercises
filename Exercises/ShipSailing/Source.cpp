#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void clean()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "\nThe ship has been cleaned\n";
}

void full_speed()
{
	std::cout << "Fueling up the engine...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "\nThe engine is running at full speed\n\n";
}

void stop_engine()
{
	std::cout << "Stopping the engine...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "\nThe engine has been shut down\n\n";
}

int main()
{
	std::cout << "This is the captain speaking. Let's set sail" << std::endl;
	

	std::string selection{};
	do
	{
		std::cout << "Which commands shall i order my crew to do?" << std::endl
			<< "1. clean" << std::endl
			<< "2. full speed ahead" << std::endl
			<< "3. stop the engine" << std::endl
			<< "100. abandon the ship" << std::endl << std::endl;

		std::cout << "Enter your choice: ";
		std::cin >> selection;
		std::cout << std::endl;

		if (selection == "1")
		{
			std::cout << "The captain can manage other tasks while the ship is being cleaned\n";
			std::thread cleaning_crew(clean);
			cleaning_crew.detach();
			std::cout << "Cleaning the ship...\n\n";
		}
		else if (selection == "2")
		{
			std::cout << "The captain must wait the response of the engine crew before he can issue new orders\n";
			std::thread engine_crew1(full_speed);
			engine_crew1.join();
		}
		else if (selection == "3")
		{
			std::cout << "The captain must wait the response of the engine crew before he can issue new orders\n";
			std::thread engine_crew2(stop_engine);
			engine_crew2.join();
		}
		else if (selection == "100")
		{
			std::cout << "Abandoning the ship..." << std::endl;
		}
		else
		{
			std::cout << "Invalid order. Try again" << std::endl << std::endl;
		}
	} while (selection != "100");
}