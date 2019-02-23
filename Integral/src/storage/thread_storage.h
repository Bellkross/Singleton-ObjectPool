#ifndef THREAD_STORAGE_H_
#define THREAD_STORAGE_H_

#include "storage.h"

#include <thread>
#include <queue>

using namespace std;

class ThreadStorage : public Storage<thread> {
public:
	ThreadStorage();
	ThreadStorage(int capacity);
	ThreadStorage(const ThreadStorage&) = delete;
	ThreadStorage& operator=(const ThreadStorage&) = delete;
	ThreadStorage(const ThreadStorage&&) = delete;
	ThreadStorage&& operator=(const ThreadStorage&&) = delete;

	bool isEmpty() const override;
	thread* getResource() override;
	void returnResource(const thread* resource) override;
	int getItemsCount() const override;
	int getCapacity() const override;
	~ThreadStorage() override;
private:
	static const int defaultCapacity;
	queue<thread*> resources;
	int capacity;
	int itemsCount;
};

#endif // THREAD_STORAGE_H_