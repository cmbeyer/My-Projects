#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#include <stdlib.h>
#include "stdafx.h"
 
#include "monthendbalance.h"

void findhighest(CObList *list);
void sortdata (CObList * list);

int main()
{
       system("Color 70");

	   CObList *list=new CObList; 	
	   monthendbalanceclass * pa2;
	   
	   CString thestring;
       char lastname[10];       
	 
       double previousbalance;
	   double payments, charges ,newbalance,financecharges,monthendbalance,totalmonthendbalance=0;
	   
	  ifstream inFile( "F:\\monthendbalance.txt", ios::in );




	  if ( !inFile ) 
        {
          cerr<< "File could not be opened\n";
          exit( 1 );
        }
         

        while ( inFile >> lastname>>previousbalance>>payments>>charges )
        {          
		     thestring = CString(lastname);
		     pa2 = new monthendbalanceclass(thestring, previousbalance, payments, charges);	 
	         list->AddHead(pa2); 
	         pa2->compute();
	         monthendbalance = pa2->getmonthendbalance();  

		    cout<<setw(10)<<"Last Name:  "<<thestring<<setw(10)<<"Previous Balance:   "<<previousbalance<<setw(10)<<"Payments:  "<<payments<<setw(10)<<"Charges:  "<<charges<<endl;
	  
		   thestring.Empty();
        }
		totalmonthendbalance = monthendbalanceclass::gettotalmonthendbalance();
		   cout<<endl;
		   

		   findhighest(list);

		   cout<<endl<<endl;
		   cout<<"Sorted list "<<endl;
		   sortdata(list);
		   cout<<endl<<endl;
 
	return 0;
}

void sortdata (CObList * list)
{
	monthendbalanceclass * pa3 = new monthendbalanceclass (CString(""),0,0,0);
	pa3->sort(list);
 
    int number= list->GetCount();

    POSITION pos;

    pos= list->GetTailPosition();
    CObject  *b2 =list->GetPrev(pos);
	   
    pa3 = (monthendbalanceclass  *)b2;
 
	CString lastname;
	double previousbalance;
	double payments, charges;
	  
     for (int st = 1; st <= number; st++)
	 {
       	  pa3->getdata(lastname, previousbalance, payments, charges);

		  cout<<setw(10)<<lastname<<setw(10)<<previousbalance<<setw(10)<<payments<<setw(10)<<charges<<setw(10)<<endl;
 
	      if (st < number)
		  {
	           b2 =list->GetPrev(pos);
               pa3 = (monthendbalanceclass *)b2;
		 }
	 }

}

void findhighest(CObList *list)
{		 
	 monthendbalanceclass * pa3;	 
      int number= list->GetCount();
      POSITION pos;
      pos= list->GetTailPosition();
      CObject  *b2 =list->GetPrev(pos);	   
      pa3 = (monthendbalanceclass  *)b2;
      monthendbalanceclass *top = pa3;

     for (int st = 1; st <= number; st++)
	 {
           if (*pa3 > top)
		     top = pa3;

	     if (st < number)
		 {
	           b2 =list->GetPrev(pos);
                 pa3 = (monthendbalanceclass *)b2;
		 }
	 }

	 CString lastname;
	 double previousbalance;
	 double payments, charges,monthendbalance;
	 top->getdata(lastname, previousbalance, payments, charges);

	 cout<<"Person with the highest Month End Balance is "<<endl;
	 cout<<setw(10)<<lastname<<setw(10)<<previousbalance<<setw(10)<<payments<<setw(10)<<charges<<endl;
	 
}