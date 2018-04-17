#include "LinkInsertSort.h"	    	// ��̬�����ϵĲ��������㷨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10, p;
    Node<int> *table;              	// ��̬����

    table = new Node<int>[n + 1];
    for (p = 1; p <= n; p++){		// ��������a�е�Ԫ�ع��쾲̬���� 
        table[p].data = a[p - 1];
        table[p - 1].next = p;
    }
    table[n].next = -1;

	
	cout << "����ǰ:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;  
      
	LinkInsertSort(table);		   // ��̬�����ϵĲ�������
	
	cout << "�����:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;    

	system("PAUSE");				
	return 0;						
}
