#ifndef __TOPSORT_H__
#define __TOPSORT_H__

#include "AdjListDirGraph.h"			// �ڽӾ�������ͼ

template <class ElemType>
void StatIndegree(const AdjListDirGraph<ElemType> &g, int *indegree)
// ���������ͳ��ͼg����������
{
	for (int v = 0; v < g.GetVexNum(); v++)	// ��ʼ�����Ϊ0
		indegree[v] = 0;

	for (int v = 0; v < g.GetVexNum(); v++)// ����ͼ�Ķ���
		for (int u = g.FirstAdjVex(v); u != -1; u = g.NextAdjVex(v, u))
			indegree[u]++;
}

template <class ElemType>
Status TopSort(const AdjListDirGraph<ElemType> &g)
// ��ʼ��������������ͼg
// �����������g�޻�·,�����g�Ķ����һ����������,������SUCCESS,���򷵻�FAIL
{
	int *indegree = new int[g.GetVexNum()];	// �����������		
	int v, u, count = 0, top = -1;
	ElemType e;
	StatIndegree(g, indegree);				// ͳ�ƶ�������
	

	for (v = 0; v < g.GetVexNum(); v++)
		if (indegree[v] == 0)  {            // ���Ϊ0�Ķ�����ջ 
			indegree[v] = top;
            top = v;
        }

	while (top != -1)	{	// ջ�ǿ�
		v = top;
        top = indegree[v];
		g.GetElem(v, e);
		cout << e << "  ";
		count++;			// �����������м���
		for (u = g.FirstAdjVex(v); u != -1; u = g.NextAdjVex(v, u))
			// ��v��ÿ���ڽӵ�u��ȼ�1
			if (--indegree[u] == 0)	{// u���Ϊ0,��u��ջ
			   indegree[u] = top;
               top = u;
            }
	}
	delete []indegree;						// �ͷ�indegree��ռ�õĴ洢�ռ�

	if (count < g.GetVexNum()) return FAIL;	// ͼg�л�·
	else return SUCCESS;					// ��������ɹ�
}

#endif

