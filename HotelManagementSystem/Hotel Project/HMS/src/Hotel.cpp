#include "Project.h"

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iomanip>

Hotel::Hotel()
{
    //ctor
}

Hotel::~Hotel()
{
    //dtor
}

void HOTEL::add()
{


	int r,flag;
	ofstream fout("Record.DAT",ios::app|ios::binary);

    system("cls");
    system("color F2");

	cout<<"\n\t\t\t\t    ________________________________________________";
	cout<<"\n\t\t\t\t   |          Rooms         |       Room Type       |";
	cout<<"\n\t\t\t\t   |________________________________________________|";
	cout<<"\n\t\t\t\t   |           1-50         |         Deluxe        |";
	cout<<"\n\t\t\t\t   |           51-80        |        Executive      |";
	cout<<"\n\t\t\t\t   |           81-100       |       Presidential    |";
	cout<<"\n\t\t\t\t   |________________________________________________|";
	cout<<"\n\n ENTER CUSTOMER DETAILS";
	cout<<"\n ----------------------";
	cout<<"\n\n Room Number: ";
	cin>>r;
	flag=check(r);
	if(flag==1)
		cout<<"\n Sorry, Room is already booked.\n";
	else
	{
	   if(flag==2)
		   cout<<"\n Sorry, Room does not exist.\n";
	   else
	   {
		   room_no=r;
		   cout<<" ID: ";
		   cin>>ID;
		   cout<<" Name: ";
		   cin>>name;
		   cout<<" Address: ";
		   cin>>address;
		   cout<<" Phone Number: ";
		   cin>>phone;
		   cout<<" Number of Days: ";
		   cin>>days;
		   if(room_no>=1&&room_no<=50)
		   {
		      strcpy(rtype,"Deluxe");
		      cost=days*10000;
		   }
		   else
		   {
		      if(room_no>=51&&room_no<=80)
		      {
			 strcpy(rtype,"Executive");
			 cost=days*12500;
		      }
		      else
		      {
			 if(room_no>=81&&room_no<=100)
			 {
			    strcpy(rtype,"Presidential");
			    cost=days*15000;
			 }
		      }
		   }
		   fout.write((char*)this, sizeof(HOTEL));
		   cout<<"\n Room has been booked.";
	   }
	}
	cout<<"\n Press any key to continue.";
	getchar();
	getchar();
	fout.close();
}

void HOTEL::display()
{

	ifstream fin("Record.DAT",ios::in|ios::binary);
	int r,flag;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	while(fin.read((char*)this,sizeof(HOTEL)))
	{
		if(room_no==r)
		{

			cout<<"\n Customer Details";
			cout<<"\n ----------------";
			cout<<"\n\n ID: "<<ID;
			cout<<"\n Room Number: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone Number: "<<phone;
			cout<<"\n Staying for "<<days<<" days.";
			cout<<"\n Room Type: "<<rtype;
			cout<<"\n Total cost of stay: "<<cost;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Room is Vacant.";
	cout<<"\n\n Press any key to continue.";
	getchar();
	getchar();
	fin.close();

}


void HOTEL::rooms()
{
    system("cls");
    system("color F0");

	const char separator=' ';
	const int NoWidth=10;
	const int RoomNoWidth=16;
	const int GuestWidth=15;
	const int AddressWidth=14;
	const int RoomWidth=14;
	const int ContactNoWidth=13;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	cout<<"\n\t\t\t                      LIST OF ROOMS ALLOTED";
	cout<<"\n\t\t\t                     ------------------------";
	cout<<"\n     +----------+------------------+-----------------+--------------+---------------+--------------+";
	cout<<"\n     |     ID   |      Room No.    |    Guest Name   |    Address   |   Room Type   |  Contact No. |";
	cout<<"\n     +----------+------------------+-----------------+--------------+---------------+--------------+";
	while(fin.read((char*)this,sizeof(HOTEL)))
	{
		cout<<"\n     |"<<setw(NoWidth)<<setfill(separator)<<ID<<" |";
		cout<<setw(RoomNoWidth)<<setfill(separator)<<room_no<<" |";
		cout<<setw(GuestWidth)<<setfill(separator)<<name<<" |";
		cout<<setw(AddressWidth)<<setfill(separator)<<address<<" |";
		cout<<setw(RoomWidth)<<setfill(separator)<<rtype<<" |";
		cout<<setw(ContactNoWidth)<<setfill(separator)<<phone<<" |";
	}
	cout<<"\n     +----------+------------------+-----------------+--------------+---------------+--------------+";
	cout<<"\n     Press any key to continue.";
	getchar();
	getchar();
	fin.close();
}

void HOTEL::edit()
{
    system("cls");

	int choice;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1. Modify Customer Information.";
	cout<<"\n 2. Customer Check Out.";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	 system("pause");
        system("cls");
	switch(choice)
	{
		case 1:	modify();
			break;
		case 2:	delete_rec();
			break;
		default: cout<<"\n Wrong Choice.";
			 break;
	}
	cout<<"\n Press any key to continue.";
	getchar();
}


int HOTEL::check(int r)
{
	int flag=0;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	while(fin.read((char*)this,sizeof(HOTEL)))
	{
		if(room_no==r)
		{
			flag=1;
			break;
		}
		else
		{
		  if(r>100)
		  {
			flag=2;
			break;
		  }
		}
	}
	fin.close();
	return(flag);
}


void HOTEL::modify()
{
    system("cls");
    system("color F3");

	int ch,r;
	cout<<"\n MODIFY MENU";
	cout<<"\n -----------";
	cout<<"\n\n\n 1. Modify ID";
	cout<<"\n 2. Modify Name";
	cout<<"\n 3. Modify Address";
	cout<<"\n 4. Modify Phone Number";
	cout<<"\n 5. Modify Number of Days of Stay";
	cout<<"\n Enter Your Choice: ";
	cin>>ch;
	 system("pause");
        system("cls");
	cout<<"\n Enter Room Number: ";
	cin>>r;
	switch(ch)
	{
	    case 1: modify_ID(r);
	        break;
		case 2: modify_name(r);
			break;
		case 3: modify_address(r);
			break;
		case 4: modify_phone(r);
			break;
		case 5: modify_days(r);
			break;
		default: cout<<"\n Wrong Choice";
				 getchar();
				 getchar();
			 break;
	}
}

void HOTEL::modify_ID(int r)
{
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New ID: ";
			cin>>ID;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Customer ID has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_name(int r)
{
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Name: ";
			cin>>name;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Customer Name has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_address(int r)
{
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Address: ";
			cin>>address;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Customer Address has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_phone(int r)
{
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Phone Number: ";
			cin>>phone;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Customer Phone Number has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_days(int r)
{
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			cout<<" Enter New Number of Days of Stay: ";
			cin>>days;
			if(room_no>=1&&room_no<=50)
			{
				strcpy(rtype,"Deluxe");
				cost=days*10000;
			}
			else
			{
				if(room_no>=51&&room_no<=80)
				{
				   strcpy(rtype,"Executive");
				   cost=days*12500;
				}
				else
				{
					if(room_no>=81&&room_no<=100)
					{
					   strcpy(rtype,"Presidential");
					   cost=days*15000;
					}
				}
			}
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Customer information is modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::delete_rec()
{
	int r,flag=0;
	char ch;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	ofstream fout("temp.DAT",ios::out|ios::binary);
	while(fin.read((char*)this,sizeof(HOTEL)))
	{
		if(room_no==r)
		{
		    cout<<"\n ID: "<<ID;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone Number: "<<phone;
			cout<<"\n Room Type: "<<rtype;
			cout<<"\n Your total bill is: Rs. "<<cost;
			cout<<"\n\n Do you want to check out this customer(y/n): ";
			cin>>ch;
			if(ch=='n')
			   fout.write((char*)this,sizeof(HOTEL));
			else
			   cout<<"\n Customer Checked Out.";
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(HOTEL));
	}
	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	else
	{
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
	getchar();
	getchar();
}


void HOTEL::restaurant()
{
    system("pause");

	int r,ch;
	cout<<"\n RESTAURANT MENU:";
	cout<<"\n --------------- ";
	cout<<"\n\n 1. Order Breakfast\n 2. Order Lunch\n 3. Order Dinner";
	cout<<"\n\n Enter your choice: ";
	cin>>ch;
	 system("pause");
        system("cls");
	cout<<" Enter Room Number: ";
	cin>>r;
	switch(ch)
	{
		case 1: breakfast(r);

			break;

		case 2: lunch(r);
			break;

		case 3: dinner(r);
			break;
	}
		cout<<"\n\n Press any key to continue.";
		getchar();
		getchar();
		return;
}

void HOTEL::breakfast(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=500*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}


void HOTEL::lunch(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=1000*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}


void HOTEL::dinner(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=1200*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	file.close();
}

void HOTEL::services()
{
    system("pause");

	int r,ch;
	cout<<"\n SERVICES:";
	cout<<"\n --------------- ";
	cout<<"\n\n 1. Vehicle\n 2. Ironing\n 3. Laundry\n 4. Sport Room\n 5. Swimming";
	cout<<"\n\n Enter your choice: ";
	cin>>ch;

    system("cls");
	cout<<" Enter Room Number: ";
	cin>>r;
	switch(ch)
	{
		case 1: Vehicle(r);
			break;
		case 2: Ironing(r);
			break;
		case 3: Laundry(r);
			break;
        case 4: Sport_Room(r);
			break;
        case 5: Swimming(r);
			break;
	}
		cout<<"\n\n Press any key to continue.";
		getchar();
		getchar();
		return;
}

void HOTEL::Vehicle(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=1000*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::Ironing(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=1200*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::Laundry(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=1200*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::Sport_Room(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=2000*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::Swimming(int r)
{
	int num,flag=0;
	long pos;
	cout<<" Enter number of people: ";
	cin>>num;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOTEL));
		if(room_no==r)
		{
			pay=1500*num;
			cost=cost+pay;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOTEL));
			cout<<"\n Amount added to the bill: Rs. "<<pay;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}
