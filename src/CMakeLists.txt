add_executable(simple_thread simple_thread.cpp)
target_link_libraries (simple_thread Threads::Threads)

add_executable(thread_container thread_container.cpp)
target_link_libraries (thread_container Threads::Threads)

add_executable(thread_lock thread_lock.cpp)
target_link_libraries (thread_lock Threads::Threads)

add_executable(thread_scope_lock thread_scope_lock.cpp)
target_link_libraries (thread_scope_lock Threads::Threads)

add_executable(atomic_shared_ptr atomic_shared_ptr.cpp)
target_link_libraries (atomic_shared_ptr Threads::Threads)

add_executable(simple_asyn simple_asyn.cpp)
target_link_libraries (simple_asyn Threads::Threads)
