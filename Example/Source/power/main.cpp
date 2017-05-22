#include "utility.h"				// ʵ�ó��������
#include "large_int.h"				// ��Ǹ��������ͷ�ļ�
#include "power.h"					// �����������������������������η�

int main(void)
{
	Timer tm;						// ��ʱ������
	CLargeInt largeInt(0);			// ����һ����Ǹ�����
	largeInt = Power(8, 0);			// ���������������������������η�
	cout << "8^0="	
		 << largeInt << endl;		// ��ʾ�������������������������η�ֵ

	largeInt = Power(2, 10);		// ���������������������������η�
	cout << "2^10="	
		 << largeInt << endl;		// ��ʾ�������������������������η�ֵ

	largeInt = Power(189, 200);		// ���������������������������η�
	cout << "189^200="	
		 << largeInt << endl;		// ��ʾ�������������������������η�ֵ
	printf("��ʱ%.3f��!\n", tm.ElapsedTime());

	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
}