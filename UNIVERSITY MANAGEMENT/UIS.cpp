#include <iostream>
#include <windows.h>                		           	
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>               
using namespace std;
COORD coord = {0,0};              
void gotoxy(int x, int y)         
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition( GetStdHandle (STD_OUTPUT_HANDLE), coord ); 
}
void loading()
{	gotoxy(24,26);
	int i;
	for (i=0; i<5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl;
	gotoxy(24,28);
}
	void mainEntrance()
{
cout << "     **************************************************************" << endl;
cout << "               UNIVERSITY INFORMATION SYSTEM                " << endl;
cout << "     **************************************************************" << endl;
}
void login()
{
	system("cls");
	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	mainEntrance();
	gotoxy(55,10);
	cout << "(LOGIN)";
	gotoxy(20,15);
	cout << "Enter Username: \n\t\t    Enter Password: ";
	gotoxy(36,15);
	ch2=getch();
	while(ch2 != 13){ 
	
		if(ch2 == '\b'){
			if(username.size() > 0 )  {
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}	
	gotoxy(36,16);
	ch=getch();
	while(ch != 13){                  
		if(ch == '\b'){
			if(password.size() > 0){
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*"; 
				ch = getch();
				i++;
			}
			else{
				ch = getch();
			}
		}
	}
	if (username == "abhishek" && password == "11718851")
	{
		gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}	
	else 
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;	
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				login();
			}
			else
			{
				exit(0);
			}
	}
}
static int height = 0;
class records
{private:
		struct student
		{
			int roll;
			char name[30];
			char fname[30];
			float cgpa;
			student *left;
			student *right;
		};			
		public:		
		student *root;
			records();
			void insert();
			void display(int);
			void show1 (student *&);
			void show4 (student *&);
			void search();
			int remove(int rn, student *&,int &found);
			void totalNodes();
			int findHeight(student *&);
			void findDepthOfNode();
			void studentMenu();
};
records r;
records :: records()
	{
		root = NULL;
	}
void records :: insert()
{
	system("cls");
	label:	
	student *newnode, *nodeptr;
	char ch;
	cout << "\n\n _________________________RECORDS INSERTION_________________________";
	do 
	{
		system ("cls");	
		newnode = new student;
	cout << "\n\n Enter Roll Number of Student: ";
	while(1)
	{
		cin >> newnode->roll;
		if (cin.fail() || newnode->roll < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else 
			break;
	}
	student *temp = new student;
	temp = root;
	while (temp != NULL)
	{
		if(newnode->roll == temp->roll)
			{
				cout << "\n\n This Roll No. has already been used";
				cout << "\n\n\t Please Enter a unique Roll NO. \n\n";
				system("pause");
				goto label;
				break;
			}
		else if(newnode->roll > temp->roll)
			{
				temp = temp->right;
			}
			else if(newnode->roll < temp->roll)
			{
				temp = temp->left;
			}
	}
	
		label1:
	cout << "\n\n Enter Name of Student: ";
	cin.ignore();
	cin.getline (newnode->name,30);

	int check1 = 0;
for(int i = 0; i < strlen(newnode->name); i++){
        if(isalpha(newnode->name[i]) == 0){
        	if (newnode->name[i] == ' ')
        	{
        		check1 = 0;
			}
			else
			{
            cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
            check1 = 1;
            break;
        	}
        }
    }
    if (check1 == 1)
    {
    	goto label1;
	}
	
	label2:
	cout << "\n\n Enter Father Name of Student: ";
	cin.getline(newnode->fname,30);

	int check2 = 0;
for(int j = 0; j < strlen(newnode->fname); j++){
        if(isalpha(newnode->fname[j]) == 0 ){
        	if (newnode->fname[j] == ' ')
        	{
        		check2 = 0;
			}
			else
			{
            cout << "\n\nInvalid Input...\nPlease Enter alphabets only:";
            check2 = 1;
            break;
        	}
        }
    }
    if (check2 == 1)
    {
    	goto label2;
	}

	cout << "\n\n Enter CGPA of Student (out of 10.0): ";
	
	while(1)
	{
		cin >> newnode->cgpa;
		if (cin.fail() || (newnode->cgpa < 0.0) || (newnode->cgpa > 10.0) )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter CGPA ranging from 0.0 to 10.0: ";
		}
		else 
			break;
	}

	newnode->left = NULL;
	newnode->right = NULL;
	
	if (root == NULL)
	{
		root = newnode;
		height++;
	}
	
	else
	{
		nodeptr = root;
		while (nodeptr != NULL)
		{
			if (newnode->roll < nodeptr->roll)
			{
				if (nodeptr->left != NULL)
				{
					nodeptr = nodeptr->left;
				}
				else
				{
					nodeptr->left = newnode;
					height++;
					break;
				}
			}
			
			else if (newnode->roll > nodeptr->roll)
			{
				if(nodeptr->right != NULL)
				{
					nodeptr = nodeptr->right;
				}
				else
				{
					nodeptr->right = newnode;
					height++;
					break;
				}
			}
		}	
	}
			cout << "\n\n\t Do you want to enter more Records ? \n\n";
			cin >> ch;
				} while(ch == 'y' || ch == 'Y'); 			
	}
	
void records :: show1(student *&temp)
{
	if(temp != NULL)
	{
		show1(temp->left);
		cout << "\n\n\n\n Roll-No: " << temp->roll;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Father's Name: " << temp->fname;
		cout << "\n\n CGPA: " << temp->cgpa;
		show1(temp->right);	
	}
}

void records :: show4(student *&temp)
{
	if(temp != NULL)
	{
		show4(temp->right);
		cout << "\n\n\n\n Roll-No: " << temp->roll;
		cout << "\n\n Name: " << temp->name;
		cout << "\n\n Father's Name: " << temp->fname;
		cout << "\n\n CGPA: " << temp->cgpa;
		show4(temp->left);	
	}
}

void records :: display(int choice)
{
	system("cls");
	if(root == NULL)
	{
		cout << "\n\n\tPlease Enter some Record First...\n\n";
		return;
	}
	cout << "\n\n _________________________RECORDS DISPLAY_________________________";
	if (choice == 1)
	{
		records :: show1(root);
	}
	else if (choice == 2)
	{
		records :: show4(root);
	}
	
}
void records :: search()
{
	system("cls");
	if (root == NULL)
	{
		cout << "\n\n\tPlease Enter Some Record First...\n\n";
		return;
	}
	int rn,check = 0;
	student *temp;
	cout << "\n\n _________________________RECORDS SEARCH_________________________";
	cout << "\n\n Please Enter Roll No. of Student to Search: ";
	while(1)
	{
		cin >> rn;
		if (cin.fail() || rn < 1 )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(),'\n');
			cout << "\nInvalid Input...\nPlease Enter a Roll No. greater than or equal to 1: ";
		}
		else 
			break;
	}
	temp = root;
	while(temp != NULL)
	{
		if (temp->roll == rn)
		{
			cout << "\n\n\n\n Roll-No: " << temp->roll;
			cout << "\n\n Name: " << temp->name;
			cout << "\n\n Father's Name: " << temp->fname;
			cout << "\n\n CGPA: " << temp->cgpa;
			check = 1;
			break;
		}
		else if(rn < temp->roll)
		{
			temp = temp->left;
		}
		else if(rn > temp->roll)
		{
			temp = temp->right;
		}
	}
		if (check == 0)
		{
			cout << "\n\n\t Record of Student with Roll NO. " << rn << " not Found...!\n\n";
			return;
		}
}
int records :: remove (int rn, student *&nodeptr,int &found)
{
	if (nodeptr == NULL)
	{
		return found;
	}
	else if(rn < nodeptr->roll)
	{
		records :: remove(rn,nodeptr->left,found);
		}
	else if (rn > nodeptr->roll)
	{records :: remove (rn,nodeptr->right,found);}
	else if (rn == nodeptr->roll)
	{
		found = 1;
			}
		return found;
}
void records :: totalNodes()
{	system("cls");
	if (height == 0)
	{
		cout << "\n\n\t Please Insert Some Records First...";
		return;
	}
	else
	{
		cout << "\n\n Total Number of Students are: " << height;
	}	
}
void records :: studentMenu()
{
	system("cls");
	int choice;
	while(true)
	{system("cls");
	cout << "\n\n  _________________________STUDENT RECORD DATABASE_________________________";
	cout << "\n\n 1: Enter Record ";
	cout << "\n\n 2: Display Records in Ascending Order";
	cout << "\n\n 3: Display Records in Descending Order";
	cout << "\n\n 4: Search Record ";
	cout << "\n\n 5: Check Total No. of Students";
	cout << "\n\n Enter your Choice: ";
	label1:
	choice = getch();
	if (choice >= '1' && choice <= '5')
	{
		goto label2;
	}
	goto label1;
	label2:
	cout << choice-48;
	system("cls");
	switch(choice)
	{
		case '1':
			r.insert();
			cout << "\n\n\t";
			system("pause");
			break;
		case '2':
			r.display(1);
			cout << "\n\n\t";
			system("pause");
			break;
		case '3':
			r.display(2);
			cout << "\n\n\t";
			system("pause");
			break;
		case '4':
			r.search();
			cout << "\n\n\t";
			system("pause");
			break;
		case '5':
			r.totalNodes();
			cout << "\n\n\t";
			system("pause");
			break;		
		default:
			cout << "\n\n Please Enter a valid Choice: \n\n";
			system ("pause");
			break;
		}
	}
}	
int main()
{
	system("color A");
	login();
	while(true)
	
	{system("cls");
	r.studentMenu();		
	}
	return 0;
}
