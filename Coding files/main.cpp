//include files
using namespace std;
#include <iostream>
#include <string>

void message();

int main()
{
	bool continue=true;
	int choice=0;

	while(continue)
	{

		option1();
		cin>>choice;
		if(choice==0){
			//
		} else if(choice==1){
			//
		} else if(choice==2){
			//
		} else if(choice==3){
			//
		}


		option2();
		cin>>choice;
		if(choice==0){
			//
		} else if(choice==1){
			//
		} else if(choice==2){
			//
		} else if(choice==3){
			//
		}


		option3();
		cin>>choice;
		if(choice==0){
			//
		} else if(choice==1){
			//
		} else if(choice==2){
			//
		} else if(choice==3){
			//
		}




		continue=false;
	}




	return 0;
}

void message(string msg)
{
	cout<<msg<<end;
}

void option1()
{
	cout<<"Input number for action:";
	cout<<"1 - build rocket 1";
	cout<<"2 - build rocket 2";
	cout<<"3 - build rocket 3";
	cout<<"4 - go to lauch sequence";
}

void option2()
{
	cout<<"Input number for action:";
	cout<<"1 - add next component";
	cout<<"2 - change component";
	cout<<"3 - rebuild rocket";
	cout<<"4 - go to lauch sequence";
}

void option3()
{
	cout<<"Input number for action:";
	cout<<"1 - add component 1";
	cout<<"2 - add component 2";
	cout<<"3 - add component 3";
	cout<<"4 - go to lauch sequence ";
}

