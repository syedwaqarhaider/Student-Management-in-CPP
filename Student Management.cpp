#include<iostream>
#include<conio.h>

using namespace std;

//============================= GLOBAL FILE POINTER DECLARATION ==============================//

FILE *fptr;

//================================= DECALARATION OF STRUCTURE ===============================//

struct student{
	 
	 int srno;
	 char name[50];
	 float gpa, per;
	 int p_marks, ict_marks, e_marks, pcal_marks, is_ps_marks, total;
}st;

//============================= USER DEFINED FUNCTIONS DECLARATION ==============================//

void class_result();
void create_record();
void search_record();
void display_all();
void delete_record(int);
void modify_record(int);
void showMenu();
//calculate(student st);

//=================================== FUNCTION TO CREATE RECORD =================================//

void create_record()
{
	fptr = fopen("student.txt","ab");
	cout << "\n\n\t==================  CREATE RECORDS ===================\n\n\n";
	cout << "\nEnter the Registration No: of Student: ";
	cin  >> st.srno;
	if(st.srno == 0000){
		system("cls");
		showMenu();
	}
	cout << "\nEnter Name of Student: ";
	fflush(stdin);
	cin.getline(st.name,50);
	cout << "\nEnter Programming Marks out of 100: ";
	cin  >> st.p_marks;
	cout << "\nEnter ICT Marks out of 100: ";
	cin  >> st.ict_marks;
	cout << "\nEnter Funtional English Marks out of 100: ";
	cin  >> st.e_marks;
	cout << "\nEnter Pre-Calculus Marks out of 100: ";
	cin  >> st.pcal_marks;
	cout << "\nEnter Islamic Studies and Pakistan Studies Marks out of 100: ";
	cin  >> st.is_ps_marks;
	st.total = st.p_marks+st.ict_marks+st.pcal_marks+st.is_ps_marks+st.e_marks;
	st.per = (float)st.total/500*100;
	st.gpa = st.per/100*4.0;
	fwrite(&st,sizeof(st),1,fptr);
	fclose(fptr);
	cout << "\n\n\n\tRecord has been created.";
	getch();
}

//=================================== FUNCTION TO SEARCH RECORD =================================//

void display_all()
{
	system("cls");
	cout << "\n\n\t================== DISPLAY ALL RECORDS ===================\n\n\n";
	fptr = fopen("student.txt","r");
	while((fread(&st,sizeof(st),1,fptr))>0)
	{
		cout << "\nEnter the Registration No: of Student: " << st.srno;
		cout << "\nEnter Name of Student: " << st.name;
		cout << "\nEnter Programming Marks out of 100: " << st.p_marks;
		cout << "\nEnter ICT Marks out of 100: " << st.ict_marks;
		cout << "\nEnter Funtional English Marks out of 100: " << st.e_marks;
		cout << "\nEnter Pre-Calculus Marks out of 100: " << st.pcal_marks;
		cout << "\nEnter Islamic Studies and Pakistan Studies Marks out of 100: " << st.is_ps_marks;
		cout << "\nTotal Marks of student out of 500: " << st.total;
		cout << "\nTotal Perentage of Student : " << st.per << "%";
		cout << "\nTotal CGPA of Student: " << st.gpa;
		cout << "\n\n==================================================================\n\n\n";
		getch();
	}
	fclose(fptr);
	cout << "\n\n\tPress Enter to continue...!";
	getch();
}

//=================================== FUNCTION TO MODIFY RECORD =================================//

void modify_record(int rn)
{
	
	int flag = 0;
	cout << "\n\n\t================== MODIFY RECORDS ===================\n\n\n";
	fptr = fopen("student.txt","rb+");
	cout << "\n\n\tEnter the registration no: of student to be modified :"; cin >> rn;
	while((fread(&st,sizeof(st),1,fptr))== 1)
	{
		cout << "File here....!";
		if(st.srno == rn)
		{
		cout << "\nEnter the Registration No: of Student: " << st.srno;
		cout << "\nEnter Name of Student: " << st.name;
		cout << "\nEnter Programming Marks out of 100: " << st.p_marks;
		cout << "\nEnter ICT Marks out of 100: " << st.ict_marks;
		cout << "\nEnter Funtional English Marks out of 100: " << st.e_marks;
		cout << "\nEnter Pre-Calculus Marks out of 100: " << st.pcal_marks;
		cout << "\nEnter Islamic Studies and Pakistan Studies Marks out of 100: " << st.is_ps_marks;
		cout << "\nTotal Marks of student out of 500: " << st.total;
		cout << "\nTotal Perentage of Student : " << st.per << "%";
		cout << "\nTotal CGPA of Student: " << st.gpa;
		cout << "\n\n\tPlease Enter new details of student.";
		cout << "\n\nEnter the Registration No: of Student: ";
		cin  >> st.srno;
		cout << "\nEnter Name of Student: ";
		fflush(stdin);
		cin.getline(st.name,50);
		cout << "\nEnter Programming Marks out of 100: ";
		cin  >> st.p_marks;
		cout << "\nEnter ICT Marks out of 100: ";
		cin  >> st.ict_marks;
		cout << "\nEnter Funtional English Marks out of 100: ";
		cin  >> st.e_marks;
		cout << "\nEnter Pre-Calculus Marks out of 100: ";
		cin  >> st.pcal_marks;
		cout << "\nEnter Islamic Studies and Pakistan Studies Marks out of 100: ";
		cin >> st.is_ps_marks;
		st.total = st.p_marks+st.ict_marks+st.pcal_marks+st.is_ps_marks+st.e_marks;
		st.per = (float)st.total/500*100;
		st.gpa = st.per/100*4.0;
		fseek(fptr,ftell(fptr)-sizeof(st),0);
		fwrite(&st,sizeof(st),1,fptr);
		fclose(fptr);
		cout << "\n\n\n\tRecord has been updated...!";
		flag = 1;
		}
	}
	fclose(fptr);
	if(flag = 0)
	cout << "\n\n\tRecord not exist...!";
	cout << "\n\n\tPress Enter to continue...!";
	getch();
}

//=================================== FUNCTION TO SEARCH RECORD =================================//

void search_record()
{
	int rn;
	bool flag = false;
	cout << "\n\n\t================== CREATE RECORD ===================\n\n\n";
	cout << "Enter Registration No: of Student: "; cin >> rn;
	fptr= fopen("Student.txt","r");
	while((fread(&st,sizeof(st),1,fptr)) != 0)
	{
		if(st.srno == rn)
		{
			cout << "\nEnter the Registration No: of Student: " << st.srno;
			cout << "\nEnter Name of Student: " << st.name;
			cout << "\nEnter Programming Marks out of 100: " << st.p_marks;
			cout << "\nEnter ICT Marks out of 100: " << st.ict_marks;
			cout << "\nEnter Funtional English Marks out of 100: " << st.e_marks;
			cout << "\nEnter Pre-Calculus Marks out of 100: " << st.pcal_marks;
			cout << "\nEnter Islamic Studies and Pakistan Studies Marks out of 100: " << st.is_ps_marks;
			cout << "\nTotal Marks of student out of 500: " << st.total;
			cout << "\nTotal Perentage of Student : " << st.per << "%";
			cout << "\nTotal CGPA of Student: " << st.gpa;
			cout << "\n\n\tPress enter to continue...!";
			flag = true;
			break;
		}
	}
	fclose(fptr);
	if(flag == false)
	cout << "\n\n\tRecord not exist...!";
	getch();
}


//============================= FUNCTION TO DELETE RECORD ==============================//

void delete_record(int rn)
{
	FILE *fptr2;
	int flag = 0;
	fptr2 = fopen("Temp.txt","w");
	fptr = fopen("student.txt", "r");
	cout << "Enter the Registration No of student to be deleted: ";
	cin  >> rn;
	rewind(fptr);
	while((fread(&st,sizeof(st),1,fptr))>0)
	{
		if(st.srno != rn)
		{
			fwrite(&st,sizeof(st),1,fptr2);
			flag = 1;
		}
	}
	fclose(fptr);
	fclose(fptr2);
	remove("student.txt");
	rename("Temp.txt","student.txt");
	if(flag == 0)
	{
		cout << "\n\n\tRecord not exist...!";
	}
	cout << "\n\n\n\tRecord has been deleted.";
	getch();
}


//============================= DEFINATION OF ENTRY MENU FUNCTION ==============================//

void entry_menu()
{
	char ch;
	int rn;
	system("cls");
	cout << "\n\n\n\tENTRY MENU"
  		 << "\n\n\t1.CREATE STUDENT RECORD"
  	 	 << "\n\n\t2.DISPLAY ALL STUDENTS RECORDS"
	 	 << "\n\n\t3.SEARCH STUDENT RECORD "
	 	 << "\n\n\t4.MODIFY STUDENT RECORD"
	 	 << "\n\n\t5.DELETE STUDENT RECORD"
	 	 << "\n\n\t6.BACK TO MAIN MENU"
	 	 << "\n\n\tPlease Enter Your Choice (1-6) ";
	cin  >> ch;
	system("cls");
	switch(ch)
	{
		case '1' : create_record();   break;
		case '2' : display_all();     break;
		case '3' : search_record(); break;
		case '4' : modify_record(rn); break;
		case '5' : delete_record(rn); break;
		case '6' : break;
		default  : cout << "\a"; entry_menu();
	}
}

//==================================== RESULT MENU FUNCTION =================================//

void result()
{
 	system("cls");
 	char d;
	cout << "\n\n\n\tRESULT   MENU\n"
	     << "\t________________________________"
	     << "\n\n\t01.  CLASS RESULT"
	     << "\n\n\t02.  STUDENT REPORT CARD"
	     << "\n\n\t03.  BACK TO ENTRY MENU"
	     << "\n\n\n\t Please select your option (1-3): ";
	cin>>d;
	system("cls");
	switch(d){
		case '1':  class_result(); 	break;
		case '2':  search_record();    break;
		case '3':  break;
		default :  cout<< "\a";
	}
}

//==================================== CLASS RESULT FUNCTION =================================//

void class_result()
{
    system("cls");
    fptr=fopen("student.txt","rb");
    if(fptr==NULL)
    {
      cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
      cout<<"\n\n\n Program is closing ....";
      getch();
      exit(0);
    }
    
	cout<<"\t\t\tAll Student Result\n";
	cout<<"*****************************************************************************************\n";
	cout<<"Rno  Name\t Eng\t ICT\t Precal\t Prog\t IS&PS\t Total\t %age\t GPA\t\n";
	cout<<"*****************************************************************************************\n";
	while((fread(&st,sizeof(st),1,fptr)) == 1)
	{
	cout<<st.srno<<"  "<<st.name<<"\t"<<st.e_marks<<"\t"<<st.ict_marks<<"\t"<<st.pcal_marks<<"\t"<<st.p_marks
	<<"\t"<<st.is_ps_marks<<"\t"<<st.total<<"\t"<<st.per<<"\t"<<st.gpa<<endl;
	}
	fclose(fptr);
	getch();
	system("cls");
}

//==================================== INTORDUCTION FUNCTION =================================//

void intro()
{
	
	cout << "\n\n\n\n\n\n\t\t\t     Project: Student Report Card System \n\n";
	cout << "\t\t\t       Made By: Group Ideals BS-CS & SE\n";
	cout << "\n\t\t\tGROUP MEMBERS"
	     << "\n\n\t\t\t* Shakeel Ahmed"
	     << "\n\n\t\t\t* Shahzeb Mahesar"
	     << "\n\n\t\t\t* Sajan Dass"
	     << "\n\n\t\t\t* Mohammad Suleman"
	     << "\n\n\t\t\t* Jamal Hussain";
	cout << "\n\n\t\t\tSukkur Institute of Business Administration\n";
	
	getch();
	system ("cls");
}

//==================================== THE MAIN FUNCTION =================================//

void showMenu(){
	char ch;
	int rno;
	intro();
	do
	{
		system("cls");
	cout << "\n\n\n\tM A I N     M E N U\n"
	     << "\t________________________________"
	     << "\n\n\t01.  RESULT MENU"
	     << "\n\n\t02.  ENTRY/EDIT RECORD MENU"
	     << "\n\n\t03.  EXIT."
	     << "\n\n\n\t Please select your option (1-3): ";
	cin  >> ch;
	system("cls");
	switch(ch)
		{
			case '1' : result();  break;
			
			case '2' : entry_menu();  break;
			
			case '3' : exit(0); break;
			
			default  : cout << "\a";
		}
	}
	while(ch != 3);
}

int main()
{
	showMenu();
}

