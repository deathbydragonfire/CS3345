#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <string>
class book {
private:
	int ISBN;
	std::string title;
	std::string authorLastName;
public:
	book(int isbn, std::string t, std::string n) 
		:ISBN(isbn), title(t), authorLastName(n)
	{}

	int getISBN() {
		return ISBN;
	}
	std::string getTitle() {
		return title;
	}
	std::string getAuthorLastName() {
		return authorLastName;
	}
};
#endif // !BOOK_H
