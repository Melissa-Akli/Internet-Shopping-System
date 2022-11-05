#include "functions.h"
#include <fstream>

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
              if(pass.empty())return true;
              if(pass.size()<8)return true;

             for(char c: pass)
             {
                 if(c==' ') return true ;
             }

             return false;
         }


  void display_services()
  {
      cout<<"1- Display Profile "<<endl;
      cout<<"2- Update Profile "<<endl;
      cout<<"3- Add an Order "<<endl;
  }



// void do_service(int);

void add_to_file_map(const unordered_map<string , User>& mymap)
{
    string name;
    double member;
    Card Credit;
    address Home_add;
    string pass;



    ofstream os;
    os.open("mydata.txt");

    for(pair<string,User>it: mymap)
    {
        name=(it.second.get_name());
        member=(it.second.get_membership_count());
        Credit.number=(it.second.get_card()).number;
        Credit.ExpiryDate=(it.second.get_card()).ExpiryDate;
        Home_add=(it.second.get_address());
        pass=(it.second.get_password());


        os<<name<<","<<member<<","<<member<<","<<Credit.number<<",";
        os<< Credit.ExpiryDate.day<<","<< Credit.ExpiryDate.month<<","<< Credit.ExpiryDate.year<<",";
        os<<Home_add.region<<","<<Home_add.street<<","<<Home_add.home_number<<",";
        os<<pass;
    }
}

