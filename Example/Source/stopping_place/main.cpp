// �ļ�·����:stopping_place\main.cpp
#include "utility.h"					// ʵ�ó��������
#include "stopping_place.h"				// ͣ�������ͷ�ļ�

int main(void)
{
	int maxNum;							// ͣ����ֹͣ�����������
	int rate;							// ͣ��λʱ����շ�ֵ
	VehicleType ve;						// ������Ϣ
	StoppingPlace *pStopingSpace;		// ͣ����ָ��
	int select = 0;						// ����ѡ��

	cout << "����ͣ����ֹͣ�������������ͣ��λʱ����շ�ֵ:";
	cin >> maxNum >> rate;				// ����ͣ����ֹͣ�������������ͣ��λʱ����շ�ֵ
	pStopingSpace = new StoppingPlace(maxNum, rate);// ����ͣ��������	

	while (select != 4)
	{	// ѭ��������
		cout << "1. ��������" << endl;
		cout << "2. �����뿪" << endl;
		cout << "3. ��ʾ״̬" << endl;
		cout << "4. ����" << endl;
		cout << "ѡ����:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "���복������뵽��ʱ��:";
			cin >> ve.num >> ve.time;	// ���복������뵽��ʱ��	
			pStopingSpace->Arrive(ve);	// �������ﴦ��
			break;
		case 2:
			cout << "���복��������뿪ʱ��:";
			cin >> ve.num >> ve.time;	// ���복������뵽��ʱ��	
			pStopingSpace->Leave(ve);	// �����뿪����
			break;
		case 3:
			pStopingSpace->DisplayStatus();	// ��ʾͣ���������г���״̬
			break;
		}
	}

	delete pStopingSpace;				// �ͷ�ͣ��������

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}