/************Topics of Practice*************************/
/* => Dynamic Allocation of objects         		   */
/* => Constructor overloading		        		   */
/* => Copy constructor				        		   */
/* => Passing and returning objects from functions     */
/*******************************************************/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Book{
	int isbn;
	char* title;
	int price;
	public:
		//Constructor functions
		Book(){//default constructor
		    cout<<"In the default constructor of Book"<<endl;
			//Write your code here
			isbn=-1;
			price =0;
		}

		Book(int isbn, char* title, int price){//constructor with arguments
			cout<<"In the parameterized constructor of Book"<<endl;
			//Write your code here
			this->isbn=isbn;
			this->price=price;
			int len=strlen(title)+1;
			this->title=(char *)malloc(sizeof(char)*len);
			strcpy(this->title,title);

		}
		Book(const Book& book){//Copy constructor
		    cout<<"In the copy constructor of Book"<<endl;
			//Write your code here
			isbn=book.isbn;
			price=book.price;
			int len=strlen(book.title)+1;
			title=(char *)malloc(sizeof(char)*len);
            strcpy(title,book.title);
		}

		//Destructor function
		~Book(){
		    cout<<"In the destructor of Book"<<endl;
			//Write your code here
			if(!title){
			    delete []title;
			}
		}

		//Write the setter functions here
		void setISBN(int i){
			isbn=i;
		}
		void setPrice(int p){
			price=p;
		}
		void setTitle(char *title){
			int len=strlen(title)+1;
			this->title=(char *)malloc(sizeof(char)*len);
			strcpy(this->title,title);
		}

		//Write the getter functions here
		int getISBN(){
			return isbn;
		}
		int getPrice(){
			return price;
		}
		char *getTitle(){
			return title;
		}
		//Service functions
		void print(){
			//Write your code here
			cout<< "ISBN: "<<isbn;
			cout<<", Title: "<<title;
			cout<<", Price: "<<price<<endl;
		}

		int isTheSameBook(Book b){
			//Write your code here
			if(isbn==b.isbn)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}

		Book generateNewEdition(int isbn, int price){
			//Write your code here
			Book temp;
			int len=strlen(title)+1;
			temp.title=(char *)malloc(sizeof(char)*len);
			strcpy(temp.title,title);
			temp.isbn=isbn;
			temp.price=price;
			return temp;
		}
		
};

int main(){
	//To do: Create a book object named b1 with the default constructor
	Book b1;
	//To do: Set the properties of b1 as follows: isbn=101, title="Teach yourself C++", price=230
	b1.setISBN(101);
	b1.setTitle("Teach yourself C++");
	b1.setPrice(230);
	//To do: Print the details of b1
	b1.print();

	//To do: Create a book object named b2 with values initialized as- isbn=102, title="Teach Yourself Java", price=235
	Book b2(102,"Teach Yourself Java",235);
	//To do: Crate a book object b3 and initialize with b2
	Book b3(b2);
	//To do: Check if b2 and b3 represent the same book. Print "Yes" or "No" based on the check result.
	b2.isTheSameBook(b3);

	//To do: Change the title of b3 to "Teach Yourself Java in Thirty Days"
	b3.setTitle("Teach Yourself Java in Thirty Days");
	//To do: Change the isbn of b3 to 103
	b3.setISBN(103);
	//To do: Print the details of book b2 and b3
	b2.print();
	b3.print();
	//To do: Create a book b4 as a new edition of b3. Set the isbn and price of the new edition to 104 and 600, respectively
	Book b4=b3.generateNewEdition(104,600);
	
	//To do: Create a Book pointer named bp1
	Book *bp1;
	//To do: Allocate a Book object to bp1 initialized as- isbn=104, title="C++ For Dummies", price=400
	bp1=new Book(104,"C++ For Dummies",400);
	//To do: Print the details of the book pointed by bp1
	bp1->print();
	//To do: Free the memory allocated to bp1
	free(bp1);
	//To do: Create a Book pointer named bl1 and allocate three book objects to it without any initialization
	Book *bl1;
	bl1=new Book[3];
	//To do: Set the properties of the three book objects pointed to by bl1 as follows:
	// <isbn=201, title=Compilers, price=340>,
	// <isbn=202, title=Operating Systems, price=450>,
	// <isbn=203, title=Data Communications, price=600>
	(bl1+0)->setISBN(201);
	(bl1+0)->setPrice(340);
	(bl1+0)->setTitle("Compilers");

	(bl1+1)->setISBN(202);
	(bl1+1)->setPrice(450);
	(bl1+1)->setTitle("Operating Systems");

	(bl1+2)->setISBN(203);
	(bl1+2)->setPrice(600);
	(bl1+2)->setTitle("Data Communications");

	//To do: Print the details of all the three books pointed to by bl1
	(bl1+0)->print();
	(bl1+1)->print();
	(bl1+2)->print();
	//To do: Free the memory allocated to bl1
	free(bl1);
	return 0;
}