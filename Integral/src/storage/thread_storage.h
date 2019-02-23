#ifndef THREAD_STORAGE_H_
#define THREAD_STORAGE_H_

#include "storage.h"

#include <thread>
#include <queue>

using namespace std;

class ThreadStorage : public Storage<thread> {
public:

	static ThreadStorage& getInstance();

	ThreadStorage(const ThreadStorage&) = delete;
	ThreadStorage& operator=(const ThreadStorage&) = delete;
	ThreadStorage(const ThreadStorage&&) = delete;
	ThreadStorage&& operator=(const ThreadStorage&&) = delete;

	bool isEmpty() const override;
	thread* getResource() override;
	void returnResource(thread* resource) override;
	int getItemsCount() const override;
	~ThreadStorage() override;
private:
	static ThreadStorage* instance;

	ThreadStorage();
	ThreadStorage(int capacity);

	static const int defaultCapacity;
	queue<thread*> resources;

	void fill(int n);
};

#endif // THREAD_STORAGE_H_