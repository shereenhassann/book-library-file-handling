
// Data structures
// Book library using file handling
// Add, delete, update, Display book, and display all books

#include <iostream>
#include <fstream>

using namespace std;

struct Book
{
    char ISBN[ 5 ];
    char* title;
    char* author;
    char* price;
    char* year;
    char* pages;

};

fstream file;
bool check = true;

void AddBook(Book book);    //to add a new book to the file
void DeleteBook(char ISBN[5]);  //to delete an existing record(book) from the file
void UpdateBook(char ISBN[5]);  //to change the fields inside a specific record
void printBook(string title);   //to print a specific book
void PrintAllBooks();   //to print all the books inside the file
//bool ISBNexist(char ISBN[5]);  //to check if the ISBN is unique or not

int main()
{
    Book book;
    char choice;
    /*for(int i = 0 ; i < 10 ; i++)
    {
        AddBook(book);
    }*/
    while(true)
    {
        cout <<"\n\nWhat do want to do today?\n\n";
        cout << "1-Add book.\n2-Delete book.\n3-Update book.\n4-Print book.\n5-Print All books.\n6-End Program.\n\n>>";
        cin>>choice;
        if(choice == '1')
            AddBook(book);
        else if(choice == '2')
        {
            char ISBN[5];
            check = true;
            while (check)   //to check that the ISBN is a valid number
            {
                cout << "Please Enter ISBN: ";
                cin >> ISBN;
                cout << endl;
                for(int i = 0 ; i < 5 ; i++)
                {
                    if( ISBN[i] < char( 0 + 48 ) || ISBN[i] > char( 9 + 48 ) )
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }

                }
            }
            check = true;
            DeleteBook(ISBN);
        }
        else if(choice == '3')
        {
            char ISBN[5];
            check = true;
            while (check)   //to check that the ISBN is a valid number
            {
                cout << "Please Enter ISBN: ";
                cin >> ISBN;
                cout << endl;
                for(int i = 0 ; i < 5 ; i++)
                {
                    if( ISBN[i] < char( 0 + 48 ) || ISBN[i] > char( 9 + 48 ) )
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }
                }
            }
            check = true;   //to be able to use it again
            UpdateBook(ISBN);
        }
        else if(choice == '4')
        {
            string title;
            cout << "Please enter the title: ";
            getline(cin >> std::ws, title); //to get the input from the user with white space in it
            cout << endl;
            printBook(title);
        }
        else if(choice == '5')
            PrintAllBooks();
        else if(choice == '6')
        {
            cout << "\n\nThank you for using this program.\n\n";
            break;
        }
        else
        {
            cout << "\nPlease enter a valid input.\n\n";
        }
        cout << "\n\n-------------------------------------------------------------\n\n";
    }

    return 0;
}

void AddBook(Book book)
{
    string title, author, price, year, pages;
    char ISBN[5];
    file.open("Books.txt", ios:: out | ios::app | ios::in); //to open the file and append a new record to it
    check = true;
    while (check)
    {
        cout << "Please Enter ISBN: ";
        cin >> book.ISBN;
        cout << endl;
        for(int i = 0 ; i < 5 ; i++)
        {
            if( book.ISBN[i] < char( 0 + 48 ) || book.ISBN[i] > char( 9 + 48 ) )
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
    }
    check = true;
    file.write(book.ISBN, 5);
    file << '|';

    cout << "Please enter the title: ";
    getline(cin >> std::ws, title);
    cout << endl;
    book.title = new char[ title.length() ];
    for(int j = 0 ; j < title.length() ; j++)
        book.title[ j ] = title[ j ];
    file.write(book.title, title.length());
    file << '|';

    cout << "Please enter the author's name: ";
    getline(cin >> std::ws, author);
    cout << endl;
    book.author = new char[ author.length() ];
    for(int j = 0 ; j < author.length() ; j++)
        book.author[ j ] = author[ j ];
    file.write(book.author, author.length());   //to write in the file
    file << '|';

    check = true;
    while (check)
    {
        cout << "Please enter the price of the book: ";
        cin >> price;
        cout << endl;
        for(int i = 0 ; i < price.length() ; i++)
        {
            if( price[i] < char( 0 + 48 ) || price[i] > char( 9 + 48 ) )
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
    }
    check = true;

    book.price = new char[ price.length() ];
    for(int j = 0 ; j < price.length() ; j++)
        book.price[ j ] = price[ j ];
    file.write(book.price,price.length());
    file << '|';

    check = true;
    while (check)
    {
        cout << "Please enter the year: ";
        cin >> year;
        cout << endl;
        for(int i = 0 ; i < year.length() ; i++)
        {
            if( year[i] < char( 0 + 48 ) || year[i] > char( 9 + 48 ) )
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
    }
    check = true;

    book.year = new char[ year.length() ];
    for(int j = 0 ; j < year.length() ; j++)
        book.year[ j ] = year[ j ];
    file.write(book.year, year.length());
    file << '|';

    check = true;
    while (check)
    {
        cout << "Please enter the book's number of pages: ";
        cin >> pages;
        cout << endl;
        for(int i = 0 ; i < pages.length() ; i++)
        {
            if( pages[i] < char( 0 + 48 ) || pages[i] > char( 9 + 48 ) )
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }

        }
    }
    check = true;
    book.pages = new char[ pages.length() ];
    for(int j = 0 ; j < pages.length() ; j++)
        book.pages[ j ] = pages[ j ];
    file.write(book.pages, pages.length());
    file << '|'; ///End of field
    file << '&';///End of record

    file.close();

    delete []book.title;
    delete []book.author;
    delete []book.price;
    delete []book.year;
    delete []book.pages;

}

void DeleteBook(char ISBN[5])
{
    string str = "";
    int counter = 0;
    int len = 0;    //used to get the number of the characters inside the file
    file.open("Books.txt", ios::out| ios:: in);
    while(!file.eof())
    {
        getline(file, str, '&');    //gets every record and puts it in the string
        len += str.length();
        len++;
        for(int i = 0 ; i < 5 ; i++)    //to check if it is the wanted record or not
        {
            if(ISBN[i] == str[i])
            {
                counter++;
            }
        }
        if(counter == 5)    //if it is the wanted record
        {
            len -= str.length();    //to move to the beginning of the wanted record
            len--;  //to overwrite on the first character in the record
            file.seekg( 0, ios::beg );  //to go to the beginning of the file
            file.seekp( 0, ios::beg );
            file.seekg( len, ios::beg );    //to move to the targeted location
            string tmp = "*";
            file.write(&tmp[0], 1); //to overwrite * on the fist number of the ISBN to mark it as deleted
            break;
        }
        else
        {
            counter = 0;    //to reset the counter
        }
    }
    file.close();
}


void printBook(string title)
{
    file.open("Books.txt", ios::out| ios:: in);
    string str = "";
    int counter = 0;
    while(!file.eof())
    {
        getline(file, str, '&');

        if(str[0] != '*')   //to see if the record is already supposed to be deleted or nor
        {

            for(int i = 6, j = 0 ; i < str.length() ; i++, j++)
            {
                if(str[i] == '|')
                    break;
                if(title[j] == str[i])
                {
                    counter++;
                }
            }
            if(counter == title.length())   //if the record is not deleted
            {
                int i = 0;
                cout << "ISBN: ";
                while(str[i] != '|')    //to separate the fields from each other
                {
                    cout << str[i];
                    i++;
                }
                cout << endl << "Title: " << title << endl;
                i++;
                i += title.length();
                i++;
                cout << "Author: ";
                while(str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << endl << "Price: ";
                while(str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << endl << "Year: ";
                while(str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << endl << "Number of Pages: ";
                while(str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                cout << endl;

                break;
            }
            else
            {
                counter = 0;
            }
        }
    }
    file.close();
}

void PrintAllBooks()
{
    file.open("Books.txt", ios::out | ios::in);
    string str = "";
    int counter = 0;
    file.clear();
    while (!file.eof())
    {
        getline(file, str, '&');
        if(str[0] != '*')   //to see if the record is deleted or not
        {
            for (int i = 0; i < str.length(); i++)
            {

                cout << "\nISBN: ";
                while (str[i] != '|')   //to separate the fields from each other inside the record
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << "\nTitle: ";
                while (str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << "\nAuthor: ";
                while (str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << "\nPrice: ";
                while (str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << "\nYear: ";
                while (str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << "\nNumber of pages: ";
                while (str[i] != '|')
                {
                    cout << str[i];
                    i++;
                }
                i++;
                cout << "\n\n";
            }
        }
    }
    file.close();
}

void UpdateBook(char ISBN[5])
{
    string str = "";
    int counter = 0;
    int len = 0;
    file.open("Books.txt", ios::out| ios:: in);
    while(!file.eof())
    {
        getline(file, str, '&');
        len += str.length();    //to know the position of the targeted record
        len++;
        for(int i = 0 ; i < 5 ; i++)
        {
            if(ISBN[i] == str[i])
            {
                counter++;
            }
        }
        if(counter == 5)
        {
            len -= str.length();
            len--;
            file.seekg( 0, ios::beg );
            file.seekp( 0, ios::beg );
            file.seekg( len, ios::beg );
            string tmp = "";    //to store the new record in it
            for(int i = 0 ; i < 5 ; i++)
            {
                tmp += ISBN[i];
            }
            tmp += '|';
            string title, author, price, year, pages;
            cout << "Please enter the new title: ";
            getline(cin >> std::ws, title);
            tmp += title;
            tmp += '|';

            cout << "Please enter the new name of the author: ";
            getline(cin >> std::ws, author);
            tmp += author;
            tmp += '|';
            check = true;
            while (check)
            {
                cout << "Please enter the new price of the book: ";
                cin >> price;
                cout << endl;
                for(int i = 0 ; i < price.length() ; i++)
                {
                    if( price[i] < char( 0 + 48 ) || price[i] > char( 9 + 48 ) )
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }

                }
            }
            check = true;
            tmp += price;
            tmp += '|';

            check = true;
            while (check)
            {
                cout << "Please enter the new year: ";
                cin >> year;
                cout << endl;
                for(int i = 0 ; i < year.length() ; i++)
                {
                    if( year[i] < char( 0 + 48 ) || year[i] > char( 9 + 48 ) )
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }

                }
            }
            check = true;

            tmp += year;
            tmp += '|';

            check = true;
            while (check)
            {
                cout << "Please enter the new number of pages: ";
                cin >> pages;
                cout << endl;
                for(int i = 0 ; i < pages.length() ; i++)
                {
                    if( pages[i] < char( 0 + 48 ) || pages[i] > char( 9 + 48 ) )
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }

                }
            }
            check = true;

            tmp += pages;
            tmp += '|';
            for(int k = 0 ; k  < str.length() ; k++)    //to overwrite inside the file
                file.write(&tmp[k], 1);
            break;
        }
        else
        {
            counter = 0;
        }
    }
    file.close();

}

/*bool ISBNexist(char ISBN[5])
{
	string str = "";
	int counter = 0;
	while (!file.eof())
	{
		counter = 0;
		getline(file, str, '&');

		for (int i = 0; i < 5; i++)
		{
			if (str[i] == ISBN[i])
			{
				counter++;
			}
			else
			{
				break;
			}
		}

		if (counter == 5)
		{
			cout << "\nError. This ISBN is already used.\n";
			return true;
		}
		else
		{
			counter = 0;
		}
	}
	return false;
}*/

