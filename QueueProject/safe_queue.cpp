#include "safe_queue.h"

//template<class T>
void safe_queue::push(std::function<void()> f)
{
	std::unique_lock<std::mutex> lock(mx);
	cv.wait(lock);
	q.push(f);
	std::cout << "push";
	lock.unlock();
	cv.notify_one();
}

std::function<void()> safe_queue::pop()
{
	std::unique_lock<std::mutex> lock(mx);
	cv.wait(lock);
	auto f = std::move(q.front());
	q.pop();
	lock.unlock();
	cv.notify_one();
	std::cout << "pop";
	return f;
}
