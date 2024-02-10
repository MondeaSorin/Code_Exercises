#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <chrono>

void clean(std::queue<uint8_t>& cleaning_queue, bool& done, bool& can_execute)
{
	while (!done)
	{
		if (!can_execute)
		{
			continue;
		}
		std::cout << "Checking for cleaning tasks...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << cleaning_queue.size() << " tasks found\nExecuting tasks";
		while (!cleaning_queue.empty())
		{
			std::cout << "Executing cleaning task... \n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "Cleaning done for cleaning task\n";
			cleaning_queue.pop();
		}

		if (cleaning_queue.empty())
		{
			can_execute = false;
		}
	}
}

void stop_engine()
{
	std::cout << "Stopping the engine...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "\nThe engine has been shut down\n\n";
}

void full_speed(std::queue<uint8_t>& engine_queue, bool& done, bool& can_execute)
{
	while (!done)
	{
		if (!can_execute)
		{
			continue;
		}
		std::cout << "Checking for engine tasks...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << engine_queue.size() << " tasks found\nExecuting tasks";

		while (!engine_queue.empty())
		{
			if (engine_queue.front() == 3)
			{
				stop_engine();
			}
			else
			{
				std::cout << "Fueling up the engine...\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				std::cout << "\nThe engine is running at increased speed\n\n";
			}
			engine_queue.pop();
		}
		if (engine_queue.empty())
		{
			can_execute = false;
		}
	}
}

int main()
{
	int allowed_threads = std::thread::hardware_concurrency();
	
	//std::cout << "Number of allowed threads on my PC is " << allowed_threads << std::endl;
	std::cout << "This is the captain speaking. Let's set sail" << std::endl;
	
	bool done{ false };
	bool can_execute_c{ false };
	bool can_execute_e{ false };

	std::queue<uint8_t> cleaning_queue;
	std::queue<uint8_t> engine_queue;

	std::thread engine_crew(full_speed, std::ref(engine_queue), std::ref(done), std::ref(can_execute_e));
	std::thread cleaning_crew(clean, std::ref(cleaning_queue), std::ref(done), std::ref(can_execute_c));

	engine_crew.detach();
	cleaning_crew.detach();

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
			cleaning_queue.push(1);
			std::cout << "Added 1 task to the cleaning queue" << std::endl << std::endl;
			can_execute_c = true;
		}
		else if (selection == "2")
		{
			engine_queue.push(2);
			std::cout << "Added 1 speed task to the engine queue" << std::endl << std::endl;
			can_execute_e = true;
		}
		else if (selection == "3")
		{
			engine_queue.push(3);
			std::cout << "Added 1 stop task to the engine queue" << std::endl << std::endl;
			can_execute_e = true;
		}
		else if (selection == "100")
		{
			std::cout << "Abandoning the ship..." << std::endl;
			done = true;
		}
		else
		{
			std::cout << "Invalid order. Try again" << std::endl << std::endl;
		}
	} while (selection != "100");
}