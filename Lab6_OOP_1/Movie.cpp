// This file contains the implementation of the class "Movie"

#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie()
{
	// The default constructor
	ID = 0;
	Title = "";
	Genre = "";
	ApparitionYear = 0;
	NumberOfLikes = 0;
	Trailer = "";
}

Movie::Movie(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer)
{
	// The constructor with parameters
	this->ID = ID;
	this->Title = Title;
	this->Genre = Genre;
	this->ApparitionYear = ApparitionYear;
	this->NumberOfLikes = NumberOfLikes;
	this->Trailer = Trailer;
}

Movie::~Movie()
{
	// The default destructor.
}

int Movie::get_id()
{
	// This method gets the ID of the movie.
	return this->ID;
}

std::string Movie::get_title()
{
	// This method gets the title of the movie.
	return this->Title;
}

std::string Movie::get_genre()
{
	// This method gets the genre of the movie.
	return this->Genre;
}

int Movie::get_apparition_year()
{
	// This method gets the apparition year of the movie.
	return this->ApparitionYear;
}

int Movie::get_number_of_likes()
{
	// This method gets the number of likes of the movie.
	return this->NumberOfLikes;
}

std::string Movie::get_trailer()
{
	// This method gets the trailer of the movie.
	return this->Trailer;
}

void Movie::set_id(int ID)
{
	// This method sets the ID of the movie.
	this->ID = ID;
}

void Movie::set_title(std::string Title)
{
	// This method sets the title of the movie.
	this->Title = Title;
}

void Movie::set_genre(std::string Genre)
{
	// This method sets the genre of the movie.	
	this->Genre = Genre;
}

void Movie::set_apparition_year(int Year)
{
	// This method sets the apparition year of the movie.
	this->ApparitionYear = Year;
}

void Movie::set_number_of_likes(int Number)
{
	// This method sets the number of likes of the movie.
	this->NumberOfLikes = Number;
}

void Movie::set_trailer(std::string Trailer)
{
	// This method sets the trailer of the movie.
	this->Trailer = Trailer;
}

void Movie::Play()
{
	// This method plays the trailer on Chrome.
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_trailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}