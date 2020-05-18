// This file contains the implementation of the class "Controller"
#pragma once
#include "Controller.h"
#include "MovieValidator.h"
#include <iostream>

Controller::~Controller()
{
	// The default destructor.
}

Repository Controller::get_repository()
{
	// This method gets all the movies from the repository.
	return movies_list;
}

Repository Controller::get_watchlist_repo()
{
	// This method gets all the movies from the watchlist repository.
	return watchlist;
}

void Controller::add_movie_to_repository(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer)
{
	// This method creates a movie with the given parameters and adds it to the list of movies (in the repository)
	Movie m{ ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer };
	this->validator.validate(m);
	this->movies_list.AddMovie(m);
}

void Controller::add_movie_to_file(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer, std::string file)
{
	// This method creates a movie with the given parameters and adds it to the list of movies (in the file)
	Movie m{ ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer };
	this->movies_list.AddMovieToFile(m, file);
}

void Controller::add_movie_to_watchlist(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer)
{
	// This method creates a movie with the given parameters and adds it to the list of movies (in the watchlist)
	Movie m{ ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer };
	this->watchlist.AddMovie(m);
}

bool Controller::find_movie(int &ID)
{
	// This method searches for a movie and returns true, if it was found and false, otherwise.
	if (this->movies_list.findMovieById(ID) == true)
		return true;
	return false;
}

void Controller::delete_movie_from_repository(int &ID)
{
	// This method deletes a movie from the repository by its ID.
	this->movies_list.DeleteMovie(ID);
}

void Controller::delete_movie_from_file(int &ID, std::string file)
{
	// This method deletes a movie from the file by its ID.
	this->movies_list.DeleteMovieFromFile(ID, file);
}

void Controller::delete_movie_from_watchlist(int &ID)
{
	// This method deletes a movie from the watchlist by its ID.
	this->watchlist.DeleteMovie(ID);
}

void Controller::update_title(int &ID, std::string &Title)
{
	// This method updates the title of a movie from the repository.
	this->movies_list.UpdateTitle(ID, Title);
}

void Controller::update_title_from_file(int &ID, std::string &Title, std::string file)
{
	// This method updates the title of a movie in the file.
	this->movies_list.UpdateTitleFromFile(ID, Title, file);
}

void Controller::update_genre(int &ID, std::string &Genre)
{
	// This method updates the genre of a movie from the repository.
	this->movies_list.UpdateGenre(ID, Genre);
}

void Controller::update_genre_from_file(int &ID, std::string &Genre, std::string file)
{
	// This method updates the genre of a movie in the file.
	this->movies_list.UpdateGenreFromFile(ID, Genre, file);
}

void Controller::update_number_of_likes(int &ID, int &Number)
{
	// This method updates the number of likes of a movie from the repository.
	this->movies_list.UpdateNumberOfLikes(ID, Number);
}

void Controller::update_number_of_likes_from_file(int &ID, int &Number, std::string file)
{
	// This method updates the number of likes of a movie from the repository.
	this->movies_list.UpdateNumberOfLikesFromFile(ID, Number, file);
}

void Controller::update_trailer(int &ID, std::string &Trailer)
{
	// This method updates the trailer of a movie from the repository.
	this->movies_list.UpdateTrailer(ID, Trailer);
}

void Controller::update_trailer_from_file(int &ID, std::string &Trailer, std::string file)
{
	// This method updates the trailer of a movie in the file.
	this->movies_list.UpdateTrailerFromFile(ID, Trailer, file);
}

DynamicVector Controller::search_by_genre(std::string &Genre)
{
	// This method searches movies by a given genre.
	DynamicVector movies_by_genre = this->movies_list.getMovies();
	DynamicVector result;
	Movie *movie = movies_by_genre.getAllElems();
	for (int i = 0; i < movies_by_genre.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_genre() == Genre)
			result.add(m);
	}
	return result;
}

DynamicVector Controller::get_all_movies()
{
	// This method returns all the movies.
	return this->movies_list.getMovies();
}

bool Controller::number_validation(int Number)
{
	// This method validates the number of likes.
	if (Number >= 0 && Number == floor(Number))
		return true;
	return false;
}

bool Controller::year_validation(int Year)
{
	// This method validates the year.
	if (Year == floor(Year) && Year >= 1895 && Year <= 2018)
		return true;
	return false;
}