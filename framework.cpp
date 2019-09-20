#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
#include <chrono>
#include <unistd.h>
 
std::mutex mtx; // 全局互斥锁.
std::condition_variable cv; // 全局条件变量. 
using namespace std;
 
void consumer(int id)
{
    std::unique_lock <std::mutex> lck(mtx);
    while (true)
    {
        cout << "read " << id << endl;
        cv.wait(lck);  
    }
    // 线程被唤醒, 继续往下执行打印线程编号id.
    std::cout << "thread " << id << '\n';
}
 
void go()
{
    cout << "tell consumer to process. " <<endl; 
    cv.notify_all(); // 唤醒所有线程.
}
 
void
producer(){
    int ok;
    while(1)
    {
        cin >> ok;
        cout <<"ok is"<< ok ;
        if(ok){
            std::cout << "10 threads ready to race...\n";
            sleep(2);
            go(); // go!
        }
        ok = 0;
    }
}
 
 
int main()
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(consumer, i);
    
 
    producer();
 
    
    for (auto & th:threads)
        th.join();
 
    return 0;
}
