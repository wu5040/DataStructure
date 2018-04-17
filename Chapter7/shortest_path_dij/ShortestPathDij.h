#ifndef __SHORTEST_PATH_DIJ_H__
#define __SHORTEST_PATH_DIJ_H__

#include "AdjListDirNetwork.h"			// �������ڽӱ� 
#include "LinkStack.h"		            // ��ʽջ

template <class ElemType, class WeightType>
void DisplayPathAndDist(const AdjListDirNetwork<ElemType, WeightType> &g, int v0, int *path, WeightType *dist)
{
    ElemType e1, e2;
	WeightType infinity = g.GetInfinity();
    g.GetElem(v0, e1);
	for (int v1 = 0; v1 < g.GetVexNum(); v1++)	{
       cout << endl;
       g.GetElem(v1, e2);
       if (v1 != v0) 
	      if (dist[v1] < infinity )		{	// ���ڴ�v0��v1���·��
			 cout << "�Ӷ��� " << e1 << " �� " << e2 << ":";
			 cout << " ·������ = " << dist[v1];
			 cout << " ·��:";
			 LinkStack<int> s;	// �洢·�ϵĶ���
			 int v = v1;
			 while (v != v0)	{
				s.Push(v);	// vΪ·���ϵĶ���
				v = path[v];// ȡ��·���ϵ�ǰһ������
			 }
			 s.Push(v0);		// v��·������ʼ��
			 while (!s.IsEmpty())			{	// ���·�ϵĶ���
				s.Pop(v);
                g.GetElem(v, e2);
				cout << e2 << " ";
			 }
		 }
	 	 else 	// ��v0��v1��·��
			cout << "�Ӷ��� " << e1 << " �� "  << e2 << "��·��";
   }
   cout << endl;
}


template <class ElemType, class WeightType>
void ShortestPathDij(const AdjListDirNetwork<ElemType, WeightType> &g, int v0, 
	int *path, WeightType *dist)
// �������: ��Dijkstra�㷨��������g�Ӷ���v0�����ඥ��v�����·��path��·������dist[v],
//	path[v]�洢���·�����յ��ǰһ����Ķ����
{
	WeightType minVal, infinity = g.GetInfinity();
    int v, u;
	for (v = 0; v < g.GetVexNum(); v++){	// ��ʼ��path��dist�������־
 	    dist[v] = (v0 != v) ? g.GetWeight(v0, v) : 0;
   	    if (dist[v] == infinity)
            path[v] = -1;
        else 
            path[v] = v0;
		g.SetTag(v, UNVISITED);	// �ö����־
	}
	g.SetTag(v0, VISITED);		// U={v0}

	for (int i = 1; i < g.GetVexNum(); i++){	// ��g.GetVexNum() - 1����������·��  
		minVal = infinity;
        u = v0;
		for (v = 0; v < g.GetVexNum(); v++)   // ������С�����·�� 
			if (g.GetTag(v) == UNVISITED && dist[v] < minVal)		{
            	// g.GetTag(v) == UNVISITED��ʾv��V - U
				u = v;
				minVal = dist[v];
			}
		g.SetTag(u, VISITED);	// ��u����U

		for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))
			if (g.GetTag(v) == UNVISITED && minVal + g.GetWeight(u, v) < dist[v])	{
               	// ��v��V - U��minVal + g.GetWeight(u, v) < dist[v],���޸�dist[v]��path[v]
				dist[v] = minVal + g.GetWeight(u, v);
				path[v] = u;
			}
	}
}

#endif

