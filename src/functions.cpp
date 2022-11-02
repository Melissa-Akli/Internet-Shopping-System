#include "functions.h"

//____________________________________FUNCTIONS__________________________________________________________


 bool valid_username(const string & username)
    {
        if(username.empty())return false;
        if(username.size()<3)return false;
        if(!isalpha(username[0]))return false;

        return true ;
    }


    // function to help check the validity of a name

        bool Is_valid_name(const string & name)
        {
            for(char c: name)
            {
                if(!isalpha(c)&& c!=' ')
                {
                    return false;
                }
            }

            return true;
        }


      // function to help check the validity of numbers

        bool isvalid_Number(const string & number)
        {
            for(char c: number)
            {
                if(!isdigit(c)) return false;
            }

            return true;
        }



    // function to help check the validity of a password

         bool Invalid_password(const string pass)
         {
             if(isdigit(pass[0])) return true;

             for(char c: pass)
             {
                 if(c==' ') return true ;
             }

             return false;
         }

