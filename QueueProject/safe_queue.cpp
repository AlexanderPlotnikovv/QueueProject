#include "safe_queue.h"

bool safe_queue::empty()
{
	return q.empty();
}

void safe_queue::push(std::function<void()> f)
{
	std::unique_lock<std::mutex> lock(mx);
	q.push(f);
	std::cout << "push" << std::endl;
	cv.notify_one();
}

std::function<void()> safe_queue::pop()
{
	std::unique_lock<std::mutex> lock(mx);
	cv.wait(lock, [this] {return !q.empty(); });
	auto f = std::move(q.front());
	q.pop();
	std::cout << "pop" << std::endl;
	cv.notify_one();
	return f;
}
