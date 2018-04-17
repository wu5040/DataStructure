#include "RadixSort.h"				// ���������㷨

int main(void)
{
	int a[] = {432, 820, 53, 786, 481, 529, 314, 608, 764, 104};
	int n = 10, r = 10, d = 3, p;
    Node<int> *table;              // ��̬����

    table = new Node<int>[n + 1];
    for (p = 1; p <= n; p++){
        table[p].data = a[p - 1];
        table[p - 1].next = p;
    }
    table[n].next = -1;

	cout << "����ǰ:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl; 
     
	RadixSort(table, d, r);			// ��������

	cout << "�����:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;    

	system("PAUSE");				
	return 0;						
}
