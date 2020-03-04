#include<iostream>
#include<time.h>
#include <ctime>
#include<conio.h>
#include"Intro_sort.h"
#include"LSD_sort.h"
#include"Introsort_template.h"

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

int comp(const void*a, const void* b)
{
	if (*(check_stable*)a < *(check_stable*)b) return -1;
	if (*(check_stable*)a == *(check_stable*)b) return 0;
	if (*(check_stable*)a > *(check_stable*)b) return 1;
}

int main()
{
	check_stable arr[10] = {2147000000, 1, 2147000000, 2, -2147000000, 3, 0, 4, 0, 5, -2147000000, 6, 1, 7, 7, 8, 9, 9, 5, 10};

	for (int i = 0; i < 10; i++)
	{
		arr[i].key = 0;
		arr[i].check = i;
	}

	qsort(arr, 10, 8, comp);
	Introsort_template(arr, 0, 9);

	return 0;
} 