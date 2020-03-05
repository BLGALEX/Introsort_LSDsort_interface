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
int Getdigit_test(unsigned int number, int digit, int divider)
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
void LSDSort_test(int* first, int length)
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
			indexes_of_numbers[Getdigit_test(first_u[j], i, max_short)]++;
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
			x = Getdigit_test(first_u[j], i, max_short);
			buffer[indexes_of_numbers[x]] = first_u[j];
			indexes_of_numbers[x]++;
		}
		for (int j = 0; j < length; j++)
			first_u[j] = buffer[j];
	}
	for (int j = 0; j < length; j++)
		first[j] =( first_u[j] +minimum_int);
}



