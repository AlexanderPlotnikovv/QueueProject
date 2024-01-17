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
	std::vector<std::thread> tasks;
	safe_queue q;
	std::mutex mx;
	std::condition_variable cv;
	bool flag = false;
public:
	thread_pool();
	void work();
	void submit(std::function<void()> func);
	~thread_pool();
};