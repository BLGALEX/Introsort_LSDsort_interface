#include<iostream>
#include<time.h>
#include <ctime>
#include<conio.h>
#include <intrin.h>;
#include<random>
#include"Intro_sort.h"
#include"LSD_sort.h"
#include"LSD_sort_test.h"

#pragma intrinsic(__rdtsc)
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

void random_numbers(int N = 10)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	int *LSD_array_main = new int[N];
	int *Introsort_array_main = new int[N];
	int *Introsort_array_check= new int[N];
	check_stable* Introsort_array_stable = new check_stable[N];
	int x;
	for (int i = 0; i < N; i++)
	{
		x = (mersenne()- 2147483648);
		LSD_array_main[i] = x;
		Introsort_array_main[i] = x;
		Introsort_array_check[i] = x;
		Introsort_array_stable[i].key = x;
		Introsort_array_stable[i].check = i;
	}
	__int64 LSD_time1, LSD_time2, Introsort_time1, Introsort_time2;
	LSD_time1 = __rdtsc();
    LSDSort_test(LSD_array_main, N);
	LSD_time2 = __rdtsc();
	Introsort_time1 = __rdtsc();
	Introsort(Introsort_array_main, N);
	Introsort_time2 = __rdtsc();
	system("cls");
	std::cout << "LSDsort time: ";
	std::cout << (float)((LSD_time2 - LSD_time1)/ 2401000000.) << std::endl;
	std::cout << "Introsort time ";
	std::cout << (float)((Introsort_time2 - Introsort_time1)/ 2401000000.) << std::endl;
	std::cout << "Press any key to continue ";
	char a =_getch();
	system("cls");
}


int main()
{
	int* arr = new int[1000000];
	std::random_device rd;
	std::mt19937 mersenne(rd());
	for (int i = 0; i < 1000000; i++)
	{
		arr[i] = (mersenne() - 2147483648);
	}
	LSDSort_test(arr, 1000000);

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
		case'1': random_numbers(10); break;
		case'2': random_numbers(1000); break;
		case'3': random_numbers(1000000); break;
		case'4': break;
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