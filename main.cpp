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


int main() {
	cout<<endl<<"This is a Login and Registration system"<<endl;
	int d;
	while(d!=3)
	{
		cout<<"1. Login"<<endl
		<<"2. Register"<<endl
		<<"3. Exit"<<endl<<endl;
		cin>>d;
		switch(d)
		{
			case 1:
				{
					
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
						cout<<"Already registered"<<endl;
					}
					else
					{
						cout<<"Enter password: ";
						cin>>pass;

						file.open("data//"+name+".txt");
						file<<name<<endl;
						file<<pass;
						cout<<"Succesfully Registered"<<endl;
					}
					
				}
		}
	}
	
	
	return 0;
}