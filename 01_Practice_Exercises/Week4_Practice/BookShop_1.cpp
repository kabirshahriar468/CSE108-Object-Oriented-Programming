#include<iostream>
#include<cstring>
#include<cmath>
//#include "Book.cpp"
#include<ctime>

using namespace std;
class Book
{
    int isbn;
    char *title;
    double price;

public:
    // Constructor functions
    Book()
    {
        // default constructor
        title = new  char[20];

        isbn = -1;
        price = 0;

        strcpy(title, "No Title");
    }

    Book(int isbn, char *title, int price)
    {
        // constructor with arguments

        int len = strlen(title) + 1;
        this->title = new char[len];
        strcpy(this->title, title);

        this->isbn = isbn;
        this->price = price;
    }


    Book(const Book &book)
    {
        // Copy constructor

        int len = strlen(book.title) + 1;
        title = new char[len];
        isbn = book.isbn;
        price = book.price;

        strcpy(title, book.title);
    }

    // Destructor function
    ~Book()
    {

        delete[] title;
    }

    void setisbn(int n)
    {
        isbn = n;
    }

    void setprice(int n)
    {
        price = n;
    }

    void settitle(const char *Title)
    {
        delete[] title;
        int len = strlen(Title) + 1;
        title = new char[len];

        strcpy(title, Title);
    }

    int getisbn()
    {
        return isbn;
    }
    int getprice()
    {
        return price;
    }
    char *gettitle()
    {
        return title;
    }

    // Service functions
    void print()
    {
        cout << "title: " << title << ", isbn: " << isbn << ", price: " << price << endl;
    }

    int isTheSameBook(Book b)
    {
        return isbn == b.isbn;
    }

    Book generateNewEdition(int isbn, int price)
    {
        Book boi;
        boi.price = price;
        boi.title = title;
        boi.isbn = isbn;

        return boi;
    }
};
class BookShop
{   clock_t start;
    char* name;
    Book* books; //List of books in the shop
    int size;  //maximum number of books the shop can keep
    int count; //tracks currently how many numbers in the shop
public:
    void setName(char* name)
    {
        /*Set the name of the bookshop to the given name*/
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    BookShop() //Default constructor
    {
        /*Initialize with size 5 and name to empty string ""*/
        books=new Book[sizeof(Book)*5];
        count=0;
    }

    BookShop(char* name, int size) //Parameterized constructor
    {
        /*Initialize with the given name and size*/
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        books=new Book[sizeof(Book)*size];
        this->size=size;
        start=clock();


    }

    BookShop(const BookShop& bs) //Copy constructor
    {
        /*Write necessary code for the copy constructor*/
        name=bs.name;
        books=new Book[5];
        books=bs.books;
        size=bs.size;
        count=bs.count;

    }

    ~BookShop() //Destructor
    {
        /*Free memory as applicable*/
        delete []name;
        delete []books;
    }

    void addBook(Book b)
    {
        /*Add book b to the end of the list*/
        books[count]=b;


    }

    void addBook(Book* ba, int c)
    {
        /*Add the given array of books ba to the end of the list*/
        books[c].setisbn(ba->getisbn());
        books[c].setprice(ba->getprice());
        char str[20];
        strcpy(str,ba->gettitle());
        books[c].settitle(str);
        count=c+1;
        clock_t end;
        end=clock();
        cout<<"In this segment"<<(end-start)/(CLOCKS_PER_SEC)<<endl;
    }

    Book getBookInfo(char* title)
    {
        /*Return the **first** book that has the given title. Assume there is atleast one book in the list with the given title*/
        int info;
        Book p;
        for(int i=0; i<count; i++)
        {

            if(!strcmp(books[i].gettitle(),title))
            {

                info=i;
                break;
            }
        }

        p.setisbn(books[info].getisbn());
        p.setprice(books[info].getprice());
        strcpy(p.gettitle(),books[info].gettitle());
        return p;

    }

    void updateBookPrice(int isbn, int price)
    {
        /*Update the price of the book with given isbn to the given price*/
        int flag;
        for(int k=0; k<count; k++)
        {

            if(books[k].getisbn()==isbn)
            {
                flag=k;
            }
        }
        books[flag].setprice(price);
    }

    void removeBook(int isbn)
    {
        /*Remove the book with the given isbn from the list. After removing a book all the books below the removed book will be shifted up, i.e, there will be no hole in the list*/
        int flag,p;
        for(int k=0; k<count; k++)
        {

            if(books[k].getisbn()==isbn)
            {
                flag=k;
            }
        }

        for(int a=flag,p=0; a<count-1; a++,p++)
        {

            books[a]=books[a+1];

        }
        count=count-1;

    }

    int totalPrice()
    {
        int sum=0;
        for(int i=0; i<count; i++)
        {
            sum=sum+books[i].getprice();
        }
        return sum;
        /*Return the sum of the prices of all the books in the list*/
    }

    void print()
    {
        /*Print the bookshop's name followed by information of all the books in the bookshop*/
        /*Output:
        			Bookshop Name: Boimela
        			ISBN: 101, Title: Teach Yourself C++, Price: 100
        			ISBN: 102, Title: Teach Yourself C, Price: 200
        			ISBN: 103, Title: Java For Dummies, Price: 300
        		 */

        cout<<"Bookshop Name:"<<name<<endl;

        for(int i=0; i<count; i++)
        {
            cout<<"ISBN:"<<books[i].getisbn()<<",Title:"<<books[i].gettitle()<<",Price:"<<books[i].getprice()<<endl;
        }


    }


    BookShop mergeShop(BookShop b)
    {
        /* Return a new bookshop object that will contain all the books of this bookshop and the given bookshop b*/
        /* Use the title **MergedShop** of the new bookshop														*/
        BookShop temp;
        temp.books=new Book[5];
        int j,k;

        for(int i=0; i<2; i++)
        {
            temp.books[i]=this->books[i];
        }
        for(j=2,k=0; j<5,k<3; j++,k++)
        {

            temp.books[j]=b.books[k];

        }
        return temp;



    }
    int counter()
    {
        return count;
    }
    void setcounter(int n){

        count=n;
    }

};

int main()
{

    BookShop bs1;
    bs1.setName("Boimela");
    Book b1(101,"Teach Yourself C++",100);
    Book b2(102,"Teach Yourself C",200);
    Book b3(103,"Java For Dummies",300);
    bs1.addBook(&b1,0);
    bs1.addBook(&b2,1);
    bs1.addBook(&b3,2);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 102, Title: Teach Yourself C, Price: 200
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */
    cout<<endl;
    cout<<"Total price of books: "<<bs1.totalPrice()<<endl;	/*Output:
															   Total price of books: 600
															*/
    //cout<<bs1.counter();
     cout<<endl;
     bs1.removeBook(102);
     //cout<<bs1.counter()<<endl;
     bs1.print(); /*Output:
    				Bookshop Name: Boimela
    				ISBN: 101, Title: Teach Yourself C++, Price: 100
    				ISBN: 103, Title: Java For Dummies, Price: 300*/


    cout<<endl;
     bs1.updateBookPrice(101,500);
     bs1.print(); /*Output:
    				Bookshop Name: Boimela
    				ISBN: 101, Title: Teach Yourself C++, Price: 500
    				ISBN: 103, Title: Java For Dummies, Price: 300*/


     cout<<endl;
     Book jfd=bs1.getBookInfo("Java For Dummies");
     jfd.print();  /*Output:
    				 ISBN: 103, Title: Java For Dummies, Price: 300*/


     cout<<endl;
    //  cout<<bs1.counter();
     Book ba[3]= {Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
     BookShop bs2("Puthighor",5);
     bs2.addBook(&ba[0],0);
     bs2.addBook(&ba[1],1);
     bs2.addBook(&ba[2],2);

     bs2.print();  /*Output:
    				 Bookshop Name: Puthighor
    				 ISBN: 201, Title: Operating Systems, Price: 1000
    				 ISBN: 202, Title: Compilers, Price: 2000
    				 ISBN: 203, Title: Computer Networks, Price: 1500*/

    // cout<<bs2.counter();
     cout<<endl;
     BookShop bs3(bs1.mergeShop(bs2));
     int q=bs2.counter()+bs1.counter();
     bs3.setcounter(q);
     bs3.setName("Mullick Brothers");
     bs3.print();
     // cout<<bs3.counter();
     /*Output:
    				Bookshop Name: Mullick Brothers
    				ISBN: 101, Title: Teach Yourself C++, Price: 500
    				ISBN: 103, Title: Java For Dummies, Price: 300
    				ISBN: 201, Title: Operating Systems, Price: 1000
    				ISBN: 202, Title: Compilers, Price: 2000
    				ISBN: 203, Title: Computer Networks, Price: 1500
    				*/

}
