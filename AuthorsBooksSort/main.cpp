
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <array>

using namespace std;


struct BInfo
{
    string Title;
    string AuthorName;
    int Year;
    string Language;
    string Genre;
    int sale;
};

struct DOB
{
    int month;
    int day;
    int year;
};

struct AInfo
{
    string Name;
    struct DOB;
    string famousBook;
};

void printBook(BInfo ReadB[], ifstream& InfileBooks, ofstream& outfileBooks,int& booksize);
void printAuthors(AInfo ReadA[], ifstream& InfileAuthors,ofstream& oufileAuthors, DOB AuthorDate[], int& authorsize);
void printAuthorsMatched(AInfo ReadA[],BInfo ReadB[],ifstream& InfileBooks,ifstream& InfileAuthors,int& authorsize, int& booksize,
                         DOB AuthorDate[]);


int main()
{
    ifstream InfileBooks;
    ifstream InfileAuthors;
    ofstream outfileBooks;
    ofstream outfileAuthors;
    InfileBooks.open("Books.txt");
    InfileAuthors.open("Authors.txt");
    outfileBooks.open("OrderedBooks.txt");
    outfileAuthors.open("OrderedAuthors.txt");


    int booksize;
    int authorsize;

    InfileBooks>>booksize;
    InfileAuthors>>authorsize;

    BInfo ReadB[booksize];
    AInfo ReadA[authorsize];
    DOB AuthorDate[authorsize];

    int selection = 0;

         while(selection  < 4)
    {

        cout << " 1.   Print Books\n 2.   Print Authors\n 3.   Print Matches\n "
        << "4.   Terminate\n Enter selection: ";
        cin>>selection;
        cout<<endl;


    switch(selection){
    case 1:
        printBook(ReadB,InfileBooks,outfileBooks,booksize);
        break;

    case 2:
        printAuthors(ReadA, InfileAuthors,outfileAuthors, AuthorDate, authorsize);
        break;
  case  3:
        printAuthorsMatched(ReadA, ReadB,InfileBooks,InfileAuthors,authorsize,booksize,AuthorDate);
        break;
        }
    }

    InfileBooks.close();
    InfileAuthors.close();
    outfileBooks.close();
    outfileAuthors.close();

    return 0;
}

void printBook(BInfo ReadB[],ifstream& InfileBooks,ofstream& outfileBooks, int& booksize )
{
    cout<<"                                       Books                                      \n";
    cout<<left<<setw(33)<<"TITLE"<<left<<setw(20)<<"AUTHOR"<<left<<setw(18)<<"RELEASE YEAR"<<left<<setw(15)<<"LANGUAGE"<<left<<setw(22)
        <<"GENRE" <<left<<"SALE\n\n";
    int i=0,j;
    int temp;
    string tempo;
    for (i = 0; i < booksize ; i++ )
    {
        InfileBooks>> ReadB[i].Title>> ReadB[i].AuthorName >>ReadB[i].Year>>ReadB[i].Language>>ReadB[i].Genre>>ReadB[i].sale;
            replace( ReadB[i].Title.begin(), ReadB[i].Title.end(), '_', ' ');
            replace( ReadB[i].AuthorName.begin(), ReadB[i].AuthorName.end(), '_', ' ');
    }

    for (i = 0; i < booksize; i++)
    {
        for(j = i+1 ; j < booksize+1; j++)
        {
            if(ReadB[i].sale<ReadB[j].sale)
            {
                tempo=ReadB[i].Title;
                ReadB[i].Title=ReadB[j].Title;
                ReadB[j].Title=tempo;

                tempo=ReadB[i].AuthorName;
                ReadB[i].AuthorName=ReadB[j].AuthorName;
                ReadB[j].AuthorName=tempo;

                temp=ReadB[i].Year;
                ReadB[i].Year=ReadB[j].Year;
                ReadB[j].Year=temp;

                tempo=ReadB[i].Language;
                ReadB[i].Language=ReadB[j].Language;
                ReadB[j].Language=tempo;

                tempo=ReadB[i].Genre;
                ReadB[i].Genre=ReadB[j].Genre;
                ReadB[j].Genre=tempo;

                temp=ReadB[i].sale;
                ReadB[i].sale=ReadB[j].sale;
                ReadB[j].sale=temp;
            }

        }
        cout<<left<<setw(33)<<ReadB[i].Title<<left<<setw(23)<< ReadB[i].AuthorName<<setw(15)<<ReadB[i].Year<<setw(15)
            <<ReadB[i].Language<<setw(22)<<ReadB[i].Genre<<left<<ReadB[i].sale<<endl;

        outfileBooks<<left<<setw(33)<<ReadB[i].Title<<left<<setw(23)<< ReadB[i].AuthorName<<setw(15)<<ReadB[i].Year<<setw(15)
            <<ReadB[i].Language<<setw(22)<<ReadB[i].Genre<<left<<ReadB[i].sale<<endl;
    }
    cout<<endl;
}


void printAuthors(AInfo ReadA[], ifstream& InfileAuthors, ofstream& outfileAuthors, DOB AuthorDate[], int& authorsize)
{

    cout<<"                                 Authors                                    \n\n";
    cout<<left<<setw(24)<<"NAME"<<left<<setw(18)<<"DOB"<<left<<setw(15)<<" NOTABLE WORK\n\n";

     char x = '/';
    int i,j,temp;
    string tempo;
    for ( i = 0; i < authorsize; i++)
    {
        InfileAuthors>>ReadA[i].Name>>AuthorDate[i].month>>x>>AuthorDate[i].day>>x>>AuthorDate[i].year>>ReadA[i].famousBook;
        replace( ReadA[i].Name.begin(), ReadA[i].Name.end(), '_', ' ');
        replace( ReadA[i].famousBook.begin(), ReadA[i].famousBook.end(), '_', ' ');
    }
    for (j = i+1; j < authorsize+1 ; j++)
    {
       InfileAuthors>>ReadA[i].Name>>AuthorDate[i].month>>x>>AuthorDate[i].day>>x>>AuthorDate[i].year>>ReadA[i].famousBook;
        replace( ReadA[i].Name.begin(), ReadA[i].Name.end(), '_', ' ');
        replace( ReadA[i].famousBook.begin(), ReadA[i].famousBook.end(), '_', ' ');
    }


    for (i = 0; i < authorsize;i++)
    {
        for(j = i+1; j < authorsize+1; j++)
        {
            if(AuthorDate[i].year > AuthorDate[j].year )
            {
                tempo = ReadA[i].Name;
                ReadA[i].Name = ReadA[j].Name;
                ReadA[j].Name = tempo;

                temp = AuthorDate[i].month;
                AuthorDate[i].month = AuthorDate[j].month;
                AuthorDate[j].month = temp;

                temp = AuthorDate[i].year;
                AuthorDate[i].year = AuthorDate[j].year;
                AuthorDate[j].year = temp;

                tempo = ReadA[i].famousBook;
                ReadA[i].famousBook = ReadA[j].famousBook;
                ReadA[j].famousBook = tempo;
            }
        }
            cout<<left<<setw(24)<<ReadA[i].Name<<right<<setw(2)<<AuthorDate[i].month<<x<<setw(1)<<AuthorDate[i].year
            <<right<<setw(30)<<ReadA[i].famousBook<<endl;

             outfileAuthors<<left<<setw(24)<<ReadA[i].Name<<right<<setw(2)<<AuthorDate[i].month<<x<<setw(1)<<AuthorDate[i].year
            <<right<<setw(30)<<ReadA[i].famousBook<<endl;

   }
    cout<<endl;
}




void printAuthorsMatched(AInfo ReadA[],BInfo ReadB[],ifstream& InfileBooks,ifstream& InfileAuthors,
                          int& authorsize, int& booksize, DOB AuthorDate[])
{
    cout<<"                              Authors Matched                               "<<endl;
    cout<<left<<setw(23)<<"NAME"<<left<<setw(20)<<"NATIONALITY"<<left<<setw(10)<<"BOOK"<<endl<<endl;

    for(int i = 0; i < booksize ; i++)
    {
        InfileBooks>> ReadB[i].Title>> ReadB[i].AuthorName >>ReadB[i].Year>>ReadB[i].Language>>ReadB[i].Genre>>ReadB[i].sale;
            replace(ReadB[i].AuthorName.begin(),ReadB[i].AuthorName.end(),'_',' ');
            replace(ReadB[i].Title.begin(),ReadB[i].Title.end(),'_',' ');
    }

    for(int j = 0; j < authorsize; j++)
    {
        char x ='/';
              InfileAuthors>>ReadA[j].Name>>AuthorDate[j].month>>x>>AuthorDate[j].day>>x>>AuthorDate[j].year>>ReadA[j].famousBook;
                replace(ReadA[j].Name.begin(),ReadA[j].Name.end(),'_',' ');
                replace(ReadA[j].famousBook.begin(),ReadA[j].famousBook.end(),'_',' ');
    }

    for(int i = 0; i < booksize ;i++)
    {
        for(int j = 0; j < authorsize ; j++)
        {
            if(ReadB[i].AuthorName == ReadA[j].Name)
            {
                replace(ReadB[i].AuthorName.begin(),ReadB[i].AuthorName.end(),'_',' ');
                replace(ReadB[i].Title.begin(),ReadB[i].Title.end(),'_',' ');
                cout<<left<<setw(23)<<ReadB[i].AuthorName<<left<<setw(15)<<ReadB[i].Language<<left<<setw(10)<<ReadB[i].Title<<endl;
            }
        }
    }

    cout<<endl;
}
