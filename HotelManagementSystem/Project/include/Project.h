#ifndef PROJECT_H
#define PROJECT_H


class HOTEL
{
    public:
        HOTEL();
        virtual ~HOTEL();

      void main_menu();	 	  //to dispay the main menu
	  void add();			  //to book a room
	  void display(); 		  //to display the specific customer information
	  void rooms();			  //to display alloted rooms
	  void edit();			  //to edit the customer by calling modify or delete
	  int check(int);		  //to check room status
	  void modify();		  //to modify the customer information
	  void delete_rec();              //to check out the customer
	  void restaurant();	          //to order food from restaurant
	  void modify_ID(int);            //to modify ID of guest
	  void modify_name(int);          //to modify name of guest
	  void modify_address(int);       //to modify address of guest
	  void modify_phone(int);         //to modify phone number of guest
	  void modify_days(int);          //to modify days of stay of guest
	  void services();



    private:
      int room_no;
	  char ID[50];
	  char name[30];
	  char address[50];
	  char phone[15];
	  long days;
	  long cost;
	  char rtype[30];
	  long pay;
	  void breakfast(int);        //to assign price of breakfast
	  void lunch(int);            //to assign price of lunch
	  void dinner(int);           //to assign price of dinner
	  void Vehicle(int);
	  void Ironing(int);
	  void Laundry(int);
	  void Sport_Room(int);
	  void Swimming(int);
};

#endif // PROJECT_H
