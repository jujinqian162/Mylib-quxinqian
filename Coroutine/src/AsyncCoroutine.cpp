#include <future>
#include <thread>
#include "AsyncCoroutine.h"

std::future<void> co::sleep(long long int miliseconds)
{
    return std::async([=]{
       	std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
    });
}
