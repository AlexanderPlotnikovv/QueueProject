#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <functional>
#include <chrono>
#include <condition_variable>

#include "safe_queue.h"

class thread_pool
{
	std::vector<std::thread> vec;
	safe_queue q;
public:
	thread_pool();
	void work();
	void submit(std::function<void()> func);
	~thread_pool();
};