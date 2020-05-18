// This file contains the implementation of the class "Watchlist"
#include "Watchlist.h"
#include <iostream>

Watchlist::Watchlist()
{
	// The default constructor.
}

Watchlist::~Watchlist()
{
	// The default destructor.
}

void Watchlist::ShowWatchlist()
{
	// This method shows all the movies from the watchlist.
	DynamicVector vector = this->watchlist;
	Movie* movie = vector.getAllElems();
	if (movie == NULL)
		return;
	if (vector.getSize() == 0)
	{
		std::cout << "There are no movies in the database." << std::endl;
		return;
	}
	std::cout << "The movies from the database: " << std::endl << std::endl;
	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		std::cout << i + 1 << "." << "ID: " << m.get_id() << std::endl;
		std::cout << "  Title: " << m.get_title() << std::endl;
		std::cout << "  Genre: " << m.get_genre() << std::endl;
		std::cout << "  Apparition year: " << m.get_apparition_year() << std::endl;
		std::cout << "  Number of likes: " << m.get_number_of_likes() << std::endl;
		std::cout << "  Trailer: " << m.get_trailer() << std::endl;
		std::cout << std::endl;
	}
}

void Watchlist::AddMovieToWatchlist(Movie &Movie)
{
	// This method adds a movie in the watchlist.
	this->watchlist.add(Movie);
}

DynamicVector Watchlist::GetMoviesFromWatchlist()
{
	// This method returns the list of movies from the watchlist.
	return watchlist;
}

void Watchlist::DeleteMovieFromWatchlist(int &ID)
{
	// This method deletes a movie from the watchlist.
	Movie* movies_vector = this->watchlist.getAllElems();
	if (findMoviebyIDWatchlist(ID) == true)
		for (int i = 0; i < this->watchlist.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
				this->watchlist.deleteElement(movie, i);
		}
	else
		std::cout << "No movie with the given ID was found in the watchlist." << std::endl;
}

bool Watchlist::findMoviebyIDWatchlist(int &ID)
{
	// This method searches for a movie in the list and returns true if the movie was found; false otherwise.
	Movie* movies_vector = this->watchlist.getAllElems();
	bool return_value = false;
	if (movies_vector != NULL)
	{
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
				return_value = true;
		}
	}
	return return_value;
}
