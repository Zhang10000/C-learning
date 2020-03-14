class Singleton
{
public:
    static Singleton* Instance();
protected:
    Singleton(){}
private:
    static Singleton* _instance;
};

Singleton* Singleton::_instance = NULL;

Singleton* Singleton::Instance()
{
    if (_instance == NULL)
        _instance = new Singleton;
    return _instance;
}
