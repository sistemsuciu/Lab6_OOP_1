// This file contains the implementation of the class "Repository"
#pragma once
#include "Repository.h"
#include "RepositoryExceptions.h"
#include <iostream>
#include <fstream>
using std::ofstream;
using std::ifstream;

Repository::Repository()
{
	// The default constructor.
	ReadFromFile();
}

Repository::Repository(std::string Test)
{
	// Another constructor
}

Repository::~Repository()
{
	// The default destructor.
}

void Repository::ReadFromFile()
{
	// This method reads from a file and then adds the movies to the repository.
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("1 - InitialiseRepository.txt");
	if (myFile.is_open())
	{
		int line_number = 0;
		int ID, ApparitionYear, NumberOfLikes;
		std::string Title, Genre, Trailer;
		while (getline(myFile, line))
		{
			line_number++;
			if (line_number % 6 == 1) // ID
				ID = atoi(line.c_str());
			else if (line_number % 6 == 2) //  Title
				Title = line;
			else if (line_number % 6 == 3) //  Genre
				Genre = line;
			else if (line_number % 6 == 4) //  Apparition year
				ApparitionYear = atoi(line.c_str());
			else if (line_number % 6 == 5) //  Number of likes
				NumberOfLikes = atoi(line.c_str());
			else if (line_number % 6 == 0) //  Trailer
			{
				Trailer = line;

				Movie m{};
				m.set_id(ID);
				m.set_title(Title);
				m.set_genre(Genre);
				m.set_apparition_year(ApparitionYear);
				m.set_number_of_likes(NumberOfLikes);
				m.set_trailer(Trailer);
				AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open file!";
}

void Repository::AddMovie(Movie &m)
{
	// This method adds a movie in the movie list.
	try
	{
		int id = m.get_id();
		if (this->findMovieById(id) == true)
			throw DuplicateMovieException();
	}
	catch (InexistentMovieException &e) {}
	this->movies.add(m);
}

void Repository::AddMovieToFile(Movie &Movie, std::string file)
{
	ofstream myFile;
	myFile.open(file, std::ios_base::app);
	if (myFile.is_open())
	{
		myFile << Movie.get_id() << std::endl;
		myFile << Movie.get_title() << std::endl;
		myFile << Movie.get_genre() << std::endl;
		myFile << Movie.get_apparition_year() << std::endl;
		myFile << 0 << std::endl; // Number of likes is always zero, at first
		myFile << Movie.get_trailer() << std::endl;
		myFile.close();
	}
	else std::cout << "Unable to open file";
}

void Repository::DeleteMovie(int &ID)
{
	// This method deletes a movie from the movie list, by its ID.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == false)
		throw; //InexistentMovieException{};
	else
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
				this->movies.deleteElement(movie, i);
		}
}

void Repository::DeleteMovieFromFile(int &ID, std::string file)
{
	// This method deletes a movie from the file, by its ID.
	ifstream myFile1;
	ofstream myFile2;
	std::string line;
	myFile1.open(file);
	myFile2.open("1 - Repository.txt", std::fstream::in | std::fstream::out | std::ios::app); // a temporary file
	if (myFile1.is_open() && myFile2.is_open())
	{
		int line_number = 0;
		int delete_next_5 = 0;
		while (getline(myFile1, line))
		{
			line_number++;
			if (delete_next_5 > 0)
			{
				line.erase(line.begin(), line.begin() + line.length());
				delete_next_5--;
			}
			if(line_number % 6 == 1) // if we found the ID, it deletes the next 5 lines from the file
				if (atoi(line.c_str()) == ID)
				{
					line.erase(line.begin(), line.begin() + line.length());
					delete_next_5 = 5;
				}
			if(line != "")
				myFile2 << line << std::endl;
		}
		myFile1.close();
		myFile2.close();
		const char * c = file.c_str();
		remove(c);
		rename("1 - Repository.txt", c);
	}
	else
		std::cout << "Unable to open file!";
}

void Repository::UpdateTitle(int &ID, std::string &Title)
{
	// This method updates the title of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == false)
		throw InexistentMovieException{};
	else
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = Title;
				std::string genre = movie.get_genre();
				int year = movie.get_apparition_year();
				int likes = movie.get_number_of_likes();
				std::string trailer = movie.get_trailer();
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

void Repository::UpdateTitleFromFile(int &ID, std::string &Title, std::string file)
{
	// This method updates the title of a movie from the file (search by ID).
	ifstream myFile1;
	ofstream myFile2;
	std::string line;
	myFile1.open(file);
	myFile2.open("1 - Repository.txt", std::fstream::in | std::fstream::out | std::ios::app); // a temporary file
	if (myFile1.is_open() && myFile2.is_open())
	{
		int line_number = 0;
		bool found = false;
		while (getline(myFile1, line))
		{
			line_number++;
			if (found == true) // if we found the ID, it modifies the title-line from the file
			{
				line.replace(line.begin(), line.begin() + line.length(), Title);
				found = false;
			}
			if (line_number % 6 == 1) 
				if (atoi(line.c_str()) == ID) // if the ID matches
					found = true;
			myFile2 << line << std::endl;
		}
		myFile1.close();
		myFile2.close();
		const char * c = file.c_str();
		remove(c);
		rename("1 - Repository.txt", c);
	}
	else
		std::cout << "Unable to open file!";
}

void Repository::UpdateGenre(int &ID, std::string &Genre)
{
	// This method updates the genre of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == false)
		throw InexistentMovieException{};
	else
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = movie.get_title();
				std::string genre = Genre;
				int year = movie.get_apparition_year();
				int likes = movie.get_number_of_likes();
				std::string trailer = movie.get_trailer();
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

void Repository::UpdateGenreFromFile(int &ID, std::string &Genre, std::string file)
{
	// This method updates the genre of a movie from the file (search by ID).
	ifstream myFile1;
	ofstream myFile2;
	std::string line;
	myFile1.open(file);
	myFile2.open("1 - Repository.txt", std::fstream::in | std::fstream::out | std::ios::app); // a temporary file
	if (myFile1.is_open() && myFile2.is_open())
	{
		int line_number = 0, genre_line = 0;
		while (getline(myFile1, line))
		{
			line_number++;
			if (genre_line == line_number) // if we found the ID, it modifies the genre-line from the file
				line.replace(line.begin(), line.begin() + line.length(), Genre);
			if (line_number % 6 == 1)
				if (atoi(line.c_str()) == ID) // if the ID matches
					genre_line = line_number + 2;
			myFile2 << line << std::endl;
		}
		myFile1.close();
		myFile2.close();
		const char * c = file.c_str();
		remove(c);
		rename("1 - Repository.txt", c);
	}
	else
		std::cout << "Unable to open file!";
}

void Repository::UpdateNumberOfLikes(int &ID, int &Number)
{
	// This method updates the number of likes of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == false)
		throw InexistentMovieException{};
	else
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = movie.get_title();
				std::string genre = movie.get_genre();
				int year = movie.get_apparition_year();
				int likes = Number;
				std::string trailer = movie.get_trailer();
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

void Repository::UpdateNumberOfLikesFromFile(int &ID, int &Number, std::string file)
{
	// This method updates the number of likes of a movie from the file (search by ID).
	ifstream myFile1;
	ofstream myFile2;
	std::string line;
	myFile1.open(file);
	myFile2.open("1 - Repository.txt", std::fstream::in | std::fstream::out | std::ios::app); // a temporary file
	if (myFile1.is_open() && myFile2.is_open())
	{
		int line_number = 0, genre_line = 0;
		std::string NumberString = std::to_string(Number);
		while (getline(myFile1, line))
		{
			line_number++;
			if (genre_line == line_number) // if we found the ID, it modifies the likes-line from the file
				line.replace(line.begin(), line.begin() + line.length(), NumberString);
			if (line_number % 6 == 1)
				if (atoi(line.c_str()) == ID) // if the ID matches
					genre_line = line_number + 4;
			myFile2 << line << std::endl;
		}
		myFile1.close();
		myFile2.close();
		const char * c = file.c_str();
		remove(c);
		rename("1 - Repository.txt", c);
	}
	else
		std::cout << "Unable to open file!";
}

void Repository::UpdateTrailer(int &ID, std::string &Trailer)
{
	// This method updates the trailer of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == false)
		throw InexistentMovieException{};
	else
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = movie.get_title();
				std::string genre = movie.get_genre();
				int year = movie.get_apparition_year();
				int likes = movie.get_number_of_likes();
				std::string trailer = Trailer;
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}		
}

void Repository::UpdateTrailerFromFile(int &ID, std::string &Trailer, std::string file)
{
	// This method updates the trailer of a movie from the file (search by ID).
	ifstream myFile1;
	ofstream myFile2;
	std::string line;
	myFile1.open(file);
	myFile2.open("1 - Repository.txt", std::fstream::in | std::fstream::out | std::ios::app); // a temporary file
	if (myFile1.is_open() && myFile2.is_open())
	{
		int line_number = 0, trailer_line = 0;
		while (getline(myFile1, line))
		{
			line_number++;
			if (trailer_line == line_number) // if we found the ID, it modifies the genre-line from the file
				line.replace(line.begin(), line.begin() + line.length(), Trailer);
			if (line_number % 6 == 1)
				if (atoi(line.c_str()) == ID) // if the ID matches
					trailer_line = line_number + 5;
			myFile2 << line << std::endl;
		}
		myFile1.close();
		myFile2.close();
		const char * c = file.c_str();
		remove(c);
		rename("1 - Repository.txt", c);
	}
	else
		std::cout << "Unable to open file!";
}

DynamicVector Repository::getMovies()
{
	// This method returns the vector of all movies.
	return movies;
}

bool Repository::findMovieById(int &ID)
{
	// This method searches for a movie in the list and returns true if the movie was found; false otherwise.
	Movie* movies_vector = this->movies.getAllElems();
	if (movies_vector == NULL)
		return false;
	for (int i = 0; i < this->movies.getSize(); i++)
	{
		Movie movie = movies_vector[i];
		if (movie.get_id() == ID)
			return true;
	}
	return false;
}