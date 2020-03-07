#ifndef _TSTACK_
#define _TSTACK_
template <class T>
class TStack {
	T* arr;
	int size;
	int num;
public:
	TStack(int _size = 10) {         //�����������
		if (_size <= 0) throw _size;
		size = _size;
		arr = new T[size];
		num = -1;
	}
	~TStack() {                      //����������  
		delete[] arr;
	}
	TStack(const TStack &St) {       //����������� �����������
		size = St.size;
		arr = new T[size];
		num = St.num;
		for (int i = 0; i <= num; i++)
			arr[i] = St.arr[i];
	}
	void Push(const T& el) {                //�������� � ����
		if (IsFull()) throw num;
		else {
			arr[++num] = el;
		}
	}
	T Pop() {                        //����� �� �����
		if (IsEmpty()) throw num;
		else {
			return arr[num--];
		}
	}
	T Top() {                        //���������� ��� �� ������� �����
		if (num == -1) throw num;
		return arr[num];
	}
	bool IsEmpty() const {           //��������� �� �������
		if (num == -1)
			return true;
		return false;
	}
	bool IsFull() const {            //��������� �� ��������
		if (num == size - 1)
			return true;
		return false;
	}
	void Clear() {                   //�������� ����
		num = -1;
	}
};
#endif // !_TSTACK_
