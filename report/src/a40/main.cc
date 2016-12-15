#include "main.ih"

int main(int argc, char **argv)
{
	mutex queueLock;
	
	SafeQueue sQueue(&queueLock);
	
	sQueue.push("Test1");
	sQueue.push("Test2");
	sQueue.push("Test3");
	sQueue.push("Test4");
	sQueue.push("Test5");
	sQueue.push("Test6");
	
	thread worker(printer, std::ref(sQueue), &queueLock);
	
	worker.join();
}
