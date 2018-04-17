#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "Assistance.h"				// ���������

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

	while (i <= mid)				// �鲢elem[low .. mid]��ʣ��Ԫ��
		tmpElem[k++] = elem[i++];

    while (j <= high)				// �鲢elem[mid + 1 .. high]��ʣ��Ԫ��
		tmpElem[k++] = elem[j++];

	for (i = low; i <= high; i++)	// ��tmpElem[low .. high]���Ƶ�elem[low .. high]
		elem[i] = tmpElem[i];

	delete []tmpElem;				// �ͷ�tmpElem�����ÿռ�
}

template <class ElemType>
void RecursionMergeSort(ElemType elem[], int low, int high, int n)
// �������:��elem[low .. high]���й鲢����
{
	if (low < high)	{	
		int mid = (low + high) / 2;			
			// ��elem[low .. high]ƽ��Ϊelem[low .. mid]��elem[mid + 1 .. high]
		RecursionMergeSort(elem, low, mid, n);	 
		  	// ��elem[low .. mid]���й鲢����
		RecursionMergeSort(elem, mid + 1, high, n);
			// ��elem[mid + 1 .. high]���й鲢����
		Merge(elem, low, mid, high);		 
		  	// ��elem[low .. mid]��elem[mid + 1 .. high]���й鲢
        cout << "�鲢���䣺" << low << "--" << high << endl; 
        Display(elem, n);
        cout << endl;
	}
}
#endif

