#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

#define DEFAULT_SIZE 50;

class disjointSet
{
private:
	int _totalSize;
	std::vector<int> _size;
	std::vector<int> _set;
public:
	disjointSet(int size) {
		_totalSize = size;
		_set.resize(_totalSize);
		_size.resize(_totalSize);
		for (int i = 0; i < size; i++) {
			_set[i] = i;
			_size[i] = 0;
		}
	}

	disjointSet() {
		_totalSize = DEFAULT_SIZE;
	}

	~disjointSet() {
		_set.clear();
	}

	int find(int x) {
		if (x == _set[x]) return x;
		else _set[x] = find(_set[x]);
	}

	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (x > y) std::swap(x, y);
		_set[y] = x;
		_size[x] += _size[y];
	}

};

