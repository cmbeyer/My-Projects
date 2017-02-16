#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "stdafx.h"
 
#include "monthendbalance.h"
 

int monthendbalanceclass::count=0;
double monthendbalanceclass::totalmonthendbalance=0; 
		

monthendbalanceclass::monthendbalanceclass()
{

}



monthendbalanceclass::monthendbalanceclass( CString &  n, double pb, double py, double ch)
{
	lastname=n  ;
	previousbalance = pb;
	payments = py;
	charges = ch;
}
 


 double monthendbalanceclass::getmonthendbalance()
 {
	 return monthendbalance;
 }

void monthendbalanceclass::compute()
{
	newbalance = (previousbalance-payments) + charges;	
	financecharge= newbalance * .12;
	monthendbalance= newbalance + financecharge;
     count++;
	 cout<<"New Balance=  "<<newbalance<<setw(10)<<"Finance Charges=   "<<financecharge<<setw(10)<<"MonthEndBalance=   "<<monthendbalance<<endl;
}

double monthendbalanceclass::gettotalmonthendbalance()
{
	return totalmonthendbalance;
}

bool monthendbalanceclass::operator > (monthendbalanceclass  * p)
{    
	return (monthendbalance > p->monthendbalance);
}



int monthendbalanceclass::getcount()
{
	return count;
}

 



void monthendbalanceclass::getdata(CString & n, double & pb, double & py,double & ch)
{
	n = lastname;
	pb= previousbalance;
	py = payments;
	ch=charges;
	                                         

}


  
void monthendbalanceclass::sort(CObList * list)
{
       POSITION pos; 
        pos= list->GetTailPosition();
        CObject *b2 =list->GetPrev(pos);	   
	   monthendbalanceclass * pa1;     
        pa1 = (monthendbalanceclass *)b2;
	   int number = list->GetCount();
	   CObArray arraywithdata;

	   for (int st = 0; st < number; st++)
        {
                 arraywithdata.Add(pa1);
	             if (st < number-1)
		         {
			          b2 =list->GetPrev(pos);
			          pa1 = (monthendbalanceclass *)b2;
		          }
            }


	   monthendbalanceclass * hold;
        monthendbalanceclass * obj1, * obj2;
     
		  for (int pass = 1; pass <=number-1 ; pass++)  
		  {
              for (int i = 0; i <= number-2 ; i++)       
	          {        
                     obj1 = (monthendbalanceclass *) arraywithdata.GetAt(i); 
                     obj2 = (monthendbalanceclass *)  arraywithdata.GetAt(i+1);
      
                   if (obj1->lastname.CompareNoCase(obj2->lastname) > 0)
                    {
                          hold =  (monthendbalanceclass *) arraywithdata.GetAt(i);                   
                          arraywithdata.SetAt(i, ((monthendbalanceclass *) arraywithdata.GetAt(i + 1)  ));
                          arraywithdata.SetAt(i + 1, hold);
                    }
              }
		  }
     
	   list->RemoveAll();

        monthendbalanceclass *fromarray;
        fromarray = (monthendbalanceclass *) arraywithdata.GetAt(0);
        for (int st = 1; st <= number; st++)
         {          
              list->AddHead(fromarray);

	          if (st < number)
	          {
	             fromarray = (monthendbalanceclass *) arraywithdata.GetAt(st);			 
   	           }
           } 
}