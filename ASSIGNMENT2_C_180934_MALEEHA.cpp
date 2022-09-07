#include<iostream>
#include<stdlib.h>
#include<ctime>
#include <unistd.h>
#include<string.h>

using namespace std;

 
struct name /*this structure was declared to store course title. */ 
{
  
     string subject;
     string instructor;

};   
    
     int lab_hours[3] = { 8, 11, 2, };	/*working hours for lab */
     int minuets = 40;		/*global variable for opening time */
     
    int class_hours[9] = { 8,9,10, 11,12,1,2,3,4 };	/*working hours for class */
    
   //below are given all the prototypes//
    class LAB; 
	class CLASSROOM;
	class BUILDINGS;
	class UNIVERSITY;
	
	 void EDIT_DATA();  
	  
	 void EDITlab();
     void edit_no_oflab_courses ();      
	 void edit_SUBJECTS_IN_lab ();	
     void edit_lab_seating_capacity ();	
     void edit_lab_name (); 
     void week_days(int);
     
    void EDITclassroom();
    void edit_no_ofclass_courses ();      
	void edit_SUBJECTS_IN_CLASS ();	
    void edit_class_seating_capacity ();	
    void edit_class_name (); 
    void week_days();
    
    void input_all_lab_data();
    void print_all_lab_data();
    void input_specific_lab_data();
    void print_specific_lab_data();
    
    void input_all_classroom_data();
    void print_all_classroom_data();
    void input_specific_class_data();
    void print_specific_class_data();
    
    void date();
    void display();
    void title();
    void menu();
    void Exit();   
    
class UNIVERSITY 
{
public:
     UNIVERSITY();	
    ~UNIVERSITY();
     int BUILDINGS_in_uni; 
     void get_BUILDINGS ();  
     void set_BUILDINGS (); 
     BUILDINGS * build;
    };
    
    UNIVERSITY uni;//globaly declared object
    
class BUILDINGS
{
     string blockname; 
     
public:
     BUILDINGS();
     ~BUILDINGS();
     int TOTALlab;
     int TOTALCLASSES; 
     
     void get_total_labs (int);
     void get_total_classes (int);
     void get_block_name (int);	/*this store the BUILDING number of the lab */
     
	 LAB * lab;
     CLASSROOM * classes;
   
     void set_total_lab (int);
     void set_total_classes (int);
     void set_block_name (int);

    };
 
 class LAB 
{    
     int *subnumber;		/*dynamic array to store number of subjects per day*/
     int seatinlab;		            /*variable for seating capacity of lab */
     string lab_name;
     name lab_sub[5][3];
     name lab_instruct[5][3]; 
 
public:
	 LAB();
     ~LAB();                                //DESTRUCTOR
     void get_no_oflab_courses (int,int);  /*this store number of courses of one LAB */
     void get_SUBJECTS_IN_LAB (int);	/*this store the subject title of the courses */
     void get_lab_seating_capacity (int);	/*this store the seating capacity of the lab */
     void get_lab_name (int);
 
 /*all the function below when they are called they simply print the data */ 
  
     void set_no_oflab_courses (int,int);
     void set_SUBJECTS_IN_LAB (int);
     void set_lab_seating_capacity (int);
     void set_lab_name (int);

 
};

class CLASSROOM
{
   int *subnumber;		/*variable for no of number of subjects in a LAB */
   int seatinclass;		            /*variable for seating capacity of lab */
   string class_name;
  
   name class_sub[5][9];
   name class_instruct[5][9];
 
public:
	CLASSROOM();
	~CLASSROOM();                               //DESTRUCTOR	
    void get_no_ofclass_courses (int,int);         /*this store number of courses of one LAB */
	void get_SUBJECTS_IN_CLASS (int);	          /*this store the subject title of the courses */
    void get_class_seating_capacity (int);	      /*this store the seating capacity of the lab */
    void get_class_name (int);
    
 /*all the function below when they are called they simply print the data */ 
 
  void set_no_ofclass_courses (int,int);
  void set_SUBJECTS_IN_CLASS (int);
  void set_class_name (int);
  void set_class_seating_capacity (int);
 
 

};
/////////////// HERE IS THE MAIN

 int main(){
  	
  	display();         //simply display the project name
  	system ("PAUSE"); //pause displays a message and waits for the user to hit a key
  	system ("CLS");   //clear the consoule
  	title();          //title page
	menu();           //display menu

  }

void input_all_lab_data() 
     {
  	
  	 uni.get_BUILDINGS ();
     for (int j = 0; j < uni.BUILDINGS_in_uni; j++)
     {
 	 uni.build[j].get_block_name (j);      
     uni.build[j].get_total_labs (j);

     for (int i = 0; i < uni.build[j].TOTALlab; i++)
     {
     uni.build[j].lab[i].get_lab_name(i);
     uni.build[j].lab[i].get_lab_seating_capacity(i);
    
	 for(int k=0;k<5;k++){
	  
     uni.build[j].lab[i].get_no_oflab_courses (i,k);
     uni.build[j].lab[i].get_SUBJECTS_IN_LAB(k);
     
	}
	  system("cls"); 	} 
    system("cls");
    cout << endl;
    
} }

void print_all_lab_data() {
    if(uni.BUILDINGS_in_uni==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }
    uni.set_BUILDINGS ();
    for (int j = 0; j < uni.BUILDINGS_in_uni; j++)
    {
    uni.build[j].set_block_name (j);   
	   
    if(uni.build[j].TOTALlab==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }
	uni.build[j].set_total_lab (j);
    for (int i = 0; i < uni.build[j].TOTALlab; i++)
    {  
    uni.build[j].lab[i].set_lab_name(i);
    uni.build[j].lab[i].set_lab_seating_capacity(i);
	for(int k=0;k<5;k++){
	  
    uni.build[j].lab[i].set_no_oflab_courses (i,k);
    uni.build[j].lab[i].set_SUBJECTS_IN_LAB(k);
	}
	   	} 

    cout << endl;
    system("pause");
    
}   
	  }
     
    

void print_specific_lab_data(){
	 int i,j;
	 cout<<"\n\n\n\n\n\n\n";
      cout<<"\t\t\t\t";	
	 cout<<"ENTER BUILDING NUMBER : ";
	 cin>>j;
	  cout<<"\t\t\t\t";
	 cout<<"ENTER LAB NO          : ";
   	 cin>>i;
   	 system("cls");
		--i;
		--j;
	if(uni.BUILDINGS_in_uni==0)
	  {
  	   	cout<<"NO DATA AVAILABLE\n";	
	  }
	else if(uni.build[j].TOTALlab==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }	

     uni.build[j].lab[i].set_lab_name(i);
     uni.build[j].lab[i].set_lab_seating_capacity(i);
  
	 for(int k=0;k<5;k++){
     uni.build[j].lab[i].set_no_oflab_courses (i,k);
     uni.build[j].lab[i].set_SUBJECTS_IN_LAB(k);
	 } 	

     cout << endl;
     system("pause");
     }
     
void input_all_classroom_data() {
  	
  	uni.get_BUILDINGS ();
  	if(uni.BUILDINGS_in_uni==0)
	  {
  	   	cout<<"NO DATA AVAILABLE\n";	
	  }
    for (int j = 0; j < uni.BUILDINGS_in_uni; j++)
 {
 	
     uni.build[j].get_block_name (j);      
     uni.build[j].get_total_classes (j);

    for (int i = 0; i < uni.build[j].TOTALCLASSES; i++)
 {
    uni.build[j].classes[i].get_class_name(i);
    uni.build[j].classes[i].get_class_seating_capacity(i);
    
	for(int k=0;k<5;k++){
	  
    uni.build[j].classes[i].get_no_ofclass_courses (i,k);
    uni.build[j].classes[i].get_SUBJECTS_IN_CLASS(k);
	}  system("cls"); 	} 
    system("cls");
    cout << endl;
    
} }


void print_all_classroom_data() {

    if(uni.BUILDINGS_in_uni==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }
    uni.set_BUILDINGS ();
   for (int j = 0; j < uni.BUILDINGS_in_uni; j++)
 {
 	
    uni.build[j].set_block_name (j);      
    if(uni.build[j].TOTALCLASSES==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }
	uni.build[j].set_total_classes (j);
    for (int i = 0; i < uni.build[j].TOTALCLASSES; i++)
    {  
    uni.build[j].classes[i].set_class_name(i);
    uni.build[j].classes[i].set_class_seating_capacity(i);
	for(int k=0;k<5;k++){
	  
    uni.build[j].classes[i].set_no_ofclass_courses (i,k);
    uni.build[j].classes[i].set_SUBJECTS_IN_CLASS(k);
	}
	   	} 

    cout << endl;
    system("pause");
    
} }

void print_specific_class_data(){
	 int i,j;
	 cout<<"\n\n\n\n\n\n\n";
	 cout<<"\t\t\t\t";
	 cout<<"ENTER BUILDING NUMBER : ";
	 cin>>j;
	  cout<<"\t\t\t\t";
	 cout<<"ENTER CLASSROOM NO.          : ";
   	 cin>>i;
   	 system("cls");
     --i;
     --j;
   if(uni.BUILDINGS_in_uni==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }
   else if(uni.build[j].TOTALCLASSES==0)
	  {
  	   	cout<<"\n\n\n\n\n\t\t\t\tNO DATA AVAILABLE\n";
		system("pause");
		menu();	 	
	  }	  
	for (int i = 0; i < uni.build[j].TOTALCLASSES; i++)
 {  
    uni.build[j].classes[i].set_class_name(i);
    uni.build[j].classes[i].set_class_seating_capacity(i);
	
	for(int k=0;k<5;k++){
	  
    uni.build[j].classes[i].set_no_ofclass_courses (i,k);
    uni.build[j].classes[i].set_SUBJECTS_IN_CLASS(k);
	}
	   	} 

    cout << endl;
   system("pause");
}

void EDIT_DATA()
    {
	int k;
	change:
    cout<<"\n\n\n\n"; 
    cout<<"\n\n\t\t\t\t\t\t";
    cout<<"EDIT MENU\n\n\n";
    cout<<"\n\n\t\t\t\t";
	cout<<"1. EDIT LAB DATA\n";
	cout<<"\n\n\t\t\t\t";
	cout<<"2. EDIT CLASSROOM DATA\n";
	 cout<<"Choose options:[1/2]:";
	 fflush(stdin);
  	cin>>k;
  	system("cls");
	switch(k){
	
	case 1:
    EDITlab();
	break;
	
	case 2:
	EDITclassroom();
	break;
     default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      system("cls");
      goto change;
    }
  }
   }

  void EDITclassroom(){
  	change:
    system("cls");
  	int k;
  	cout<<"\n\n\n\n\n\n\n\n\n";
  	cout<<"\t\t\t\t1. EDIT NUMBER OF COURSES IN A CLASSROOM\n";
  	cout<<"\t\t\t\t2. EDIT SUBJECT IN A CLASSROOM\n";
  	cout<<"\t\t\t\t3. EDIT SEATING CAPACITY OF A CLASSROOM\n";
  	cout<<"\t\t\t\t4. EDIT NAME OF CLASSROOM\n";
  	 cout<<"\t\t\t\tChoose options:[1/2/3/4]:";
  fflush(stdin);
  cin>>k;
  	switch(k){
  		
	case1:
  	edit_no_ofclass_courses ();
	system("pause");
	break;   
	case 2:
	edit_SUBJECTS_IN_CLASS ();
	system("pause");
	break;
	case 3:
    edit_class_seating_capacity ();	
    system("pause");
	break;
    case 4:
    edit_class_name (); 
    system("pause");
	break;
    
	default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      goto change;
    }
  			
	  }
  }
  
  ///keep edit simple void fun and call get using uni
  
      void edit_no_ofclass_courses (){
      	int x,y,k;
      	cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the classroom ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER classroom number ";
      	cin>>y;
      	cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	cin>>k;
      	--x;
      	--y;
      	--k;
      	if(k>5){
      		cout<<"\t\t\t\tTHERE ARE ONLY FIVE WORKING DAYS \n";
      		cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	    cin>>k;
		  }
		  
	    uni.build[x].classes[y].get_no_ofclass_courses (y,k);
	
	  }      
	void edit_SUBJECTS_IN_CLASS (){      
		int x,y,k;
		cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the classroom ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER classroom number ";
      	cin>>y;
      	cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	cin>>k;
      	--x;
      	--y;
      	--k;
      	if(k>5){
      	cout<<"\t\t\t\tTHERE ARE ONLY FIVE WORKING DAYS \n";
     	cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	cin>>k;
	 }
		uni.build[x].classes[y].get_SUBJECTS_IN_CLASS (k); 
	}	
    void edit_class_seating_capacity (){
    	int x,y;
    	cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the classroom ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER classroom number ";
      	cin>>y;
      	--x;
      	--y;
      	
      	uni.build[x].classes[y].get_class_seating_capacity (y);
    	
	}
    void edit_class_name (){
    	int x,y;
    	cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the classroom ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER classroom number ";
      	cin>>y;
      	--x;
      	--y;
      	
      	uni.build[x].classes[y].get_class_name (y);
    	
	} 
	void EDITlab(){
  	int k;
  	change:
  	system("cls");
  	cout<<"\n\n\n\n\n\n\n\n\n";
  	cout<<"\t\t\t\t1. EDIT NUMBER OF COURSES IN A lab\n";
  	cout<<"\t\t\t\t2. EDIT SUBJECT IN A lab\n";
  	cout<<"\t\t\t\t3. EDIT SEATING CAPACITY OF A lab\n";
  	cout<<"\t\t\t\t4. EDIT NAME OF lab\n";
  	cout<<"\t\t\t\tChoose options:[1/2/3/4]:";
    fflush(stdin);
  	cin>>k;
  	system("cls");

  	switch(k){
  		
	case 1:
  	edit_no_oflab_courses (); 
  	system("pause");
	break;   
	case 2:
	edit_SUBJECTS_IN_lab ();
	system("pause");
	break;
	case 3:
    edit_lab_seating_capacity ();	
    system("pause");
    break;
    case 4:
    edit_lab_name ();
    system("pause");
	break;
		    default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      system("cls");
      goto change;
    } } 
    system("cls");
  			
}
  
  ///keep edit simple void fun and call get using uni
  
      void edit_no_oflab_courses (){
      	int x,y,k;
      	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the lab ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER lab number ";
      	cin>>y;
      	cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	cin>>k;
      	--x;
		--y;
		--k;
      	if(k>5){
      		cout<<"\t\t\t\tTHERE ARE ONLY FIVE WORKING DAYS \n";
      		cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	    cin>>k;
		  }
		  
	    uni.build[x].lab[y].get_no_oflab_courses (y,k);
	
	  }      
	void edit_SUBJECTS_IN_lab (){      
		int x,y,k;
		cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the lab ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER lab number ";
      	cin>>y;
      	cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	cin>>k;
      	--x;
		--y;
		--k;
      	if(k>5){
      	cout<<"\t\t\t\tTHERE ARE ONLY FIVE WORKING DAYS \n";
     	cout<<"\t\t\t\tENTER WEEK DAY IN NUMERIC FORM ";
      	 cin>>k;
	 }
	
		uni.build[x].lab[y].get_SUBJECTS_IN_LAB(k); 
	}	
    void edit_lab_seating_capacity (){
    	int x,y;
    	cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the lab ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER lab number ";
      	cin>>y;
      	--x;
      	--y;
      	uni.build[x].lab[y].get_lab_seating_capacity (y);
    	
	}
    void edit_lab_name (){
    	int x,y;
    	cout<<"\n\n\n\n\n\n\n\n\n";
      	cout<<"\t\t\t\tENTER block number of the lab ";
      	cin>>x;
      	cout<<"\t\t\t\tENTER lab number ";
      	cin>>y;
      	--x;
      	--y;
      	uni.build[x].lab[y].get_lab_name (y);
    	
	} 
	/////
	//////university fun
UNIVERSITY::UNIVERSITY()
{
		BUILDINGS_in_uni=0;
}

void UNIVERSITY::get_BUILDINGS ()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t";
    cout << "Enter total buildings in the UNIVERSITY : ";
    cin >> BUILDINGS_in_uni;
    system("cls");
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t";
        cout << "Not a valid number. Please reenter: ";
        cin >> BUILDINGS_in_uni;
        system("cls");

    }
  
    build = new BUILDINGS[BUILDINGS_in_uni];

} 
 
void UNIVERSITY::set_BUILDINGS()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t";
    cout<<"TOTAL BUILDINGS IN UNIVERSITY ARE : "<< BUILDINGS_in_uni<<endl;
}

UNIVERSITY::~UNIVERSITY(){
	delete []build;
}
 //building building  building
 
 BUILDINGS::BUILDINGS()
 {
 	TOTALlab=0;
 	TOTALCLASSES=0;
 }
 
void BUILDINGS::get_total_labs (int x) 

    {    
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t";
    cout << "Enter TOTAL LABS in the BUILDING/ block " << x + 1 << " : ";
    cin >> TOTALlab;
    system("cls");
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t";
        cout << "Not a valid number. Please reenter: ";
        cin >> TOTALlab;
        system("cls");
    }
    

    lab = new LAB[TOTALlab];
	}

void BUILDINGS:: set_total_lab (int x)
    {
 	cout<<"\n\t\t\t\tTOTAL LAB IN THE BUILDING "<<x+1<<" :  "<<TOTALlab<<endl;
    }
    	 
void  BUILDINGS::get_block_name (int x) 
{
  
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
     cout<<"\t\t\t\t";
     cout << "Enter name of the "<<x+1<<" BUILDING / block:  ";
     cin >> blockname;
     system("cls"); 
} 

void BUILDINGS::set_block_name (int x) 
    {
    	
     cout << "\n\t\t\t\tNAME of the "<<x+1<<" BUILDING / block:  "<<blockname<<endl;
 
    } 

void BUILDINGS::get_total_classes (int x) 
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t";
    cout << "Enter TOTAL CLASSROOM in the BUILDING/ block " << x + 1 << " : ";
    cin >> TOTALCLASSES;
    system("cls"); 
    classes = new CLASSROOM[TOTALCLASSES];
} 
void BUILDINGS:: set_total_classes (int x){
	cout<<"\n\t\t\t\tTOTAL CLASSROOM IN THE BUILDING NO."<<x+1<<" : "<<TOTALCLASSES<<endl;
}
BUILDINGS::~BUILDINGS()
{
delete []lab;
delete []classes;
}
//lab  lab    lab   lab //
//below are function defination of all function that belong to LAB class

LAB::LAB()
{ //set default values
	subnumber=new int[5];	
}

void LAB::get_lab_name(int x){
	
	   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
       cout<<"\t\t\t\t";
	   cout<<"ENTER NAME OF THE LAB "<<x+1<<" : ";
	   cin>>lab_name;
       cout<<"\n\n";
       
}
void LAB::get_lab_seating_capacity (int x) 
{

 
    changeseats:
    	
    cout <<"\t\t\t\tEnter seating capacity of LAB "<<x+1<<"      : ";
    cin >> seatinlab;
   
        while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"\n\t\t\t\t";
        cout << "Not a valid number. Please reenter: ";
        cin >> seatinlab;
        cout<<"\n\n";
    }
  
   if (seatinlab > 50)
    {
   cout<<"\n\t\t\tlab seating capacity should not exceed 50 as per UNIVERSITY rules\n\n";
   goto changeseats;
   } }
   
void LAB::get_no_oflab_courses (int x,int y) {
	
    changesub_no:
    cout<<"\n\t\t\t   ";
    week_days(y);
    cout << "enter NUMBER of courses in the lab "<<x+1<<" : ";//this will be called 5 time i only need  to declare 2d array
    cin >> subnumber[y];
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "\n\n\t\t\t\tNot a valid number. Please reenter: ";
        cin >> subnumber[y];
        cout<<"\n\n";
    }
  
  
    if (subnumber[y] > 3 || subnumber[y] <= 0)
    {
    
    cout << "\t\t\tAs per university rule  there could be minimum one ; maximum three labs \n\n\t\t\t\t  please change the number of courses \n";  
    goto changesub_no;
    } }

void LAB::get_SUBJECTS_IN_LAB (int x) 
    {
    for (int i = 0; i < subnumber[x]; i++)
    {
      
    change:
    cout<<"\n\n";
    cout << "\t\t\t\tEnter SUBJECT from " << lab_hours[i] << ":" << minuets <<" in the lab :   ";
    cin >> lab_sub[x][i].subject;
    int result1=lab_sub[x][i].subject.compare("empty");
    int result2=lab_sub[x][i].subject.compare("EMPTY");

    if(result1==0||result2==0)
    {
    i++;
    goto change;
    } 
    else
    {
    cout << "\t\t\t\tEnter lab INSTRUCTOR name : ";
    cin >> lab_instruct[x][i].instructor;
	 
    } } } 


void LAB::set_lab_name(int x){
	cout<<"\n\t\t\t\tNAME OF THE LAB "<<x+1<<"  :   "<<lab_name<<endl;
    }

void LAB::set_no_oflab_courses (int x,int y){
	week_days(y);
    cout<<"\n\n\t\t\t\tNUMBER OF COURSES IN LAB NO. "<<x+1<<" : "<<subnumber[y]<<endl;
    }
    

 
void LAB::set_lab_seating_capacity(int x){
    
	cout<<"\n\t\t\t\tseatiog Capacity of LAB "<<x+1<<" is : "<<seatinlab<<endl;
    
    }


void LAB::set_SUBJECTS_IN_LAB (int x){
   
    for (int i = 0; i < 3; i++)
    { 
    cout << "\t\t\t\tSUBJECT from " << lab_hours[i] << ":" << minuets <<" in the LAB : ";
    int result1=lab_sub[x][i].subject.compare("empty");
    int result2=lab_sub[x][i].subject.compare("EMPTY");
    if(result1==0||result2==0||lab_sub[x][i].subject=="")
	{
   	cout<<"LAB IS EMPTY"<<endl;
	}
	else{
	
    cout<< lab_sub[x][i].subject<<endl;
    cout << "\t\t\t\tLAB INSTRUCTOR name : ";
    cout<< lab_instruct[x][i].instructor;
    cout<<endl;
	} } }    
	
	//////////////////////////////////////////////////////////classroom function defination
	
CLASSROOM::CLASSROOM()
{
   subnumber=new int[5];		
}	
	
void CLASSROOM::get_class_name (int x){
	   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
       cout<<"\t\t\t\t";
    cout<<"ENTER THE NAME OF CLASSROOM "<<x+1<<" : ";
    cin>>class_name; 
	 cout<<"\n\n";	 
 }
 void CLASSROOM::get_class_seating_capacity (int x) 
{
    changeseats:
    cout <<"\t\t\t\tEnter seating capacity of CLASSROOM NO. "<<x+1<<" : ";
    cin >> seatinclass;
       while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"\n\t\t\t\t";
        cout << "Not a valid number. Please reenter: ";
        cin >> seatinclass;
        cout<<"\n\n";
    }
 if (seatinclass > 50)
     {
    cout<<"CLASSROOM seating capacity should not exceed 50 as per UNIVERSITY rules";
    goto changeseats;
} }
void CLASSROOM::get_SUBJECTS_IN_CLASS (int x) 
{ 
    for (int i = 0; i < subnumber[x]; i++)   
    {
    change:
    cout<<"\n\n";
    cout << "\t\t\t\tEnter SUBJECT from " << class_hours[i] << ":" << minuets <<" in the lab "; 
    cin >> class_sub[x][i].subject;
  
    int result1=class_sub[x][i].subject.compare("empty");
    int result2=class_sub[x][i].subject.compare("EMPTY");

    if(result1==0||result2==0)
{   i++;
    goto change;
}
    else     
 {
    cout << "\t\t\t\tEnter lab INSTRUCTOR name : ";
    cin >> class_instruct[x][i].instructor;
    cout<<endl; 
} }
} 

void CLASSROOM::get_no_ofclass_courses (int x,int y) 
{
//this will be called 5 time i only need  to declare 2d array
//call weeks name function
   week_days(y); 
   cout<<"\n\t\t\t\t"; 	
   changesub_no:
   cout << "enter NUMBER of courses in the CLASSROOM "<<x+1<<" ";
   cin >> subnumber[y];
     while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "\n\n\t\t\t\tNot a valid number. Please reenter: ";
        cin >> subnumber[y];
        cout<<"\n\n";
    }
  
   if (subnumber[y] > 8 || subnumber[y] <= 0)
    {
    
   cout <<"As per university rule a there could be minimum one ; maximum three labs \n  please change the number of courses \n";
    goto changesub_no;
    
} }


void CLASSROOM::set_no_ofclass_courses (int x,int y){
     week_days(y);
     cout<<"\n\n\t\t\t\tNUMBER OF COURSES IN CLASSROOM NO. "<<x+1<<" : "<<subnumber[y]<<endl;
 
  }
  

  
void CLASSROOM::set_SUBJECTS_IN_CLASS (int x){
  
for (int i = 0; i < 9; i++)
    
    { 
    cout << "\n\t\t\t\tSUBJECT from " << class_hours[i] << ":" << minuets <<" in the CLASSROOM : ";
    
    int result1=class_sub[x][i].subject.compare("empty");
    int result2=class_sub[x][i].subject.compare("EMPTY");
    if(result1==0||result2==0||class_sub[x][i].subject=="")
	{
    	cout<<"CLASSROOM IS EMPTY"<<endl;
	}
	else{
	
    cout<< class_sub[x][i].subject<<endl;
    cout << "\t\t\t\tSUBJECT INSTRUCTOR name : ";
    cout<< class_instruct[x][i].instructor;
    cout<<endl;}
} }   
  void CLASSROOM::set_class_seating_capacity (int x){
  	cout<<"\n\t\t\t\tNUMBER OF SEATS IN CLASSROOM "<<x+1<<" ARE "<<seatinclass<<endl;
  }
  void CLASSROOM::set_class_name(int x){
	cout<<"\n\t\t\t\tENTER THE NAME OF CLASSROOM NO. "<<x+1<<" : "<<class_name;
}


void Exit()                                 //this function exit end execution whenever called
      {
       system("cls");
       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
       cout<<"\t\t\t\t\t";
       cout<<"You are out of the System.";
       cout<<"\n\n";
       cout<<"\t\t\t\t";
       cout<<"   Press Enter to Continue Exit Program...";
       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n"; 
       getchar();
       exit(0);
      }

void week_days(int x){

   cout<<"\n\t\t\t\t";
   switch(x){
   case 0:
   cout<<"For MONDAY ";
   break;
   case 1:
   cout<<"For TUSEDAY ";
   break;
   case 2:
   cout<<"For WEDNESDAY ";
   break;
   case 3:
   cout<<"For THURSDAY ";
   break;
   default:
   cout<<"For FRIDAY ";

}}
	   

void date(){
  	   // current date/time based on current system
  time_t now = time(0);
   
   // convert now to string form
  char* dt = ctime(&now);
  cout<<"\n\n\n";
  cout<<"\t\t\t\t\t"<<dt;
  
  }
  
void display(void){
  cout<<"\n\n\n";
  cout<<"\t\t\t\t\t";
  cout<<"\n";
  cout<<"\t\t\t\t       ----------------------------\n";
  cout<<"\t\t\t\t       |BUILDING MANAGEMENT SYSTEM|\n";
  cout<<"\t\t\t\t       ----------------------------\n";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  }

void title()
 {  
  int process=0;
  system("cls");
  date();
  cout<<"\n\t\t\t\t      ---------------------------\n";
  cout<<"\t\t\t\t      |BUILDING MANAGEMENT SYSTEM|\n";
  cout<<"\t\t\t\t      ---------------------------\n";
  cout<<"\n\n\n";
  cout<<"\t\t\t\t";
  cout<<"Prepared By    ";
  cout<<":";
  cout<<"   MALEEHA REHMAN";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  cout<<"Mini Project    ";
  cout<<":";
  cout<<"  Building Management System";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  cout<<"Guided By      ";
  cout<<":";
  cout<<"   Dr. NAVEED ANWAR BHATTI";
  cout<<"\n\n";
  cout<<"\t\t\t\t    Press Enter to continue......";
  cout<<"\n\n";
  getchar();
  cout<<"\t\t\t\tLoading";

  for(process=0;process<25;process++)
  {
    usleep(50000);
    cout<<".";
  }
}
void menu(){
	change:
	 int input,var,var2;
  system("cls");
  display();
  cout<<" 1. Enter new Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 2. Modify Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 3. View Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 4. Exit\n\n";
  cout<<"\t\t\t\t";
  cout<<"Choose options:[1/2/3/4]:";
  fflush(stdin);
  cin>>input;
  system("cls");
  switch(input)
  	{
	  case 1:
	 {
      change1:
	  system("cls");
	  cout<<"\n\n\n\n\n\n\n\n\n\n";
      cout<<"\t\t\t\t";	
	  cout<<"1. ENTER RECORD FOR LABS\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"2. ENTER RECORD FOR CLASSROOMS\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"Choose options:[1/2]:";
      fflush(stdin);
	  cin>>var;	
	  system("cls");
	  switch(var){
	  	case 1:
	  		input_all_lab_data();
	  		goto change;
	  	break;
		  
		case 2:
		    input_all_classroom_data() ;
		    goto change;
		break;
		
		default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      goto change1;
    } } } 
	  break;
	  
	  case 2:
	  {
	 change2: 	
     system("cls");
	  cout<<"\n\n\n\n\n\n\n\n\n\n";
      cout<<"\t\t\t\t";	
	  cout<<"1. EDIT LABS RECORD\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"2. EDIT CLASSROOMS RECORD\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"Choose options:[1/2]:";
      fflush(stdin);
	  cin>>var2;
	  switch(var2){
	  	case 1:
	  	EDITlab();
	  	goto change;
		break;
		case 2:
		EDITclassroom();
		goto change;
		break;
		 default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      goto change2;
    }  }
	  
      }
	 	  case 3:
	 {
      change3:
	  system("cls");
	  cout<<"\n\n\n\n\n\n\n\n\n\n";
      cout<<"\t\t\t\t";	
	  cout<<"1. VIEW RECORD FOR ALL LABS\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"2. VIEW RECORD FOR ALL CLASSROOMS\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"3. VIEW FOR SPECIFIC CLASS\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"4. VIEW FOR SPECIFIC LAB\n\n";
	  cout<<"\t\t\t\t";
	  cout<<"Choose options:[1/2/3/4]:";
      fflush(stdin);
	  cin>>var;	
	  system("cls");
	  switch(var){
	  	case 1:
	  		print_all_lab_data();
	  		goto change;
	  	break;
		  
		case 2:
		    print_all_classroom_data() ;
		    goto change;
		break;
		
		case 3:
		    print_specific_class_data();
		    goto change;
		break;
		
		case 4:
		    print_specific_class_data();
		    goto change;
		break;
		
		    default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      goto change3;
    } } } 
	  break;
	case 4:
    {
      Exit() ;  
    }
     break;

    default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!";
      cout<<"\n\n";
      cout<<"\t\t\t\t";
      cout<<"Press Enter to choose again...";
      getchar();
      goto change;
    }
    
}   }
  
 LAB::~LAB()
 { delete []subnumber;
 }
 CLASSROOM::~CLASSROOM()
 {
 	delete []subnumber;
 }
