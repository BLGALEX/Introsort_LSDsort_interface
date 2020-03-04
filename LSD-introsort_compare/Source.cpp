#include<iostream>
#include<time.h>
#include <ctime>
#include<conio.h>
#include"Intro_sort.h"
#include"LSD_sort.h"

int main()
{

	int arr[10000], k, check = 0;

	std::cout << "To enter your massive press 1 \n";
	std::cout << "To set random massive whith 50 numbers press any key \n";
	if (_getch() == '1')
	{
		unsigned short n = 0;
		std::cout << "Enter massive size \n";
		std::cin >> n;
		std::cout << "Enter massive \n";
		for (int i = 0; i < n; i++)
			std::cin >> arr[i];
		Introsort(arr, 0, n - 1);
		for (int i = 0; i < n; i++)
			std::cout << arr[i] << ' ';
	}
	else
	{
		srand(time(NULL));
		for (int i = 0; i < 50; i++)
		{
			k = rand() % 2;
			if (k == 1)
				arr[i] = -rand() % 1000;
			else
				arr[i] = rand() % 1000;
		}
		for (int i = 0; i < 50; i++)
			std::cout << arr[i] << ' ';
		Introsort(arr, 0, 49);
		std::cout << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 50; i++)
			std::cout << arr[i] << ' ';
	}
	return 0;
} //etg