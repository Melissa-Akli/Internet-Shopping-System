#include<iostream>
#include<string>
#include<unordered_map>
//#include<User.h> // include nested to deeply because user include functions and function include user !!!!
using namespace std;


#ifndef FUNCTIONS_H
#define FUNCTIONS_H


bool valid_username(const string &);
bool Is_valid_name(const string & );
bool isvalid_Number(const string & );
bool Invalid_password(const string );

void display_services();
void do_service(int );
void add_to_file_map(const unordered_map<string,User> &);

 //_____________________________________________ STRUCTURES ______________________________________________________________________


        // we define the structure here coz we need them in the implementation ....

// a structure date
  struct date
  {
     int day;
     int month;
     int year;

     date():day(1),month(1),year(2022){}

     date(int d, int m, int y)
     {
         day=(d>0 && d<=31) ? d:1;
         month=(m>0 && m<=12)? m:1;
         year=(y>2022)? y:2022;
     }

  }; // end of date




// a structure card
        struct Card
        {
           date ExpiryDate;
           string number;

           Card():number("") {}
           Card( int d, int m, int y , string n):ExpiryDate(d,m, y), number(n) {}


        }; // end of card



// a structure address
  struct address
  {
      string region;
      string street;
      int home_number;

      address(): region(""),street(""),home_number(0){}

      address(string r, string s, int h)
      {
          region=(Is_valid_name(r))?r :"";
          street=(Is_valid_name(s))? s:"";
          home_number=(h>0 )? h : 0;

      }

  };// end of address



#endif // FUNCTIONS_H
