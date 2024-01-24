#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <functional>
#include <chrono>
#include <condition_variable>

#include "thread_pool.h"

void f()
{
	std::cout << "f called" << std::endl;
}
int main()
{
	thread_pool tp;
	tp.submit(f);
	tp.submit(f);
	tp.work();
	return 0;
}