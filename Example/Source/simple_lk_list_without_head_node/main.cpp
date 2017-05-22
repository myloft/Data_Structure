#include "utility.h"							// ʵ�ó��������
#include "simple_lk_list_without_head_node.h"	// ��ͷ���ļ�����������

int main(void)
{
	char c = '0';
    SimpleLinkListWithoutHeadNode<double> la,lb;
    double e;
	int position;

    while (c != '7')
	{
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ����Ԫ��.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
		cout << endl << "7. �˳�";
		cout << endl << "ѡ����(1~7):";
		cin >> c;
		switch (c) 
		{
			case '1':
				cout << endl << "����e(e = 0ʱ�˳�):";
				cin >> e;
				while (e != 0)
				{
					la.Insert(la.Length() + 1, e);
					cin >> e;
				}
				break;
			case '2':
			    lb = la;
			    lb.Traverse(Write<double>);
				break;
			case '3':
			    cout << endl << "����Ԫ��λ��:";
			    cin >> position;
			    if (la.GetElem(position, e) == NOT_PRESENT) 
					cout << "Ԫ�ز��洢." << endl;
				else
					cout << "Ԫ��:" << e << endl;
			    break;
			case '4':
			    cout << endl << "����λ��:";
			    cin >> position;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
				if (la.SetElem(position, e) == RANGE_ERROR)
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "���óɹ�." << endl;
			    break;
			case '5':
			    cout << endl << "����λ��:";
			    cin >> position;
			    if (la.Delete(position, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "��ɾ��Ԫ��ֵ:" << e << endl;
			    break;
			case '6':
			    cout << endl << "����λ��:";
			    cin >> position;
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> e;
			    if (la.Insert(position, e) == RANGE_ERROR) 
					cout << "λ�÷�Χ��." << endl;
				else
					cout << "�ɹ�:" << e << endl;
			    break;
		}
	}

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
