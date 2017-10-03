#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class IntArray {
public:					// "Public" allows everything written
	IntArray(int size);		// within the section to be accessed
	~IntArray();			// by outside sources
	int & operator[](int i) const;
	int size() const;
	void fill(int k);
	int * begin() {
		return data;
	};
	int * end() {
		return (data + len);
	};
private:		// "Private" makes code only accessable within
	int len;	// the IntArray class
	int * data;
};

IntArray::IntArray(int size) {	// Constructor - allocates memory for
	len = size;		// the IntArray stored as "data"
	data = new int[len];
};

IntArray::~IntArray() {		// Destructor - deletes the allocated
	delete [] data;		// memory stored for the IntArray
};

int & IntArray::operator[](int i) const {	// Defines the operator[] to allow
	return data[i];				// returning of specific data values
};

int IntArray::size() const {	// Returns the given length
	return len;		// or size of the IntArray
};

void IntArray::fill(int k) {		// Fills all the slots in data with
	for(int i = 0; i < len; i++) {	// the given value of "k"
		data[i] = k;
	}
};

int main(int argc, char * args[]) {
	IntArray a(3);
	a[0] = 10;
	a[1] = 11;
        a[2] = 12;
        assert(a[0] == 10);	// assert() is used to check if the given
        assert(a[1] == 11);	// statement is true without printing to the screen
        assert(a[2] == 12);
        assert(a.size() == 3);
        a.fill(5);
        assert(a[0] == 5);
        assert(a[1] == 5);
        assert(a[2] == 5);
        a[0] = 3;
        a[1] = 1;
        a[2] = 2;
        sort(a.begin(), a.end());
        assert(a[0] == 1);
        assert(a[1] == 2);
        assert(a[2] == 3);
        int * it = a.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
        ++it;
        assert(*it == 3);
        ++it;
        assert(it == a.end());

	cout << "All tests passed." << endl;
}
