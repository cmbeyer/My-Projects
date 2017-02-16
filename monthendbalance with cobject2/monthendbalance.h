#ifndef MONTHENDBALANCE_H
#define MONTHENDBALANCE_H

#include "stdafx.h" 
 

class monthendbalanceclass : public CObject
{   
     
   public:
       
	   monthendbalanceclass();	
	   monthendbalanceclass(  CString &  , double , double, double );	 
 
	   
	   void compute();
	   double getmonthendbalance();
	   void getdata(CString & lastname, double & previousbalance, double & payments,double & charges);	  
	   static double gettotalmonthendbalance();	   
       static int getcount();  	  
	   bool operator>(monthendbalanceclass * p);
	   void sort(CObList * list);

   private:
 
	    CString lastname;
		double previousbalance;
		double payments, charges,newbalance,financecharge;
		static int count;
		double monthendbalance;
		static double totalmonthendbalance;
  
   };  

#endif
