#include<iostream>
#include <windows.h> 
using namespace  std;
struct  field {
	field() {
		inf = 0;
		next = nullptr;
		pre = nullptr;
	}
	int inf;
	field* next;
	field* pre;
};

class collection {
protected:
	virtual void reverse(field*&, field*&) = 0;
	virtual bool is_empty(field*) = 0;
	virtual void size_list(int) = 0;

};

void menu();
void menuList();

class list : public collection {
private:
	bool is_empty(field* begin) {
		return (begin->next == 0 && begin->pre == 0);
	}
public:
	~list() {
	}
	void out(field* begin, field* end) {
		if (is_empty(begin)) {
			cout << "список пуст" << endl;
		}
		else {
			while (begin != end) {
				cout << begin->inf;
				begin = begin->next;
			}
			cout << endl;
		}
	}
	void size_list(int size) {
		cout << size << endl;
	}
	void reverse(field* &begin, field* &end) {
		field * saveBegin = new field;
		saveBegin->pre = begin;
		begin->pre = saveBegin;
		begin = saveBegin;
		while (begin->pre != end) {
			begin = begin->pre;
			field *tmp = new field;
			tmp = begin->next;
			begin->next = begin->pre;
			begin->pre = tmp;
		}
		end = saveBegin;
	}
	void pushBack(field*& end, int& size) {
		cout << "Добавте элемнет  в конец:";
		field *tmp = new field;
		cin >> end->inf;
		tmp->pre = end;
		end->next = tmp;
		end = tmp;
		size++;
	}

	void pushFront(field*& begin, int& size) {
		cout << "Добавте элемнет  в начало:";
		field *tmp = new field;
		tmp->next = begin;
		begin->pre = tmp;
		cin >> tmp->inf;
		begin = tmp;
		size++;
	}
	void remove(field* &begin, field* end, int& size) {
		if (!is_empty(begin)) {
			cout << "введите число:";
			int nom;
			cin >> nom;
			if (begin->inf == nom) {
				field* tmp = new field;
				tmp = begin;
				begin = begin->next;
				begin->pre = nullptr;
				delete tmp;
				cout << "элемент успешно удален" << endl;
				return;
			}
			field* it = begin;
			while (it != end) {
				if (it->inf == nom) {
					it->pre->next = it->next;
					it->next->pre = it->pre;
					delete it;
					size--;
					break;
				}
				else {
					it = it->next;
					if (end == it) {
						cout << "элемента нет";
					}
				}
			}
			cout << "элемент успешно удален" << endl;
			return;
		}
		cout << "список пуст" << endl;
	}
};
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	//Numbers.remove(end, begin);
}

void menu() {
	menuList();
}

void menuList() {
	list Numbers;
	field* end = new field;
	field* begin = new field;
	end = begin;
	int size = 0;
	char flag;
	while (1) {
		cout << "1 - pushBack" << endl
			<< "2 - pushFront" << endl
			<< "3 - size_list" << endl
			<< "4 - reverse " << endl
			<< "5 - out " << endl
			<< "6 - remove" << endl
			<< "7 - exit" << endl;
		cin >> flag;
		switch (flag)
		{
		case '1':
			Numbers.pushBack(end, size);
			break;
		case '2':
			Numbers.pushFront(begin, size);
			break;
		case '3':
			Numbers.size_list(size);
			break;
		case '4':
			Numbers.reverse(begin, end);
			break;
		case '5':
			Numbers.out(begin, end);
			break;
		case '6':
			Numbers.remove(begin, end, size);
			break;
		case '7':
			return;
			break;
		default:
			cout << "invalid input";
			break;
		}
	}
}


