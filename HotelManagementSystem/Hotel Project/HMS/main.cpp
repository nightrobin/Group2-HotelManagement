#include <iostream>

#include"HMS.h"

using namespace std;

int main()
{
cout<<"\t\t\t\t\t\t\t HOME\n";
cout<<"\t\t\t\t\t\t  WELCOME TO (hotelname)\n";
cout<<"\t\t\t\t  Get the best prices on 2,000,000+ properties, worldwide";
cout<<"\n\t\t\t\t\t    Founded in 1995 in Philippines,";
cout<<"\n\t\tLyntell has grown from a small Dutch startup to one of the worlds leading digital travel companies.";
cout<<"\n\t\t   Lyntell's mission is to make it easier and comfortable for everyone to experience the world.\n";
cout<<"\n      You're eligible for a Genius discount at Lyntell Hotel! To save at this property, all you have to do is book now.";

cout<<"\n\t\t      It features an outdoor saltwater swimming pool. Guests can enjoy drinks at the bar.";
cout<<"\n\t\t      Air-conditioned contemporary-style rooms are fitted with a desk and a flat-screen TV.";
cout<<"\n\t\t\t\t        Certain rooms are fitted with a terrace.";
cout<<"\n\t\t\t    Some units feature a seating area to relax in after a busy day.";
cout<<"\n\t\t    Every room has a private bathroom, includes shower facilities and free toiletries";
cout<<"\n\t\t\t   Guests can enjoy international cuisine at the on-site restaurant.\n";
cout<<"\n\t\t\t\t\t       We speak your language!\n";
cout<<"------------------------------------------------------------------------------------------------------------------------";
cout<<"\nMost popular facilities:\n";
cout<<"    - Free WiFi    - Beachfront    - Airport shuttle    - Family rooms    - Non-smoking rooms    - Room service Bar\n";

cout<<"\n5 reasons to choose Lyntell Hotel\n";
cout<<"1. Prices you can't beat!\n";
cout<<"2. Booking is safe\n";
cout<<"3. Manage your bookings online\n";
cout<<"4. The staff speak English\n";
cout<<"5. Great location and facilities for couples\n";
cout<<"\nFor more Information:\n";

system("pause");

{

	int choice;
	while(choice!=6)
	{
        HOTEL htl; //Instantiate HotelManagementSystemm = htl
        system("cls");
        system("color F2");

		cout<<"\n\t\t\t\t    ______________________________________________";
		cout<<"\n\t\t\t\t   |--------------------THE HOTEL-------------------|";
		cout<<"\n\t\t\t\t   |________________________________________________|";
		cout<<"\n\t\t\t\t   |--------------------MAIN MENU-------------------|";
		cout<<"\n\t\t\t\t   |________________________________________________|";
		cout<<"\n\t\t\t\t   |[1] Book A Room                                 |";
		cout<<"\n\t\t\t\t   |[2] Customer Information                        |";
		cout<<"\n\t\t\t\t   |[3] Rooms Allotted                              |";
		cout<<"\n\t\t\t\t   |[4] Edit Customer Details                       |";
		cout<<"\n\t\t\t\t   |[5] Order Food from Restaurant                  |";
		cout<<"\n\t\t\t\t   |[6] Other Services                              |";
		cout<<"\n\t\t\t\t   |[7] Exit                                        |";
		cout<<"\n\t\t\t\t   |________________________________________________|";
		cout<<"\n\n\t\t\t\t   Enter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			    htl.add();
				break;
			case 2:
			    htl.display();
				break;
			case 3:
			    htl.rooms();
				break;
			case 4:
			    htl.edit();
				break;
			case 5:
			    htl.restaurant();
				break;
            case 6:
                htl.services();
				break;
				{
					cout<<"\n\n\t\t\tWrong choice.";
					cout<<"\n\t\t\tPress any key to continue.";
					getchar();
				}
		}
	}
}
}
