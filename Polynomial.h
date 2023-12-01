#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "LinkList.h"			// ������
#include "PolyItem.h"			// ����ʽ����


// ����ʽ��
class Polynomial
{
protected:
// ����ʽʵ�ֵ����ݳ�Ա:
	LinkList<PolyItem> polyList;// ����ʽ��ɵ����Ա�
///////////////////////////////////////////////////////////
	//friend class LinkList<PolyItem>;
///////////////////////////////////////////////////////////

public:
///////////////////////////////////////////////////////////
    // ���һ����������ȡ����ʽ��ͷ���
    Node<PolyItem> *GetHeaditem() const
    {
        return polyList.GetHeadlink();
    }
///////////////////////////////////////////////////////////
	//  �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	Polynomial(){};				// �޲ι��캯��
	~Polynomial(){};			// ��������
	int Length() const;			// �����ʽ������			 
	bool IsZero() const;		// �ж϶���ʽ�Ƿ�Ϊ0
	void SetZero();				// ������ʽ��Ϊ0
	void Display();				// ��ʾ����ʽ
	void InsItem(const PolyItem &item);		// ����һ��
	Polynomial operator +(const Polynomial &p) const; // �ӷ����������
	Polynomial(const Polynomial &copy);			// ���ƹ��캯��
	Polynomial(const LinkList<PolyItem> &copyLinkList);				
		// �ɶ���ʽ��ɵ����Ա������ʽ
	Polynomial &operator =(const Polynomial &copy);	// ��ֵ�������
	Polynomial &operator =(const LinkList<PolyItem> &copyLinkList);	// ��ֵ�������

///////////////////////////////////////////////////////////
	Polynomial operator -(const Polynomial &p) const; // �������������
	int Calculate(int xnum);//����x��ֵ
	Polynomial D();//��
	///////////////////////////////////////////////////////////
};


// ����ʽ���ʵ�ֲ���

///////////////////////////////////////////////////////////
int Polynomial::Calculate(int xnum){
	//������������㵱ǰ����ʽ����x��ֵ
	int result = 0;
    // ��ȡ����ʽ��ͷ���
    Node<PolyItem> *p = GetHeaditem()->next;
    // ��������ʽ��ÿһ��
    while (p != NULL)
    {
        result += p->data.coef * (pow(xnum, p->data.expn));
        p = p->next;
    }
    return result;
}
///////////////////////////////////////////////////////////

int Polynomial::Length() const
// ������������ض���ʽ������
{
	return polyList.GetLength();
}

bool Polynomial::IsZero() const
// ��������������ʽΪ0���򷵻�true�����򷵻�false
{
	return polyList.IsEmpty();
}

void Polynomial::SetZero()
// ���������������ʽ��Ϊ0
{
	polyList.Clear(); 
}

void Polynomial::Display()
// �����������ʾ����ʽ
{
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while ( status == ENTRY_FOUND)	{// ������ʾ����ʽ��ÿһ��
	    if (pos > 1 && it.coef>=0)
          cout<<"+";
        if ( it.coef != 1)
            if (it.coef !=-1)
               cout << it.coef;
            else 
               cout << "-";
        if (it.expn > 1)
           cout << "x^" << it.expn ; 
        else
           if (it.expn == 1)
               cout << "x"  ;
		status = polyList.GetElem(++pos, it);	// ȡ����һ��
	}
}

void Polynomial::InsItem( const PolyItem &item)
// ��������������ʽ����һ��
{
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while ( status == ENTRY_FOUND && it.expn > item.expn) 	// ���Ҳ���λ��
			status = polyList.GetElem(++pos, it);
	polyList.InsertElem(pos, item);					            // �����ʽ����һ��
}

Polynomial Polynomial::operator +(const Polynomial &p) const
// ������������ص�ǰ����ʽ��p֮�͡����ӷ����������
{
	LinkList<PolyItem> la = polyList;			// ��ǰ����ʽ��Ӧ�����Ա�
	LinkList<PolyItem> lb = p.polyList;			// ����ʽp��Ӧ�����Ա�
	LinkList<PolyItem> lc;						// �Ͷ���ʽ��Ӧ�����Ա�
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	Status aStatus, bStatus;
	
	aStatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1�� 
	bStatus = lb.GetElem(bPos++, bItem);			// ȡ��lb�ĵ�1��

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND )	{
		if (aItem.expn > bItem.expn) {		// la�е���aItemָ����С
			lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ı�β 
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
		}
		else if (aItem.expn < bItem.expn) {	// lb�е���bItemָ����С
			lc.InsertElem(bItem);	// ��bItem׷�ӵ�lc�ı�β
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
		else {	// la�е���aItem��lb�е���bItemָ�����
			PolyItem sumItem(aItem.coef + bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// ������ĺ�׷�ӵ�lc�ı�β
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
	}

	while (aStatus == ENTRY_FOUND) {	// ��la��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ĺ���
		aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
	}

	while (bStatus == ENTRY_FOUND) {	// ��lb��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(bItem);	// ��bItem׷�ӵ�lc�ĺ���
		bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
	}

	Polynomial fc;							// �Ͷ���ʽ
	fc.polyList = lc;

	return fc;
}

Polynomial::Polynomial(const Polynomial &copy)
// ����������ɶ���ʽcopy�����¶���ʽ�������ƹ��캯��
{
	polyList = copy.polyList;
}

Polynomial::Polynomial(const LinkList<PolyItem> &copyLinkList)	
// ����������ɶ���ʽ��ɵ����Ա������ʽ����ת�����캯��
{
	polyList = copyLinkList;
}

Polynomial &Polynomial::operator =(const Polynomial &copy)	
// ���������������ʽcopy��ֵ����ǰ����ʽ������ֵ�������
{
	if ( &copy != this)	{
		polyList = copy.polyList;
	}
	return *this;
}

Polynomial &Polynomial::operator =(const LinkList<PolyItem> &copyLinkList)
// ���������������ʽ��ɵ����Ա�copyLinkList��ֵ����ǰ����ʽ
//	������ֵ�������
{
	polyList = copyLinkList;
	return *this;
}

////////////////////////////////////////////////
Polynomial Polynomial::D()
{
	LinkList<PolyItem> la = this->polyList;			// ����ʽp��Ӧ�����Ա�
	LinkList<PolyItem> lc;						// �Ͷ���ʽ��Ӧ�����Ա�
	int aPos = 1,cPos=1;
	PolyItem aItem,cItem,expn_same_Item;//��һ�������ʽʱ�����˶��������ͬ�������Ҫ��������ͬ���󵼺��ϵ���ϲ����˴�expn_same_Item�������Ǽ�¼��ͬ�η�����
	Status aStatus,cStatus;
	
	aStatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1��
	while (aStatus == ENTRY_FOUND)
	{
		expn_same_Item = aItem;
		expn_same_Item.coef = expn_same_Item.coef * expn_same_Item.expn;//����ϵ������
		expn_same_Item.expn -= 1;//ָ������
		if (expn_same_Item.coef == 0)//���ϵ����������ֱ�ӽ�����һ��ѭ��
		{
			aStatus = la.GetElem(aPos++, aItem);
			continue;
		}
		aStatus = la.GetElem(aPos++, aItem);
		if (expn_same_Item.expn + 1 == aItem.expn&& aStatus == ENTRY_FOUND)//��Ҫ�жϴ����Ƿ���ͬҲҪע������Ѿ���������ĩ�ڵ�
		{
			expn_same_Item.coef += aItem.coef * aItem.expn;
			aStatus = la.GetElem(aPos++, aItem);
		}
		lc.InsertElem(expn_same_Item);
		
	}
	Polynomial fc;							// �Ͷ���ʽ
	fc.polyList = lc;

	return fc;
}
////////////////////////////////////////////////
////////////////////////////////////////////////
Polynomial Polynomial::operator-(const Polynomial& p) const
// ������������ص�ǰ����ʽ��p֮����������������
{
	LinkList<PolyItem> la = polyList;			// ��ǰ����ʽ��Ӧ�����Ա�
	LinkList<PolyItem> lb = p.polyList;			// ����ʽp��Ӧ�����Ա�
	LinkList<PolyItem> lc;						// �Ͷ���ʽ��Ӧ�����Ա�
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	PolyItem cItem;

	Status aStatus, bStatus;

	aStatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1�� 
	bStatus = lb.GetElem(bPos++, bItem);			// ȡ��lb�ĵ�1��

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND) {
		if (aItem.expn > bItem.expn) {		// la�е���aItemָ����С
			lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ı�β 
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
		}
		else if (aItem.expn < bItem.expn) {	// lb�е���bItemָ����С
			cItem = bItem;
			cItem.coef = -cItem.coef;
			lc.InsertElem(cItem);	// ��-bItem׷�ӵ�lc�ı�β
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
		else {	// la�е���aItem��lb�е���bItemָ�����
			PolyItem sumItem(aItem.coef - bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// ������Ĳ�׷�ӵ�lc�ı�β
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
	}

	while (aStatus == ENTRY_FOUND) {	// ��la��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ĺ���
		aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
	}

	while (bStatus == ENTRY_FOUND) {	// ��lb��ʣ����׷�ӵ�lc�ĺ���
		cItem = bItem;
		cItem.coef = -cItem.coef;
		lc.InsertElem(cItem);	// ��-bItem׷�ӵ�lc�ĺ���
		bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
	}

	Polynomial fc;							// �����ʽ
	fc.polyList = lc;

	return fc;
}
////////////////////////////////////////////////

#endif
