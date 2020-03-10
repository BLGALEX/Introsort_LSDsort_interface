#include<iostream>
#include<time.h>
#include <ctime>
#include<conio.h>
#include <intrin.h>;
#include<random>
#include"Intro_sort.h"
#include"LSD_sort.h"


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
	check_stable* LSDt_array_stable = new check_stable[N];
	int x;
	for (int i = 0; i < N; i++)
	{
		x = (mersenne()- 2147483648);
		LSD_array_main[i] = x;
		Introsort_array_main[i] = x;
		Introsort_array_check[i] = x;
		Introsort_array_stable[i].key = x;
		Introsort_array_stable[i].check = i;
		LSDt_array_stable[i].key = x;
		LSDt_array_stable[i].check = i;
	}
	__int64 LSD_time1, LSD_time2, Introsort_time1, Introsort_time2;
	LSD_time1 = __rdtsc();
    LSDSort(LSD_array_main, N);
	LSD_time2 = __rdtsc();
	Introsort_time1 = __rdtsc();
	Introsort(Introsort_array_main, N);
	Introsort_time2 = __rdtsc();
	int swaps = 0, compare = 0;
	Introsort_count(Introsort_array_check, N, &compare, &swaps);
	system("cls");
	std::cout << N << "  elements \n";
	std::cout << "LSDsort time: ";
	std::cout << (float)((LSD_time2 - LSD_time1)/ 2401000000.) << std::endl;
	std::cout << "Introsort time ";
	std::cout << (float)((Introsort_time2 - Introsort_time1)/ 2401000000.) << std::endl;
	std::cout << "Introsort swaps: " << swaps<< std::endl;
	std::cout << "Introsort compares: " << compare << std::endl << std::endl;
	std::cout << "Press 1 to continue \n";
	std::cout << "Press 2 to check Introsort stability \n";
	std::cout << "Press 3 to check LSD-sort stability \n";
	char a = _getch();
	while (a != '1')
	{
		if (a == '2')
		{
			Introsort(Introsort_array_stable, N);
			for (int i = 0; i < N; i++)
				std::cout << Introsort_array_stable[i].key << "  " << Introsort_array_stable[i].check << std::endl;
		}
		else if (a == '3')
		{
			Introsort(Introsort_array_stable, N);
			for (int i = 0; i < N; i++)
				std::cout << Introsort_array_stable[i].key <<"  " << Introsort_array_stable[i].check << std::endl;
		}
		std::cout << "Press any key to continue";
		a = _getch();
		system("cls");
		std::cout << N << "elements \n";
		std::cout << "LSDsort time: ";
		std::cout << (float)((LSD_time2 - LSD_time1) / 2401000000.) << std::endl;
		std::cout << "Introsort time ";
		std::cout << (float)((Introsort_time2 - Introsort_time1) / 2401000000.) << std::endl;
		std::cout << "Introsort swaps: " << swaps << std::endl;
		std::cout << "Introsort compares: " << compare << std::endl << std::endl;
		std::cout << "Press 1 to continue \n";
		std::cout << "Press 2 to check Introsort stability \n";
		std::cout << "Press 3 to check LSD-sort stability \n";
		a = _getch();
	}
	
	system("cls");
}


int main()
{
	int* arr = new int[10000];
	std::random_device rd;
	std::mt19937 mersenne(rd());
	for (int i = 0; i < 10000; i++)
	{
		arr[i] = (mersenne() - 2147483648);
	}
	int swaps = 0, compare = 0;
	Introsort_count(arr, 10000, &compare, &swaps);

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