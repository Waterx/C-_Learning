在给异常对象传递字符串时，字符串可以使用如下代码构造：
#include <sstream>
stringstream ss;
ss << "Radius underflow: " << radius;
然后，可以调用 stringstream 类中的 str() 函数，获得一个字符指针，该指针指向字符串流对象中的字符串。如有问题，可以参考 stringstream 类的说明: http://www.cplusplus.com/reference/sstream/stringstream/  及其成员函数 str() 的说明: http://www.cplusplus.com/reference/sstream/stringstream/str/ 