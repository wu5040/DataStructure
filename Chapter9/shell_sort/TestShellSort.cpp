#include "ShellSort.h"			// ϣ�������㷨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "����ǰ:";
	Display(a, n);				
	ShellSort(a, n);			// ϣ������
	cout << "�����:";
	Display(a, n);				

	system("PAUSE");			
	return 0;					
}
