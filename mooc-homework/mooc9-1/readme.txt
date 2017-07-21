ostream这个类提供了setf()函数，可以设置数值输出时是否要带标志位。【具体可以查阅 setf 函数】
ostream os;
os.setf(std::ios::showpos);
os << 12;  //输出 +12
ostream这个类还提供了unsetf()函数，可以将某个标志位取消。

当你使用了setf，输出复数 1+2i 时
os.setf(std::ios::showpos);
os << real << image << "i";
就会显示“+1+2i”。怎样把实部前面的那个正号去掉呢？
此时，你需要用两条语句，分别输出复数的实部和虚部。输出实部前，使用
os.unsetf(std::ios::showpos);
输出虚部前，使用
os.setf(std::ios::showpos);