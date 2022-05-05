#include <bits/stdc++.h>
#include <fstream>
#include<dirent.h>

using namespace std;

bool isExist(string check)
{
	DIR *directory;
    struct dirent *x;
    if (( directory= opendir ("data\\")) != NULL)
    {
        while((x = readdir(directory)) != NULL)
        {
            if(check==x->d_name)
            {
                return true;
            }
        }
    }
    closedir (directory);
	return false;
}

void calculate()
{
	int a, b;
	cout<<"Enter 2 elements: ";
	cin>>a>>b;
	cout<<"Sum = "<<a+b<<endl<<endl;
}

int main() 
{
	cout<<endl<<"This is a Login and Registration system"<<endl;
	int d;
	while(d!=3)
	{
		cout<<"---------------"<<endl
		<<"1. Login"<<endl
		<<"2. Register"<<endl
		<<"3. Exit"<<endl
		<<"---------------"<<endl<<endl;
		cin>>d;
		switch(d)
		{
			case 1:
				{
					string username, password, un, pw; 

					cout << "Enter username :";
					cin >> username;

					if(!isExist(username+".txt"))
					{
						cout<<"No account found"<<endl<<endl;
						break;
					}

					cout << "Enter password :";
					cin >> password;

					ifstream read("data\\" + username + ".txt"); 
					
					getline(read, un); 
					getline(read, pw); 

					if (un == username && pw == password)
					{
						cout<<endl<<"Logged In"<<endl<<endl;
						calculate();
					}
					else
					{
						cout<<endl<<"!!!!!!Incorrect Password!!!!!!"<<endl<<endl;
					}
					break;
				}
			case 2:
				{
					cout<<"Welcome to Registration system"<<endl<<endl;
		
					string name, pass;
					ofstream file;
		
					cout<<"Enter your username: ";
					cin>>name;

					if(isExist(name+".txt"))
					{
						cout<<endl<<"Already registered"<<endl<<endl;
					}
					else
					{
						cout<<"Enter password: ";
						cin>>pass;

						file.open("data//"+name+".txt");
						file<<name<<endl;
						file<<pass;
						cout<<endl<<"Succesfully Registered"<<endl<<endl;
					}
					break;
				}
				default:
				{
					cout<<endl<<"Invalid entry"<<endl<<endl;
					break;
				}
		}
	}
	
	
	return 0;
}