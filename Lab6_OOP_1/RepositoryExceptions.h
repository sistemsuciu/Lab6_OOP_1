// This file contains the declarations of the classes "FileException", "RepositoryException", "DuplicateMovieException" and "InexistentMovieException"
#pragma once
#include <exception>
#include <string>

class FileException: public std::exception
{
protected:
	std::string message;

public:
	// A constructor with one parameter.
	FileException(const std::string& msg);

	// This method returns the message of the error.
	virtual const char* what();
};

class RepositoryException: public std::exception
{
protected:
	std::string message;
public:

	// A constructor based on inheritance from the standard exception class.
	RepositoryException();

	// A constructor with one parameter.
	RepositoryException(const std::string &message);
	virtual ~RepositoryException() {}

	// This method returns the message of the error.
	virtual const char * what(); // virtual declaration for POLYMORPHISM
};

class DuplicateMovieException: public RepositoryException // INHERITANCE
{
public:

	// This method is called when another movie with the same ID was found and returns a message for the user.
	const char * what(); // polymorphism
};

class InexistentMovieException : public RepositoryException // INHERITANCE
{
public:

	// This method is called when no movie with the given ID was found and returns a message for the user.
	const char * what(); // polymorphism
};