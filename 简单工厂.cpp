#include <iostream>
using namespace std;

/* 定义手机类型 */
enum PRODUCTTYPE { OPPO, VIVO, HUAWEI };

/* 抽象产品phone */
class phoneBase
{
public:
	virtual ~phoneBase() {};
	virtual void show() = 0;
};

/* OPPO具体产品phone */
class OPPOPhone :public phoneBase
{
public:
	void show() { cout << "OPPO Phone" << endl; }
};

/* VIVO具体产品phone */
class VIVOPhone :public phoneBase
{
public:
	void show() { cout << "VIVO Phone" << endl; }
};

/* HUAWEI具体产品phone */
class HUAWEIPhone :public phoneBase
{
public:
	void show() { cout << "HUAWEI Phone" << endl; }
};

/* 手机工厂 */
class Factory
{
public:
	/* 根据相应的类型进行生产 */
	phoneBase* createPhone(PRODUCTTYPE type)
	{
		switch (type)
		{
		case OPPO:
			return new OPPOPhone(); // 生产OPPO手机
			break;
		case VIVO:
			return new VIVOPhone(); // 生产VIVO手机
			break;
		case HUAWEI:
			return new HUAWEIPhone(); // 生产HUAWEI手机
			break;
		default:break;
		}

	}
};

int main()
{
	Factory factory;

	phoneBase* p1 = factory.createPhone(OPPO);
	p1->show();
	phoneBase* p2 = factory.createPhone(VIVO);
	p2->show();
	phoneBase* p3 = factory.createPhone(HUAWEI);
	p3->show();

	delete p1;
	delete p2;
	delete p3;
	return 0;
}
