#include <iostream>
#include <ctime>

using namespace std;

void print_arr(long long int* mass, long long int len, string name = "");
void insertionSort(long long int*, long long int);
void addItems(long long int* mass, long long int length, string sort = "increase");
int increment(long inc[], long size);
void mergeSort(long long int* a, long long int n);
template<class T>
void shellSort(T a[], long size);


int main()
{
	setlocale(LC_ALL, "Russian");
	long long int n;
	cout << "������� ����� ������� n: ";
	cin >> n;
	long long int* is = new long long int[n]; // Insertion sort

	//��������� ���������� �������
	srand(time(NULL));
	for (long long int i = 0; i < n; i++)
	{
		int num = rand() % 100 + 1; // ��������� ����� �� 0 �� 100
		is[i] = num;
	}

	addItems(is, n, "decrease"); // ������������� ���������� �������
	//print_arr(is, n, "��������� ������");
	//insertionSort(is, n); // ���������� ���������
	//print_arr(is, n, "Insertion sort �������������");
	//shellSort(is, n); // Shell Sort
	//print_arr(is, n, "Shell Sort �������������");
	mergeSort(is, n); // Merge Sort
	//print_arr(is, n, "Merge Sort �������������");
	delete[] is;
	system("pause");
}

void print_arr(long long int* mass, long long int len, string name) { // ����� ������� �� �����
	cout << "------������ ������� (������) " << name << " ------" << endl;
	for (long long int i = 0; i < len; i++) {
		cout << "mass[" << i << "]=" << mass[i] << endl;
	}
	cout << "------������ ������� (�����) " << name << " ------" << endl;
}

void insertionSort(long long int* arrayPtr, long long int length) // ���������� ���������
{
	int sf = 0, mf = 0;
	int t1 = clock();
	int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
		item; // ������ ����������� ��������
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = counter - 1; // ���������� ������ ����������� �������� �������
		sf+= 4;
		while (item >= 0 && arrayPtr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			mf+= 5;
			arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� �������
			arrayPtr[item] = temp;
			item--;
		}
	}
	int t2 = clock();
	cout << "����� �� ���������� ���������� ��������� (������������): " << t2 - t1 << endl;
	cout << "������� ������������ ���������� �������� ��������� ��=" << sf << " ���������� �������� ����������� ��=" << mf << endl;
}

void addItems(long long int* mass, long long int length, string sort)
{
	if (sort == "increase")
	{
		for (long long int i = 0; i < length; i++)
		{
			mass[i] = i + 1;
		}
	}
	else if (sort == "decrease")
	{
		for (long long int i = length; i > 0; i--)
		{
			mass[length - i] = i;
		}
	}
}
int increment(long inc[], long size) {
// inc[] ������, � ������� ��������� ����������
// size ����������� ����� �������
 int p1, p2, p3, s;
  
  p1 = p2 = p3 = 1;
  s = -1;
  do {// ��������� ������ ��������� �� ������� ������� ��������
    if (++s % 2) {
      inc[s] = 8*p1 - 6*p2 + 1;
    } else {
      inc[s] = 9*p1 - 9*p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
    p1 *= 2;
// ��������� ������, ���� ������� ���������� ���� �� � 3 ���� ������ ���������� ��������� � �������
  } while(3*inc[s] < size);
  
  return s > 0 ? --s : 0;// ���������� ���������� ��������� � �������
}
  
template<class T>
void shellSort(T a[], long size) {
// inc ���������, ���������� ����� ���������� ���������
// i � j ����������� ���������� �����
// seq[40] ������, � ������� �������� ����������
  long inc, i, j, seq[40];
  int s;//���������� ��������� � ������� seq[40]
  int t1 = clock();
  int sf = 0, mf = 0, ss = 0;
  
  // ���������� ������������������ ����������
  s = increment(seq, size);
  while (s >= 0) {
    //��������� �� ������� ��������� ����������
    inc = seq[s--];
	sf += 3;
// ���������� ��������� � ������������ inc
    for (i = inc; i < size; i++) {
      T temp = a[i];
// �������� �������� �� ��� ���, ���� �� ������ �� ����� ��� �� ���������� � ������ �������
	  for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc) {
		  a[j + inc] = a[j];
		  ss += 3;
	  }
// ����� ���� ������� ������ �� ����� j+inc �������, ������� ��������� �� i �����
      a[j+inc] = temp;
	  mf += 4;
    }
  }
  int t2 = clock();
  cout << "����� �� ���������� Shell ���������� (������������): " << t2 - t1 << endl;
  cout << "���-�� �������� sf=" << sf << " ���������� �������� mf=" << mf << " ���������� �������� ss=" << ss << endl;
}

// ����� ����������� �������
void mergeSort(long long int* a, long long int n)
{
	int t1 = clock();
	long long int sf = 0, mf = 0, ss = 0;
	int step = 1;  // ��� ��������� ������������������
	int* temp = (int*)malloc(n * sizeof(int)); // �������������� ������
	while (step < n)  // ���� ��� ������ ����� �������
	{
		int index = 0;    // ������ ��������������� �������
		int l = 0;      // ����� ������� �������
		int m = l + step;  // �������� �������
		int r = l + step * 2;  // ������ ������� �������
		sf += 7;
		do
		{
			mf += 8;
			m = m < n ? m : n;  // ����������� ������� �� ������� �� ������� ������������������
			r = r < n ? r : n;
			int i1 = l, i2 = m; // ������� ������������ ���������
			for (; i1 < m && i2 < r; ) // ���� i1 �� ����� �� �������� � i2 �� ����� �� �����
			{
				ss += 4;
				if (a[i1] < a[i2]) { temp[index++] = a[i1++]; } // ��������� ������� �������������� ������������������
				else { temp[index++] = a[i2++]; }
			}
			// ��� i1 < m ��� i2 < r - ������ ���� �� ���������� while ����� �����������
			while (i1 < m) temp[index++] = a[i1++]; ss += 3; // ������� ���������� �������� ����������� ��������
			while (i2 < r) temp[index++] = a[i2++]; ss += 3; // � �������������� ������
			l += step * 2; // ������������ �� ��������� ����������� �������
			m += step * 2;
			r += step * 2;
		} while (l < n); // ���� ����� ������� ������������ ������� - � �������� �����������������
		for (int i = 0; i < n; i++) { // ��������� �������������� ������ ������� � a
			a[i] = temp[i];
			mf += 3;
		}
		step *= 2; // ����������� � 2 ���� ��� ���������
	}
	int t2 = clock();
	cout << "����� �� ���������� Merge ���������� (������������): " << t2 - t1 << endl;
	cout << "���-�� �������� sf=" << sf << " ���������� �������� mf=" << mf << " ���������� �������� ss=" << ss << endl;
}