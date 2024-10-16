#include <iostream>
using namespace std;

class A
{
	int x = 0;
	int y = 0;

public:

	A() = default;
	A(int a, int b) : x(a), y(b) {}

	A operator+(const A& b) const 
	{
		return A(x + b.x, y + b.y);
	}

	A operator-(const A& b) const
	{
		return A(x - b.x, y - b.y);
	}

	A operator*(const A& b) const
	{
		return A(x * b.x, y * b.y);
	}

	A operator/(const A& b) const
	{
		if (b.x != 0 && b.y != 0)
		{
			return A(x / b.x, y / b.y);
		}
		else
		{
			cout << "Error: Division by zero." << endl;
			return *this;
		}
		
	}

	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(int value) { x = value; }
	void SetY(int value) { y = value; }


};

ostream& operator<< (ostream& os, const A& obj)
{
	os << obj.GetX() << ":" << obj.GetY();

	return os;
}

istream& operator>>(istream& is, A& obj) {
	int x, y;
	is >> x >> y; 
	obj.SetX(x); 
	obj.SetY(y); 
	return is;
}


template <class T>
class MyArray {
private:
	T* arr;
	int size;

	void clear() {
		for (int i = 0; i < size; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

public:
	MyArray(int size);
	void Output();
	~MyArray();
	MyArray(const MyArray<T>& b);
};

template<class T>
MyArray<T>::MyArray(int size)
{
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 * 1.2;
	}
}

template<class T>
void MyArray<T>::Output()
{

}

template<class T>
MyArray<T>::~MyArray()
{
	clear();
}

template<class T>
MyArray<T>::MyArray(const MyArray<T>& b)
{
}
