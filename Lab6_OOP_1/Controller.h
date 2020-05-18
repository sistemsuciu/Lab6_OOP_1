// This header contains the definition of the class "Controller".
#pragma once
#include "Repository.h"
#include "Watchlist.h"
#include "MovieValidator.h"

class Controller
{
private:
	Repository movies_list;
	Repository watchlist;
	MovieValidator validator;

public:
	Controller(const Repository &r) : movies_list(r) {}

	// The default destructor.
	~Controller();

	// This method gets all the movies from the repository.
	Repository get_repository();

	// This method gets all the movies from the watchlist repository.
	Repository get_watchlist_repo();

	// This method creates a movie with the given parameters and adds it to the list of movies (in the repository)
	void add_movie_to_repository(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer);

	// This method creates a movie with the given parameters and adds it to the list of movies (in the file)
	void add_movie_to_file(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer, std::string file);

	// This method creates a movie with the given parameters and adds it to the list of movies (in the watchlist)
	void add_movie_to_watchlist(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer);

	// This method deletes a movie from the repository by its ID.
	void delete_movie_from_repository(int &ID);

	// This method deletes a movie from the file by its ID.
	void delete_movie_from_file(int &ID, std::string file);

	// This method deletes a movie from the watchlist by its ID.
	void delete_movie_from_watchlist(int &ID);

	// This method updates the title of a movie from the repository.
	void update_title(int &ID, std::string &Title);

	// This method updates the title of a movie in the file.
	void update_title_from_file(int &ID, std::string &Title, std::string file);

	// This method updates the genre of a movie from the repository.
	void update_genre(int &ID, std::string &Genre);

	// This method updates the genre of a movie in the file.
	void update_genre_from_file(int &ID, std::string &Genre, std::string file);

	// This method updates the number of likes of a movie from the repository.
	void update_number_of_likes(int &ID, int &Number);

	// This method updates the number of likes of a movie from the repository.
	void update_number_of_likes_from_file(int &ID, int &Number, std::string file);

	// This method updates the trailer of a movie from the repository.
	void update_trailer(int &ID, std::string &Trailer);

	// This method updates the trailer of a movie in the file.
	void update_trailer_from_file(int &ID, std::string &Trailer, std::string file);

	// This method searches movies by a given genre.
	DynamicVector search_by_genre(std::string &Genre);

	// This method returns all the movies.
	DynamicVector get_all_movies();

	// This method searches for a movie and returns true, if it was found and false, otherwise.
	bool find_movie(int &ID);

	// This method validates the number of likes.
	bool number_validation(int Number);

	// This method validates the year.
	bool year_validation(int Year);
};