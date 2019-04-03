#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;
using std::endl;

class D{ /**1 byte**/
public:
    D(){}
    ~D(){}
};

class A{ /**8 byte**/
public:
    A() {}
    ~A() {}
    int m1;
    int m2;
};

class B:A{ /**16 byte**/
    B() {}
    ~B() {}
    char m2; /**注意对其方式**/
    int m1;
    static char m3; /**静态数据不在计算中**/
};

class C{ /**12 byte**/
public:
    C() {}
    ~C() {}
    virtual void fun_1(){} /**虚函数表指针占用4byte**/
    virtual void fun_2(){}
    virtual void fun_3(){}
    int m1;
    short m2;
};

class BU{/**24 byte**/
    int number;
    union UBffer { /**对其后16byte**/
        char buffer[13];
        int number;
    }ubuf;
    void foo(){} /**函数声名不占用空间**/
    typedef char*(*f)(void*); /**取别名不占用空间**/
    enum {hdd,ssd,blueray} disk; /**对其后4byte**/
};

int main ( ) {
    int *a;
    cout << "Int    " << sizeof *a << "\n";     // 4
    cout << "Point  " << sizeof(a) << "\n";     // 4 (or 8)
    double *arr = new double[10];
    cout << "double " << sizeof(*arr) << "\n";  // 8
    cout << "Point  " << sizeof(arr) << "\n";   // 4(or 8)

    cout << "Char   " << sizeof(char) << "\n";      // 1
    cout << "Short  " << sizeof(short) << "\n";     // 2
    cout << "int    " << sizeof(int) << "\n";       // 4
    cout << "Float  " << sizeof(float) << "\n";     // 4
    cout << "Double " << sizeof(double) << "\n";    // 8
    cout << "long   " << sizeof(long) << "\n";      // 8

    cout << "--- Class ---\n";
    cout << "A      " << sizeof(A) << ", B      " << sizeof(B) << "\n"; // 8, 16
    cout << "C      " << sizeof(C) << ", D      " << sizeof(D) << "\n"; // 12, 1 or(16, 1)
    cout << "BU      " << sizeof(BU) <<endl;

    cout << "--- Array ---\n";
    float f[] = {1.0,2.0,3.0,4.0,5.0};
    cout << "Array  " << sizeof(f) << "\n";     // 20
    char str[]="Tencent";
    cout << "char[] " << sizeof(str) << "\n";   // 8

    cout << "--- Vector, String ---\n";
    vector<int> v(1, 0);
    cout << "Vector " << sizeof(v) << "\n";     /**12 byte**/
    string s("12345");
    cout << "String " << sizeof(s) << "\n";     /**4 byte,是指针**/

    return 0;
}
