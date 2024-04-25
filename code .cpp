  #include <iostream>
#include <vector>
#include <string>

// Structure to represent a book
struct Book {
    std::string title;
    std::string author;
    double price; // New member variable to store the price of the book
    bool available;
};

// Function to add a book to the library
void addBook(std::vector<Book>& library) {
    Book book;
    std::cout << "Enter the title of the book: ";
    std::cin.ignore(); // Ignore newline character from previous input 
    std::getline(std::cin, book.title);
    std::cout << "Enter the author of the book: ";
    std::getline(std::cin, book.author);
    std::cout << "Enter the price of the book: ";
    std::cin >> book.price;
    book.available = true; // Book is initially available
    library.push_back(book);
    std::cout << "Book added successfully!\n";
}

// Function to display the list of available books
void displayAvailableBooks(const std::vector<Book>& library) {
    std::cout << "List of available books:\n";
    for (const Book& book : library) {
        if (book.available) {
            std::cout << "Title: " << book.title << ", Author: " << book.author << ", Price: $" << book.price << std::endl;
        }
    }
}

// Function to check out a book from the library
void checkOutBook(std::vector<Book>& library) {
    std::string title;
    std::cout << "Enter the title of the book you want to check out: ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, title);
    for (Book& book : library) {
        if (book.title == title && book.available) {
            book.available = false;
            std::cout << "You have successfully checked out the book.\n";
            return;
        }
    }
    std::cout << "Book not found or already checked out.\n";
}

// Function to return a book to the library
void returnBook(std::vector<Book>& library) {
    std::string title;
    std::cout << "Enter the title of the book you want to return: ";
    std::cin.ignore(); // Ignore newline character from previous input
    std::getline(std::cin, title);
    for (Book& book : library) {
        if (book.title == title && !book.available) {
            book.available = true;
            std::cout << "You have successfully returned the book.\n";
            return;
        }
    }
    std::cout << "Book not found or already returned.\n";
}

int main() {
    std::vector<Book> library;

    int choice;
    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Display available books\n";
        std::cout << "3. Check out a book\n";
        std::cout << "4. Return a book\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                displayAvailableBooks(library);
                break;
            case 3:
                checkOutBook(library);
                break;
            case 4:
                returnBook(library);
                break;
            case 5:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                
        }
    } while (choice != 5);

    return 0;
}
