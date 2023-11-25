cmake_minimum_required(VERSION 3.22.0)
project(QueueProject)
add_executable (QueueProject main.cpp thread_pool.cpp thread_pool.h "safe_queue.h" "safe_queue.cpp")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
 # set_property(TARGET QueueProject PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
