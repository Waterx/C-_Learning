ostream������ṩ��setf()����������������ֵ���ʱ�Ƿ�Ҫ����־λ����������Բ��� setf ������
ostream os;
os.setf(std::ios::showpos);
os << 12;  //��� +12
ostream����໹�ṩ��unsetf()���������Խ�ĳ����־λȡ����

����ʹ����setf��������� 1+2i ʱ
os.setf(std::ios::showpos);
os << real << image << "i";
�ͻ���ʾ��+1+2i����������ʵ��ǰ����Ǹ�����ȥ���أ�
��ʱ������Ҫ��������䣬�ֱ����������ʵ�����鲿�����ʵ��ǰ��ʹ��
os.unsetf(std::ios::showpos);
����鲿ǰ��ʹ��
os.setf(std::ios::showpos);