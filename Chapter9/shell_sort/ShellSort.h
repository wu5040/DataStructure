#ifndef __SHELL_SORT_H__
#define __SHELL_SORT_H__

#include "Assistance.h"				// ���������
template <class ElemType>
void ShellSort(ElemType elem[], int n)
// �������: ȡ��������n/2,n/4,n/8,...,1.������elem����Shell����
{
    int i, j, d = n / 2;            // ��ʼ����ȡn/2 
    ElemType e;
	while (d > 0) {
       for (i = d ; i < n; i++)	{	// ����Ϊdʱ�Ĳ�������
		  e = elem[i];		        // ȡ�±�Ϊi��Ԫ�� 
		  j = i - d; 
          while (j >= 0 && e < elem[j]) { 
			 elem[j + d] = elem[j];	// ���������б�e��ļ�¼������
             j -= d;
          }	
		  elem[j + d] = e;			// ���±�Ϊi��Ԫ�ز��뵽�����е��ʵ�λ��
       }
	   cout << "����Ϊ" << d << "ʱϣ������Ľ����"; 
       Display(elem, n);			// ��ʾ�м��� 
       d = d / 2;                   // ���̲��� 
	}
}

#endif

