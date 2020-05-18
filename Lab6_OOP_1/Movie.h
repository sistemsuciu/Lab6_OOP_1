// This header contains the definition of the class "Movie".

#pragma once
#include <string>

class Movie
{
	int ID;
	std::string Title;
	std::string Genre;
	int ApparitionYear;
	int NumberOfLikes;
	std::string Trailer;

public:
	// The default constructor
	Movie();

	// The constructor with parameters
	Movie(int &ID);
	Movie(int &ID, std::string &Title, std::string &Genre, int &ApparitionYear, int &NumberOfLikes, std::string &Trailer);

	// The default destructor.
	~Movie();

	// This method gets the ID of the movie.
	int get_id();

	// This method gets the title of the movie.
	std::string get_title();

	// This method gets the genre of the movie.
	std::string get_genre();

	// This method gets the apparition year of the movie.
	int get_apparition_year();

	// This method gets the number of likes of the movie.
	int get_number_of_likes();

	// This method gets the trailer of the movie.
	std::string get_trailer();

	// This method sets the ID of the movie.
	void set_id(int id);

	// This method sets the title of the movie.
	void set_title(std::string Title);

	// This method sets the genre of the movie.
	void set_genre(std::string Genre);

	// This method sets the apparition year of the movie.
	void set_apparition_year(int Year);

	// This method sets the number of likes of the movie.
	void set_number_of_likes(int Number);

	// This method sets the trailer of the movie.
	void set_trailer(std::string Trailer);

	// This method plays the trailer on Chrome.
	void Play();
};