#pragma once
// Symmetric min-max heap implement.
#include <sstream>
#include <algorithm>

template<class T>
class Depq {
public:
	Depq(int initCapacity = 10) {
		if (initCapacity < 1) {
			std::ostringstream s;
			s << "Initial capacity = " << initCapacity << " Must be > 0";
			throw s.str();
		}
		_len = initCapacity + 2;
		_h = new T[_len];
		_last = 1;
	}

	~Depq() { delete[] _h; }
	
	const T& min() const {
		if (_last == 1) throw "Queue is empty";
		return _h[2];
	}

	const T& max() const {
		if (_last == 1) throw "Queue is empty";
		if (_last == 2) return _h[2];
		else return _h[3];
	}

	const bool empty() {
		return _last == 1;
	}

	void push(const T& x) {
		// Promise 1. Each node's element is same or less than right sibling(if exist)'s element.
	// Promise 2. For each node "N" that has grand-parent, element of left child of grand-parent is same or less than element of node "N".
	// Promise 3. For each node "N" that has grand-parent, element of right child fo grand-parent is same or greater than element of ndoe "N".

	// If neccessary increase length of array.
		if (_last == _len - 1) {
			// Make length double.
			T* tmp = new T[_len * 2];
			std::copy(_h, _h + _len, tmp);
			_h = tmp;
			_len *= 2;
		}

		// Search position of x.
		// CurrentNode is start from leaf to upward.
		int currentNode = ++_last;
		if (_last % 2 == 1 && x < _h[_last - 1]) {
			_h[_last] = _h[_last - 1];
			currentNode--;
		}

		bool done = false;
		while (!done && currentNode >= 4) {
			int gp = currentNode / 4;		// Grand-parent.
			int lcgp = 2 * gp;				// Left child of grand-parent.
			int rcgp = lcgp + 1;			// Right child of grand-parent.
			if (x < _h[lcgp]) {
				// Illegal to Promise 2.
				_h[currentNode] = _h[lcgp];
				currentNode = lcgp;
			}
			else if (x > _h[rcgp]) {
				// Illegal to Promise 3.
				_h[currentNode] = _h[rcgp];
				currentNode = rcgp;
			}
			else done = true;				// Not illegal to any of Promises.
		}
		_h[currentNode] = x;
	};

	void pop_min() {
		if (empty()) {
			throw "Queue is empty.";
			return;
		}
		if (_last == 2) {
			for (int i = 2; i < _last; i++) {
				_h[i] = _h[i + 1];
			}
			_last--;
		}
		else {
			T x = _h[_last--];
			for (int i = 2; i < _last; i++) {
				_h[i] = _h[i + 1];
			}
			push(x);
		}
	};

	void pop_max() {
		if (empty()) {
			throw "Queue is empty.";
			return;
		}
		if (_last == 2) {
			for (int i = 2; i < _last; i++) {
				_h[i] = _h[i + 1];
			}
			_last--;
		}
		else if (_last == 3) {
			for (int i = 3; i < _last; i++) {
				_h[i] = _h[i + 1];
			}
			_last--;
		}
		else {
			T x = _h[_last--];
			for (int i = 3; i < _last; i++) {
				_h[i] = _h[i + 1];
			}
			push(x);
		}
	};
private:
	int _last;			// Last element index of queue.
	int _len;			// Capacity of queue + 2.
	T* _h;				// Element array.
};
