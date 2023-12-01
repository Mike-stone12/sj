#include "Assistance.h"	// 实用程序软件包
#include "Polynomial.h"	// 多项式类
int main(void)
{
	int c = 1;
    Polynomial fa, fb, fc, fcal;
    PolyItem it;

    while (c != 0){
        cout << endl << "1. 生成多项式.";
        cout << endl << "2. 显示多项式.";
        cout << endl << "3. 多项式加法.";
		cout << endl << "4. 多项式减法.";
		cout << endl << "5. 多项式求导.";
		cout << endl << "6. 多项式求值.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~6):";
		cin >> c;
		switch (c) 	{
			case 1:
				cout << endl << "输入(coef, expn)(expn = -1时退出):" << endl;
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
				// 输入fa
				fa.SetZero();		// 将fa设置为0
				cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				// 输入fb
				fb.SetZero();		// 将fb设置为0
				cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				fc = fa + fb;
			    cout << "fa:" << endl;			// 显示fa
				fa.Display();
			    cout << endl;			

			    cout << "fb:" << endl;			// 显示fa
				fb.Display();
			    cout << endl;			

			    cout << "fa + fb:" << endl;		// 显示fc = fa + fb
				fc.Display();
			    cout << endl;			
				break;
			case 4:
				// 输入fa
				fa.SetZero();		// 将fa设置为0
				cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1) {
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				// 输入fb
				fb.SetZero();		// 将fb设置为0
				cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1) {
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				fc = fa - fb;
				cout << "fa:" << endl;			// 显示fa
				fa.Display();
				cout << endl;

				cout << "fb:" << endl;			// 显示fa
				fb.Display();
				cout << endl;

				cout << "fa - fb:" << endl;		// 显示fc = fa - fb
				fc.Display();
				cout << endl;
				break;
			case 5:
				// 输入fa
				fa.SetZero();		// 将fa设置为0
				cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1) {
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				cout << "求导前多项式为：";
				fa.Display();
				cout << endl << "求导后多项式为：";
				fa.D().Display();
				cout << endl;
				break;
			case 6:
				fa.SetZero();
			    cout << endl << "输入(coef, expn)(expn = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)	{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				fa.Display();
				cout << endl;
				int xnum=0;
				cout << "输入x的值" << endl;
				cin >> xnum;
				int result = fa.Calculate(xnum);
				cout << "该多项式当x=" << xnum << "时，值为：" << result << endl;
				break;
		}
	}
	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}
