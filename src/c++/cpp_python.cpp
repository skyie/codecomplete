#include <vector>
#include <cstddef> // for nullptr
#include <iostream>
#include <Python.h> // C++调用Python需要该头文件


using namespace std;
/*
 * C++和python互相调用示例
 * ubuntu下需要先安装 apt-get install python-dev
 * linux下编译: g++ -o test cpp_python.cpp -I/usr/include/python2.7 -lpython2.7 --std=c++11
 */


/*
    1. 下面演示C++调用python的add_func函数
    called_python.py和该cpp文件在同级目录下
    def add_func(x,y):
        return x+y
*/

void init_env()
{
    // 初始化
    Py_Initialize();
    // 设置从当前路径找called_python.py文件，不加这个不会自己从当前目录找
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");


}
void free_env()
{
    Py_Finalize();

}
int do_call_python_class()
{
    cout<<"call python class"<<endl;
    //定义参数
    PyObject* pModule = nullptr;
    PyObject* pArg = nullptr;
    PyObject* pFunc = nullptr;
    PyObject* pRet = nullptr;
    PyObject* pDict = nullptr;
    PyObject* pClass = nullptr;
    PyObject* pIns = nullptr;

    //导入python文件
    pModule = PyImport_Import(PyString_FromString("called_python"));
    if (pModule == nullptr) {
        cout<<"fail import"<<endl;
        return -1;
    }
    //获取模块的字典
    pDict = PyModule_GetDict(pModule);
    if (pDict == nullptr) {
        cout<<"get dic fail"<<endl;
        return -1;
    }
    //从字典中获取类名
    pClass = PyDict_GetItemString(pDict, "TestObj");
    if (pClass == nullptr) {
        cout<<"get class name fail"<<endl;
        return -1;      
    }
    // 创建类
    pIns = PyInstance_New(pClass, NULL, NULL);
    if (pIns == nullptr) {
        cout<<"fail get Ins"<<endl;
        return -1;
    }

    char arg[] = "hello";
    // 执行函数
    pRet = PyObject_CallMethod(pIns, "add_prefix", (char*)"s", (char*)arg);

    char* ret = nullptr;    
    PyArg_Parse(pRet, "s", &ret);
    cout<<ret<<endl;

    // 释放资源
    if (pFunc) {
        Py_DECREF(pFunc);
    }
    if (pArg) {
        Py_DECREF(pArg);
    }
    
}
int do_call_python_func(int a, int b)
{
    int res;

    //定义参数
    PyObject* pModule = nullptr;
    PyObject* pArg = nullptr;
    PyObject* pFunc = nullptr;
    PyObject* pRet = nullptr;
    PyObject* pDic = nullptr;
    

    //导入python文件
    pModule = PyImport_Import(PyString_FromString("called_python"));
    if (pModule == nullptr) {
        cout<<"fail import"<<endl;
        return -1;
    }

    // 获取函数名
    pFunc = PyObject_GetAttrString(pModule, "add_func");
    if (pFunc == nullptr) {
        cout<<"fail get func"<<endl;
        return -1;
    }
    // 传入参数
    pArg = Py_BuildValue("ii", a, b);
  

    // 执行函数
    pRet = PyObject_CallObject(pFunc, pArg);


    // 获取返回值
    res = PyInt_AsLong(pRet);
    // 释放资源
    if (pFunc) {
        Py_DECREF(pFunc);
    }
    if (pArg) {
        Py_DECREF(pArg);
    }
    
    return res;
}

void cpp_call_python()
{
    init_env();
    int ret = do_call_python_func(1, 2);
    cout<<"ret "<< ret <<endl;

    do_call_python_class();
}
















int main()
{
    cpp_call_python();

}




