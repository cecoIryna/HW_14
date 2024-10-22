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
	int rows, cols;

public:

	void clear() {
		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	MyArray(int r, int c) : rows(r), cols(c)
	{
		arr = new T*[rows];
		for (int i = 0; i < rows; i++) {
			arr[i] = new T[cols];
		}
	}

	~MyArray()
	{
		clear();
	}

	void Input()
	{
		cout << "Enter matrix values:\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> arr[i][j];
			}
		}
	}

	void FillRandom() {
		srand(time(0));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				arr[i][j] = T(rand() % 100); 
			}
		}
	}

	void Display() const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		} 
	}

	MyArray operator+(const MyArray& other) const {
		MyArray result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.arr[i][j] = arr[i][j] + other.arr[i][j];
			}
		}
		return result;
	}


	MyArray operator-(const MyArray& other) const {
		MyArray result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.arr[i][j] = arr[i][j] - other.arr[i][j];
			}
		}
		return result;
	}

	MyArray operator*(const MyArray& other) const {
		MyArray result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.arr[i][j] = arr[i][j] * other.arr[i][j];
			}
		}
		return result;
	}

	MyArray operator/(const MyArray& other) const {
		MyArray result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.arr[i][j] = arr[i][j] / other.arr[i][j];
			}
		}
		return result;
	}

	T maxElement() const {
		T max = arr[0][0];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
		}
		return max;
	}

	T minElement() const {
		T min = arr[0][0];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (arr[i][j] < min) {
					min = arr[i][j];
				}
			}
		}
		return min;
	}
};

int main() {
	MyArray<A>mat1(2, 2);
	mat1.FillRandom();
	mat1.Display();

	cout << "Max element: " << mat1.maxElement() << endl;
	cout << "Min element: " << mat1.minElement() << endl;

	MyArray<A> mat2(2, 2);
	mat2.FillRandom();
	cout << "Second matrix:\n";
	mat2.Display();

	MyArray<A> matSum = mat1 + mat2;
	cout << "Sum of matrices:\n";
	matSum.Display();

	return 0;
}