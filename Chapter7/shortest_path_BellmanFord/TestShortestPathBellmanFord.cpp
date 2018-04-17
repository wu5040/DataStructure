#include "ShortestPathBellmanFord.h"	// ���·��BellmanFord�㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', };
		int m[7][7] = {
			{infity,     60,     50,     50,  infity, infity,  infity},
			{infity, infity, infity, infity,     -10, infity,  infity},
			{infity,    -20, infity, infity,      10, infity,      70}, 
			{infity, infity,    -20, infity,  infity,    -10,  infity},
			{infity, infity, infity, infity,  infity, infity,      30},
			{infity, infity, infity, infity,  infity, infity,      30},
			{infity, infity, infity, infity,  infity, infity,  infity}
		};  
		int n = 7;

		AdjListDirNetwork<char, int> net(vexs, n);

		for (int u = 0; u < n; u++) {
			for (int v = n-1; v >=0; v--){
				if (m[u][v] != infity)
					net.InsertArc(u, v, m[u][v]);
			}
		}

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		int dist[n], path[n], v0 = 0;
		ShortestPathBellmanFord(net, v0, path, dist);	//��BellmanFord�㷨�����·��
		DisplayPathAndDist(net, v0, path, dist);		//��ʾ���·�� 
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

