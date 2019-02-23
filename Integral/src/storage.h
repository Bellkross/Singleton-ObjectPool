#ifndef STORAGE_H_
#define STORAGE_H_

class Storage {
public:

	virtual ~Storage();
	Storage(const Storage&) = delete;
	Storage& operator=(const Storage&) = delete;
	Storage(const Storage&&) = delete;
	Storage&& operator=(const Storage&&) = delete;

};

#endif // STORAGE_H_