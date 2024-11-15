#include <iostream>
#include "Computer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Branch.h"
#include "Tablet.h"
#include <vector>
#include <algorithm>
#include "MainOffice.h"
#include <string>
#include "HWExceptions.h"
#include <chrono>
// not all includes are a "must"

// This define is used for Run-time calculation
#define TIME_THIS(x) timer.restart(); x; total_counter+=timer.check()

// This define enables one-time print to console even if freopen is redirecting output to file
#define STDCOUT(x) fclose(fp);fp = freopen("CON", "w", stdout);std::cout <<x<< std::endl;fclose(fp);fp = freopen("benchmark_test.txt", "a", stdout);

//This defines are realted to testing constants
#define RATE 1
#define TEST_COUNT 10
#define ITEMS_COUNT 3000
#define BRANCHES_COUNT 100
#define PRINTS_COUNT 20
#define FINEST_COUNT 200 
#define PERIPHERALS 40
#define CONNECTING_COUNT 10
#ifndef ID
#define ID 0
#endif // !ID




void printless_print_branch_catalog(const Branch& branch)
{
	const std::vector<Item*>& catalog = branch.getCatalog();
	return;
}

class Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
public:
	Timer()
	{
		start_point = std::chrono::high_resolution_clock::now();
	}
	void restart()
	{
		start_point = std::chrono::high_resolution_clock::now();
	}
	long long check()
	{
		auto end_point = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();
		auto duration = end - start;
		return duration;
	}
};

template<int i>
class PeripheralDerived : public PeripheralDevice
{
public:
	PeripheralDerived(int, const std::string&, const std::string&, bool);
	void connect(Computer&) override;
	operator std::string() const override;
};
template<int i>
void peripheralConnector(Computer& computer, PeripheralDevice** pdArray, Timer& timer, long long& total_counter)
{
	PeripheralDerived<i>* pdi = new PeripheralDerived<i>(0, "", "", false);
	pdArray[i - 1] = pdi;
	TIME_THIS(pdi->connect(computer));
	peripheralConnector<i - 1>(computer, pdArray, timer, total_counter);
	return;
}
template<>
void peripheralConnector<1>(Computer& computer, PeripheralDevice** pdArray, Timer& timer, long long& total_counter)
{
	PeripheralDerived<1>* pdi = new PeripheralDerived<1>(0, "", "", false);
	pdArray[0] = pdi;
	TIME_THIS(pdi->connect(computer));
	return;

}

int main()
{
	if (!ID)
	{
		std::cout << "Don't forget to #DEFINE you id in Item.h!" << std::endl;
	}

	//Uncommenting this line will result in a lot of prints, the output itself is meaningless
	FILE* fp = freopen("benchmark_test.txt", "w", stdout);
	long long time_counter_sum = 0;
	long long max_count = -1;

	for (int test = 0; test < TEST_COUNT; test++)
	{
		STDCOUT("Test iteration: " << test)
			long long total_counter = 0;
		Timer timer;
		MainOffice& mo = MainOffice::getInstance();
		for (int c = 0; c < (BRANCHES_COUNT); c++)
		{
			std::string index = std::to_string(c);
			std::string location = "City" + index;
			Item** items = new Item * [ITEMS_COUNT];
			TIME_THIS(mo.addBranch(location, ITEMS_COUNT));
			Branch* branch = NULL;
			TIME_THIS(branch = &mo.getBranch(location));
			for (int i = 0; i < ITEMS_COUNT; i++)
			{
				if (i % 3 == 0)
				{
					items[i] = new Computer(i, "-", "-", i % 2, i % 10);
					TIME_THIS(branch->addItem(items[i]));
					continue;
				}
				if (i % 3 == 1)
				{
					items[i] = new Keyboard(i, "-", "-", i % 2, (i + 60) % 30);
					TIME_THIS(branch->addItem(items[i]));
					continue;

				}
				if (i % 3 == 2)
				{
					items[i] = new Mouse(i, "-", "-", i % 2, (i + 2000) % 1000);
					TIME_THIS(branch->addItem(items[i]));
					continue;

				}
				std::cout << i << std::endl;
				exit(0);
			}
			delete[] items;
		}
		for (int p = 0; p < PRINTS_COUNT; p++)
		{
			TIME_THIS(mo.printBranchesByLocation(&printless_print_branch_catalog));
			TIME_THIS(mo.printBranchesByValue(&printless_print_branch_catalog));
		}
		for (int p = 0; p < PRINTS_COUNT; p++)
		{
			TIME_THIS(mo.printBranchesByLocation(&printless_print_branch_catalog));
		}
		for (int p = 0; p < PRINTS_COUNT; p++)
		{
			TIME_THIS(mo.printBranchesByValue(&printless_print_branch_catalog));
		}
		for (int p = 0; p < FINEST_COUNT; p++)
		{
			Computer* cpt = new Computer(0, "", "", false, 0);
			Keyboard* kpt = new Keyboard(0, "", "", false, 0);
			Mouse* mpt = new Mouse(0, "", "", false, 0);

			std::string index = std::to_string(0);
			std::string location = "City" + index;
			const Branch& branch = mo.getBranch(location);

			Computer* crv = NULL;
			Keyboard* krv = NULL;
			Mouse* mrv = NULL;
			TIME_THIS(crv = branch.giveMeFinest(cpt));
			TIME_THIS(krv = branch.giveMeFinest(kpt));
			TIME_THIS(mrv = branch.giveMeFinest(mpt));
			delete cpt;
			delete kpt;
			delete mpt;
		}
		for (int c = 0; c < (BRANCHES_COUNT); c++)
		{
			std::string index = std::to_string(c);
			std::string location = "City" + index;
			TIME_THIS(mo.removeBranch(location));
		}
		for (int c = 0; c < CONNECTING_COUNT; c++)
		{
			PeripheralDevice* pdArray[PERIPHERALS];
			Computer* computer = new Computer(0, "", "", false, PERIPHERALS);
			peripheralConnector<PERIPHERALS>(*computer, pdArray, timer, total_counter);

			for (int p = 0; p < PRINTS_COUNT; p++)
			{
				TIME_THIS(computer->printConnected());
			}

			TIME_THIS(delete computer);
			for (int pi = 0; pi < PERIPHERALS; pi++) delete pdArray[pi];

			computer = new Computer(0, "", "", false, PERIPHERALS);
			peripheralConnector<PERIPHERALS>(*computer, pdArray, timer, total_counter);
			for (int pi = 0; pi < PERIPHERALS; pi++)
			{
				TIME_THIS(pdArray[pi]->disconnect());
				delete pdArray[pi];
			};
			delete computer;
		}

		STDCOUT("Test " << test << " time is: " << total_counter)
			if (max_count < total_counter)
				max_count = total_counter;
		time_counter_sum += total_counter;
	}
	double avg = (time_counter_sum - max_count) * (1 / double(TEST_COUNT - 1));
	STDCOUT("Your avg time is: " << avg)
		return 0;
}


template<int i>
PeripheralDerived<i>::PeripheralDerived
(int price, const std::string& manufacturer, const std::string& color, bool isWireless) :
	Item(price, manufacturer), PeripheralDevice(0, "0", color, isWireless) {}

template<int i>
void PeripheralDerived<i>::connect(Computer& computer)
{
	std::cout << "Connecting a peripheralDerived" << i << std::endl;
	PeripheralDevice::connect(computer);
}

template<int i>
PeripheralDerived<i>::operator std::string() const
{
	return PeripheralDevice::operator std::string() + ", PeripheralDeviceFactory" + std::to_string(i);
}
