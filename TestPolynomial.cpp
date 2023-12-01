#include "Assistance.h"	// ʵ�ó��������
#include "Polynomial.h"	// ����ʽ��
int main(void)
{
	int c = 1;
    Polynomial fa, fb, fc, fcal;
    PolyItem it;

    while (c != 0){
        cout << endl << "1. ���ɶ���ʽ.";
        cout << endl << "2. ��ʾ����ʽ.";
        cout << endl << "3. ����ʽ�ӷ�.";
		cout << endl << "4. ����ʽ����.";
		cout << endl << "5. ����ʽ��.";
		cout << endl << "6. ����ʽ��ֵ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~6):";
		cin >> c;
		switch (c) 	{
			case 1:
				cout << endl << "����(coef, expn)(expn = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				break;
			case 2:
			    fa.Display();
				break;
			case 3:
				// ����fa
				fa.SetZero();		// ��fa����Ϊ0
				cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				// ����fb
				fb.SetZero();		// ��fb����Ϊ0
				cout << endl << "����fb����(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				fc = fa + fb;
			    cout << "fa:" << endl;			// ��ʾfa
				fa.Display();
			    cout << endl;			

			    cout << "fb:" << endl;			// ��ʾfa
				fb.Display();
			    cout << endl;			

			    cout << "fa + fb:" << endl;		// ��ʾfc = fa + fb
				fc.Display();
			    cout << endl;			
				break;
			case 4:
				// ����fa
				fa.SetZero();		// ��fa����Ϊ0
				cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1) {
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				// ����fb
				fb.SetZero();		// ��fb����Ϊ0
				cout << endl << "����fb����(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1) {
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				fc = fa - fb;
				cout << "fa:" << endl;			// ��ʾfa
				fa.Display();
				cout << endl;

				cout << "fb:" << endl;			// ��ʾfa
				fb.Display();
				cout << endl;

				cout << "fa - fb:" << endl;		// ��ʾfc = fa - fb
				fc.Display();
				cout << endl;
				break;
			case 5:
				// ����fa
				fa.SetZero();		// ��fa����Ϊ0
				cout << endl << "����fa����(coef, expn)(e = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1) {
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				cout << "��ǰ����ʽΪ��";
				fa.Display();
				cout << endl << "�󵼺����ʽΪ��";
				fa.D().Display();
				cout << endl;
				break;
			case 6:
				fa.SetZero();
			    cout << endl << "����(coef, expn)(expn = -1ʱ�˳�):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				fa.Display();
				cout << endl;
				int xnum=0;
				cout << "����x��ֵ" << endl;
				cin >> xnum;
				int result = fa.Calculate(xnum);
				cout << "�ö���ʽ��x=" << xnum << "ʱ��ֵΪ��" << result << endl;
				break;
		}
	}
	system("PAUSE");				// ���ÿ⺯��system()
	return 0;						// ����ֵ0, ���ز���ϵͳ
}
