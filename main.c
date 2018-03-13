// Initialization and input parsing

/*
hey gabe this is really raw! like really raw! i am just posting it so well you can have something from where to grab your self 
once we start adding more stuff, so well atlest we get some stuff working and we have a base or something, now we just need to add more stuff 
and welle ventually make it better or come up with better stuff!

you can post this in your editor, run it and you should have an ouput, sorting not working well but its ok we will fix it

*/


int main() {
	
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
 
 typedef struct info
  {        
    char *streetName ; 
    int streetNumber;
    int numberOfBedrooms;
    int pricePerBedRoom;   
    int baseDistance;
    struct info *pNext;
        
}info ;

typedef struct node{
    
    info *pInfo;
    struct node *pNext;
    
}node;
	
int main ()
{    
    int count=0;
    info *pInform[12];  
    srand( time(NULL) );  
    
    info infoArray []={
        
        {"Sussex Drive1", 0, 0, 0},
        {"Sussex Drive2", 0, 0, 0},
        {"Sussex Drive3", 0, 0, 0}, 
        {"Sussex Drive4", 0, 0, 0},
        {"Fish Lane", 0, 0, 0},
        {"Robin Road", 0, 0, 0},
        {"Tesla street", 0, 0, 0},
        {"C Road", 0, 0, 0},
        {"Maple Street", 0, 0, 0},
        {"First Road", 0, 0, 0},
        {"Abbey Road", 0, 0, 0},
        {"Sussex Drive5", 0, 0, 0},
    };


        //this code will create the linked list, we will have to change it and put all this in a function eventually
 
        info *pProperty = (struct info*) malloc( sizeof (struct info) );       
        pProperty->pNext = NULL;
     
        info *pPropertyTwo = (struct info*) malloc( sizeof (struct info) );      
        pProperty->pNext = pPropertyTwo;
        pPropertyTwo->pNext=NULL;
        
        info *pPropertyThree = (struct info*) malloc( sizeof (struct info) );        
        pPropertyTwo->pNext = pPropertyThree;
        pPropertyThree->pNext = NULL;
        
        info *pPropertyFour = (struct info*) malloc( sizeof (struct info) );        
        pPropertyThree->pNext = pPropertyFour;
        pPropertyFour->pNext = NULL;
        
        info *pPropertyFive = (struct info*) malloc( sizeof (struct info) );        
        pPropertyFour->pNext = pPropertyFive;
        pPropertyFive->pNext = NULL;
        
        info *pPropertySix = (struct info*) malloc( sizeof (struct info) );        
        pPropertyFive->pNext = pPropertySix;
        pPropertySix->pNext = NULL;
        
        info *pPropertySeven = (struct info*) malloc( sizeof (struct info) );        
        pPropertySix->pNext = pPropertySeven;
        pPropertySeven->pNext = NULL;
        
        info *pPropertyEight = (struct info*) malloc( sizeof (struct info) );        
        pPropertySeven->pNext = pPropertyEight;
        pPropertyEight->pNext = NULL;
        
        info *pPropertyNine = (struct info*) malloc( sizeof (struct info) );        
        pPropertyEight->pNext = pPropertyNine;
        pPropertyNine->pNext = NULL;
        
        info *pPropertyTen = (struct info*) malloc( sizeof (struct info) );        
        pPropertyNine->pNext = pPropertyTen;
        pPropertyTen->pNext = NULL;
    
     
     
     
     info *pInfo = pProperty;
     
	// initiaize each node of the linked list
     while ( pInfo != NULL )
         {
         
             pInfo->streetName= infoArray[count].streetName;
             pInfo->streetNumber=(rand() % (200)+1);
             pInfo->numberOfBedrooms= (rand()% (4)+1);
             pInfo->baseDistance=(rand() % (4)+ 0.5); // we need to fix this later
             pInfo->pricePerBedRoom =(rand() % (6)+2)*100; // this one too         
             
	     // printf("%d %s %d %d %d\n\n", pInfo->streetNumber, pInfo->streetName, pInfo->numberOfBedrooms, pInfo->pricePerBedRoom, pInfo->baseDistance );
                      
             pInfo= pInfo->pNext;        
         count++;
     }
 
 //function that will sort the values ( not working properly now)
 sortByNumberOfBedRooms(pProperty);
 
 pInfo = pProperty;
 
//while loop it will print values of the linked list
 while ( pInfo != NULL )
 {  
  printf("%d %s %d %d %d\n", pInfo->streetNumber, pInfo->streetName, pInfo->numberOfBedrooms, pInfo->pricePerBedRoom, pInfo->baseDistance );
  pInfo= pInfo->pNext;
 }    
    return 0;    
}


void swap(  info* a,  info* b )
{
    
    //i know there is another way to swap the nodes, i tried alot of things i honestly could't make it work
    //i was trying creating another struct like he said on the assignmet but just didn't work for me
    
    
   char* tempStreetName = a->streetName;
    int tempStreetNumber = a->streetNumber;
    int tempNumberOfBedrroms = a->numberOfBedrooms;
    int tempBaseDistance = a->baseDistance;
    int tempPricePerBedRoom = a->pricePerBedRoom;
    
    
     
     a->streetName =  b->streetName;
     a->streetNumber= b->streetNumber;
     a->numberOfBedrooms = b->numberOfBedrooms; 
     a->baseDistance =  b->baseDistance;
     a->pricePerBedRoom = b->pricePerBedRoom;
     
     
    b->streetName = tempStreetName;
     b->streetNumber = tempStreetNumber;
     b->numberOfBedrooms = tempNumberOfBedrroms;
      b->baseDistance = tempBaseDistance;
     b->pricePerBedRoom = tempPricePerBedRoom;
}


/*
The sorting function is not working well we will need to change the code, i just put it because it took me alot just to try to get the linked list
to get swaped i was not able to change the values, so anyways once i was able to swaped the values i cheacked i saw that the sorting was not working good.
*/	
	
void sortByNumberOfBedRooms( info* sort)
{    
     int boolean=0; 
     info *temp =sort;  
 
    do
    {
        while (temp->pNext != NULL){   
            if(temp->numberOfBedrooms > temp->pNext->numberOfBedrooms)
            {  
                 swap(temp, temp->pNext);                 
                 boolean=0;              
            }            
            else             
            boolean=1;  
            
            temp = temp->pNext;            
        }
    }while (boolean=0);  
    }


		
		
		
		
}
