#pragma once



/**
 * input: ������������� ����� � ����� ������� ������� (���� � ������� 1, 2, 3...)
 *
 * output: ���������� �����, ������� �� ����� ���������� �������
 *
 * ������� ����� ��� ��������� �������� ���������� ������� �� ����-���� �����
 *
 * @param number - ������������� ����� �����
 * @param digit - ����� �������
 */
int Getdigit(unsigned int number, int digit, int divider)
{
	for (digit; digit > 1; digit--)
	{
		number /= divider;
	}
	number %= divider;
	return number;
}

/**
 * input: ��������� �� ������ ������� ������ � ��������� �� ����� �������
 *
 * output: ��������������� ������� ������
 *
 * ������� ��������� �������� ����������� ���������� �� �������� �������� � �������
 * ��������� ��������� ������ ����� �����. � ������ ����������� �������� ������
 * ����������� � ������� ���������� ���������.
 * ������ �������, ��� ��������� ���������� ��� ���������� ������������� �����,
 * �������� ������� ������ ��������� � ������� �������� ����������� �������� ���� int,
 * ��������� ����� �������� � ��������������� ������ ���� unsigned int
 *
 * @param *first - ��������� �� ������ ������, �� ������ �������
 * @param *last - ��������� �� ��������� ������� �������
 */
void LSDSort(int* first, int length)
{
	int x;
    constexpr short max_short = std::numeric_limits<short>::max();
	constexpr int minimum_int = std::numeric_limits<int>::min();
	unsigned int* buffer = new unsigned int[length];
	unsigned int* first_u = new unsigned int[length];
    for (int i = 0; i < length; i++)
		first_u[i] = (first[i] - minimum_int);
	unsigned int *indexes_of_numbers = new unsigned int[max_short];
	unsigned int max = (first_u[0]);
	int digits = 0;
	for (int i = 1; i < length; i++)
		if (max < (first_u[i]))
			max = (first_u[i]);
	while (max != 0)
	{
		digits++;
		max /= max_short;
	}
	for (int i = 1; i <= digits; i++)
	{
		for (int j = 0; j < max_short; j++)
		{
			indexes_of_numbers[j] = 0;
		}
		for (int j = 0; j < length; j++)
		{
			indexes_of_numbers[Getdigit(first_u[j], i, max_short)]++;
		}
		int count = 0;
		for (int j = 0, temp; j < max_short; j++)
		{
			temp = indexes_of_numbers[j];
			indexes_of_numbers[j] = count;
			count += temp;
		}
		for (int j = 0; j < length; j++)
		{
			x = Getdigit(first_u[j], i, max_short);
			buffer[indexes_of_numbers[x]] = first_u[j];
			indexes_of_numbers[x]++;
		}
		for (int j = 0; j < length; j++)
			first_u[j] = buffer[j];
	}
	for (int j = 0; j < length; j++)
		first[j] =( first_u[j] +minimum_int);
}

//����� ����������, ������������ ��� ��������� � ����� ������ ���� int, ���������� ��������� �� ������� ����

struct check_stable
{
	int key;
	int check;
};

struct check_stable_buf
{
	unsigned int key;
	int check;
};

void LSDSort_check(check_stable* first, int length)
{
	int x;
	constexpr short max_short = std::numeric_limits<short>::max();
	constexpr int minimum_int = std::numeric_limits<int>::min();
	check_stable_buf*  buffer = new check_stable_buf[length];
	check_stable_buf* first_u = new check_stable_buf[length];
	for (int i = 0; i < length; i++)
	{
		first_u[i].key = (first[i].key - minimum_int);
		first_u[i].check = first[i].check;
	}
	unsigned int* indexes_of_numbers = new unsigned int[max_short];
	unsigned int max = (first_u[0]).key;
	int digits = 0;
	for (int i = 1; i < length; i++)
		if (max < (first_u[i].key))
			max = (first_u[i].key);
	while (max != 0)
	{
		digits++;
		max /= max_short;
	}
	for (int i = 1; i <= digits; i++)
	{
		for (int j = 0; j < max_short; j++)
		{
			indexes_of_numbers[j] = 0;
		}
		for (int j = 0; j < length; j++)
		{
			indexes_of_numbers[Getdigit(first_u[j].key, i, max_short)]++;
		}
		int count = 0;
		for (int j = 0, temp; j < max_short; j++)
		{
			temp = indexes_of_numbers[j];
			indexes_of_numbers[j] = count;
			count += temp;
		}
		for (int j = 0; j < length; j++)
		{
			x = Getdigit(first_u[j].key, i, max_short);
			buffer[indexes_of_numbers[x]] = first_u[j];
			indexes_of_numbers[x]++;
		}
		for (int j = 0; j < length; j++)
			first_u[j] = buffer[j];
		
	}
	for (int j = 0; j < length; j++)
	{
		first[j].key = (first_u[j].key + minimum_int);
		first[j].check = first_u[j].check;
	}

}