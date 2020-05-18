#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

	// This method prints the main menu.
	static void printMenu();

	// This method prints the admin menu.
	static void printAdminMenu();

	// This method prints the user menu.
	static void printUserMenu();

	// This method adds a movie in the list of movies.
	void AddMovie();

	// This method deletes a movie from the list.
	void DeleteMovie();

	// This method deletes a movie from the watchlist
	void DeleteMovieFromWatchlist();

	// This method modifies the title of a movie.
	void UpdateTitle();

	// This method modifies the genre of a movie.
	void UpdateGenre();

	// This method modifies the number of likes of a movie.
	void UpdateNumberOfLikes();

	// This method modifies the trailer of a movie.
	void UpdateTrailer();

	// This method shows all the movies from the list of movies.
	void ShowAllMovies();

	// This method shows all the movies with a specific genre.
	void ShowMoviesByGenre();

	// This method shows all the movies from the watchlist.
	void ShowWatchlist();

	// This method saves all the movies from the watchlist in a given format.
	void SaveWatchlistFormat(std::string Format);

	// This method reads the file format and calls the function that saves the watchlist in the given format.
	void SaveWatchlist();

	// This method reads the file format and calls the function that opens the watchlist in the given format.
	void OpenWatchlistFormat(std::string Format);
	void OpenWatchlist();

public:
	UI(Controller& c) : ctrl(c) {};
	~UI();


	// This method runs the user interface.
	void run();
};