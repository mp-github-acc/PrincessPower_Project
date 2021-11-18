//include files
using namespace std;
#include <iostream>
#include <string>

void printMessage();
void printError();
void option1();
void option2();
void option3();
void rerun();


int main()
{
    bool userContinue=true;
    bool validOption;
    int choice=0;

    while(userContinue)
    {
        validOption=false;
        while(!validOption)
        {
            option1();
            cin>>choice;
            cout<<endl;
            if(choice==1){
                validOption=true;
            }
            else if(choice==2){
                validOption=true;
            }
            else if(choice==3){
                validOption=true;
            }
            else{
                printError();
            }
        }


        validOption=false;
        while(!validOption)
        {
            option2();
            cin>>choice;
            cout<<endl;
            if(choice==1){
                validOption=true;
            }
            else if(choice==2){
                validOption=true;
            }
            else if(choice==3){
                validOption=true;
            }
            else{
                printError();
            }
        }


        validOption=false;
        while(!validOption)
        {
            option3();
            cin>>choice;
            cout<<endl;
            if(choice==1){
                validOption=true;
            }
            else if(choice==2){
                validOption=true;
            }
            else if(choice==3){
                validOption=true;
            }
            else{
                printError();
            }
        }


        validOption=false;
        while(!validOption)
        {
            rerun();
            cin>>choice;
            cout<<endl;
            if(choice==1){
                validOption=true;
            }
            else if(choice==2){
                validOption=true;
                userContinue=false;
            }
            else{
                printError();
            }
        }
    }




    return 0;
}

void printMessage(string msg)
{
    cout<<msg<<endl;
}
void printError()
{
    cout<<"Invalid option selected, please try again"<<endl;
}

void option1()
{
    cout<<"Input number for action:"<<endl;;
    cout<<"1 - build rocket 1"<<endl;;
    cout<<"2 - build rocket 2"<<endl;;
    cout<<"3 - build rocket 3"<<endl;;
    cout<<"4 - go to launch sequence"<<endl;;
    cout<<"~";
}

void option2()
{
    cout<<"Input number for action:"<<endl;;
    cout<<"1 - add next component"<<endl;;
    cout<<"2 - change component"<<endl;;
    cout<<"3 - rebuild rocket"<<endl;;
    cout<<"4 - go to launch sequence"<<endl;;
    cout<<"~";
}

void option3()
{
    cout<<"Input number for action:"<<endl;;
    cout<<"1 - add component 1"<<endl;;
    cout<<"2 - add component 2"<<endl;;
    cout<<"3 - add component 3"<<endl;;
    cout<<"4 - go to launch sequence "<<endl;;
    cout<<"~";
}

void rerun()
{
    cout<<"Input number for action:"<<endl;
    cout<<"1 - run another simulation"<<endl;
    cout<<"2 - go to launch sequence"<<endl;
    cout<<"~";
}
