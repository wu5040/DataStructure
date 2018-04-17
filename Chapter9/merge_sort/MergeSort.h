#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__
#include "Assistance.h"		     	// ���������

template <class ElemType>
void Merge(ElemType elem[], int low, int mid, int high)
// �������:������������elem[low .. mid]��elem[mid + 1 .. midhigh]�鲢Ϊ�µ�
//	��������elem[low .. high]
{
	ElemType *tmpElem = new ElemType[high+1]; // ������ʱ����
	int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)	
		// iΪ�鲢ʱelem[low .. mid]��ǰԪ�ص��±�,jΪ�鲢ʱelem[mid + 1 .. high]��ǰԪ��
		// ���±�,kΪtmpElem�е�ǰԪ�ص��±�
		if (elem[i] <= elem[j])		
			tmpElem[k++] = elem[i++];
		else	
			tmpElem[k++] = elem[j++];

	while (i <= mid)		// �鲢elem[low .. mid]��ʣ��Ԫ��
		tmpElem[k++] = elem[i++];

    while (j <= high)		// �鲢elem[mid + 1 .. high]��ʣ��Ԫ��
		tmpElem[k++] = elem[j++];

	for (i = low; i <= high; i++)	// ��tmpElem[low .. high]���Ƶ�elem[low .. high]
		elem[i] = tmpElem[i];

	delete []tmpElem;		// �ͷ�tmpElem�����ÿռ�
}

template <class ElemType>
void MergeSort(ElemType elem[], int n)
// �������:��elem�е�n��Ԫ�ؽ�����·�鲢����
{
    int len = 1, i;
    while (len < n) {
        i = 0;
        while (i + 2 * len <= n) { // �Դ�i��ʼ�ĳ���Ϊlen��������������������й鲢 
		    Merge(elem, i, i + len - 1, i + 2 * len -1);
            i += 2 * len;
        }
        if (i + len < n)	{	   // �����������������������й鲢
		    Merge(elem, i, i + len - 1, n -1);	
		}
        cout << "���䳤��Ϊ" << len << "����·�鲢������" << endl; 
        len *= 2;
        Display(elem, n);			
        cout << endl;
	}
}
#endif

