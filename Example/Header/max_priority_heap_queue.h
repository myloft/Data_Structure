#ifndef __MAX_PRIORITY_HEAP_QUEUE__H__
#define __MAX_PRIORITY_HEAP_QUEUE__H__

// ������ȶѶ�����
template<class ElemType>
class MaxPriorityHeapQueue 
{
protected:
//  ������ȶѶ���ʵ�ֵ����ݳ�Ա:
	ElemType *elem;									// �洢�ѵ�����
	int size;										// �����Ԫ�ظ���
	int count;										// ��Ԫ�ظ���

// ��������:
	void Init(int sz);								// ��ʼ�����ȶ���
	void SiftAdjust(int low, int high);
		// ����elem[low]ʹ��elem[low .. high]���ؼ��ֳ�Ϊһ���󶥶�
	void BuildHeap();								// ������

public:
//  �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	MaxPriorityHeapQueue(int sz = DEFAULT_SIZE);	// �������Ԫ�ظ���Ϊsz�Ķ�
	MaxPriorityHeapQueue(ElemType e[], int cnt = 0, int sz = DEFAULT_SIZE);	
		// �����Ԫ��Ϊe[0] ...e[cnt - 1], ���Ԫ�ظ�Ϊsz�Ķ�
	virtual ~MaxPriorityHeapQueue();				// ��������
	int Length() const;								// �����ȶ��г���			 
	bool Empty() const;								// �ж����ȶ����Ƿ�Ϊ��
	void Clear();									// �����ȶ������
	void Traverse(void (*Visit)(ElemType &)) ;		// �������ȶ���
	StatusCode OutQueue(ElemType &e);				// ���Ӳ���
	StatusCode GetHead(ElemType &e) const;			// ȡ��ͷ����
	StatusCode InQueue(const ElemType &e);			// ��Ӳ���
	MaxPriorityHeapQueue(const MaxPriorityHeapQueue<ElemType> &copy);		// ���ƹ��캯��
	MaxPriorityHeapQueue<ElemType> &operator =(const MaxPriorityHeapQueue<ElemType> &copy);
		// ��ֵ�������
};

// ������ȶѶ������ʵ�ֲ���
template <class ElemType>
void MaxPriorityHeapQueue<ElemType>::Init(int sz)
// �����������ʼ�����Ԫ�ظ���Ϊsz���ȶ���
{
	elem = new ElemType[sz];						// Ϊ�ѷ���洢�ռ�
	size = sz;										// �����Ԫ�ظ���
	count = 0;										// ��Ԫ�ظ���
}

template <class ElemType>
void MaxPriorityHeapQueue<ElemType>::SiftAdjust(int low, int high)
// �������:elem[low .. high]�м�¼�Ĺؼ��ֳ�elem[low]���ⶼ����Ѷ���,��
//	��elem[low]ʹ��elem[low .. high]���ؼ��ֳ�Ϊһ���󶥶�
{
	for (int f = low, i = 2 * low + 1; i <= high; i = 2 * i + 1)
	{	// fΪ���������,iΪf�����ؼ��ֺ���
		if (i < high && elem[i] < elem[i + 1])
		{	// �Һ��ӹؼ��ָ���, iָ���Һ���
			i++;
		}
		if (elem[f] >= elem[i])
		{	// �ѳ�Ϊ�󶥶�
			break;
		}
		Swap(elem[f], elem[i]);						// ����elem[f], elem[i]
		f = i;										// ��Ϊ�µĵ������		
	}
}

template<class ElemType>
void MaxPriorityHeapQueue<ElemType>::BuildHeap()
// �������:�����󶥶�
{
	int i;
	for (i = (count - 2) / 2; i >= 0; --i) 
	{	// ��elem[0 .. count - 1]�����ɴ󶥶�
		SiftAdjust(elem, i, count - 1);
	};
}

template<class ElemType>
MaxPriorityHeapQueue<ElemType>::MaxPriorityHeapQueue(int sz)
// �������������һ�����Ԫ�ظ���Ϊsz�Ŀ����ȶ���
{
	Init(sz);										// ��ʼ����
}

template<class ElemType>
MaxPriorityHeapQueue<ElemType>::MaxPriorityHeapQueue(ElemType e[], int cnt, int sz)	
// ��������������Ԫ��Ϊe[0] ...e[cnt - 1], ���Ԫ�ظ�����Ϊsz�Ķ�
{
	Init(sz);										// ��ʼ����
	for (int pos = 0; pos < cnt; pos++)
	{	// ��e[]��ֵ��elem[]
		elem[pos] = e[pos];
	}
	BuildHeap();									// ������
}

template<class ElemType>
MaxPriorityHeapQueue<ElemType>::~MaxPriorityHeapQueue()
// ����������������ȶ���
{
	delete []elem;									// �ͷŶ���ռ�ô洢�ռ�
}

template<class ElemType>
int MaxPriorityHeapQueue<ElemType>::Length() const
// ����������������ȶ��г���			 
{
	return count;
}

template<class ElemType>
bool MaxPriorityHeapQueue<ElemType>::Empty() const
// ��������������ȶ���Ϊ�գ��򷵻�true�����򷵻�false
{
   return count == 0;
}

template<class ElemType>
void MaxPriorityHeapQueue<ElemType>::Clear() 
// ���������������ȶ���
{
	count = 0;										// �����ȶ���Ԫ�ظ���Ϊ0 
}

template <class ElemType>
void MaxPriorityHeapQueue<ElemType>::Traverse(void (*Visit)(ElemType &))
// ������������ζ����ȶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
	for (int pos = 0; pos < count; pos++)
	{	// �����ȶ���ÿ��Ԫ�ص��ú���(*visit)
		(*Visit)(elem[pos]);
	}
}

template<class ElemType>
StatusCode MaxPriorityHeapQueue<ElemType>::OutQueue(ElemType &e)
// ���������������ȶ��зǿգ���ôɾ���Ѷ�Ԫ�أ�����e������ֵ����������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!Empty()) 
	{	// ���ȶ��зǿ�
		e = elem[0];								// ��e���ضѶ�Ԫ��ֵ
		Swap(elem[0], elem[count - 1]);				// ���Ѷ�Ԫ�غ����һ��Ԫ�ؽ���
		SiftAdjust(0, count - 2);					// ��elem[0 .. count - 2]���µ���Ϊ�󶥶�
		count--;									// ɾ���Ѷ�Ԫ�غ�, Ԫ�ظ����Լ�1
		return SUCCESS;								// �����ɹ�
	}
	else
	{	// ���ȶ���Ϊ��
		return UNDER_FLOW;							// ����ʧ��
	}
}

template<class ElemType>
StatusCode MaxPriorityHeapQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ضѶ�Ԫ�أ���������SUCCESS,
//	����������UNDER_FLOW��
{
	if (!Empty()) 
	{	// ���ȶ��зǿ�
		e = elem[0];								// ��e���ضѶ�Ԫ��
		return SUCCESS;
	}
	else
	{	// ����Ϊ��
		return UNDER_FLOW;
	}
}

template<class ElemType>
StatusCode MaxPriorityHeapQueue<ElemType>::InQueue(const ElemType &e)
// �������������Ԫ��e�������ɹ�����SUCCESS,��񷵻�OVER_FLOW
{
	if (count >= size)
	{	// ���Ѹ�, ���
		return OVER_FLOW;
	}
	else
	{	// ��δ��, �ɲ���Ԫ��e
		int curPos = count++;						// ��ǰλ��
		int parent = (curPos - 1) / 2;				// ��ǰ��˫��	
		elem[curPos] = e;							// ��ʼʱ��Ԫ��e�����ڶѵ�ĩ��
		while (curPos > 0 && elem[curPos] > elem[parent])
		{	// elem[curPos]����˫��, ��˫�׽���
			Swap(elem[curPos], elem[parent]);		// ����elem[curPos]��˫��Ԫ��elem[parent]
			curPos = parent;						// ��˫����Ϊ�µ�ǰλ��
			parent = (curPos - 1) / 2;				// ��ǰ˫��	
		}
		return SUCCESS;								// �����ɹ�
	}
}

template<class ElemType>
MaxPriorityHeapQueue<ElemType>::MaxPriorityHeapQueue(const MaxPriorityHeapQueue<ElemType> &copy)
// ��������������ȶ���copy���������ȶ���--���ƹ��캯��
{
	Init(copy.count);								// ��ʼ����ǰ���ȶ���
	count = copy.count;								// �����ȶ��е�Ԫ�ظ���
	for (int pos = 0; pos < count; pos++)
	{	// ��copy���ȶ���ÿ��Ԫ�ظ�ֵ����ǰ���ȶ�
		elem[pos] = copy.elem[pos];
	}
}

template<class ElemType>
MaxPriorityHeapQueue<ElemType> &MaxPriorityHeapQueue<ElemType>::operator =(const MaxPriorityHeapQueue<ElemType> &copy)
// ��������������ȶ���copy��ֵ����ǰ���ȶ���--��ֵ�������
{
	if (&copy != this)
	{
		delete []elem;								// �ͷſռ�
		Init(copy.count);							// ��ʼ����ǰ���ȶ���
		count = copy.count;							// �����ȶ��е�Ԫ�ظ���
		for (int pos = 0; pos < count; pos++)
		{	// ��copy���ȶ���ÿ��Ԫ�ظ�ֵ����ǰ���ȶ�
			elem[pos] = copy.elem[pos];
		}
	}
	return *this;
}

#endif