#include "BubbleSort.h"			// ð�������㷨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "����ǰ:";
	Display(a, n);				// ��ʾ����a������ 
	BubbleSort(a, n);			// ð������
	cout << "�����:";
	Display(a, n);				// ��ʾa����a������ 

	system("PAUSE");			// ���ÿ⺯��system()
	return 0;					// ����ֵ0, ���ز���ϵͳ
}
