#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <functional>
#include <chrono>
#include <condition_variable>

//template<class T>
class safe_queue
{
	std::queue<std::function<void()>> q;
	std::mutex mx;
	std::condition_variable cv;
public:
	safe_queue() = default;
	void push(std::function<void()> f);
	std::function<void()> pop();
};