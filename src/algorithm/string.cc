/**
 * 字符串相关算法
 */

#include <iostream>

using namespace std;
class StringAlgorithm
{
public:
    StringAlgorithm();
    ~StringAlgorithm();

    static int string_to_int(const char* string);
    static char* int_to_string(int num);




//private:
    
};




int StringAlgorithm::string_to_int(const char * string)
{
    if (string == nullptr) {
        return -1;
    }

    int number = 0;
    while (*string != '\0') {
        number = number * 10 + *string - '0';
        ++string;
    }
    return number;

}






void test_string()
{
    const char* string = "123";
    int res = StringAlgorithm::string_to_int(string);
    cout<<"after convert:"<< res << endl;

}


int main()
{
    test_string();
        

    return 0;

}