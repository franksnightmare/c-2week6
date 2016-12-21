#include "main.ih"

int main(int argc, char **argv)
{
	SafeQueue sQueue;
	
	for (size_t id = 0; id != 32; ++id)
		sQueue.push(std::to_string(id));
	
	thread worker1(printer, std::ref(sQueue));
	
	for (size_t id = 32; id != 64; ++id)
		sQueue.push(std::to_string(id));
	
	thread worker2(printer, std::ref(sQueue));
	
	worker1.join();
	worker2.join();
}
