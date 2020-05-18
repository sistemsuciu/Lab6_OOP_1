// This header contains the definition of the class "UI".
#include "UI.h"
#include "Watchlist.h"
#include "RepositoryExceptions.h"
#include "MovieValidator.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using std::ofstream;

UI::~UI()
{
	// The destructor.
}

void UI::printMenu()
{
	// This method prints the main menu.
	std::cout << std::endl;
	std::cout << "Main menu:" << std::endl;
	std::cout << "   1 - Admin menu;" << std::endl;
	std::cout << "   2 - User menu;" << std::endl;
	std::cout << "   0 - Exit." << std::endl;
	std::cout << "Choose an option. ";
}

void UI::printAdminMenu()
{
	// This method prints the admin menu.
	std::cout << std::endl;
	std::cout << "Admin menu:" << std::endl;
	std::cout << "   1 - Add a new movie;" << std::endl;
	std::cout << "   2 - Delete a movie;" << std::endl;
	std::cout << "   3 - Modify a movie's title;" << std::endl;
	std::cout << "   4 - Modify a movie's genre;" << std::endl;
	std::cout << "   5 - Modify a movie's number of likes;" << std::endl;
	std::cout << "   6 - Modify a movie's trailer;" << std::endl;
	std::cout << "   7 - See all the movies;" << std::endl;
	std::cout << "   0 - Back to the main menu." << std::endl;
	std::cout << "Choose an option: ";
}

void UI::printUserMenu()
{
	// This method prints the user menu.
	std::cout << std::endl;
	std::cout << "User menu:" << std::endl;
	std::cout << "   1 - See the movies with a given genre;" << std::endl;
	std::cout << "   2 - See all the movies;" << std::endl;
	std::cout << "   3 - See the movies from the watchlist;" << std::endl;
	std::cout << "   4 - Delete a movie from the watchlist;" << std::endl;
	std::cout << "   5 - Save the watchlist CSV or HTML format;" << std::endl;
	std::cout << "   6 - See the watchlist in the right format;" << std::endl;
	std::cout << "   0 - Back to the main menu." << std::endl;
	std::cout << "Choose an option: ";
}

void UI::AddMovie()
{
	// This method adds a movie in the list of movies.
	std::string title, genre, trailer, tempStr;
	int apparition_year, number_of_likes = 0, ID;
	std::cout << "ID: ";
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if(show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}
	std::cout << "Title: ";
	getline(std::cin, title);
	std::cout << "Genre: ";
	getline(std::cin, genre);
	std::cout << "Apparition year: ";
	std::cin >> apparition_year;
	std::cin.ignore();

	show_message_only_one_time = false;
	read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the year: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> apparition_year;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	std::cout << "Trailer: ";
	getline(std::cin, trailer);

	bool ok = true;
	try
	{
		this->ctrl.add_movie_to_repository(ID, title, genre, apparition_year, number_of_likes, trailer);
		this->ctrl.add_movie_to_file(ID, title, genre, apparition_year, number_of_likes, trailer, "1 - InitialiseRepository.txt");
	}
	catch (MovieException &e)
	{
		ok = false;
		for (auto s : e.getErrors())
			std::cout << s << std::endl;
	}
	catch (RepositoryException &e)
	{
		ok = false;
		std::cout << e.what() << std::endl;
	}
	catch (FileException &e)
	{
		ok = false;
		std::cout << e.what() << std::endl;

	}

	if (ok == true)
		std::cout << "Added!" << std::endl;
	else
		std::cout << "The movie was not added." << std::endl;
}

void UI::DeleteMovie()
{
	// This method deletes a movie from the list.
	std::cout << "Type the ID of the movie that you want to delete: ";
	int ID;
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	bool ok = true;
	try
	{
		this->ctrl.delete_movie_from_repository(ID);
		this->ctrl.delete_movie_from_file(ID, "1 - InitialiseRepository.txt");
	}
	catch(RepositoryException &e)
	{
		ok = false;
		std::cout << e.what() << std::endl;
	}

	if(ok == true)
		std::cout << "The movie with the ID " << ID << " was successfully deleted!" << std::endl;
	else
		std::cout << "The movie with the ID " << ID << " was not deleted!" << std::endl;
}

void UI::DeleteMovieFromWatchlist()
{
	// This method deletes a movie from the watchlist
	DynamicVector vector = this->ctrl.get_watchlist_repo().getMovies();
	Movie* movie = vector.getAllElems();
	if (movie == NULL)
		return;
	if (vector.getSize() == 0)
	{
		std::cout << "There are no movies in the database." << std::endl;
		return;
	}

	std::cout << "Type the ID of the movie that you want to delete: ";
	int ID;
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	bool ok = true;
	try
	{
		this->ctrl.delete_movie_from_watchlist(ID);
		std::cout << "The movie with the ID " << ID << " was successfully deleted!" << std::endl;
		std::cout << "Would you like to give a like to the movie? Type Yes or No." << std::endl;
		std::string option;
		getline(std::cin, option);
		bool condition = true;
		while (condition)
		{
			if (option == "Yes" || option == "yes") // if the user wants to give a like to the movie
			{
				int new_number;

				for (int i = 0; i < vector.getSize(); i++)
				{
					Movie m = movie[i];
					if (m.get_id() == ID)
					{
						new_number = m.get_number_of_likes();
						new_number++; // we are increasing the number of likes of the movie
					}
				}

				this->ctrl.update_number_of_likes(ID, new_number);
				std::cout << "The number of likes was successfully modified!" << std::endl;
				std::cout << "Press any key to continue." << std::endl;
				condition = false;
			}
			else if (option == "No" || option == "no") // if the user doesn't want to give a like to the movie
			{
				std::cout << "The number of likes was not modified." << std::endl;
				std::cout << "Press any key to continue." << std::endl;
				condition = false;
			}
			else
			{
				std::cout << "Invalid option." << std::endl;
				std::cout << "Retype the option: ";
				getline(std::cin, option);
			}
			break;
		}
	}
	catch (RepositoryException &e)
	{
		std::cout << "The movie with the ID " << ID << " was not deleted!" << std::endl;
		std::cout << e.what() << std::endl;

	}
}

void UI::UpdateTitle()
{
	// This method modifies the title of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	std::cout << "Type the new title: ";
	std::string new_title;
	getline(std::cin, new_title);
	try
	{
		this->ctrl.update_title(ID, new_title);
		this->ctrl.update_title_from_file(ID, new_title, "1 - InitialiseRepository.txt");
		std::cout << "The name of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
	}
	catch (RepositoryException &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "The name of the movie with the ID " << ID << " was not modified!" << std::endl;
	}
}

void UI::UpdateGenre()
{
	// This method modifies the genre of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	std::cout << "Type the new genre: ";
	std::string new_genre;
	getline(std::cin, new_genre);
	try
	{
		this->ctrl.update_genre(ID, new_genre);
		this->ctrl.update_genre_from_file(ID, new_genre, "1 - InitialiseRepository.txt");
		std::cout << "The genre of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
	}
	catch (RepositoryException &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "The genre of the movie with the ID " << ID << " was not modified!" << std::endl;
	}	
}

void UI::UpdateNumberOfLikes()
{
	// This method modifies the number of likes of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	std::cout << "Type the new number of likes: ";
	int number;
	std::cin >> number;
	std::cin.ignore();
	show_message_only_one_time = false;
	read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the number: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> number;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	try
	{
		this->ctrl.update_number_of_likes(ID, number);
		this->ctrl.update_number_of_likes_from_file(ID, number, "1 - InitialiseRepository.txt");
		std::cout << "The number of likes of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
	}
	catch (RepositoryException &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "The number of likes of the movie with the ID " << ID << " was not modified!" << std::endl;
	}
}

void UI::UpdateTrailer()
{
	// This method modifies the trailer of a movie.
	std::cout << "Type the ID of the movie: ";
	int ID;
	std::cin >> ID;
	std::cin.ignore();
	bool show_message_only_one_time = false;
	bool read_fail = std::cin.fail();

	while (read_fail == true)
	{
		std::cin.clear();
		std::cin.ignore();
		if (show_message_only_one_time == false)
			std::cout << "Invalid format. Retype the ID: " << std::endl;
		show_message_only_one_time = true;
		std::cin >> ID;
		std::cin.ignore();

		read_fail = std::cin.fail();
	}

	std::cout << "Type the new trailer: ";
	std::string new_trailer;
	getline(std::cin, new_trailer);
	try
	{
		this->ctrl.update_trailer(ID, new_trailer);
		this->ctrl.update_trailer_from_file(ID, new_trailer, "1 - InitialiseRepository.txt");
		std::cout << "The trailer of the movie with the ID " << ID << " has been successfully modified!" << std::endl;
	}
	catch (RepositoryException &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "The trailer of the movie with the ID " << ID << " was not modified!" << std::endl;
	}
}

void UI::ShowAllMovies()
{
	// This method shows all the movies from the list of movies.
	DynamicVector vector = this->ctrl.get_repository().getMovies();
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

void UI::ShowWatchlist()
{
	// This method shows all the movies from the watchlist.
	DynamicVector vector = this->ctrl.get_watchlist_repo().getMovies();
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

void UI::SaveWatchlistFormat(std::string Format)
{
	// This method saves all the movies from the watchlist in a given format.
	DynamicVector vector = this->ctrl.get_watchlist_repo().getMovies();
	Movie* movie = vector.getAllElems();
	if (movie == NULL)
		return;
	if (vector.getSize() == 0)
	{
		std::cout << "There are no movies in the watchlist." << std::endl;
		return;
	}

	if (Format == "CSV" || Format == "csv")
	{
		std::ofstream myFile;
		myFile.open("3 - WatchlistCSV.txt", std::ios_base::out);
		if (myFile.is_open())
		{
			for (int i = 0; i < vector.getSize(); i++)
			{
				Movie m = movie[i];
				myFile << m.get_id() << ", ";
				myFile << m.get_title() << ", ";
				myFile << m.get_genre() << ", ";
				myFile << m.get_apparition_year() << ", ";
				myFile << m.get_number_of_likes() << ", ";
				myFile << m.get_trailer() << std::endl;
			}
			myFile.close();
			std::cout << "Saved!" << std::endl;
		}
		else
			std::wcout << "Unable to open file!";
	}
	else if(Format == "HTML" || Format == "html")
	{
		std::ofstream myFile;
		myFile.open("4 - WatchlistHTML.html", std::ios_base::out);
		if (myFile.is_open())
		{
			myFile << "<!DOCTYPE html>" << std::endl;
			myFile << "<html>" << std::endl;
			myFile << "<head>" << std::endl;
			myFile << "<title>Watchliste</title>" << std::endl;
			myFile << "</head>" << std::endl;

			myFile << "<body>" << std::endl;
			myFile << "<table border=\"1\">" << std::endl;
			myFile << "<tr>" << std::endl;
			myFile << "<td>ID</td>" << std::endl;
			myFile << "<td>Title</td>" << std::endl;
			myFile << "<td>Genre</td>" << std::endl;
			myFile << "<td>Apparition Year</td>" << std::endl;
			myFile << "<td>Number of likes</td>" << std::endl;
			myFile << "<td>Trailer</td>" << std::endl;

			for (int i = 0; i < vector.getSize(); i++)
			{
				Movie m = movie[i];
				myFile << "<tr>" << std::endl;
				myFile << "<td>" << m.get_id() << "</td>" << std::endl;
				myFile << "<td>" << m.get_title() << "</td>" << std::endl;
				myFile << "<td>" << m.get_genre() << "</td>" << std::endl;
				myFile << "<td>" << m.get_apparition_year() << "</td>" << std::endl;
				myFile << "<td>" << m.get_number_of_likes() << "</td>" << std::endl;
				myFile << "<td><a href = \" " << m.get_trailer() << "\">Link</a></td>" << std::endl;
				myFile << "</tr>" << std::endl;
			}

			myFile << "</table>" << std::endl;
			myFile << "</body>" << std::endl;
			myFile << "</html>" << std::endl;
			myFile.close();
			std::cout << "Saved!" << std::endl;
		}
	}
	else std::cout << "Unable to open file";
}

void UI::SaveWatchlist()
{
	// This method reads the file format and calls the function that saves the watchlist in the given format.
	std::cout << "Choose a format: CSV/HTML" << std::endl;
	std::string format_option;
	getline(std::cin, format_option);
	while (format_option != "CSV" && format_option != "HTML" && format_option != "csv" && format_option != "html")
	{
		std::cout << "Incorrect format. Please retype the format: " << std::endl;
		getline(std::cin, format_option);
	}
	SaveWatchlistFormat(format_option);
}

void UI::OpenWatchlistFormat(std::string Format)
{
	if (Format == "csv" || Format == "CSV")
	{
		std::string filename = "3 - WatchlistCSV";
		std::string aux = "\"" + filename + "\"";
		ShellExecuteA(NULL, NULL, "C:\\Windows\\System32\\Notepad", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
		std::cout << "Shown." << std::endl;
	}
	else if (Format == "html" || Format == "HTML")
	{
		std::string filename = "4 - WatchlistHTML.html";
		std::string aux = "\"" + filename + "\"";
		LPCSTR name = aux.c_str();
		ShellExecuteA(NULL, NULL, "chrome.exe", name, NULL, SW_SHOWMAXIMIZED);
		std::cout << "Shown." << std::endl;
	}
	else
		std::cout << "Unable to open file!" << std::endl;
}

void UI::OpenWatchlist()
{
	// This method reads the file format and calls the function that opens the watchlist in the given format.
	std::cout << "Choose a format: CSV/HTML" << std::endl;
	std::string format_option;
	getline(std::cin, format_option);
	while (format_option != "CSV" && format_option != "HTML" && format_option != "csv" && format_option != "html")
	{
		std::cout << "Incorrect format. Please retype the format: " << std::endl;
		getline(std::cin, format_option);
	}
	OpenWatchlistFormat(format_option);
}

void UI::ShowMoviesByGenre()
{
	// This method shows all the movies with a specific genre.
	std::cout << "Type the genre: ";
	std::string genre;
	getline(std::cin, genre);
	if (genre != "")
	{
		DynamicVector vector = this->ctrl.search_by_genre(genre);
		Movie* movie = vector.getAllElems();
		if (movie == NULL)
			return;
		if (vector.getSize() == 0)
		{
			std::cout << "No movie with the given genre was found." << std::endl;
			return;
		}
		std::cout << "The movies with the given genre: " << std::endl;
		std::cout << std::endl;
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
	else
	{
		DynamicVector vector = this->ctrl.get_all_movies();
		Movie* movie = vector.getAllElems();
		Watchlist watchlist;
		if (movie == NULL)
			return;
		std::cout << "All the movies, but one by one: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < vector.getSize(); i++)
		{
			Movie m = movie[i];
			int ID = m.get_id();
			std::string Title = m.get_title();
			std::string Genre = m.get_genre();
			int ApparitionYear = m.get_apparition_year();
			int NumberOfLikes = m.get_number_of_likes();
			std::string Trailer = m.get_trailer();
			std::cout << i + 1 << "." << "ID: " << ID << std::endl;
			std::cout << "  Title: " << Title << std::endl;
			std::cout << "  Genre: " << Genre << std::endl;
			std::cout << "  Apparition year: " << ApparitionYear << std::endl;
			std::cout << "  Number of likes: " << NumberOfLikes << std::endl;
			std::cout << "  Trailer: " << Trailer << std::endl;
			std::cout << std::endl;
			m.Play();
			std::cout << std::endl << "Do you like the trailer? Type Yes or No." << std::endl;
			std::string trailer_option;
			getline(std::cin, trailer_option);
			bool condition1 = true;
			while (condition1)
			{
				if (trailer_option == "Yes" || trailer_option == "yes")
				{
					std::cout << std::endl << "Do you want to add the movie to the watchlist? Type Yes or No." << std::endl;
					std::string watchlist_option;
					getline(std::cin, watchlist_option);
					bool condition2 = true;
					while (condition2)
					{
						if (watchlist_option == "Yes" || watchlist_option == "yes")
						{
							this->ctrl.add_movie_to_watchlist(ID, Title, Genre, ApparitionYear, NumberOfLikes, Trailer);
							std::cout << "Added to the watchlist." << std::endl;
							std::cout << "Press any key to continue." << std::endl;
							condition2 = false;
						}
						else if (watchlist_option == "No" || watchlist_option == "no")
						{
							std::cout << "The movie was not added to the watchlist." << std::endl;
							std::cout << "Press any key to continue." << std::endl;
							condition2 = false;
						}
						else
						{
							std::cout << "Invalid option." << std::endl;
							std::cout << "Retype the option: ";
							getline(std::cin, watchlist_option);
						}
					}
					condition1 = false;
				}
				else if (trailer_option == "No" || trailer_option == "no")
				{

					std::cout << "The movie was not added to the watchlist." << std::endl;
					std::cout << "Press any key to continue." << std::endl;
					condition1 = false;
				}
				else
				{
					std::cout << "Invalid option." << std::endl;
					std::cout << "Retype the option: ";
					getline(std::cin, trailer_option);
				}
			}
			getchar();
		}
	}
}

void UI::run()
{
	// This method runs the user interface.

	//system("start file:///C:/Users/TIBIK/source/repos/Lab6_OOP_1/Lab6_OOP_1/4%20-%20WatchlistHTML.html");
	while (true)
	{
		UI::printMenu();
		int option;
		std::string temp;
		getline(std::cin, temp);
		option = atoi(temp.c_str());
		if (option == 0)
			break;

		if (option == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int admin_option;
				std::string temp;
				getline(std::cin, temp);
				admin_option = atoi(temp.c_str());
				if (admin_option == 0)
					break;
				switch (admin_option)
				{
				case 1:
					this->AddMovie();
					break;
				case 2:
					this->DeleteMovie();
					break;
				case 3:
					this->UpdateTitle();
					break;
				case 4:
					this->UpdateGenre();
					break;
				case 5:
					this->UpdateNumberOfLikes();
					break;
				case 6:
					this->UpdateTrailer();
					break;
				case 7:
					this->ShowAllMovies();
					break;
				}
			}
		}

		if (option == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int user_option;
				std::string temp;
				getline(std::cin, temp);
				user_option = atoi(temp.c_str());
				if (user_option == 0)
					break;
				switch (user_option)
				{
				case 1:
					this->ShowMoviesByGenre();
					break;
				case 2:
					this->ShowAllMovies();
					break;
				case 3:
					this->ShowWatchlist();
					break;
				case 4:
					this->DeleteMovieFromWatchlist();
					break;
				case 5:
					this->SaveWatchlist();
					break;
				case 6:
					this->OpenWatchlist();
					break;
				}
			}
		}
	}
}