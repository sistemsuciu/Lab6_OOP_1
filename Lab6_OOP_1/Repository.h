// This header contains the definition of the class "Repository".
#pragma once
#include "Movie.h"
#include "DynamicVector.h"
class Repository
{
public:
	DynamicVector movies;
	// The default constructor.
	Repository();

	// Another constructor
	Repository(std::string Test);

	// The default destructor.
	~Repository();

	// This method adds a movie in the movie list.
	void AddMovie(Movie &Movie);

	// This method adds a movie in the movie list file.
	void AddMovieToFile(Movie &Movie, std::string file);

	// This method reads from a file and then adds the movies to the repository.
	void ReadFromFile();

	// This method deletes a movie from the movie list, by its ID.
	void DeleteMovie(int &ID);

	// This method deletes a movie from the file, by its ID.
	void DeleteMovieFromFile(int &ID, std::string file);

	// This method updates the title of a movie.
	void UpdateTitle(int &ID, std::string &Title);

	// This method updates the title of a movie from the file (search by ID).
	void UpdateTitleFromFile(int &ID, std::string &Title, std::string file);

	// This method updates the trailer of a movie.
	void UpdateTrailer(int &ID, std::string &Trailer);

	// This method updates the trailer of a movie from the file (search by ID).
	void UpdateTrailerFromFile(int &ID, std::string &Trailer, std::string file);

	// This method updates the genre of a movie.
	void UpdateGenre(int &ID, std::string &Genre);

	// This method updates the genre of a movie from the file (search by ID).
	void UpdateGenreFromFile(int &ID, std::string &Genre, std::string file);

	// This method updates the number of likes of a movie.
	void UpdateNumberOfLikes(int &ID, int &Number);

	// This method updates the number of likes of a movie from the file (search by ID).
	void UpdateNumberOfLikesFromFile(int &ID, int &Number, std::string file);

	// This method returns the vector of all movies.
	DynamicVector getMovies();

	// This method searches for a movie in the list and returns true if the movie was found; false otherwise.
	bool findMovieById(int &ID);
};