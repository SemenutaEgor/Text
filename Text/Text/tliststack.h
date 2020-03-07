#include <iostream>
template <class T>
struct TNode {
	T val; //значение
	TNode<T> *pNext; //указатель на следующий элемене
};
//
template <class T>
class TStack {
	TNode<T> *pFirst;
public:
	//конструктор
	TStack() {
		pFirst = NULL;
	}
	//деструктор
	~TStack() {
		TNode<T> *tmp = pFirst;
		if (tmp == NULL)
			delete tmp;
		while (pFirst != NULL) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	//Конструктор копирования
	TStack(const TStack<T>& st) {
		TNode<T> *tmp = st.pFirst;
		if (tmp == NULL)
			pFirst = tmp;
		while (tmp != NULL){
			Push(tmp->val);
			tmp = tmp->pNext;
		}
		delete tmp;
	}
	//оператор присваивания
	TStack<T> operator=(const TStack<T>& st) {
		if (this != &st){
			if (!IsEmpty())
				Clear();
			else{
				TNode<T> *tmp = st.pFirst;
				if (tmp == NULL)
					pFirst = tmp;
				while (tmp != NULL){
					Push(tmp->val);
					tmp = tmp->pNext;
				}
				delete tmp;
			}
		}
		return *this;
	}
	//проверка на пустоту
	bool IsEmpty() const {
		return pFirst == NULL;
	}
	//проверка на полноту
	bool IsFull() const {
		TNode<T> *tmp;
		tmp = new TNode<T>;
		if (tmp == NULL)
			return 1;
		else{
			delete tmp;
			return 0;
		}
	}
	//добавить в стек
	void Push(const T& a){
		if (IsFull())
			throw - 1;
		else{
			TNode<T> *tmp;
			tmp = new TNode<T>;
			tmp->pNext = pFirst;
			tmp->val = a;
			pFirst = tmp;
		}
	}
	//извлечь из стека
	T Pop() {
		if (IsEmpty())
			throw - 1;
		else{
			T res = pFirst->val;
			TNode<T> *tmp;
			tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			return res;
		}
	}
	//Посмотреть, что на вершине стека
	T Top() {
		if (IsEmpty())
			throw - 1;
		else
			return pFirst->val;
	}
	//очистить стек
	void Clear() {
		TNode<T> *tmp = pFirst;
		while (pFirst != NULL){
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
};

