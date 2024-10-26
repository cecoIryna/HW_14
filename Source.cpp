#include <iostream>
#include<time.h>
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

	bool operator>(const A& other) const {
		return (x > other.x) || (x == other.x && y > other.y);
	}

	bool operator<(const A& other) const {
		return (x < other.x) || (x == other.x && y < other.y);
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

public:
	MyArray(int s) : size(s)
	{
		arr = new T[size];
	}

	~MyArray()
	{
		delete[] arr;
	}

	void Input()
	{
		cout << "Enter " << size*2 << " array values: ";
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}

	void FillRandom() {
		srand(time(0));
		for (int i = 0; i < size; i++) {
			arr[i] = T(rand() % 100, rand() % 100);
		}
	}

	void Display() const {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
			cout << endl;
		} 
	}

	MyArray operator+(const MyArray& other) const {
		MyArray result(size);
		for (int i = 0; i < size; i++) {
			result.arr[i] = arr[i] + other.arr[i];
		}
		return result;
	}


	MyArray operator-(const MyArray& other) const {
		MyArray result(size);
		for (int i = 0; i < size; i++) {
			result.arr[i] = arr[i] - other.arr[i];
		}
		return result;
	}

	MyArray operator*(const MyArray& other) const {
		MyArray result(size);
		for (int i = 0; i < size; i++) {
			result.arr[i] = arr[i] * other.arr[i];
		}
		return result;
	}

	MyArray operator/(const MyArray& other) const {
		MyArray result(size);
		for (int i = 0; i < size; i++) {
			result.arr[i] = arr[i] / other.arr[i];
		}
		return result;
	}

	T maxElement() const {
		T max = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}

	T minElement() const {
		T min = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}
};

int main() {
	MyArray<A>mat1(2);
	mat1.Input();
	cout << "First array:\n";
	mat1.Display();

	cout << "Max element: " << mat1.maxElement() << endl;
	cout << "Min element: " << mat1.minElement() << endl;

	MyArray<A> mat2(2);
	mat2.FillRandom();
	cout << "Second array:\n";
	mat2.Display();

	MyArray<A> matSum = mat1 + mat2;
	cout << "Sum of array:\n";
	matSum.Display();

	return 0;
}