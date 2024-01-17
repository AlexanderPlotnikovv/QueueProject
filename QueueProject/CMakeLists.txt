cmake_minimum_required(VERSION 3.22.0)
project(QueueProject)
add_executable (QueueProject main.cpp thread_pool.cpp thread_pool.h "safe_queue.h" "safe_queue.cpp")