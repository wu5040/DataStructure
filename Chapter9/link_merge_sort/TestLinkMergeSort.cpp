#include "LinkMergeSort.h"	    // ��̬�����ϵĹ鲢�����㷨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10, p;
    Node<int> *table;              // ��̬����

    table = new Node<int>[n + 1];
    for (p = 1; p <= n; p++){
        table[p].data = a[p - 1];
        table[p].next = -1;
    }

	
	cout << "����ǰ:" << endl;
    for (p = 1; p <= n; p++)
        cout << "(" << table[p].data << "," << table[p].next << ")" << endl;
    cout << endl;  
      
	table[0].next = LinkListMergeSort(table, 1, n);		    // ��̬�����ϵĹ鲢����
	
	cout << "�����:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;    

	system("PAUSE");				
	return 0;						
}
