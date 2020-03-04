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

void random_numbers(int N = 10)
{
	srand(time(NULL));
	int *LSD_array_main = new int[N];
	int *Introsort_array_main = new int[N];
	int *Introsort_array_check= new int[N];
	check_stable* Introsort_array_stable = new check_stable[N];
	int x;
	for (int i = 0; i < N; i++)
	{
		x = rand();
		LSD_array_main[i] = x;
		Introsort_array_main[i] = x;
		Introsort_array_check[i] = x;
		Introsort_array_stable[i].key = x;
		Introsort_array_stable[i].check = i;
	}
	int LSD_time1, LSD_time2, Introsort_time1, Introsort_time2;
	LSD_time1 = clock();
	LSDSort(LSD_array_main, LSD_array_main + N - 1);
	LSD_time2 = clock();
	Introsort_time1 = clock();
	Introsort(Introsort_array_main, N);
	Introsort_time2 = clock();
	system("cls");
	std::cout << "LSDsort time: ";
	std::cout << LSD_time2 - LSD_time2 << std::endl;
	std::cout << "Introsort time ";
	std::cout << Introsort_time2 - Introsort_time1 << std::endl;
	std::cout << "Press any key to continue ";
	_getch();
	system("cls");
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
		case'1': random_numbers(10); break;
		case'2': random_numbers(1000); break;
		case'3': random_numbers(100000); break;
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