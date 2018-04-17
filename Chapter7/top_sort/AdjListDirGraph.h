#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__
#include "Assistance.h"					// ���������
#include "AdjListDirGraphArc.h"			// ����ͼ�ڽӱ�ı߽����
#include "AdjListDirGraphVex.h"			// ����ͼ�ڽӱ�Ķ�������

// ����ͼ���ڽӱ���
template <class ElemType>
class AdjListDirGraph
{
protected:
// �ڽӱ�����ݳ�Ա:
	int vexNum, vexMaxNum, arcNum;			// ������Ŀ������Ķ��������Ŀ�ͱ���
	AdjListGraphVex<ElemType> *vexTable;	// �����
	mutable Status *tag;			        // ��־����				

public:
// �ڽӱ�ĺ�����Ա:
	AdjListDirGraph(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
		// ������es[]Ϊ��������,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,
        // ����Ϊ0��������ͼ
	AdjListDirGraph(int vertexMaxNum = DEFAULT_SIZE);
		// ��������Ķ��������ĿΪvertexMaxNum,�������ͱ���Ϊ0������ͼ
	~AdjListDirGraph();						// ��������
	void Clear();			                    // �������ͼ			 
	bool IsEmpty();                             // �ж�����ͼ�Ƿ�Ϊ�� 
	int GetOrder(ElemType &e) const;            // �󶥵�e�����	
	Status GetElem(int v, ElemType &e) const;   // �󶥵�v��Ԫ��ֵ	
	Status SetElem(int v, const ElemType &e);   // ���ö���v��Ԫ��ֵΪe
	int GetVexNum() const;						// ������ͼ�Ķ������			 
	int GetArcNum() const;						// ������ͼ�ı�������			 
	int FirstAdjVex(int v) const;				// ������ͼ�ж���v�ĵ�һ���ڽӵ�			 
	int NextAdjVex(int v1, int v2) const;		// ������ͼ�ж���v1�������v2����һ���ڽӵ�			 
	Status InsertVex(const ElemType &e);		// ����Ԫ��ֵΪe�Ķ���		 
	void InsertArc(int v1, int v2);				// ����Ӷ���v1��v2�ı�			 
	void DeleteVex(const ElemType &e);			// ɾ��Ԫ��ֵΪe�Ķ���			 
	void DeleteArc(int v1, int v2);			    // ɾ���Ӷ���Ϊv1��v2�ı�			 
	Status GetTag(int v) const;				    // �󶥵�v�ı�־		 
	void SetTag(int v, Status tag) const;	    // ���ö���v�ı�־Ϊtag	 
	AdjListDirGraph(const AdjListDirGraph<ElemType> &g);	// ���ƹ��캯��
	AdjListDirGraph<ElemType> &operator =
		(const AdjListDirGraph<ElemType> &g); // ���ظ�ֵ����� 
    void Display();	// ��ʾ����ͼ���ڽӱ� 
};

// ����ͼ���ڽӱ����ʵ�ֲ���
template <class ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(ElemType es[],
       int vertexNum, int vertexMaxNum)
// ������������춥������Ϊes[],������ΪnumVex,�������ΪvertexNum,����Ϊ0������ͼ
{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
    	throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

	vexNum = vertexNum;			
	vexMaxNum = vertexMaxNum; 
	arcNum = 0;
	
	tag = new Status[vexMaxNum];
	vexTable = new AdjListGraphVex<ElemType>[vexMaxNum];
 
	for (int v = 0; v < vexNum; v++)  {
		tag[v] = UNVISITED;
		vexTable[v].data = es[v];
		vexTable[v].firstarc = NULL;
	}
}

template <class ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(int vertexMaxNum)
// ������������춥�������ĿΪvertexMaxNum�Ŀ�����ͼ
{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");// �׳��쳣

	vexNum = 0;			
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListGraphVex<ElemType>[vexMaxNum];
}

template <class ElemType>
AdjListDirGraph<ElemType>::~AdjListDirGraph()
// ����������ͷ��ڽӱ�����ͼ��ռ�ÿռ�
{
    Clear();                                // �ͷű߽��
	delete []tag;							// �ͷű�־
	delete []vexTable;						// �ͷ��ڽӱ�
}

template <class ElemType>
void AdjListDirGraph<ElemType>::Clear()
// ����������ͷ����еı߽�㣬��������ͼ�Ķ������ͱ�������Ϊ0.			 
{
	AdjListGraphArc *p;
	for (int v = 0; v < vexNum; v++)	{	// �ͷű߽��
	    p = vexTable[v].firstarc;
	    while (p != NULL) {
			vexTable[v].firstarc = p->nextArc;
			delete p;
			p = vexTable[v].firstarc;
        }	
	}
    vexNum = 0;
	arcNum = 0;	
}

template <class ElemType>
bool AdjListDirGraph<ElemType>::IsEmpty()
// ����������������ͼΪ�շ���true,���򷵻�false.
{
	return vexNum == 0;
}

template <class ElemType>
int AdjListDirGraph<ElemType>::GetOrder(ElemType &e) const
// ����������󶥵�e�����.�������Ŵ�0��ʼ��ͼ�в����ڶ���eʱ����-1. 
{
    int v;
    for (v = 0; v < vexNum; v++)
        if (e == vexTable[v].data)
           break;
           
	if (v < 0 || v >= vexNum)
		return -1;	// ����e������,����-1
	else
		return v;	// ����e����,����������� 
}	

template <class ElemType>
Status AdjListDirGraph<ElemType>::GetElem(int v, ElemType &e) const
// ��������������Ϊv�Ķ���ֵ, v��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ����
//	ͨ��eȡ�ö���ֵ��������ENTRY_FOUND������������NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;			// Ԫ�ز�����
	else	{
		e = vexTable[v].data;		// ������v��Ԫ��ֵ����e
		return ENTRY_FOUND;			// Ԫ�ش���
	}
}	

template <class ElemType>
Status AdjListDirGraph<ElemType>::SetElem(int v, const ElemType &e)
// ������������ö����Ԫ��ֵv��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ��������
//	SUCCESS, ����������RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;			// λ�ô�
	else	{
		vexTable[v].data = e;		// ����Ԫ��
		return SUCCESS;				// �ɹ�
	}
}

template <class ElemType>
int AdjListDirGraph<ElemType>::GetVexNum() const
// ������������ض������			 
{
	return vexNum;
}

template <class ElemType>
int AdjListDirGraph<ElemType>::GetArcNum() const
// ������������ر�������
{
	return arcNum;
}		 

template <class ElemType>
int AdjListDirGraph<ElemType>::FirstAdjVex(int v) const
// ������������ض���v�ĵ�һ���ڽӵ�			 
{
	if (v < 0 || v >= vexNum)
       throw Error("v���Ϸ�!");// �׳��쳣

	if (vexTable[v].firstarc == NULL)
	   return -1;              // �������ڽӵ�
	else
	   return vexTable[v].firstarc->adjVex;
}

template <class ElemType>
int AdjListDirGraph<ElemType>::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�			 
{
	AdjListGraphArc *p;
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
       throw Error("v1���ܵ���v2!");// �׳��쳣
	
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
	    p = p->nextArc;

	if (p == NULL || p->nextArc == NULL)
		return -1;                   // ��������һ���ڽӵ�
	else
		return p->nextArc->adjVex;
}

template <class ElemType>
Status AdjListDirGraph<ElemType>::InsertVex(const ElemType &e)
// ����������ڶ����ı�β����Ԫ��ֵΪe�Ķ��㡣			 
{
	if (vexNum == vexMaxNum)
       return OVER_FLOW;			// ������� 

	vexTable[vexNum].data = e;
	vexTable[vexNum].firstarc = NULL;
	tag[vexNum] = UNVISITED;
    vexNum++;
    return SUCCESS; 
}

template <class ElemType>
void AdjListDirGraph<ElemType>::InsertArc(int v1, int v2)
// ������������붥��Ϊv1��v2,ȨΪw�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
       throw Error("v1���ܵ���v2!");// �׳��쳣

	AdjListGraphArc *p, *q;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2) {
		q = p;
		p = p->nextArc;
	}
	if (p == NULL) {
		if (vexTable[v1].firstarc == NULL)
    		vexTable[v1].firstarc = new AdjListGraphArc(v2);
    	else 
    		q->nextArc = new AdjListGraphArc(v2);
    			arcNum++;
	}
    else
       throw Error("�������Ѿ�����!");// �׳��쳣
}

template <class ElemType>
void AdjListDirGraph<ElemType>::DeleteVex(const ElemType &e)
// ���������ɾ��Ԫ��ֵΪe�Ķ���			 
{
    int v;
    AdjListGraphArc *p, *q;
    for (v = 0; v < vexNum; v++)
       if	(vexTable[v].data == e)
           break;
	if (v == vexNum)
       throw Error("ͼ�в�����Ҫɾ���Ķ���!");	// �׳��쳣

    for (int u = 0; u < vexNum; u++)           // ɾ������e�Ļ� 
       if (u != v) 
          DeleteArc(u, v); 
          
	p = vexTable[v].firstarc;                  // ɾ����e�����Ļ� 
	while (p != NULL) {
        vexTable[v].firstarc = p->nextArc;
        delete p;    
	    p = vexTable[v].firstarc;
		arcNum--;
	}

    vexNum--;
    vexTable[v].data = vexTable[vexNum].data;
    vexTable[v].firstarc = vexTable[vexNum].firstarc;
    vexTable[vexNum].firstarc = NULL;
    tag[v] = tag[vexNum];

    for (int u = 0; u < vexNum; u++)         
       if (u != v) {
	      p = vexTable[u].firstarc;
	      while (p != NULL) {
             if (p->adjVex == vexNum)
                p->adjVex = v;
             p = p->nextArc;
          }
       }   
}

template <class ElemType>
void AdjListDirGraph<ElemType>::DeleteArc(int v1, int v2)
// ���������ɾ������Ϊv1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2) throw
       Error("v1���ܵ���v2!");		// �׳��쳣

	AdjListGraphArc *p, *q;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2) {
        q = p;
        p = p->nextArc;
    }
    if (p != NULL) {
	    if (vexTable[v1].firstarc == p)
            vexTable[v1].firstarc = p->nextArc;
        else
            q->nextArc = p->nextArc;
        delete p;    
		arcNum--;
	}
	else
       Error("v1��v2û�л���");		// �׳��쳣
}

template <class ElemType>
Status AdjListDirGraph<ElemType>::GetTag(int v) const
// ������������ض���v�ı�־		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v���Ϸ�!");		// �׳��쳣

	return tag[v];
}

template <class ElemType>
void AdjListDirGraph<ElemType>::SetTag(int v, Status val) const
// ������������ö���v�ı�־Ϊval		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v���Ϸ�!");		// �׳��쳣

	tag[v] = val;
}

template <class ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(const AdjListDirGraph<ElemType> &g)
// ���������������ͼ���ڽӾ���g����������ͼ���ڽӾ���g�������ƹ��캯��
{
	AdjListGraphArc *p, *q;
	vexNum = g.vexNum;
	vexMaxNum = g.vexMaxNum;	
	arcNum = g.arcNum;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListGraphVex<ElemType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++)	{
		tag[v] = g.tag[v];
		vexTable[v].data = g.vexTable[v].data;
		vexTable[v].firstarc = NULL;
		p = g.vexTable[v].firstarc;
		while (p != NULL) 
           if (vexTable[v].firstarc == NULL) {
              vexTable[v].firstarc = new AdjListGraphArc(p->adjVex);	
              q = vexTable[v].firstarc;
              p = p->nextArc;
           }
           else {   
              q->nextArc = new AdjListGraphArc(p->adjVex);	
              q = q->nextArc;
              p = p->nextArc;
           }   
	}
}

template <class ElemType>
AdjListDirGraph<ElemType> &AdjListDirGraph<ElemType>::operator =(const AdjListDirGraph<ElemType> &g)
// ���������������ͼ���ڽӾ���g��ֵ����ǰ����ͼ���ڽӾ��󡪡���ֵ�������
{
	if (&g != this)
	{
        Clear();                                    // �ͷŵ�ǰ����ͼ�߽��
	    delete []tag;								// �ͷŵ�ǰ����ͼ��־���� 
	    delete []vexTable;							// �ͷŵ�ǰ����ͼ����� 

	    AdjListGraphArc *p, *q;
	    vexNum = g.vexNum;
	    vexMaxNum = g.vexMaxNum;	
	    arcNum = g.arcNum;

	    tag = new Status[vexMaxNum];
	    vexTable = new AdjListGraphVex<ElemType>[vexMaxNum];
	    for (int v = 0; v < vexNum; v++)	{
		   tag[v] = g.tag[v];
		   vexTable[v].data = g.vexTable[v].data;
		   vexTable[v].firstarc = NULL;
		   p = g.vexTable[v].firstarc;
		   while (p != NULL) 
               if (vexTable[v].firstarc == NULL) {
                  vexTable[v].firstarc = new AdjListGraphArc(p->adjVex);	
                  q = vexTable[v].firstarc;
                  p = p->nextArc;
               }
               else {   
                  q->nextArc = new AdjListGraphArc(p->adjVex);	
                  q = q->nextArc;
                  p = p->nextArc;
               }   
	   }
    }
	return *this;
}

template <class ElemType>
void AdjListDirGraph<ElemType>::Display()
// �������: ��ʾ�ڽӾ�������ͼ
{
	AdjListGraphArc *p;
    cout << "����ͼ����" << vexNum << "�����㣬" << arcNum << "���ߡ�" << endl; 
	for (int v = 0; v < vexNum; v++)	{	// ��ʾ��v���ڽ�����
		cout << v << ":\t" << vexTable[v].data;				// ��ʾ�����
	    p = vexTable[v].firstarc;
	    while (p != NULL) {
        	cout << "-->(" << p->adjVex << ")";
            p = p->nextArc; 
		}
		cout << endl; 
	}
}

#endif
