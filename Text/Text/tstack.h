#ifndef _TSTACK_
#define _TSTACK_

template <class T>
class TStack {
	T* arr;
	int size;
	int num;

public:

	//constructor
	TStack(int _size = 10) {
		if (_size <= 0) throw _size;
		size = _size;
		arr = new T[size];
		num = -1;
	}

	//destructor
	~TStack() {
		delete[] arr;
	}

	//copy constructor
	TStack(const TStack &St) {
		size = St.size;
		arr = new T[size];
		num = St.num;
		for (int i = 0; i <= num; i++)
			arr[i] = St.arr[i];
	}

	//insert into stack
	void Push(const T& el) {
		if (IsFull()) throw num;
		else {
			arr[++num] = el;
		}
	}

	//extract from stack
	T Pop() {
		if (IsEmpty()) throw num;
		else {
			return arr[num--];
		}
	}

	//see what on the top of stack
	T Top() {
		if (num == -1) throw num;
		return arr[num];
	}

	//check for emptyness
	bool IsEmpty() const {
		if (num == -1)
			return true;
		return false;
	}

	//check for full
	bool IsFull() const {
		if (num == size - 1)
			return true;
		return false;
	}

	//clean stack
	void Clear() {
		num = -1;
	}

	bool GetSize() {
		return size;
	}
};
#endif 
