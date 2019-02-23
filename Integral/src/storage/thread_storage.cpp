#include "thread_storage.h"

#include <mutex>

ThreadStorage* ThreadStorage::instance = 0;
const int ThreadStorage::defaultCapacity = 16;

ThreadStorage& ThreadStorage::getInstance() {
	if (instance == 0) {
		lock_guard<mutex> lockGuard(mutex);
		if (instance == 0) {
			instance = new ThreadStorage;
		}
	}
	return *instance;
}


ThreadStorage::ThreadStorage() : Storage<thread>() {
	fill(defaultCapacity);
}

ThreadStorage::ThreadStorage(int capacity) : Storage<thread>() {
	fill(capacity);
}

ThreadStorage::~ThreadStorage() {
	while (!resources.empty()) {
		thread* resource = resources.front();
		resources.pop();
		delete resource;
	}
}

bool ThreadStorage::isEmpty() const { 
	return resources.empty(); 
}

thread* ThreadStorage::getResource() {
	thread* resource = resources.front();
	resources.pop();
	return resource;
}

void ThreadStorage::returnResource(thread* resource) { 
	delete resource;
}

int ThreadStorage::getItemsCount() const { 
	return resources.size();
}

void ThreadStorage::fill(int n) {
	for (int i = 0; i < n; ++i) {
		resources.push(new thread());
	}
}