#ifndef STORAGE_H_
#define STORAGE_H_

template <class T>
class Storage {
public:
	Storage() = default;
	Storage(const Storage&) = delete;
	Storage& operator=(const Storage&) = delete;
	Storage(const Storage&&) = delete;
	Storage&& operator=(const Storage&&) = delete;

	virtual bool isEmpty() const = 0;
	virtual T* getResource() = 0;
	virtual void returnResource(T* resource) = 0;
	virtual int getItemsCount() const = 0;
	virtual ~Storage() = default;
};

#endif // STORAGE_H_