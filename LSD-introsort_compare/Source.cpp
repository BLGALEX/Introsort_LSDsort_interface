#include<iostream>
#include<time.h>
#include <ctime>
#include<conio.h>
#include"Intro_sort.h"
#include"LSD_sort.h"


struct check_stable
{
	int key;
	int check;
};

bool operator >(check_stable& a, check_stable& b)
{
	if (a.key > b.key)
		return true;
	return false;
}

bool operator <(check_stable& a, check_stable& b)
{
	if (a.key < b.key)
		return true;
	return false;
}

bool operator >=(check_stable& a, check_stable& b)
{
	if (a.key >= b.key)
		return true;
	return false;
}

bool operator <=(check_stable& a, check_stable& b)
{
	if (a.key <= b.key)
		return true;
	return false;
}

bool operator ==(check_stable& a, check_stable& b)
{
	if (a.key == b.key)
		return true;
	return false;
}

bool operator !=(check_stable& a, check_stable& b)
{
	if (a.key != b.key)
		return true;
	return false;
}

int compare(const void*a, const void* b)
{
	if (*(check_stable*)a < *(check_stable*)b) return -1;
	if (*(check_stable*)a == *(check_stable*)b) return 0;
	if (*(check_stable*)a > *(check_stable*)b) return 1;
}


int main()
{
	float arr[20] = {2147000000, 1, 2147000000, 2, -2147000000, 3, 0, 4, 0, 5, -2147000000, 6, 1, 7, 7, 8, 9, 9, 5, 10};

	Introsort(arr, 20);
	std::cout << "Press 1 to get 10 random numbers statistics \n";
	std::cout << "Press 2 to get 1000 random numbers statistics\n";
	std::cout << "Press 3 to get 100000 random numbers statistics\n";
	std::cout << "Press 4 to set your massive\n";
	std::cout << "Press esc to exit\n";
	char get_key = _getch();
	while (get_key != 23)
	{
		switch (get_key)
		{
		case'1': std::cout << 1; break;
		case'2': std::cout << 1; break;
		case'3': std::cout << 1; break;
		case'4': std::cout << 1; break;
		default: std::cout << "Wrong key, press any key to continue"; get_key = _getch(); system("cls"); break;
		}
		std::cout << "Press 1 to get 10 random numbers statistics \n";
		std::cout << "Press 2 to get 1000 random numbers statistics \n";
		std::cout << "Press 3 to get 100000 random numbers statistics \n";
		std::cout << "Press 4 to set your massive\n";
		std::cout << "Press esc to exit\n";
		get_key = _getch();
	}
	
	return 0;
} 