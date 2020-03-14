// 工厂方法
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

/* 抽象工厂 */
class Factory
{
public:
	/* 提供抽象生产接口，由各个具体工厂实现 */
	virtual phoneBase* createPhone() = 0;
};

/* OPPO工厂 —— 专门负责生产OPPO手机 */
class OPPOFactory : public Factory
{
public:
	phoneBase* createPhone()
	{
		return new OPPOPhone();
	}
};

/* VIVO工厂 —— 专门负责生产VIVO手机 */
class VIVOFactory : public Factory
{
public:
	phoneBase* createPhone()
	{
		return new VIVOPhone();
	}
};

/* HUAWEI工厂 —— 专门负责生产HUAWEI手机 */
class HUAWEIFactory : public Factory
{
public:
	phoneBase* createPhone()
	{
		return new HUAWEIPhone();
	}
};


int main()
{
	OPPOFactory Ofactory;
	phoneBase* p1 = Ofactory.createPhone();
	p1->show();

	VIVOFactory Vfactory;
	phoneBase* p2 = Vfactory.createPhone();
	p2->show();

	HUAWEIFactory Hfactory;
	phoneBase* p3 = Hfactory.createPhone();
	p3->show();

	delete p1;
	delete p2;
	delete p3;
	return 0;
}
