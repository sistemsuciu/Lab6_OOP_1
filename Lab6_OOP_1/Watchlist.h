// This header contains the definition of the class "Watchlist".
#pragma once
#include "Movie.h"
#include "Repository.h"

class Watchlist : public Repository // INHERITANCE
{
private:
	DynamicVector watchlist;
public:

	// The default constructor.
	Watchlist();

	// The default destructor.
	~Watchlist();

	// This method adds a movie in the watchlist.
	void AddMovieToWatchlist(Movie &Movie);

	// This method deletes a movie from the watchlist.
	void DeleteMovieFromWatchlist(int &ID);

	// This method searches for a movie in the list and returns true if the movie was found; false otherwise.
	bool findMoviebyIDWatchlist(int &ID);

	// This method returns the list of movies from the watchlist.
	DynamicVector GetMoviesFromWatchlist();

	// This method shows all the movies from the watchlist.
	void ShowWatchlist();
};