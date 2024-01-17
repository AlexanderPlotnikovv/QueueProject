#include "thread_pool.h"
#include "thread_pool.h"

thread_pool::thread_pool()
{
	int threads_count = std::thread::hardware_concurrency();
	for (int i = 0; i < threads_count; ++i)
	{
		tasks.emplace_back([this] {work(); });
	}
}

void thread_pool::work()
{
	while (true && !q.empty())
	{
		auto task = q.pop();
		task();
	}
}

void thread_pool::submit(std::function<void()> func)
{
	q.push(std::move(func));
}

thread_pool::~thread_pool()
{
	for (auto& func : tasks)
	{
		func.join();
	}
}