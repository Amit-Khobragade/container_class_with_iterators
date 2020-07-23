#pragma once
#include <iostream>
#include <typeinfo>

template<typename T>
class ring {
private:
	T* obj;
	size_t max_size, current_pos, current_size;

public:
	class iterator;

public:
	ring( size_t ini_size )
		:max_size{ ini_size }, current_pos{ 0 }, current_size{ 0 }
	{
		obj = new T[ini_size];
	}

	ring( ring& other )
		:max_size{ other.max_size }, current_pos{ other.current_pos },
		current_size{ other.current_size }
	{
		obj = new T[other.max_size];
		for (size_t i = 0; i < current_size; ++i) {
			this->add( other.obj[i] );
		}
	}

	void add( T to_add ) {
		obj[current_pos] = to_add;
		++current_pos;
		if (current_size < (max_size ))
			current_size++;
		if (current_pos >= max_size )
			current_pos = 0;
	}

	friend std::ostream& operator<<( std::ostream& os, ring<T>& R ) {
		for (size_t i = 0; i < R.current_size; ++i)
			os << R.obj[i];
		return os;

	}
	
	size_t size() { return current_size; };

	iterator begin() {
		return iterator( 0, *this );
	}

	iterator end() {
		return iterator( size(), *this );
	}

	~ring() {
		delete[] obj;
	}
};

template<typename T>
class ring<T>::iterator {
private:
	size_t current_pos;
	ring it_ring;
public:
	iterator( size_t current_pos, ring<T> R )
		:current_pos{ current_pos }, it_ring{ R }
	{}
	iterator( iterator& other )
		:current_pos{ other.current_pos }, it_ring{ other.it_ring }
	{}
	iterator (iterator&& other)
		:current_pos{ other.current_pos }, it_ring{ other.it_ring }
	{}
	iterator& operator++(int) {
		current_pos++;
		return *this;
	}
	iterator& operator++() {
		current_pos++;
		return *this;
	}
	T operator*() {
		return it_ring.obj[current_pos];
	}

	bool operator==( iterator other ) {
		return (this->current_pos == other.current_pos);
	}

	bool operator!=( iterator other ) {
		return !(*this == other);
	}
};