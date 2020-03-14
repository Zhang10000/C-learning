// 抽象工厂
#include <iostream>
using namespace std;

/* 定义手机类型 */
enum PRODUCTTYPE { OPPO, VIVO, HUAWEI };

/* 定义其他产品类型：芯片、配件 */
enum OTHERTYPE { IC, CASE }; 

/* 定义抽象产品phone */
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

/* 定义抽象产品OTHER */
class OTHERBase
{
public:
	virtual ~OTHERBase() {};
	virtual void show() = 0;
};

/* OPPO具体产品OTHER */
class OPPOOTHER :public OTHERBase
{
public:
	void show() { cout << "OPPO OTHER PRODUCT" << endl; }
};

/* VIVO具体产品OTHER */
class VIVOOTHER :public OTHERBase
{
public:
	void show() { cout << "VIVO OTHER PRODUCT" << endl; }
};

/* HUAWEI具体产品OTHER */
class HUAWEIOTHER :public OTHERBase
{
public:
	void show() { cout << "HUAWEI OTHER PRODUCT" << endl; }
};

/* 抽象工厂 : 提供了产品的生成方法。 */
class Factory
{
public:
	virtual phoneBase* createPhone() = 0;
	virtual OTHERBase* createOther() = 0;
};

/* OPPO具体工厂：实现了OPPO产品族的生成方法。 */
class OPPOFactory : public Factory
{
public:
	phoneBase* createPhone()
	{
		return new OPPOPhone();
	}

	OTHERBase* createOther()
	{
		return new OPPOOTHER();
	}
};

/* VIVO具体工厂：实现了VIVO产品族的生成方法。 */
class VIVOFactory : public Factory
{
public:
	phoneBase* createPhone()
	{
		return new VIVOPhone();
	}

	OTHERBase* createOther()
	{
		return new VIVOOTHER();
	}
};

/* HUAWEI具体工厂：实现了HUAWEI产品族的生成方法。 */
class HUAWEIFactory : public Factory
{
public:
	phoneBase* createPhone()
	{
		return new HUAWEIPhone();
	}

	OTHERBase* createOther()
	{
		return new HUAWEIOTHER();
	}
};


int main()
{
	OPPOFactory Ofactory;
	phoneBase* p1 = Ofactory.createPhone();
	OTHERBase* p2 = Ofactory.createOther();
	p1->show();
	p2->show();

	VIVOFactory Vfactory;
	phoneBase* p3 = Vfactory.createPhone();
	OTHERBase* p4 = Vfactory.createOther();
	p3->show();
	p4->show();

	HUAWEIFactory Hfactory;
	phoneBase* p5 = Hfactory.createPhone();
	OTHERBase* p6 = Hfactory.createOther();
	p5->show();
	p6->show();

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	return 0;
}
