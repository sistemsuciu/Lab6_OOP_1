// This file contains the implementation of the classes "FileException", "RepositoryException",
// "DuplicateMovieException" and "InexistentMovieException"

#include "RepositoryExceptions.h"

FileException::FileException(const std::string &message) : message(message)
{
	// A constructor with one parameter.
}

const char *FileException::what()
{
	// This method returns the message of the error.
	return message.c_str();
}

RepositoryException::RepositoryException(): exception{}, message{""}
{
	// A constructor based on inheritance from the standard exception class.
}

RepositoryException::RepositoryException(const std::string &message) : message{ message }
{
	// A constructor with one parameter.
}

const char *RepositoryException::what()
{
	// This method returns the message of the error.
	return this->message.c_str();
}

const char *DuplicateMovieException::what()
{
	// This method is called when another movie with the same ID was found and returns a message for the user.
	return "There is another movie with the given ID.";
}

const char *InexistentMovieException::what()
{
	// This method is called when no movie with the given ID was found and returns a message for the user.
	return "There are no movies with the given ID.";
}