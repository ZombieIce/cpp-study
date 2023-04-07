#include <future>
#include <iostream>
#include <thread>

int main(int argc, const char **argv) {
  std::packaged_task<int()> task([]() { return 7; });
  std::future<int> result = task.get_future();
  std::thread(std::move(task)).detach();
  result.wait();
  std::cout << "done!" << std::endl
            << "future result is " << result.get() << std::endl;

  return 0;
}