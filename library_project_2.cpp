

/*
This source code is made for employees and users of the main library. it enables the employee:

1) Retreive a book from the library
2) Add books to the library store
3)prints out the books currently in shelve, also books already borrowed
4)prints out the total number of books in the library's possession and those already borrowed
5)


N:B : Outputs are printed to the terminal
*/



//sort the entered books via the coded
//allow users to borrow books. use the find algorithm. if found give it to ther user and 
//append the borowwed book to a new container and erase it from the library container
//allow library staff to add a book

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <tuple>

using namespace std;

class Books{

friend ostream &operator<<( const ostream  &os,const  Books &rhs);

private:

    string *author_name;
    string *call_number;

public:
//class constructor
    Books( string author_name_val, string call_number_val )
        {
            
            author_name = new string;
            *author_name=author_name_val;
            
            call_number = new string ;
            *call_number =call_number_val;
           }


//Deep copy constructor
    Books( const Books &source)
        :author_name{source.author_name},call_number{source.call_number} {

            author_name =new string;
            *author_name=*source.author_name;

            call_number = new string ;
            *call_number=*source.call_number;


       
        }
    
    


//overloading the equal operator to enable use of the find algorithm
    bool operator==(const Books  &rhs){

        return  *call_number == *rhs.call_number  && *author_name == *rhs.author_name;
    
    }


    bool operator<(const Books &rhs){

        return *call_number < *rhs.call_number;
    
    }


    string get_call_number(){
        
        return *call_number;
      
    }

string get_author_name(){

            return *author_name;
    

}




~Books(){
    delete call_number;
    delete author_name;
}

};


//overloading the insertion operator to enable printing out of attributes of the class object
ostream &operator<<( ostream  &os, Books &rhs){
    os<<"author name : "<<rhs.get_author_name()<<"...........call number: "<<rhs.get_call_number();
    return os;
}




//......................................................................................//

template<typename T>
void Display(vector<T>  a);



tuple<string, string> Enter_details();
void case_incensitive(  string &word);


int main () {




char *choice = new char;


string *author_name{}, *call_number{};
int *total_books{};

author_name = new string;
call_number = new string;
total_books = new int;



vector<Books>  library{}, borrowed_books{};       


do{


cout<<"\nHere are the options:\n(a)add a book \n(l) lend a book\n(t) total books owned";
cout<<" by library and total books lend to users\n(p)list of all books  currently in library\n(q) exit from system"<<endl;

cout<<"enter your choice: ";
cin>>*choice;
*choice = toupper(*choice);




switch ( *choice) {

    case 'A':
        {
        
        system("clear");
        tie(*author_name,*call_number)=Enter_details();

     
        library.push_back(Books{*author_name,*call_number});
        }
        break;

    case 'L':
        {
            system("clear");
         
         tie(*author_name,*call_number)=Enter_details();
          Books target{*author_name,*call_number};


        auto i =find(library.begin(), library.end(), target);
      
       if (i != library.end()){
          cout<<"book found and you can have the book"<<endl;
        
          borrowed_books.push_back(target); 
          library.erase(i);                                   //deleting the book from the library shelve
       }

       else{

        //searching for book in borrowed_books container
        auto i = find(borrowed_books.begin(), borrowed_books.end(), target);
        if ( i != borrowed_books.end()){
          cout<<"book has already been borrowed; kindly check back later"<<endl;
        }
        else
            cout<<"library doesn't have the book  at all"<<endl;
        }

        }
      break;
    
    case 'T':
        {
            system("clear");
        *total_books = library.size()+borrowed_books.size();
        cout<<"Library has "<< *total_books<<" books with "<<borrowed_books.size()<<" currently borrowed by users\n"<<endl;
        break;
        
        }
    case 'P':
        
        {
        
        system("clear");
        cout<<"here are the books currently in the library:\n";
        Display(library);
        cout<<endl;
        cout<<"here are the books already borrowed:\n";
        Display(borrowed_books);
        }
        
        break;
    
    case 'Q':
        
            {
            system("clear");
            cout<<"thanks for using the library system \n "<<endl;
            }
        
            break;
            
    default:
            cout<<"Invalid Choice"<<endl;
            

}


}while(*choice != 'Q');



delete author_name;
delete call_number;
delete total_books;
delete choice;

    return 0;
}


template<typename T>
void Display(vector<T>  a){

    
    
    if ( a.size()==0){
        cout<<"none"<<endl;
    }

else{
    for ( auto i: a)
        cout<<i<<endl;

}
}


tuple<string, string> Enter_details(){

    string *author_name = new string;
    string *call_number = new string;

   
    cout<<"Enter call number: ";
    cin >> *call_number;
    
    cin.ignore();
    

    cout<<"Enter Author's name: ";
    getline(cin, *author_name);
    
    case_incensitive(*author_name);
    


    return {*author_name, *call_number};


    delete author_name;
    delete call_number;

}

void case_incensitive(  string &word){

        for( size_t i{0}; i< word.size(); i++)
                        word[i]=tolower(word[i]);
}
