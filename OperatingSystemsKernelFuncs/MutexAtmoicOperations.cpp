#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

class simpleMutex{
    private:
    std::atomic_flag lock_flag = ATOMIC_FLAG_INIT;

    public:
    void lock(){
        // Spin until we acquire the lock
        while(lock_flag.test_and_set(std::memory_order_acquire));
    }

    void unlock(){
        lock_flag.clear(std::memory_order_release);
    }
};

simpleMutex my_mutex;
int shared_counter = 0;

void increment(const std::string& thread_name){
    for(int i = 0; i < 1000; i++){
        my_mutex.lock();
        ++shared_counter;
        // unlock
        my_mutex.unlock();
    }
}


int main(){

    vector<thread> threads;
    for(int i = 0; i <  5; i++){
        threads.emplace_back(increment, "T" + to_string(i+1));
    }

    // wait for all threads finish operation
    for(auto& t: threads){
        t.join();
    }

    cout << "final counter (should be 5000): " << shared_counter << endl;

    return 0;
}
