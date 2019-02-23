#ifndef STORAGE_H_
#define STORAGE_H_

template <class T>
class Storage {
public:
	Storage(const Storage&) = delete;
	Storage& operator=(const Storage&) = delete;
	Storage(const Storage&&) = delete;
	Storage&& operator=(const Storage&&) = delete;

	virtual bool isEmpty() const;
	virtual T* getResource();
	virtual void returnResource(const T* resource);
	virtual int getItemCount() const;
	virtual int getCapacity() const;
	virtual ~Storage();
};

#endif // STORAGE_H_