// 练习运算符重载
#include <iostream>
#include <iomanip>

using namespace std;

class MyComplex {
private:
    double x, y;
public:
    /* Implementation of MyComplex */
    MyComplex() {
        x = 0;
        y = 0;
    }

    MyComplex(double x, double y) : x(x), y(y) {}

    friend ostream &operator<<(ostream &, MyComplex);

    friend istream &operator>>(istream &, MyComplex &);

    MyComplex operator+(const MyComplex &c2);

    MyComplex operator-(const MyComplex &c2);

    MyComplex operator*(const MyComplex &c2);

    MyComplex operator/(const MyComplex &c2);

    MyComplex &operator+=(const MyComplex &c2);

    MyComplex &operator-=(const MyComplex &c2);

    MyComplex &operator*=(const MyComplex &c2);

    MyComplex &operator/=(const MyComplex &c2);
};

ostream &operator<<(ostream &output, MyComplex c) //定义运算符“<<”重载函数
{
    output << fixed << setprecision(2) << c.x << " " << c.y;
    return output;
}

istream &operator>>(istream &input, MyComplex &c) //定义运算符“<<”重载函数
{
    input >> c.x >> c.y;
    return input;
}

MyComplex MyComplex::operator+(const MyComplex &c2)//定义运算符“+”重载函数
{
    return MyComplex(x + c2.x, y + c2.y);
}

MyComplex MyComplex::operator-(const MyComplex &c2)//定义运算符“+”重载函数
{
    return MyComplex(x - c2.x, y - c2.y);
}

MyComplex MyComplex::operator*(const MyComplex &c2)//定义运算符“+”重载函数
{
    return MyComplex(x * c2.x - y * c2.y, x * c2.y + y * c2.x);
}

MyComplex MyComplex::operator/(const MyComplex &c2)//定义运算符“+”重载函数
{
    return MyComplex((x * c2.x + y * c2.y) / (c2.x * c2.x + c2.y * c2.y),
                     (-x * c2.y + y * c2.x) / (c2.x * c2.x + c2.y * c2.y));
}

MyComplex &MyComplex::operator+=(const MyComplex &c2)//定义运算符“+”重载函数
{
    *this = *this + c2;
    return *this;
}

MyComplex &MyComplex::operator-=(const MyComplex &c2)//定义运算符“+”重载函数
{
    *this = *this - c2;
    return *this;
}

MyComplex &MyComplex::operator*=(const MyComplex &c2)//定义运算符“+”重载函数
{
    *this = *this * c2;
    return *this;
}

MyComplex &MyComplex::operator/=(const MyComplex &c2)//定义运算符“+”重载函数
{
    *this = *this / c2;
    return *this;
}

int main() {
    MyComplex z1;
    MyComplex z2;

    cin >> z1 >> z2;

    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << (z1 += z2) << endl;
    cout << (z1 -= z2) << endl;
    cout << (z1 *= z2) << endl;
    cout << (z1 /= z2) << endl;

    return 0;
}