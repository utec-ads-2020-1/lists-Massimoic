cmake_minimum_required(VERSION 3.15)
project(list)

set(CMAKE_CXX_STANDARD 14)

add_executable(list main.cpp structures/queue.h structures/stack.h structures/lists/list.h structures/lists/linked.h structures/lists/circular.h structures/lists/forward.h structures/lists/node.h mock/mocker.h mock/mocker.cpp test/tester.cpp test/tester.h structures/lists/iterators/forward_iterator.h structures/lists/iterators/bidirectional_iterator.h)