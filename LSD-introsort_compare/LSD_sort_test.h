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
int Getdigit_test(int number, int digit)
{
	for (digit; digit > 1; digit--)
	{
		number /= 32768;
	}
	number %= 32768;
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
void LSDSort_test(int* first_u, int length)
{
	int x;
	//int minimum_int = std::numeric_limits<int>::min();
	unsigned int* buffer = new unsigned int[length];
	//unsigned int* first_u = new unsigned int[length];
	//for (int i = 0; i < length; i++)
	//	first_u[i] = first[i] - minimum_int;
	int indexes_of_numbers[32768];
	int max = (first_u[0]);
	int digits = 0;
	for (int i = 1; i < length; i++)
		if (max < (first_u[i]))
			max = (first_u[i]);
	while (max != 0)
	{
		digits++;
		max /= 32768;
	}
	for (int i = 1; i <= digits; i++)
	{
		for (int j = 0; j < 32768; j++)
		{
			indexes_of_numbers[j] = 0;
		}
		for (int j = 0; j < length; j++)
		{
			indexes_of_numbers[Getdigit_test(first_u[j], i)]++;
		}
		int count = 0;
		for (int j = 0, temp; j < 32768; j++)
		{
			temp = indexes_of_numbers[j];
			indexes_of_numbers[j] = count;
			count += temp;
		}
		for (int j = 0; j < length; j++)
		{
			x = Getdigit_test(first_u[j], i);
			buffer[indexes_of_numbers[x]] = first_u[j];
			indexes_of_numbers[x]++;
		}
		for (int j = 0; j < length; j++)
			first_u[j] = buffer[j];
	}
	//for (int j = 0; j < length; j++)
		//first[j] =( first_u[j] +minimum_int);
}



