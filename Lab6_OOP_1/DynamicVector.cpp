// This file contains the implementation of the class "DynamicVector"
using namespace std;
#include <iostream>
#include "DynamicVector.h"

TElement* DynamicVector::getAllElems() const
{
	// This method returns all the elements from the vector
	return this->elems;
}

DynamicVector::DynamicVector(int capacity)
{
	// The default constructor
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector &v)
{
	// The copy constructor
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	// The destructor
	delete[] this->elems;
}

void DynamicVector::resize(double factor)
{
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number)
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

int DynamicVector::getSize() const
{
	// This method returns the length of the vector
	return this->size;
}

void DynamicVector::deleteElement(const TElement& e, int index)
{
	//this->elems[index] =  NULL;
	if (index >= 0 && index < this->size)
	{
		for (int i = index; i < this->size - 1; i++)
		{
			this->elems[i] = this->elems[i + 1];
			//this->elems[i + 1] = NULL;
		}
		this->size = size - 1;
		if (this->size > 0 && this->size == this->capacity / 4)
			resize(2);
	}
}

void DynamicVector::add(const TElement& e)
{
	// Adds an element to the current DynamicVector
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}