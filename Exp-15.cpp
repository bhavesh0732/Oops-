#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // For sort()

using namespace std;

struct Book {
    string title;
    string author;
    double price;
};

void displayBookDetails(const vector<Book>& books) {
    cout << "Top 5 Books with price less than 500:" << endl;
    cout << "-------------------------------------" << endl;

    int count = 0;
    for (const auto& book : books) {
        if (book.price < 500) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Price: " << book.price << endl;
            cout << "-------------------------------------" << endl;
            count++;
            if (count == 5) break;  // Only display top 5 books
        }
    }

    if (count == 0) {
        cout << "No books found with price less than 500." << endl;
    }
}

int main() {
    vector<Book> books = {
        {"The Alchemist", "Paulo Coelho", 299},
        {"The Great Gatsby", "F. Scott Fitzgerald", 400},
        {"1984", "George Orwell", 250},
        {"To Kill a Mockingbird", "Harper Lee", 320},
        {"The Catcher in the Rye", "J.D. Salinger", 450},
        {"Moby-Dick", "Herman Melville", 520},
        {"War and Peace", "Leo Tolstoy", 480},
        {"Pride and Prejudice", "Jane Austen", 499},
        {"The Lord of the Rings", "J.R.R. Tolkien", 650},
        {"The Hobbit", "J.R.R. Tolkien", 275}
    };

  
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.price < b.price;
    });

   
    displayBookDetails(books);

    return 0;
}
