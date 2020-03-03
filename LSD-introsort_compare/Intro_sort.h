#ifndef Intro_sort
#define Intro_sort

// ����� �.�. �8118-09.03.04������(2)

/**
 * ������� ������: ��� ��������� �� ������ ������
 *
 * �������� ������: ��� ������ ������
 *
 * ������ ������� ������, ���������� � ���� ������� ������
 *
 * @param *a - ��������� �� ������ ������
 * @param *b - ��������� �� ������ ������
 */
void swap(int* a, int* b)
{
	int temp = a[0];
	a[0] = b[0];
	b[0] = temp;
}

/**
 * ������� ������: ��������� �� ������ ������� ������� ������� � ��������� �� ��������� ������� ������� �������
 *
 * �������� ������: ����� ������� ���������� � ����, ��� ����� ����� ������� �����
 *
 * ������� ������� �� n/2-1 �������� �������� "����������" �� ����� �����, ����� �������� ������ ����������
 *
 * @param *left - ��������� �� ������ ������� ������� �������
 * @param *right - ��������� �� ��������� ������� ������� �������
 */
void HeapSetUp(int* left, int* right) // �������� � ����, ����� a[i] <= a[2*i+1] && a[i] <=a[i*2+2]
{
	int n = ((int)right - (int)left) / sizeof(int) + 1;
	for (int i = n / 2 - 1; i >= 0; i--) // �������� ���������� � n/2-1 ��������
	{
		for (int j = i; j <= n / 2 - 1; )
		{
			if ((j * 2 + 2) > (n - 1))
			{
				if (left[j * 2 + 1] < left[j])
				{
					swap(&left[j * 2 + 1], &left[j]);
					j = j * 2 + 1;
				}
				else break;
			}
			else if (left[j * 2 + 1] < left[j * 2 + 2] && (left[j * 2 + 1] < left[j]))
			{
				swap(&left[j * 2 + 1], &left[j]);
				j = j * 2 + 1;
			}
			else if (left[j * 2 + 2] < left[j])
			{
				swap(&left[j * 2 + 2], &left[j]);
				j = j * 2 + 2;
			}
			else break;
		}
	}
}

/**
 * ������� ������: ��������� �� ������ ������� ������� ������� � ��������� �� ��������� ������� ������� �������
 *
 * �������� ������: ��������������� ����� �������
 *
 * ������� ������ ������� 1 � ��������� ������� �������� ������ � "����������" ����� ������� ����� ������,
 * ������ �������� ����������� �� ���� (�� ���� ������ ������� ������� ��������� �� ������� �����).
 * ��� ����������� �� ��� ���, ���� ����� �� ����� �������� �� ������ ��������
 *
 * @param *left - ��������� �� ������ ������� ������� �������
 * @param *right - ��������� �� ��������� ������� ������� �������
 */
void HeapSort(int* left, int* right)
{
	HeapSetUp(left, right);// ������� �������� � ����, ��� ������� �������� �����
	int n = ((int)right - (int)left) / sizeof(int) + 1;
	for (int i = n; i > 0; i--)//����� ������ �������� ������ ���������� ��������������� � ����� �� ��� �� ���� �������
		//������� �� �������� ������ ��� � ������� ������� �� 1 ������� � �����
	{
		swap(&left[0], &left[i - 1]); // ������ ���������� ������� �������� ������ � ����� � ������� � ����� ���������� ����� �� ���������� ������
		for (int j = 0; j < (i + 1) / 2 - 1; )
		{
			if ((j * 2 + 2) >= (i - 1))
			{
				if (left[j * 2 + 1] < left[j])
				{
					swap(&left[j * 2 + 1], &left[j]);
					j = j * 2 + 1;
				}
				else break;
			}
			else if (left[j * 2 + 1] < left[j * 2 + 2] && (left[j * 2 + 1] < left[j]))
			{
				swap(&left[j * 2 + 1], &left[j]);
				j = j * 2 + 1;
			}
			else if (left[j * 2 + 2] < left[j])
			{
				swap(&left[j * 2 + 2], &left[j]);
				j = j * 2 + 2;
			}
			else break;
		}
	}
	for (int i = 0; i < n / 2; i++) //���������� ������ � �����
		swap(&left[i], &left[n - i - 1]);
}

/**
 * ������� ������: ��������� �� ������ ������� � ����� �������� � �������� ����� ���������� � ����� ������� �� �������� ����� �����������
 * � ����� ���������� ��������� ������� ��� ������ ������ ������� � ������� ��������
 *
 * �������� ������: ��������������� ����� �������
 *
 * ������� � ���������� �� ������� �������� ��������� ������� ������� ������� ����������� � �������� ���� ����, ���� ���������
 * ��� ��������� ������� ������� ������������� ����������� � ������� ������ ��������������� ���������
 *
 * @param *arr - ��������� �� ������ ������
 * @param left - ����� ������� �������� ������� � ������
 * @param right - ����� ���������� �������� ������� � ������
 * @param actuall_len - ����������� ���������� ��������� �������
 * @param deep - ������� �������� (���������� == 1)
 */
void realIntrosort(int* arr, int left, int right, int actuall_len, int deep)
{
	if (log(actuall_len) < deep)
	{
		HeapSort(arr + left, arr + right);
	}
	else
	{
		int pivot; // ����������� �������
		int l_hold = left; //����� �������
		int r_hold = right; // ������ �������
		pivot = arr[left];
		while (left < right) // ���� ������� �� ���������
		{
			while ((arr[right] >= pivot) && (left < right))
				right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
			if (left != right) // ���� ������� �� ����������
			{
				arr[left] = arr[right]; // ���������� ������� [right] �� ����� ������������
				left++; // �������� ����� ������� ������
			}
			while ((arr[left] <= pivot) && (left < right))
				left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
			if (left != right) // ���� ������� �� ����������
			{
				arr[right] = arr[left]; // ���������� ������� [left] �� ����� [right]
				right--; // �������� ������ ������� ������
			}
		}
		arr[left] = pivot; // ������ ����������� ������� �� �����
		pivot = left;
		left = l_hold;
		right = r_hold;
		deep++;
		if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
			realIntrosort(arr, left, pivot - 1, actuall_len, deep);
		if (right > pivot)
			realIntrosort(arr, pivot + 1, right, actuall_len, deep);

	}
}

/**
 * ������� ������: ��������� �� ������ ������� � ����� �������� � �������� ����� ���������� � ����� ������� �� �������� ����� �����������
 *
 * �������� ������: ��������������� ����� �������
 *
 * ������� ������� ������� ��������� � ������� ������� � �������� ������ �������, ������� ��� ��������� ����������
 *
 * @param *arr - ��������� �� ������ ������
 * @param left - ����� ������� �������� ������� � ������
 * @param left - ����� ���������� �������� ������� � ������
 */
void Introsort(int* arr, int left, int right)
{
	int n = right - left + 1;
	realIntrosort(arr, left, right, n, 1);
}



#endif