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
	cout << "Введите длину массива n: ";
	cin >> n;
	long long int* is = new long long int[n]; // Insertion sort

	//рандомное заполнение массива
	srand(time(NULL));
	for (long long int i = 0; i < n; i++)
	{
		int num = rand() % 100 + 1; // случайные числа от 0 до 100
		is[i] = num;
	}

	addItems(is, n, "decrease"); // Упорядоченное заполнение массива
	//print_arr(is, n, "Начальный массив");
	//insertionSort(is, n); // Сортировка вставками
	//print_arr(is, n, "Insertion sort сортированный");
	//shellSort(is, n); // Shell Sort
	//print_arr(is, n, "Shell Sort сортированный");
	mergeSort(is, n); // Merge Sort
	//print_arr(is, n, "Merge Sort сортированный");
	delete[] is;
	system("pause");
}

void print_arr(long long int* mass, long long int len, string name) { // вывод массива на экран
	cout << "------Ввывод массива (начало) " << name << " ------" << endl;
	for (long long int i = 0; i < len; i++) {
		cout << "mass[" << i << "]=" << mass[i] << endl;
	}
	cout << "------Ввывод массива (конец) " << name << " ------" << endl;
}

void insertionSort(long long int* arrayPtr, long long int length) // сортировка вставками
{
	int sf = 0, mf = 0;
	int t1 = clock();
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		sf+= 4;
		while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			mf+= 5;
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
	int t2 = clock();
	cout << "Время на выполнение сортировки вставками (миллисекунды): " << t2 - t1 << endl;
	cout << "подсчет фактического количества операций сравнения Сф=" << sf << " количество операций перемещения Мф=" << mf << endl;
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
// inc[] массив, в который заносятся инкременты
// size размерность этого массива
 int p1, p2, p3, s;
  
  p1 = p2 = p3 = 1;
  s = -1;
  do {// заполняем массив элементов по формуле Роберта Седжвика
    if (++s % 2) {
      inc[s] = 8*p1 - 6*p2 + 1;
    } else {
      inc[s] = 9*p1 - 9*p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
    p1 *= 2;
// заполняем массив, пока текущая инкремента хотя бы в 3 раза меньше количества элементов в массиве
  } while(3*inc[s] < size);
  
  return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}
  
template<class T>
void shellSort(T a[], long size) {
// inc инкремент, расстояние между элементами сравнения
// i и j стандартные переменные цикла
// seq[40] массив, в котором хранятся инкременты
  long inc, i, j, seq[40];
  int s;//количество элементов в массиве seq[40]
  int t1 = clock();
  int sf = 0, mf = 0, ss = 0;
  
  // вычисление последовательности приращений
  s = increment(seq, size);
  while (s >= 0) {
    //извлекаем из массива очередную инкременту
    inc = seq[s--];
	sf += 3;
// сортировка вставками с инкрементами inc
    for (i = inc; i < size; i++) {
      T temp = a[i];
// сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
	  for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc) {
		  a[j + inc] = a[j];
		  ss += 3;
	  }
// после всех сдвигов ставим на место j+inc элемент, который находился на i месте
      a[j+inc] = temp;
	  mf += 4;
    }
  }
  int t2 = clock();
  cout << "Время на выполнение Shell сортировки (миллисекунды): " << t2 - t1 << endl;
  cout << "Кол-во операций sf=" << sf << " количество операций mf=" << mf << " количество операций ss=" << ss << endl;
}

// Метод восходящего слияния
void mergeSort(long long int* a, long long int n)
{
	int t1 = clock();
	long long int sf = 0, mf = 0, ss = 0;
	int step = 1;  // шаг разбиения последовательности
	int* temp = (int*)malloc(n * sizeof(int)); // дополнительный массив
	while (step < n)  // пока шаг меньше длины массива
	{
		int index = 0;    // индекс результирующего массива
		int l = 0;      // левая граница участка
		int m = l + step;  // середина участка
		int r = l + step * 2;  // правая граница участка
		sf += 7;
		do
		{
			mf += 8;
			m = m < n ? m : n;  // сортируемый участок не выходит за границы последовательности
			r = r < n ? r : n;
			int i1 = l, i2 = m; // индексы сравниваемых элементов
			for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
			{
				ss += 4;
				if (a[i1] < a[i2]) { temp[index++] = a[i1++]; } // заполняем участок результирующей последовательности
				else { temp[index++] = a[i2++]; }
			}
			// Или i1 < m или i2 < r - только один из операторов while может выполниться
			while (i1 < m) temp[index++] = a[i1++]; ss += 3; // заносим оставшиеся элементы сортируемых участков
			while (i2 < r) temp[index++] = a[i2++]; ss += 3; // в результирующий массив
			l += step * 2; // перемещаемся на следующий сортируемый участок
			m += step * 2;
			r += step * 2;
		} while (l < n); // пока левая граница сортируемого участка - в пределах последоватльности
		for (int i = 0; i < n; i++) { // переносим сформированный массив обратно в a
			a[i] = temp[i];
			mf += 3;
		}
		step *= 2; // увеличиваем в 2 раза шаг разбиения
	}
	int t2 = clock();
	cout << "Время на выполнение Merge сортировки (миллисекунды): " << t2 - t1 << endl;
	cout << "Кол-во операций sf=" << sf << " количество операций mf=" << mf << " количество операций ss=" << ss << endl;
}