// This header contains the definition of the class "DynamicVector".
#pragma once
#include "Movie.h"

typedef Movie TElement;

class DynamicVector
{
private:
	// The private attributes:
	TElement * elems;
	int size;
	int capacity;
	void resize(double factor = 2);

public:
	// The default constructor
	DynamicVector(int capacity = 15);

	// The copy constructor
	DynamicVector(const DynamicVector &v);

	// The destructor
	~DynamicVector();

	// The methods
	DynamicVector &operator=(const DynamicVector &v);

	// Adds an element to the current DynamicVector
	void add(const TElement &e);

	// Deletes an element from the current DynamicVector
	void deleteElement(const TElement& e, int index);

	// This method returns the length of the vector
	int getSize() const;

	// This method returns all the elements from the vector
	TElement* getAllElems() const;
};