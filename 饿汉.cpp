class Singleton
{
public:
    static Singleton* Instance();
protected:
    Singleton(){}
private:
    static Singleton* _instance;
};
Singleton* Singleton::_instance = new Singleton();
Singleton* Singleton::Instance()
{
    return _instance;
}
