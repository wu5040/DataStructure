#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__
#include "Assistance.h"			// ���������

template <class ElemType>
void StraightInsertSort(ElemType elem[], int n)
// �������:������elem�е�n��Ԫ�ؽ���ֱ�Ӳ�������
{
	int i, j;							
	for (i = 1; i < n; i++)	{			// ��i��ֱ�Ӳ�������
		ElemType e = elem[i];			// ȡҪ�����Ԫ��elem[i]
		for (j = i - 1; j >= 0 && e < elem[j]; j--)	// ����e���Ԫ�غ���
			elem[j + 1] = elem[j];		// ����
		elem[j + 1] = e;				// j+1Ϊ����λ��
	    cout << "��" << i << "��ֱ�Ӳ�������Ľ����"; 
        Display(elem, n);				// ��ʾ�м��� 
	}
}

#endif

