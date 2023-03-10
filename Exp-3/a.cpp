//To update the details of a student using a member function of student class.
#include<iostream>
using namespace std;
class student  // creation of a student class
{
public:
string name;
string fatherName;
string phoneNumber;
int rollNo;
string dateOfBirth;
int semester;
string email;
char addr[50];

public:
		void input_details()
		{
		cout<<" \n\nEnter Student Name ===>";
		cin>>name;
                cout<<" \nEnter Father Name ===>";
		cin>>fatherName;
                cout<<"\n Enter Contact number ===>";
		cin>>phoneNumber;
                cout<<" \nEnter Date Of Birth ===>";
		cin>>dateOfBirth;
                cout<<"\n Enter E-mail Id ===>";
		cin>>email;
                cout<<"\n Enter Address ===>";
		cin>>addr;
                cout<<"\n Enter Roll No ===>";
		cin>>rollNo;
                cout<<"\n Enter Semester ===>";
		cin>>semester;
		}
			
            void output_details()
		{
		cout<<"\t               Model Institute of Engineering"<<endl;
				cout<<"\n________________________________________________________"<<endl;
		cout<<"\n Student Name        :---> "<<name;
		cout<<"\t\t\t\t   Father Name       :---> "<<fatherName;
		cout<<"\n Contact No          :---> "<<phoneNumber;
		cout<<"\t\t\t\t Date Of Birth       :---> "<<dateOfBirth;
		cout<<"\n Email               :---> "<<email;
		cout<<"\t\t\t\t   Address           :---> "<<addr;
		cout<<"\n Roll No     :---> "<<rollNo;
		cout<<"\t\t\t\t Semester          :---> "<<semester;
			}

		void update()
		{
			int choice;
			cout<<"\n\n\t=========================> Update Information <=========================\n\n";
			cout<<"\n\n\t ---------------> choose the Index of Details You Want to Update <--------------\n\n";
			cout<<"\n\n 1. Student Name           ===>      "<<name<<"\n";
			cout<<"\n\n 2. Father Name            ===>      "<<fatherName<<"\n";
			cout<<"\n\n 3. Contact Number         ===>      "<<phoneNumber<<"\n";
			cout<<"\n\n 4. Date Of Birth          ===>      "<<dateOfBirth<<"\n";
			cout<<"\n\n 5. Email ID               ===>      "<<email<<"\n";
			cout<<"\n\n 6. Address                ===>      "<<addr<<"\n";
			cout<<"\n\n 7. Roll Number    ===>      "<<rollNo<<"\n";
			cout<<"\n\n 8. Semester               ===>      "<<semester<<"\n";

			cout<<"\n\n Enter Your Choice ====> ";
			cin>>choice;
			switch(choice)  // switch case to select the choice
			{
				case 1:
					cout<<"\n\n Enter Student Name :--->";
					cin>>name;
					cout<<"\n";
					break;

				case 2:
					cout<<"\n\n Enter Father Name :--->";
					cin>>fatherName;
					cout<<"\n";
					break;

				case 3:
					cout<<"\n\n Enter Contact Number :--->";
					cin>>phoneNumber;
					cout<<"\n";
					break;

				case 4:
					cout<<"\n\n Enter Date Of Birth :--->";
					cin>>dateOfBirth;
					cout<<"\n";
					break;

				case 5:
					cout<<"\n\n Enter Email ID :--->";
					cin>>email;
					cout<<"\n";
					break;

                case 6:
                    cout<<"\n\n Enter Address :--->";
					cin>>addr;
					cout<<"\n";
					break;

				case 7:
					cout<<"\n\n Enter Roll Number :--->";
					cin>>rollNo;
					cout<<"\n";
					break;

				case 8:
					cout<<"\n\n Enter Semester :--->";
					cin>>semester;
					break;

				default:
					cout<<"\n\n=======> Invalid Choice <=========\n ******** Try again ********\n\n";
					break;
			}
		}
};
int main()
{
	student s;
	while(1)
	{
		cout<<"\n\n\t ********** Choose Operation You Want To Perform **********\n\n";
		cout<<"\n\n\t\t Press 1 to Insert Record of Student";
		cout<<"\n\n\t\t Press 2 to Update Record";
		cout<<"\n\n\t\t Press 3 If you want to Display Record";
		cout<<"\n\n\t\t Press 4 to Exit ";
		cout<<"\n\n Enter your choice====>";

		int ch;

		cin>>ch;
		switch(ch)
		{
			case 1:
				s.input_details();
				break;

			case 2:
			    s.update();
				break;

			case 3:
				s.output_details();
				break;

			case 4:
                goto out;
			default:
				cout<<"\n\n\t========> Invalid choice <========";
				break;
		}
	}
	out:
// getch();
return 0;
}

