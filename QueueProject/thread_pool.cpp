#include "thread_pool.h"
#include "thread_pool.h"

thread_pool::thread_pool() {}

void thread_pool::work()
{
	vec.push_back(std::thread(q.pop()));
}

void thread_pool::submit(std::function<void()> func)
{
	q.push(func);
}

thread_pool::~thread_pool()
{
	for (auto& func : vec)
	{
		func.join();
	}
}