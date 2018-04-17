#include "TopSort.h"					// ���������㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
			{0, 0, 0, 0, 0, 0},
			{1, 0, 0, 1, 0, 0},
			{1, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 1},
			{0, 0, 1, 1, 0, 1},
			{0, 0, 0, 0, 0, 0}
		};
		int n = 6;

		AdjListDirGraph<char> g(vexs, n);

		for (int u = 0; u < n; u++)
		{	// �����ڽӾ������
			for (int v = 0; v < n; v++)
			{	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] == 1) g.InsertArc(u, v);
			}
		}

		cout << "ԭͼ:" << endl;
		g.Display();						// ��ʾͼg
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "��������:";
		if (TopSort(g) == SUCCESS)
		{	// ��������ɹ�
			cout << endl << "ԭͼ�޻�!" << endl;
		}
		else
		{	// ��������ʧ��
			cout << endl << "ԭͼ���ڻ�!" << endl;
		}
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

