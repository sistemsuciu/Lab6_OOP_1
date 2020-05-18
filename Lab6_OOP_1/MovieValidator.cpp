// This file contains the implementation of the class "MovieValidator"

#pragma once
#include <iostream>
#include "MovieValidator.h"
using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

void MovieValidator::validate(Movie &movie)
{
	vector<string> errors;
	if (movie.get_id() < 0)
		errors.push_back("The ID must be a positive integer.");
	if (movie.get_title().size() == 0)
		errors.push_back("The title cannot be empty");
	if (movie.get_genre().size() == 0)
		errors.push_back("The genre cannot be empty");
	if (movie.get_apparition_year() > 2018 || movie.get_apparition_year() < 1895)
		errors.push_back("The apparition year must be a number between 1895 and 2018.");

	int www = movie.get_trailer().find("www");
	int http = movie.get_trailer().find("http");
	if (www != 0 && http != 0)
		errors.push_back("The link must start with \"www\" or \"http\".");

	if (errors.size() > 0)
		throw MovieException(errors);

}