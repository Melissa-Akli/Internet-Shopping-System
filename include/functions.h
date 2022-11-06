#include<iostream>
#include<string>

using namespace std;


#ifndef FUNCTIONS_H
#define FUNCTIONS_H


bool valid_username(const string &);
bool Is_valid_name(const string & );
bool isvalid_Number(const string & );
bool Invalid_password(const string );

void display_services();
void do_service(int );


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


     date& operator = (const date& date2)
     {
         if(this!=&date2)
         {
            day=date2.day;
            month=date2.month;
            year=date2.year;

         }

         return *this;
     }

  }; // end of date




// a structure card
        struct Card
        {
           date ExpiryDate;
           string number;

           Card():number("") {}
           Card( int d, int m, int y , string n):ExpiryDate(d,m, y), number(n) {}

           Card& operator =(const Card & card2)
           {
              if(this!=&card2)
              {
                  ExpiryDate=card2.ExpiryDate;
                  number=card2.number;
              }

              return *this;
           }


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

      address& operator = (const address & adrs)
      {
          region=adrs.region;
          street=adrs.street;
          home_number=adrs.home_number;
      }

  };// end of address



#endif // FUNCTIONS_H
