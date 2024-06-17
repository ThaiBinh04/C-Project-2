#include <bits/stdc++.h>
#include <Windows.h>


using namespace std;

typedef long long int ll;

template <class T>

class Stack {
    int size; 
    int top;
    T *data;

public:
	Stack(int size = 100) : size(size), top(-1) {
		data = new T [size];
	}
    ~Stack() { delete [] data; }

public:
    void Push(const T &value) { data[++top] = value; }
    T& Pop() { return data[top--]; }
    T& Peek() const { return data[top - 1]; }
    int Count() const { return top + 1; }
    bool IsEmpty() const { return top < 0; }
    bool IsFull() const { return top == size - 1; }
};

class Thousand {
    int value;
    int zero;
public:
    Thousand(int value = 0, int zero = 0) : value(value), zero(0) { }

    operator int() const { return value; }
    bool IsZero() const { return zero; }
};


class NumberToString : public Stack<Thousand> {
public:
    NumberToString(ll number);
};


NumberToString::NumberToString(ll number) {
    int zero = 0;
    while (number) {
        int value = number % 1000;
        zero |= value;

        number /= 1000;
        Push( Thousand(value, zero) );
    }
}


int main() {
    ll n = 123456789;
    NumberToString conv(n);

    const char* don_vi[] = { "dong", "nghin", "trieu", "ty"};

    while (!conv.IsEmpty()) {
        Thousand v = conv.Pop();
        int lev = conv.Count();
        cout << v << ' ' << don_vi[lev] << ' ';
    }
}