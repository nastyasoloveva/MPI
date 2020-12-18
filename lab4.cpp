#include <iostream>
using namespace std;

template <class T>
struct Root {
	Root(T data_ = NULL, Root<T>* next_ = nullptr) {
		data = data_;
		next = next_;
	}
	Root(Root<T>& root) {
		data = root.data;
		next = root.next;
	}
public:
	T data;
	Root<T>* next;
};


template <class T>
class Stack {
public:
	Stack() {
		head = nullptr;
	}
	T add(T data) {
		if (head == nullptr) {
			head = new Root<T>(data);
			return data;
		}
		Root<T>* root = new Root<T>(data);
		root->next = head;
		head = root;
		return data;
	}
	T pop() {
		if (head == nullptr) {
			throw std::exception("Попытка извлечения элемента пустого стека\n");
		}
		T buff;
		buff = head->data;
		head = head->next;
		return buff;
	}
	~Stack() {
		while (head != nullptr) {
			Root<T>* buff = head->next;
			delete head;
			head = buff;
			delete buff;
		}
	}
private:
	Root<T>* head;
};



int main() {
	setlocale(LC_ALL, "rus");
	Stack<int> test;
	int numb;
	try {
		for (int i = 0; i < 5; i++) {
			cin >> numb;
			test.add(numb);
		}
		for (int i = 0; i < 6; i++) {
			cout << test.pop() << " ";
		}
	}
	catch (exception& e) {
		cout << e.what();
	}
	return 0;
}