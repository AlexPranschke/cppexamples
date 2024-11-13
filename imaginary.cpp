
#include <iostream>

using namespace std;


class Imaginary {

private:
	float m_x;
	float m_y;
public:
	void print() {
		cout << m_x << (m_y > 0 ? "+" : "") << m_y << "i" << endl;
	}
	Imaginary() : m_x(0), m_y(0) {}
	Imaginary(float x, float y) : m_x(x), m_y(y) {}
	Imaginary(const Imaginary& other) : m_x(other.m_x), m_y(other.m_y) {}
	~Imaginary() {


	}
	Imaginary operator+(const Imaginary& other) {
		Imaginary result;
		result.m_x = m_x + other.m_x;
		result.m_y = m_y + other.m_y;
		return result;
	}
	Imaginary operator-(const Imaginary& other) {
		Imaginary result;
		result.m_x = m_x - other.m_x;
		result.m_y = m_y - other.m_y;
		return result;
	}
	Imaginary operator*(const Imaginary& other) {
		Imaginary result;
		result.m_x = (m_x * other.m_x - m_y * other.m_y);
		result.m_y = (m_y * other.m_x + m_x * other.m_y);
		return result;
	}
	Imaginary operator/(const Imaginary& other) {
		Imaginary result;
		if (other.m_x * other.m_x + other.m_y * other.m_y == 0) {
			result.m_x = 0;
			result.m_y = 0;
			cout << "dzielenie przez zero";
			return result;
		}

		result.m_x = (m_x * other.m_x + m_y * other.m_y) / (other.m_x * other.m_x + other.m_y * other.m_y);
		result.m_y = (m_y * other.m_x - m_x * other.m_y) / (other.m_x * other.m_x + other.m_y * other.m_y);
		return result;
	}
	Imaginary operator=(const Imaginary& other) {
		m_x = other.m_x;
		m_y = other.m_y;
		return *this;
	}
};


int main() {

	Imaginary A(1, 2);

	Imaginary* B = new Imaginary(2, 3);

	Imaginary C = A / *B;
	C.print();
	delete B;
	return 0;
}
