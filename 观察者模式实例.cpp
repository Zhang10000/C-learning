#include <iostream>
#include <list>
using namespace std;

/* 抽象观察者 */
class AbstractHero
{
public:
	virtual void update() = 0;
};

/* 具体观察者：召唤师1 */
class Hero1 : public AbstractHero
{
public:
	Hero1()
	{
		cout << "Hero1 join" << endl;
	}
	void update()
	{
		cout << "Hero1 stop to attack Boss" << endl;
	}
};

/* 具体观察者：召唤师2 */
class Hero2 : public AbstractHero
{
public:
	Hero2()
	{
		cout << "Hero2 join" << endl;
	}
	void update()
	{
		cout << "Hero2 stop to attack Boss" << endl;
	}
};

/* 具体观察者：召唤师3 */
class Hero3 : public AbstractHero
{
public:
	Hero3()
	{
		cout << "Hero3 join" << endl;
	}
	void update()
	{
		cout << "Hero3 stop to attack Boss" << endl;
	}
};

/* 具体观察者：召唤师4 */
class Hero4 : public AbstractHero
{
public:
	Hero4()
	{
		cout << "Hero4 join" << endl;
	}
	void update()
	{
		cout << "Hero4 stop to attack Boss" << endl;
	}
};

/* 抽象目标 */
class AbstractBoss
{
public:
	/* 添加观察者 */
	virtual void Add(AbstractHero* hero) = 0;

	/* 删除观察者 */
	virtual void Remove(AbstractHero* hero) = 0;

	/* 通知所有观察者 */
	virtual void Notify() = 0;
};

/* 具体目标：Boss */
class Boss : public AbstractBoss
{
public:

	/* 添加观察者 */
	void Add(AbstractHero* hero)
	{
		heroList.push_back(hero);
	}
	
	/* 删除观察者 */
	void Remove(AbstractHero* hero)
	{
		heroList.remove(hero);
	}

	/* 通知所有观察者 */
	void Notify()
	{
		auto it = heroList.begin();
		while (it != heroList.end())
		{
			(*it)->update();
			++it;
		}
	}
private:
	list <AbstractHero*> heroList;
};
int main()
{
	/* 创建观察者：4位召唤师 */
	AbstractHero* hero1 = new Hero1;
	AbstractHero* hero2 = new Hero2;
	AbstractHero* hero3 = new Hero3;
	AbstractHero* hero4 = new Hero4;

	/* 创建目标：Boss */
	AbstractBoss* bossA = new Boss;

	/* 添加观察者到目标 */
	bossA->Add(hero1);
	bossA->Add(hero2);
	bossA->Add(hero3);
	bossA->Add(hero4);

	/* 移除观察者三号召唤师 */
	cout << endl << "Hero3 die, Remove Hero3" << endl << endl;
	bossA->Remove(hero3);

	/* 轮询通知 */
	cout << endl << "Boss die, Notify other heros" << endl << endl;
	bossA->Notify();
}
