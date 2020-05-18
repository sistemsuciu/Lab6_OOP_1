#pragma once
#include <iostream>
#include <fstream>
#include <assert.h>
#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
using std::ofstream;
using std::ifstream;

void test_repo_add()
{
	// This method is checking if the function that adds a movie in the repository is working properly.
	Repository repo{};
	assert(repo.getMovies().getSize() == 10);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	assert(repo.getMovies().getSize() == 11);
	Movie m2{};
	m2.set_id(207);
	m2.set_title("Psycho");
	m2.set_genre("Horror");
	m2.set_apparition_year(1960);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=Wz719b9QUqY");
	repo.AddMovie(m2);
	assert(repo.getMovies().getSize() == 12);
	std::cout << "The function that adds a movie in the repository is working properly." << std::endl;
}

void test_repo_delete()
{
	// This method is checking if the function that deletes a movie from the repository is working properly.
	Repository repo{};
	assert(repo.getMovies().getSize() == 10);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	Movie m2{};
	m2.set_id(207);
	m2.set_title("Psycho");
	m2.set_genre("Horror");
	m2.set_apparition_year(1960);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=Wz719b9QUqY");
	repo.AddMovie(m2);
	assert(repo.getMovies().getSize() == 12);
	int id = m1.get_id();
	repo.DeleteMovie(id);
	assert(repo.getMovies().getSize() == 11);
	id = m2.get_id();
	repo.DeleteMovie(id);
	assert(repo.getMovies().getSize() == 10);
	std::cout << "The function that deletes a movie from the repository is working properly." << std::endl;
}

void test_repo_update_title()
{
	// This method is checking if the function that updates the title of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	assert(m1.get_title() == "Leon");
	int id = m1.get_id();
	std::string new_title = "New Title";
	repo.UpdateTitle(id, new_title);
	m1.set_title(new_title);
	assert(m1.get_title() == "New Title");
	std::cout << "The function that updates the title of a movie from the repository is working properly." << std::endl;
}

void test_repo_update_genre()
{
	// This method is checking if the function that updates the genre of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	assert(m1.get_genre() == "Crime");
	int id = m1.get_id();
	std::string new_genre = "New Genre";
	repo.UpdateGenre(id, new_genre);
	m1.set_genre(new_genre);
	assert(m1.get_genre() == "New Genre");
	std::cout << "The function that updates the genre of a movie from the repository is working properly." << std::endl;
}

void test_repo_update_number_of_likes()
{
	// This method is checking if the function that updates the number of likes
	// of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	assert(m1.get_number_of_likes() == 99);
	int id = m1.get_id();
	int new_number = 10;
	repo.UpdateNumberOfLikes(id, new_number);
	m1.set_number_of_likes(new_number);
	assert(m1.get_number_of_likes() == 10);
	std::cout << "The function that updates the number of likes of a movie from the repository is working properly." << std::endl;
}

void test_repo_update_trailer()
{
	// This method is checking if the function that updates the trailer of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	assert(m1.get_trailer() == "https://www.youtube.com/watch?v=DcsirofJrlM");
	int id = m1.get_id();
	std::string new_trailer = "https://www.youtube.com/watch?v=yoxLYdARO_0";
	repo.UpdateTrailer(id, new_trailer);
	m1.set_trailer(new_trailer);
	assert(m1.get_trailer() == "https://www.youtube.com/watch?v=yoxLYdARO_0");
	std::cout << "The function that updates the trailer of a movie from the repository is working properly." << std::endl;
}

void test_ctrl_add()
{
	// This method is checking if the function that adds a movie in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	assert(ctrl.get_all_movies().getSize() == 10);
	int id = 999;
	int apparition_year = 1994;
	int number_of_likes = 99;
	std::string title = "Leon";
	std::string genre = "Crime";
	std::string trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(id, title, genre, apparition_year, number_of_likes, trailer);
	assert(ctrl.get_all_movies().getSize() == 11);
	std::cout << "The function that adds a movie in the controller is working properly." << std::endl;
}

void test_ctrl_delete()
{
	// This method is checking if the function that deletes a movie in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	assert(ctrl.get_all_movies().getSize() == 10);
	int id = 1;
	ctrl.delete_movie_from_repository(id);
	assert(ctrl.get_all_movies().getSize() == 9);
	std::cout << "The function that deletes a movie in the controller is working properly." << std::endl;
}

void test_ctrl_update_title()
{
	// This method is checking if the function that updates the title of a movie in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	int id = 999;
	int apparition_year = 1994;
	int number_of_likes = 99;
	std::string title = "Leon";
	std::string genre = "Crime";
	std::string trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(id, title, genre, apparition_year, number_of_likes, trailer);
	std::string new_title = "New Title";
	ctrl.update_title(id, new_title);

	DynamicVector vector = ctrl.get_repository().getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_title() == "New Title");
	}
	std::cout << "The function that updates the title of a movie in the controller is working properly." << std::endl;
}

void test_ctrl_update_genre()
{
	// This method is checking if the function that updates the genre of a movie in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	int id = 999;
	int apparition_year = 1994;
	int number_of_likes = 99;
	std::string title = "Leon";
	std::string genre = "Crime";
	std::string trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(id, title, genre, apparition_year, number_of_likes, trailer);
	std::string new_genre = "New Genre";
	ctrl.update_genre(id, new_genre);

	DynamicVector vector = ctrl.get_repository().getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_genre() == "New Genre");
	}
	std::cout << "The function that updates the genre of a movie in the controller is working properly." << std::endl;
}

void test_ctrl_update_trailer()
{
	// This method is checking if the function that updates the trailer of a movie in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	int id = 999;
	int apparition_year = 1994;
	int number_of_likes = 99;
	std::string title = "Leon";
	std::string genre = "Crime";
	std::string trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(id, title, genre, apparition_year, number_of_likes, trailer);
	std::string new_trailer = "New Trailer";
	ctrl.update_trailer(id, new_trailer);

	DynamicVector vector = ctrl.get_repository().getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_trailer() == "New Trailer");
	}
	std::cout << "The function that updates the trailer of a movie in the controller is working properly." << std::endl;
}

void test_ctrl_update_number_of_likes()
{
	// This method is checking if the function that updates the number of likes of a movie in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	int id = 999;
	int apparition_year = 1994;
	int number_of_likes = 99;
	std::string title = "Leon";
	std::string genre = "Crime";
	std::string trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(id, title, genre, apparition_year, number_of_likes, trailer);
	int new_number_of_likes = 90;
	ctrl.update_number_of_likes(id, new_number_of_likes);

	DynamicVector vector = ctrl.get_repository().getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_number_of_likes() == 90);
	}
	std::cout << "The function that updates the number of likes of a movie in the controller is working properly." << std::endl;
}

void test_number_validation()
{
	// This method is checking if the function that validates a number in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	assert(ctrl.number_validation(5) == true);
	assert(ctrl.number_validation(-1) == false);
	std::cout << "The function that validates a number in the controller is working properly." << std::endl;
}

void test_year_validation()
{
	// This method is checking if the function that validates an year in the controller is working properly.
	Repository repo;
	Controller ctrl{ repo };
	assert(ctrl.year_validation(2000) == true);
	assert(ctrl.year_validation(1800) == false);
	assert(ctrl.year_validation(2100) == false);
	std::cout << "The function that validates an year in the controller is working properly." << std::endl;
}

void test_watchlist_add()
{
	// This method is checking if the function that adds a movie in the watchlist is working properly.
	Watchlist wl{};
	assert(wl.GetMoviesFromWatchlist().getSize() == 0);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	wl.AddMovieToWatchlist(m1);
	assert(wl.GetMoviesFromWatchlist().getSize() == 1);
	Movie m2{};
	m2.set_id(207);
	m2.set_title("Psycho");
	m2.set_genre("Horror");
	m2.set_apparition_year(1960);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=Wz719b9QUqY");
	wl.AddMovieToWatchlist(m2);
	assert(wl.GetMoviesFromWatchlist().getSize() == 2);
	std::cout << "The function that adds a movie in the watchlist is working properly." << std::endl;
}

void test_watchlist_delete()
{
	// This method is checking if the function that adds a movie in the watchlist is working properly.
	Watchlist wl{};
	assert(wl.GetMoviesFromWatchlist().getSize() == 0);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	wl.AddMovieToWatchlist(m1);
	assert(wl.GetMoviesFromWatchlist().getSize() == 1);
	Movie m2{};
	m2.set_id(207);
	m2.set_title("Psycho");
	m2.set_genre("Horror");
	m2.set_apparition_year(1960);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=Wz719b9QUqY");
	wl.AddMovieToWatchlist(m2);
	assert(wl.GetMoviesFromWatchlist().getSize() == 2);
	int id1 = m1.get_id(), id2 = m2.get_id();
	wl.DeleteMovieFromWatchlist(id1);
	wl.DeleteMovieFromWatchlist(id2);
	assert(wl.GetMoviesFromWatchlist().getSize() == 0);
	std::cout << "The function that deletes a movie in the watchlist is working properly." << std::endl;
}

void test_file_add()
{
	// This method is checking if the function that adds a movie in the file is working properly.
	Repository repo("test");
	assert(repo.getMovies().getSize() == 0);
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				repo.AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(repo.getMovies().getSize() == 3);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	repo.AddMovieToFile(m1, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 4);
	int id = 999;
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	std::cout << "The function that adds a movie to the file is working properly." << std::endl;

}

void test_file_delete()
{
	// This method is checking if the function that deletes a movie from the file is working properly.
	Repository repo("test");
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				repo.AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(repo.getMovies().getSize() == 3);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	repo.AddMovieToFile(m1, "2 - RepoTest.txt");
	Movie m2{};
	m2.set_id(207);
	m2.set_title("Psycho");
	m2.set_genre("Horror");
	m2.set_apparition_year(1960);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=Wz719b9QUqY");
	repo.AddMovie(m2);
	repo.AddMovieToFile(m2, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 5);
	int id = m1.get_id();
	repo.DeleteMovie(id);
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 4);
	id = m2.get_id();
	repo.DeleteMovie(id);
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 3);
	std::cout << "The function that deletes a movie from the file is working properly." << std::endl;
}

void test_file_update_title()
{
	// This method is checking if the function that updates the title of a movie from the file is working properly.
	Repository repo("test");
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				repo.AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(repo.getMovies().getSize() == 3);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	repo.AddMovieToFile(m1, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 4);
	assert(m1.get_title() == "Leon");
	int id = m1.get_id();
	std::string new_title = "Leonardo";
	repo.UpdateTitle(id, new_title);
	repo.UpdateTitleFromFile(id, new_title, "2 - RepoTest.txt");

	DynamicVector vector = repo.getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_title() == "Leonardo");
	}
	repo.DeleteMovie(id);
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 3);
	std::cout << "The function that updates the title of a movie from the file is working properly." << std::endl;
}

void test_file_update_genre()
{
	// This method is checking if the function that updates the genre of a movie from the file is working properly.
	Repository repo("test");
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				repo.AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(repo.getMovies().getSize() == 3);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	repo.AddMovieToFile(m1, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 4);
	assert(m1.get_genre() == "Crime");
	int id = m1.get_id();
	std::string new_genre = "Adventure";
	repo.UpdateGenre(id, new_genre);
	repo.UpdateGenreFromFile(id, new_genre, "2 - RepoTest.txt");

	DynamicVector vector = repo.getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_genre() == "Adventure");
	}
	repo.DeleteMovie(id);
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 3);
	std::cout << "The function that updates the genre of a movie from the file is working properly." << std::endl;
}

void test_file_update_trailer()
{
	// This method is checking if the function that updates the trailer of a movie from the file is working properly.
	Repository repo("test");
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				repo.AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(repo.getMovies().getSize() == 3);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	repo.AddMovieToFile(m1, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 4);
	assert(m1.get_trailer() == "https://www.youtube.com/watch?v=DcsirofJrlM");
	int id = m1.get_id();
	std::string new_trailer = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";
	repo.UpdateTrailer(id, new_trailer);
	repo.UpdateTrailerFromFile(id, new_trailer, "2 - RepoTest.txt");

	DynamicVector vector = repo.getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_trailer() == "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
	}
	repo.DeleteMovie(id);
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 3);
	std::cout << "The function that updates the trailer of a movie from the file is working properly." << std::endl;
}

void test_file_update_number_of_likes()
{
	// This method is checking if the function that updates the number of likes of a movie from the file is working properly.
	Repository repo("test");
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				repo.AddMovie(m);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(repo.getMovies().getSize() == 3);
	Movie m1{};
	m1.set_id(999);
	m1.set_title("Leon");
	m1.set_genre("Crime");
	m1.set_apparition_year(1994);
	m1.set_number_of_likes(99);
	m1.set_trailer("https://www.youtube.com/watch?v=DcsirofJrlM");
	repo.AddMovie(m1);
	repo.AddMovieToFile(m1, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 4);
	assert(m1.get_number_of_likes() == 99);
	int id = m1.get_id();
	int new_number_of_likes = 0;
	repo.UpdateNumberOfLikes(id, new_number_of_likes);
	repo.UpdateNumberOfLikesFromFile(id, new_number_of_likes, "2 - RepoTest.txt");

	DynamicVector vector = repo.getMovies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == id)
			assert(m.get_number_of_likes() == 0);
	}
	repo.DeleteMovie(id);
	repo.DeleteMovieFromFile(id, "2 - RepoTest.txt");
	assert(repo.getMovies().getSize() == 3);
	std::cout << "The function that updates the number of likes of a movie from the file is working properly." << std::endl;
}

void test_file_ctrl_update_title()
{
	// This method checks if the function from the controller that updates the title of a movie in the file is working properly.
	Repository repo{ "test" };
	Controller ctrl{ repo };
	assert(ctrl.get_all_movies().getSize() == 0);
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(ctrl.get_all_movies().getSize() == 3);

	int ID = 999;
	std::string Title = "Leon";
	std::string Genre = "Crime";
	int ApparitionYear = 1994;
	int NumberOfLikes = 99;
	std::string Trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
	ctrl.add_movie_to_file(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 4);

	std::string new_title = "Leonardo";
	ctrl.update_title(ID, new_title);
	ctrl.update_title_from_file(ID, new_title, "2 - RepoTest.txt");

	DynamicVector vector = ctrl.get_all_movies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == ID)
			assert(m.get_title() == "Leonardo");
	}
	ctrl.delete_movie_from_repository(ID);
	ctrl.delete_movie_from_file(ID, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 3);
	std::cout << "The function from the controller that updates the title of a movie in the file is working properly." << std::endl;
}

void test_file_ctrl_update_genre()
{
	// This method checks if the function from the controller that updates the genre of a movie in the file is working properly.
	Repository repo{ "test" };
	Controller ctrl{ repo };
	assert(ctrl.get_all_movies().getSize() == 0);
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(ctrl.get_all_movies().getSize() == 3);

	int ID = 999;
	std::string Title = "Leon";
	std::string Genre = "Crime";
	int ApparitionYear = 1994;
	int NumberOfLikes = 99;
	std::string Trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
	ctrl.add_movie_to_file(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 4);

	std::string new_genre = "Adventure";
	ctrl.update_genre(ID, new_genre);
	ctrl.update_genre_from_file(ID, new_genre, "2 - RepoTest.txt");

	DynamicVector vector = ctrl.get_all_movies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == ID)
			assert(m.get_genre() == "Adventure");
	}
	ctrl.delete_movie_from_repository(ID);
	ctrl.delete_movie_from_file(ID, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 3);
	std::cout << "The function from the controller that updates the genre of a movie in the file is working properly." << std::endl;
}

void test_file_ctrl_update_trailer()
{
	// This method checks if the function from the controller that updates the trailer of a movie in the file is working properly.
	Repository repo{ "test" };
	Controller ctrl{ repo };
	assert(ctrl.get_all_movies().getSize() == 0);
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(ctrl.get_all_movies().getSize() == 3);

	int ID = 999;
	std::string Title = "Leon";
	std::string Genre = "Crime";
	int ApparitionYear = 1994;
	int NumberOfLikes = 99;
	std::string Trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
	ctrl.add_movie_to_file(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 4);

	std::string new_trailer = "https://www.youtube.com/watch?v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&start_radio=1";
	ctrl.update_trailer(ID, new_trailer);
	ctrl.update_trailer_from_file(ID, new_trailer, "2 - RepoTest.txt");

	DynamicVector vector = ctrl.get_all_movies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == ID)
			assert(m.get_trailer() == "https://www.youtube.com/watch?v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&start_radio=1");
	}
	ctrl.delete_movie_from_repository(ID);
	ctrl.delete_movie_from_file(ID, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 3);
	std::cout << "The function from the controller that updates the trailer of a movie in the file is working properly." << std::endl;
}

void test_file_ctrl_update_number_of_likes()
{
	// This method checks if the function from the controller that updates the number of likes of a movie in the file is working properly.
	Repository repo{ "test" };
	Controller ctrl{ repo };
	assert(ctrl.get_all_movies().getSize() == 0);
	ifstream myFile; // the file we are reading from
	std::string line;
	myFile.open("2 - RepoTest.txt");
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
				ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
			}
		}
		myFile.close();
	}
	else
		std::cout << "Unable to open test file!";
	assert(ctrl.get_all_movies().getSize() == 3);

	int ID = 999;
	std::string Title = "Leon";
	std::string Genre = "Crime";
	int ApparitionYear = 1994;
	int NumberOfLikes = 99;
	std::string Trailer = "https://www.youtube.com/watch?v=DcsirofJrlM";
	ctrl.add_movie_to_repository(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
	ctrl.add_movie_to_file(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 4);

	int new_number_of_likes = 0;
	ctrl.update_number_of_likes(ID, new_number_of_likes);
	ctrl.update_number_of_likes_from_file(ID, new_number_of_likes, "2 - RepoTest.txt");

	DynamicVector vector = ctrl.get_all_movies();
	Movie* movie = vector.getAllElems();

	for (int i = 0; i < vector.getSize(); i++)
	{
		Movie m = movie[i];
		if (m.get_id() == ID)
			assert(m.get_number_of_likes() == 0);
	}
	ctrl.delete_movie_from_repository(ID);
	ctrl.delete_movie_from_file(ID, "2 - RepoTest.txt");
	assert(ctrl.get_all_movies().getSize() == 3);
	std::cout << "The function from the controller that updates the number of likes of a movie in the file is working properly." << std::endl;
}

void run_all_tests()
{
	std::cout << "TESTS: " << std::endl;
	test_repo_add();
	test_repo_delete();
	test_repo_update_title();
	test_repo_update_genre();
	test_repo_update_number_of_likes();
	test_repo_update_trailer();
	test_ctrl_add();
	test_ctrl_delete();
	test_ctrl_update_title();
	test_ctrl_update_genre();
	test_ctrl_update_trailer();
	test_ctrl_update_number_of_likes();
	test_number_validation();
	test_year_validation();
	test_watchlist_add();
	test_watchlist_delete();
	test_file_add();
	test_file_delete();
	test_file_update_title();
	test_file_update_genre();
	test_file_update_trailer();
	test_file_update_number_of_likes();
	test_file_ctrl_update_title();
	test_file_ctrl_update_genre();
	test_file_ctrl_update_trailer();
	test_file_ctrl_update_number_of_likes();
}


int main()
{
	//run_all_tests();
	Repository repo;
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}