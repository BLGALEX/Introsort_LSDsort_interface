#pragma once
#include<iostream>


// ����� �.�. �8118-09.03.04������(2)

/**
 * ������ �������� ��������������� ���������� �������� ��� ����� �����
 * ��� ������� ��������� �������� ����������
 *
 */

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
template<class T>
void swap(T* a, T* b)
{
	T temp = a[0];
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
template<class T>
void HeapSetUp(T* left, T* right) // �������� � ����, ����� a[i] <= a[2*i+1] && a[i] <=a[i*2+2]
{
	int n = (((int)right - (int)left) / sizeof(T)) + 1;
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
template<class T>
void HeapSort(T* left, T* right)
{
	HeapSetUp(left, right);// ������� �������� � ����, ��� ������� �������� �����
	int n = ((int)right - (int)left) / sizeof(T) + 1;
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
template <class T>
void realIntrosort(T* arr, int left, int right, int actuall_len, int deep)
{
	if (log(actuall_len) < deep)
	{
		HeapSort(arr + left, arr + right);
	}
	else
	{
		T pivot; // ����������� �������
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
		int piv = left;
		left = l_hold;
		right = r_hold;
		deep++;
		if (left < piv) // ���������� �������� ���������� ��� ����� � ������ ����� �������
			realIntrosort(arr, left, piv - 1, actuall_len, deep);
		if (right > piv)
			realIntrosort(arr, piv + 1, right, actuall_len, deep);

	}
}

/**
 * ������� ������: ��������� �� ������ ������� � ������ ������� �������
 *
 * �������� ������: ��������������� ������
 *
 * ������� ������� ������� ��������� � ������� ������� � �������� ������ �������, ������� ��� ��������� ����������
 *
 * @param *arr - ��������� �� ������ ������
 * @param n - ���������� ��������� � �������
 */
template<class T>
void Introsort(T* arr, int n)
{
	realIntrosort(arr, 0, n - 1, n, 1);
}



/**
 * ����� ��� ������ ��������������� ����������, �� �� ���������� 
 * ��� ������� � ���������
 */

template<class T>
void HeapSetUp_count(T* left, T* right, int* compare, int* swaps) // �������� � ����, ����� a[i] <= a[2*i+1] && a[i] <=a[i*2+2]
{
	int n = (((int)right - (int)left) / sizeof(T)) + 1;	
	for (int i = n / 2 - 1; i >= 0; i--) // �������� ���������� � n/2-1 ��������
	{
		for (int j = i; j <= n / 2 - 1; )
		{
			if ((j * 2 + 2) > (n - 1))
			{
				if (left[j * 2 + 1] < left[j])
				{
					swap(&left[j * 2 + 1], &left[j]);
					swaps[0]++;
					j = j * 2 + 1;
					compare[0]++;
				}
				else { compare[0]++; break;}
			}
			else if (left[j * 2 + 1] < left[j * 2 + 2] && (left[j * 2 + 1] < left[j]))
			{
				swap(&left[j * 2 + 1], &left[j]);
				j = j * 2 + 1;
				swaps[0]++;
				compare[0] += 2;
			}
			else if (left[j * 2 + 2] < left[j])
			{
				swap(&left[j * 2 + 2], &left[j]);
				j = j * 2 + 2;
				swaps[0]++;
				compare[0] += 3;
			}
			else {compare[0] += 3; break;}
		}
	}
}


template<class T>
void HeapSort_count(T* left, T* right, int* compare, int* swaps)
{
	HeapSetUp_count(left, right,  compare, swaps);// ������� �������� � ����, ��� ������� �������� �����
	int n = ((int)right - (int)left) / sizeof(T) + 1;
	for (int i = n; i > 0; i--)//����� ������ �������� ������ ���������� ��������������� � ����� �� ��� �� ���� �������
		//������� �� �������� ������ ��� � ������� ������� �� 1 ������� � �����
	{
		swap(&left[0], &left[i - 1]);// ������ ���������� ������� �������� ������ � ����� � ������� � ����� ���������� ����� �� ���������� ������
		swaps[0]++;
		for (int j = 0; j < (i + 1) / 2 - 1; )
		{
			if ((j * 2 + 2) >= (i - 1))
			{
				if (left[j * 2 + 1] < left[j])
				{
					swap(&left[j * 2 + 1], &left[j]);
					j = j * 2 + 1;
					swaps[0]++;
					compare[0] ++;
				}
				else { compare[0]++; break; }
			}
			else if (left[j * 2 + 1] < left[j * 2 + 2] && (left[j * 2 + 1] < left[j]))
			{
				swap(&left[j * 2 + 1], &left[j]);
				j = j * 2 + 1;
				swaps[0]++;
				compare[0] += 2;
			}
			else if (left[j * 2 + 2] < left[j])
			{
				swap(&left[j * 2 + 2], &left[j]);
				j = j * 2 + 2;
				swaps[0]++;
				compare[0] += 3;
			}
			else { compare[0] += 3; break; }
		}
	}
	for (int i = 0; i < n / 2; i++) //���������� ������ � �����
		swap(&left[i], &left[n - i - 1]);
}


template <class T>
void realIntrosort_count(T* arr, int left, int right, int actuall_len, int deep, int* compare, int* swaps)
{
	if (log(actuall_len) < deep)
	{
		HeapSort_count(arr + left, arr + right, compare, swaps);
	}
	else
	{
		T pivot; // ����������� �������
		int l_hold = left; //����� �������
		int r_hold = right; // ������ �������
		pivot = arr[left];
		while (left < right) // ���� ������� �� ���������
		{
			while ((arr[right] >= pivot) && (left < right))
			{
				compare[0]++; 
				right--;// �������� ������ ������� ���� ������� [right] ������ [pivot]
			} 
			if (left != right) // ���� ������� �� ����������
			{
				arr[left] = arr[right]; // ���������� ������� [right] �� ����� ������������
				left++; // �������� ����� ������� ������
				swaps[0]++;
			}
			while ((arr[left] <= pivot) && (left < right))
			{
				left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
				compare[0]++;
			}
			if (left != right) // ���� ������� �� ����������
			{
				arr[right] = arr[left]; // ���������� ������� [left] �� ����� [right]
				right--; // �������� ������ ������� ������
				swaps[0]++;
			}
		}
		arr[left] = pivot; // ������ ����������� ������� �� �����
		int piv = left;
		left = l_hold;
		right = r_hold;
		deep++;
		if (left < piv) // ���������� �������� ���������� ��� ����� � ������ ����� �������
			realIntrosort_count(arr, left, piv - 1, actuall_len, deep, compare, swaps);
		if (right > piv)
			realIntrosort_count(arr, piv + 1, right, actuall_len, deep, compare, swaps);

	}
}

template<class T>
void Introsort_count(T* arr, int n, int* compare, int *swaps)
{
	realIntrosort_count(arr, 0, n - 1, n, 1, compare, swaps );
}