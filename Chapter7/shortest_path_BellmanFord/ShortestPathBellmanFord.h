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
void ShortestPathBellmanFord(const AdjListDirNetwork<ElemType, WeightType> &g, int v0, 
	int *path, WeightType *dist)
// �������: ��BellmanFord�㷨��������g�Ӷ���v0�����ඥ��v�����·��path��·������dist[v],
//	path[v]�洢���·�����յ��ǰһ����Ķ����
{
	WeightType *distTemp, minVal, infinity = g.GetInfinity();
    int v, u, vexNum = g.GetVexNum();
	distTemp = new WeightType[vexNum];
	for (v = 0; v < vexNum; v++){	// ��ʼ��path��dist
 	    dist[v] = (v0 != v) ? g.GetWeight(v0, v) : 0;
   	    if (dist[v] == infinity)
            path[v] = -1;
        else 
            path[v] = v0;
	}

    for ( int  k = 2; k < vexNum ; k++) {
    	for (v = 0; v < vexNum; v++)
    		distTemp[v] = dist[v];
     	for (u = 0; u < vexNum ; u++) 
      		if (u != v0)
       			for (v = 0; v < vexNum; v++) 
        			if (v != v0 && distTemp[u] > dist[v] + g.GetWeight(v, u)) {
             			distTemp[u]= dist[v] + g.GetWeight(v, u);
            			path[u] = v;
					}
     	for (v = 0; v < vexNum; v++)
    		dist[v] = distTemp[v];
   }
}

#endif

