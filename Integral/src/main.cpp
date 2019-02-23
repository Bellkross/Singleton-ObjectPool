#include <iostream>
#include "storage/thread_storage.h"

using namespace std;

int main() {
	Storage<thread>& ts = ThreadStorage::getInstance();
	return 0;
}