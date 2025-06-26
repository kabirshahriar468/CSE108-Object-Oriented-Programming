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
			title="\0";
		}

		Book(int isbn, char* title, int price){//constructor with arguments
			cout<<"In the parameterized constructor of Book"<<endl;
			//Write your code here
			this->isbn=isbn;
			this->price=price;
			int len=strlen(title)+1;
			this->title=new char[len];
			strcpy(this->title,title);

		}
		Book(const Book& book){//Copy constructor
		    cout<<"In the copy constructor of Book"<<endl;
			//Write your code here
			isbn=book.isbn;
			price=book.price;
			int len=strlen(book.title)+1;
			this->title=new char[len];
            strcpy(title,book.title);
		}

		//Destructor function
		~Book(){
		    cout<<"In the destructor of Book"<<endl;
			//Write your code here
			if(strlen(title)){
				cout<<"freeing title of book class "<<endl;
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
			 this->title=new char[len];
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


class BookShop{
	char* name;
	Book* books; //List of books in the shop
	int size;  //maximum number of books the shop can keep
	int count=0; //tracks currently how many numbers in the shop
	public:
		void setName(char* name){
		/*Set the name of the bookshop to the given name*/
			this->name=new char[strlen(name)+1];
			strcpy(this->name,name);
			
		}

		BookShop(){//Default constructor
		/*Initialize with size 5 and name to empty string ""*/
		    cout<<"In the default constructor of Book  Shop"<<endl;
			size=5;
			books=new Book[size];
			name="\0";
		}

		BookShop(char* name, int size){//Parameterized constructor
		/*Initialize with the given name and size*/
		cout<<"In the parameterized constructor of Book  Shop"<<endl;
			this->name=new char[strlen(name)+1];
			strcpy(this->name,name);
			this->size=size;
			books=new Book[size];
		}

		BookShop(const BookShop& bs){//Copy constructor
		/*Write necessary code for the copy constructor*/
			cout<<"In the copy constructor of Book  Shop"<<endl;
			name=new char[strlen(bs.name)+1];
			strcpy(name,bs.name);
			size=bs.size;
			count=bs.count;
			books=new Book[size];
			for(int i=0;i<count;i++){
				
				books[i].setISBN(bs.books[i].getISBN());
				
				books[i].setPrice(bs.books[i].getPrice());
				
				books[i].setTitle(bs.books[i].getTitle());
				
			}
		}

		~BookShop(){//Destructor
		/*Free memory as applicable*/
			
			if(0){
				cout<<"freed books inside bookshop"<<endl;
				delete []books;
			}
			if(strlen(name)){
				cout<<"freed name inside bookshop "<<endl;
				delete []name;
			}
		}

		void addBook(Book b){
		/*Add book b to the end of the list*/
			
			books[count].setISBN(b.getISBN());
			books[count].setPrice(b.getPrice());
			books[count].setTitle(b.getTitle());
			count ++;
		}

		void addBook(Book *ba, int count){
		/*Add the given array of books ba to the end of the list*/
			for(int i=0;i<count;i++){
				books[this->count+i].setISBN((ba+i)->getISBN());
				books[this->count+i].setPrice((ba+i)->getPrice());
				books[this->count+i].setTitle((ba+i)->getTitle());
			}
			this->count+=count;
		}

		Book getBookInfo(char* title){
		/*Return the **first** book that has the given title. Assume there is atleast one book in the list with the given title*/
			for(int i=0;i<count;i++){
				if(!strcmp(books[i].getTitle(),title)){
					
					return books[i];
				}
			}
		}

		void updateBookPrice(int isbn, int price){
		/*Update the price of the book with given isbn to the given price*/
			for(int i=0;i<count;i++){
				if(books[i].getISBN()==isbn){
					books[i].setPrice(price);
					break;
				}
			}
		}

		void removeBook(int isbn){
		/*Remove the book with the given isbn from the list. After removing a book all the books below the removed book will be shifted up, i.e, there will be no hole in the list*/
			for(int i=0;i<count;i++){
				if(books[i].getISBN()==isbn){
					for(int j=i;j<count-1;j++){
						books[j]=books[j+1];
					}
					count--;
					break;
				}
			
			}
		}

		int totalPrice(){
		/*Return the sum of the prices of all the books in the list*/
			int sumPrice=0;
			for(int i=0;i<count;i++){
				sumPrice+=books[i].getPrice();
			}
			return sumPrice;
		}

		void print(){
		/*Print the bookshop's name followed by information of all the books in the bookshop*/
			cout<<"Bookshop Name:"<<name<<endl;
			for(int i=0;i<count;i++){
				books[i].print();
			}
		}

		BookShop mergeShop(BookShop b){
		/* Return a new bookshop object that will contain all the books of this bookshop and the given bookshop b*/ 			/* Use the title **MergedShop** of the new bookshop														*/
			BookShop mergedShop;

			mergedShop.size=size+b.size;
			mergedShop.count=count+b.count;
			mergedShop.name="Merged Shop";
			mergedShop.books=new Book[mergedShop.size];
		
			for(int i=0;i<count;i++){
				mergedShop.books[i].setISBN(books[i].getISBN());
					mergedShop.books[i].setPrice(books[i].getPrice());
						mergedShop.books[i].setTitle(books[i].getTitle());
				
				
			}
			for(int i=count;i<mergedShop.count;i++){

				//mergedShop.books[i]=b.books[i-count];
				mergedShop.books[i].setISBN(b.books[i-count].getISBN());
				mergedShop.books[i].setPrice(b.books[i-count].getPrice());
				mergedShop.books[i].setTitle(b.books[i-count].getTitle());
			}
			
			return mergedShop;

		}
		
};



int main(){

	BookShop bs1;
	bs1.setName("Boimela");
	Book b1(101,"Teach Yourself C++",100);
	Book b2(102,"Teach Yourself C",200);
	Book b3(103,"Java For Dummies",300);
	bs1.addBook(b1);
	bs1.addBook(b2);
	bs1.addBook(b3);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 102, Title: Teach Yourself C, Price: 200
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */
	cout<<endl;
	cout<<"Total price of books: "<<bs1.totalPrice()<<endl;
	        												/*Output:
															   Total price of                         books: 600
															*/

	cout<<endl;
	bs1.removeBook(102);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	bs1.updateBookPrice(101,500);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	Book jfd=bs1.getBookInfo("Java For Dummies");
	jfd.print();  /*Output:
					 ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	Book ba[3]={Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
	BookShop bs2("Puthighor",5);
	bs2.addBook(ba,3);
	bs2.print();  /*Output:
					 Bookshop Name: Puthighor
					 ISBN: 201, Title: Operating Systems, Price: 1000
					 ISBN: 202, Title: Compilers, Price: 2000
					 ISBN: 203, Title: Computer Networks, Price: 1500
				 */

	cout<<endl;
	
	BookShop bs3=bs1.mergeShop(bs2);
	
	bs3.setName("Mullick Brothers");
	bs3.print();
				 /*Output:
					Bookshop Name: Mullick Brothers
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
					ISBN: 201, Title: Operating Systems, Price: 1000
					ISBN: 202, Title: Compilers, Price: 2000
					ISBN: 203, Title: Computer Networks, Price: 1500
				 */
	return 0;
}
