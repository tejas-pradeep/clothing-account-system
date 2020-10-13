//HEADER FILES
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
void design()
{

   cout<<endl;
   for(int i=0;i<80;i++)
	cout<<"*";
   cout<<"\n\t\t\t\t    WELCOME";
   cout<<"\n\t\t\t******************************";
   cout<<endl;
   for(int l=0;l<80;l++)
	cout<<"*";
   cout<<"\n\t\t\t     INVERTORY MANAGEMENT ";
   cout<<"\n\t\t\t     ******************** ";
   cout<<"\n";
   cout<<"\n\t\t      ____       ____         ____________    ";
   cout<<"\n\t\t     /    \\     /    \\       /_____";
   cout<<"|_|";
   cout<<"____\\  ";
   cout<<"\n\t\t    /      \\___/      \\      |            |   ";
   cout<<"\n\t\t   /   /           |   \\     |    ____    |   ";
   cout<<"\n\t\t  /   /|           |\\   \\    |    |  |    |   ";
   cout<<"\n\t\t       |  ";
   cout<<"Welcome";
   cout<<"  |         |    |  |    |   ";
   cout<<"\n\t\t       |   ";
   cout<<"to our";
   cout<<"  |         |    |  |    |   ";
   cout<<"\n\t\t       |  ";
   cout<<"Clothing";
   cout<<" |         |    |  |    |   ";
   cout<<"\n\t\t       |   ";
   cout<<"Store";
   cout<<"   |         |    |  |    |   ";
   cout<<"\n\t\t       |    ";
   cout<<"  ";
   cout<<"     |         |    |  |    |   ";
   cout<<"\n\t\t       |___________|         |    |  |    |   ";
   cout<<"\n\t\t                             |    |  |    |   ";
   cout<<"\n\t\t                             |    |  |    |   ";
   cout<<"\n\t\t                             |____|  |____|   ";
   cout<<endl<<"\n";
   cout<<"Press any key to continue :)\n\n";
   for(int m=0;m<80;m++)
     cout<<"*";
}
class item_file
{
	public:
	float irate;
	int icode,qty;
	char iname[30];
	void getdata();
	int ricode(){ return icode;}
	float rirate(){ return irate;}
	int rqty(){ return qty;}
	char* rname(){ return iname;}
	void showdata()
	{
	 cout<<"CODE : "<<ricode();
	 cout<<"RATE : "<<rirate();
	 cout<<"NAME : "<<rname();
	 cout<<"QUANTITY :"<<rqty();
	}
		void showdata1()
	{
	 cout<<ricode();
	 cout<<"\t\t"<<rirate();
	 cout<<"\t\t"<<rname();
	 cout<<"\t\t"<<rqty();
	 cout<<endl;
	}
	void modidata(int ic);
};
void item_file::getdata()
{
	cout<<"\n\tENTER THE ITEM CODE : ";
	cin>>icode;
	cout<<"\n\tENTER THE NAME OF THE ITEM : ";
	gets(iname);
	cout<<"\n\tENTER THE RATE : ";
	cin>>irate;
	cout<<"\n\tENTER THE QUANTITY : ";
	cin>>qty;
}
void item_file::modidata(int ic)
{
	icode=ic;
	cout<<"\nENTER THE NEW NAME OF THE ITEM : ";
	gets(iname);
	cout<<"\nENTER THE NEW RATE : ";
	cin>>irate;
	cout<<"\nENTER THE NEW QUANTITY : ";
	cin>>qty;
}
//***************************LIST OF FUNCTIONS*******************************
void add_item();
void update();
void add_stock();
void search();
void rep_prep();
void item_delete();
//*********************************MAIN**************************************
void main()
{
	int choice , x;
   design();
	getch();
	do
	{
	 clrscr();
	 cout<<"\n\t\t\t\tSELECTION COUNTER\n";
	 cout<<"\t\t\t\t=================\n";
	 cout<<"\n\t1.) ADDITION OF NEW ITEMS\n";
	 cout<<"\n\t2.) ADDING STOCK TO EXISTING ITEM\n"	;
	 cout<<"\n\t3.) SEARCH FOR AVAILABILITY OF A PARTICULAR ITEM\n";
	 cout<<"\n\t4.) ITEM REPORTS\n";
	 cout<<"\n\t5.) DELETE ITEM\n";
	 cout<<"\n\t6.) EXIT\n";
	 cout<<"\n\n\t\t\t      ENTER YOUR CHOICE : ";
	 cin>>choice;

		switch(choice)
		{
			case 1:add_item();break;
			case 2:add_stock();break;
			case 3:search();break;
			case 4:rep_prep();break;
			case 5:item_delete();break;
			case 6:clrscr();
			       gotoxy(23,5);
			       for(x=0;x<35;x++)
			       cout<<"*";
			       gotoxy(35,7);
			       cout<<"THANK YOU: ";
			       gotoxy(35,8);
			       cout<<"*********";
			       gotoxy(25,10);
			       cout<<"SPECIAL THANKS TO OUR COMPUTER TEACHER";
			       gotoxy(32,11);
			       cout<<"MRS. ASHA EBEY ";
			       gotoxy(23,13);
			       for(x=0;x<35;x++)
				 cout<<"*";
			       gotoxy(34,15);
			       cout<<"PRESENTED BY : ";
			       gotoxy(31,17);
			       cout<<"TEJAS RAJAMADAM PRADEEP";
			       gotoxy(31,18);
			       cout<<"URVISH PARAG CHOKSHI";
			       gotoxy(38,19);
			       cout<<"XII-A";
			       gotoxy(23,21);
			       for(x=0;x<35;x++)
				 cout<<"*";
			       gotoxy(23,23);
		cout<<"Press any key to quit the program...";
			      getch();
			      exit(0);
			      break;
			default:
				cout<<"\n\a WRONG CHOICE! ENTER AGAIN";
				getchar();
		}
	}while(choice!=10);
	clrscr();

}
//************************END OF MAIN()**********************************//
//************************FUNCTION TO ADD AN ITEM TO THE ITEM_FILE*******//
void add_item()
{

	ofstream outfile;
	outfile.open("ITEM.DAT",ios::binary|ios::app);
	item_file ifi;
	int ch=0;
	do
	{
		clrscr();
		cout<<"\n";
		for(int i=0;i<=79;i++)
		{
			gotoxy(i+1,2);
			cout<<"*";
		}
		ifi.getdata();
		outfile.write((char*)(&ifi),sizeof(ifi));
		cout<<"\n\tPress '1' to continue adding items";
		cout<<"\n\tPress '2' to quit";
		cout<<"\n\tEnter your choice :";
		cin>>ch;
	}while(ch!=2);
	outfile.close();
}
//*******************END OF FUNCTION ADD_ITEM()**************************//

//************************FUNCTION TO DELETE AN ITEM TO THE ITEM_FILE*******//
void item_delete()
{
   int ch=0,c;
   char ans;
	fstream outfile,infile;
	outfile.open("TEMIT.DAT",ios::binary|ios::out);
   infile.open("ITEM.DAT",ios::binary|ios::in);
	item_file ifi;
	clrscr();
   for(int i=0;i<=79;i++)
   {
      gotoxy(i+1,2);
      cout<<"*";
   }
	cout<<"\n\nEnter the code of the item to be deleted : ";
	cin>>c;
	while(infile.read((char*)&ifi,sizeof(ifi)))
      {
      if(ifi.icode==c)
      {
	ch=2;
		cout<<"\n";
	 cout<<"\nDETAILS OF THE ITEM";
	 cout<<"\n===================";
	 cout<<endl;
	 cout<<"\n************************************************************";
	 cout<<"********************\n";
	 cout<<"CODE : "<<ifi.ricode()<<"   ";
	 cout<<" \t NAME : "<<ifi.rname()<<"   ";
	 cout<<" \t RATE : "<<ifi.rirate()<<"   ";
	 cout<<" \t QUANTITY : "<<ifi.rqty()<<"   ";
	 cout<<endl<<endl;
	 for(int m=0;m<=79;m++)
		    cout<<"*";
																																																																		 cout<<endl;
		for(int a=0;a<=79;a++)
		  cout<<"*";
	 cout<<endl;
	 cout<<"\nAre you Sure you want to delete?";
	 cout<<"\nIf yes press 'Y'";
	 cout<<"\nIf no press 'N'";
	 cout<<endl<<"Enter your choice :";
	 cin>>ans;
	 ans=tolower(ans);
	 if (ans=='n')
	 {
		ch=1;
			outfile.write((char*)&ifi,sizeof(ifi));
	 }
	}
	else
	outfile.write((char*)(&ifi),sizeof(ifi));
       }
		outfile.close();
      infile.close();
	remove("ITEM.DAT");
	rename("TEMIT.DAT","ITEM.DAT");
	if (ch==0)
		cout<<"\n\nGiven Item Code Does Not Exists";
	else if (ch==1)
		cout<<"\n\nGiven Item Code Exists, But Not Deleted";
		else if (ch==2)
	{
		cout<<"\n\nITEM DELETED!";
		}
	cout<<"\n\n\nPress Any Key to Continue....";
		getch();
}
//*******************END OF FUNCTION DELETE_ITEM()**************************//
//*************************FUNCTION TO DRAW A BOX****************************

void set_box()
{
	int x1=3,x2=18,y1=10,y2=70;
	int l=y2-y1+1;
	char c='*';
	gotoxy(y1,x1);
	for(int i=1;i<=1;i++)
	cout<<c;
	for(int j=x1;j<=x2;j++)
	{
		gotoxy(y1,j);cout<<c;
		gotoxy(y2,j);cout<<c;
	}
	gotoxy(y1,x2);
	for(int b=1;b<=l;b++)
	cout<<c;
}
//***********************END OF FUNCTION SET_BOX*****************************
//**************FUNCTION TO ADD STOCK TO AN EXISTING ITEM********************

void add_stock()
{
	int c,q,vl=0,l;
	item_file ifi;
	fstream file1;
	file1.open("ITEM.DAT",ios::binary|ios::in|ios::out);
	clrscr();
	for(int i=0;i<=79;i++)
		{
			gotoxy(i+1,2);
			cout<<"*";
		}
	cout<<"\n\tENTER THE ITEM CODE : ";
	cin>>c;
	file1.seekg(0,ios::beg);
	file1.read((char*)(&ifi),sizeof(ifi));
	while((!file1.eof())&&(vl==0))
	{
		if(ifi.icode==c)
		{
			cout<<"\n\tENTER THE QUANTITY TO BE ADDED : ";
			cin>>q;
			ifi.qty+=q;
			l=sizeof(ifi);
			file1.seekg(-l,ios::cur);
			file1.write((char*)(&ifi),sizeof(ifi));

			cout<<"\n\tSTOCK ADDED!";

	 cout<<"\n\n\tDETAILS OF THE ITEM :";
	 cout<<"\n\t===================";
	 cout<<endl;
			cout<<"\n\tITEM CODE :"<<ifi.icode;
	 cout<<"\n\tQUANTITY  :"<<ifi.qty;
			vl=1;
		}
		file1.read((char*)(&ifi),sizeof(ifi));
	}
	if(vl==0)
	cout<<"\n\tINVALID ITEM CODE!";
	file1.close();
	cout<<"\n\n\tPress any key to continue...";
	getch();
}
//*************************END OF FUNCTION ADD_STOCK*************************
//******************FUNCTION TO SEARCH FOR A PARTICULAR ITEM*****************
void search()
{
	clrscr();
	gotoxy(30,11);
	int code,found=0;
	item_file f;
	cout<<"\n\tENTER THE CODE OF THE ITEM : ";
	cin>>code;
	ifstream infile;
	infile.open("ITEM.DAT",ios::binary);
	infile.read((char*)(&f),sizeof(f));
	while((!infile.eof())&&(found==0))
	{
		if (f.icode==code)
		{

			cout<<"\n\t"<<f.iname;

	 cout<<" IS AVAILABLE IN THE INVENTORY";
			cout<<"\n\tSTOCK :"<<f.qty;
			found=1;
		}
		infile.read((char*)(&f),sizeof(f));
	}
	if(found==0)
	{
		cout<<"\n\tTHE ITEM IS NOT AVAILABLE IN THE INVENTORY";
	}
	infile.close();
	getchar();
}
//*************************END OF FUNCTION SEARCH()***************************
//************************FUNCTION TO PREPARE REPORTS************************
void rep_prep()
{
	clrscr();
	item_file ifi;
	for(int i=1;i<=80;i++)
	{
		gotoxy(i,2);
		cout<<"*";
	}
	ifstream f1;
	f1.open("ITEM.DAT",ios::binary);
	if(!f1)
	{

		cout<<"\a\n\tITEM NOT PRESENT";
	}
	else
	{

		cout<<"ITEM CODE\t RATE\t ITEM NAME\t QUANTITY"	;

      cout<<endl<<"********************************************************************************";
		f1.read((char*)&ifi,sizeof(ifi));
		while(!f1.eof())
		{
			ifi.showdata1();
			f1.read((char*)&ifi,sizeof(ifi));
		}
      cout<<"\n********************************************************************************\n";
      cout<<"\n\n";

      cout<<"Press 'Enter' to continue...";
	}
	f1.close();
	getchar();
}
//************************END OF REP_PREP FUNCTON**************************************

*******END OF PROJECT-INVENTORY MANAGEMENT SYSTEM******************
