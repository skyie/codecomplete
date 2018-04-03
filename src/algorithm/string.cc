/**
 * 字符串相关算法
 */

#include <iostream>
#include <stdint.h>

using namespace std;

#define  MAX_INT 0X7FFFFFFF
#define MAX_NEG_INT  0X80000000

bool valid = false;
class StringAlgorithm
{
public:
    StringAlgorithm();
    ~StringAlgorithm();

    static int string_to_int(const char* string);
    static char* int_to_string(int num);



private:
    static int _string_to_int(const char* string);
};


/**
 * 要考虑到以下情况：
 * 1. string位空指针和空字符串
 * 2. string非合法数字, a123
 * 3. string带正负号的数字: +123,123, -123 都是合法的
 * 4. string只带正负号: +,-  非法
 * 5. string 整数溢出,> 0x7FFFFFFF(UNIT_MAX) < 最小负整数
 * 6. 返回值借助其他变量区分非法的情况,不能通过返回0或者-1来检查
 */

int StringAlgorithm::_string_to_int(const char * string)
{


    return 0;
}


int StringAlgorithm::string_to_int(const char * string)
{
    if (string == nullptr || *string == '\0') {
        valid = false;
        return 0;
    }

    bool minus = false;
    if (*string == '+') {
        ++string;
    } else if (*string == '-') {
        minus = true;
        ++string;
    } 
    // 只包含+,- 非法
    if (*string == '\0') {
        valid = false;
        return 0;
    }
       
    long long number = 0;
    while (*string != '\0') {
        if (*string < '0' || *string > '9') {
            valid = false;
            return 0;
        }
        if (minus) {
            number =  number * 10 - (*string - '0');
            cout << number <<endl;

        }  else {
            number = number * 10 + (*string + '0');
        }
        if (/*(minus && number < (unsigned int)MAX_NEG_INT) ||*/
            (!minus && number > MAX_INT)) {
            valid = false;
            return 0;
            }
        ++string;
    }
    return (int)number;

}






void test_string()
{
    const char* string = "-123";
    int res = StringAlgorithm::string_to_int(string);
    cout<<"after convert:"<< res << " valid:"<< valid<< endl;

}


int main()
{
    test_string();
    //cout <<sizeof(long long);     

    return 0;

}
