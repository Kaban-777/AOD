#include <iostream>
using namespace std;


/*
* односвязный список
* реализация
*/


template<typename T>
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(T data);

	//добавление элемента в список по указанному индексу
	void insert(T data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

	//перестановка первых к элементов в конец
	void move_back(int k);

	//переставление местами самой малой переменной с самой большой
	void change();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::move_back(int k) {
	for (int i = 0; i < k; i++) {
		push_back(operator[](i));
	}
	for (int i = 0; i < k; i++) {
		pop_front();
	}

}

template<typename T>
void List<T>::change() {
	float max = operator[](0);
	float min = operator[](0);
	int imax, imin;
	for (int i = 0; i < GetSize(); i++) {
		if (max < operator[](i)) {
			max = operator[](i);
			imax = i;
		}
		if (min > operator[](i)) {
			min = operator[](i);
			imin = i;
		}
	}
	insert(max, imin);
	removeAt(imin + 1);
	insert(min, imax);
	removeAt(imax + 1);
}



int main()
{

	setlocale(LC_ALL, "ru");


	List<float> lst;
	lst.push_front(5.0);
	lst.push_front(7.0);
	lst.push_front(101.0);
	lst.push_front(20.0);
	lst.push_front(76.0);
	lst.push_front(45.0);

	cout << "Список чисел с плавающей точкой:\n\n";

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	char f, a;

	while (1) {

		cout << endl;
		cout << "Выберите команду для программы:" << endl << "(1) - перестановка первых k элемнтов в конец" << endl << "(2) - удаление предпоследнего элемента" << endl << "(3) - переставление местами самой малой переменной с самой большой" << endl << "(4) - удаление последнего элемента в списке\n(5) - добавление элемента в конец списка\n(6) - удаление элемента по индексу\n(7) - очистка списка";
		cout << endl << "\nВведите n для окончания работы" << endl;
		cin >> f;
		if (f == 'n')
			break;

		if (f < '8' && f > '0') {
			switch (f) {
			case '1':
				cout << "\nВведите количество элементов k, не большее чем: " << lst.GetSize() - 1 << endl;
				int k;
				cin >> k;
				if (k == 'n')
					break;
				if (!isdigit(k))
					break;
				if (k < lst.GetSize() && k > 0) {
					lst.move_back(k);
				}
				else
					cout << "\nВы ввели неверное значение.\n";
				break;
			case '2':
				lst.removeAt(lst.GetSize() - 2);
				break;
			case '3':
				lst.change();
				break;
			case '4':
				lst.pop_back();
				break;
			case '5':
				cout << "\nВведите желаемое число с плавающей точкой, для добавления в список:\n";
				float j;
				cin >> j;
				if (j == 'n')
					break;
				if (isdigit(j))
					lst.push_back(j);
				else
					cout << "\nВы ввели неверное значение.\n";
				break;
			case '6':
				cout << "\nВведите какой элемент вы хотите удалить, начиная с первого.\n";
				int h;
				cin >> h;
				if (h == 'n')
					break;
				if (h < lst.GetSize() && h > 0)
					lst.removeAt(h - 1);
				else
					cout << "\nВы ввели неверное значение.\n";
				break;
			case '7':
				lst.clear();
			}

			cout << endl;

			cout << "Список чисел с плавающей точкой:\n\n";

			for (int i = 0; i < lst.GetSize(); i++)
			{
				cout << lst[i] << endl;
			}

			cout << endl;
		}
		else
			cout << "\nВы ввели неверное значение.\n";
	}

	return 0;
}
