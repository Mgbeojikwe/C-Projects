

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
#include <list>
#include <iomanip>

using namespace std;

class Books{

friend ostream &operator<<( const ostream  &os,const  Books &rhs);

private:

string *author_name;
string *call_number;

public:
//class constructor
Books(string callnumber_val, string author_name_val )
    {
            call_number = new string;
            *call_number=callnumber_val;
  
            author_name = new string;
            *author_name = author_name_val;

           }


//Deep copy constructor
Books( const Books &source)
    {

        call_number= new string;
        *call_number=*source.call_number;


       
    }
    
    


//overloading the equal operator to enable use of the find algorithm
bool operator==(const Books  &rhs){

    return (*call_number==*rhs.call_number  && *author_name == *rhs.author_name);
}


bool operator<(const Books &rhs){

    return (call_number < rhs.call_number);
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
    os<<"author name ="<<rhs.get_author_name()<<"...........call number: "<<rhs.get_call_number();
    return os;
}




//......................................................................................//

template<typename T>
void Display(list<T>  a);


int main () {



//#include "../area.h"
char selection{};
char choice{};
string author_name{}, call_number{};
int total_books{};

list<Books> library{ {"Maclaine","LB240.1203"},
                     {"Adams","AB4.4907"},
                     {"Lott", "AC9.9078"} 
                    }, borrowed_books{};       


//list<Books>::iterator i=library.begin();
cout<<"here are the books currently in the library: "<<endl;
Display(library);

cout<<"Here are the options:\n(a)add a book \n(l) lend a book\n(t) total books owned";
cout<<" by library and total books lend to users\n(p)list of all books  currently in library\n(q) exit from system"<<endl;

do{


cout<<"enter your choice: ";
cin>>choice;
selection = toupper(choice);



switch (choice) {

    case 'A':

        cout<<"enter author's name: ";
        cin>>author_name;
        cout<<"enter code number: ";
        cin>>call_number;

        library.push_back( Books{author_name,call_number} );
        break;

    case 'L':

          cout<<"enter author's name: ";
          cin>>author_name;
          cout<<"enter call number of book: "<<endl;
          cin>>call_number;
        
          Books target{author_name,call_number};

        auto i =find(library.begin(), library.end(), target);
      
       if (i != library.end()){
          cout<<"book found and you can have the book"<<endl;
        
          borrowed_books.push_back(target); 
          library.erase(i); //deleting the book from the library shelve
       }

       else{

        //searching for book in borrowed_books container
        auto i = find(borrowed_books.begin(), borrowed_books.end(), target);
        if ( i != borrowed_books.end()){
          cout<<"book has already been borrowed"<<endl;
        }
        else
            cout<<"library doesn't have the book"<<endl;
        }
      break;
    
    case 'T':
        total_books = library.size()+borrowed_books.size();
        cout<<"Library has "<<total_books<<" books with "<<borrowed_books.size()<<" currently borrowed by users"<<endl;
        break;

    case 'P':
        cout<<"here are the latest books in the library:\n";
        Display(library);
        cout<<endl;
        cout<<"here are the books already borrowed:\n";
        Display(borrowed_books);
        break;
    
    case 'Q':
            cout<<"thanks for today "<<endl;
            break;
            
    default:
            cout<<"Invalid Choice"<<endl;
            

}

//}while(choice != 'Q');

// if (selection=='A'){
    

//     cout<<"enter code number: ";
//     cin>>call_number;

//     library.push_back( Books{call_number} );
    
//     }

//else if (selection=='L'){
    //     cout<<"enter call number of book: "<<endl;
    //     cin>>call_number;
        
    //     Books target{call_number};

    //   auto i =find(library.begin(), library.end(), target);
      
    //   if (i != library.end()){
    //       cout<<"book found and you can have the book"<<endl;
        
    //     borrowed_books.push_back(target); 
    //     library.erase(i); //deleting the book from the library shelve
      //}


    // else{

    //     //searching for book in borrowed_books container
    //   auto i = find(borrowed_books.begin(), borrowed_books.end(), target);
    //   if ( i != borrowed_books.end()){
    //       cout<<"book has already been borrowed"<<endl;
    //   }
    //     else
    //         cout<<"library doesn't have the book"<<endl;
    // }


//}

// else if ( selection =='T'){
//         total_books = library.size()+borrowed_books.size();
//         cout<<"Library has "<<total_books<<" books with "<<borrowed_books.size()<<" currently borrowed by users"<<endl;
        

//}
// else if (selection=='P'){
//     // cout<<"here are the latest books in the library:\n";
//     // Display(library);
//     // cout<<endl;
//     // cout<<"here are the books already borrowed:\n";
//     // Display(borrowed_books);
// }
// else if (selection=='Q')
//         cout<<"thanks for today "<<endl;
//else    
    // cout<<"you entered a wrong option"<<endl;

// }while(selection != 'Q');


    return 0;
}


template<typename T>
void Display(list<T>  a){

    
    
    if ( a.size()==0){
        cout<<"none"<<endl;
    }

else{
    for ( auto i: a)
        cout<<i<<endl;

}
}
