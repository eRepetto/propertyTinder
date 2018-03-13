
// this version is getting really close to lab 4 still alot to do but getting closer



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
     
     while ( pInfo != NULL )
         {
         
             pInfo->streetName= infoArray[count].streetName;
             pInfo->streetNumber=(rand() % (200)+1);
             pInfo->numberOfBedrooms= (rand()% (4)+1);
             pInfo->baseDistance=(rand() % (4)+ 0.5); // This has to be fix is not ok
             pInfo->pricePerBedRoom =(rand() % (6)+2)*100; // this has to be fix
             
             
            //  printf("%d %s %d %d %d\n\n", pInfo->streetNumber, pInfo->streetName, pInfo->numberOfBedrooms, pInfo->pricePerBedRoom, pInfo->baseDistance );
            
             
              
             pInfo= pInfo->pNext;
         
         count++;
     }
 
 
 // now is only going to sort by street but if you comment sortByStreet and uncommented whatever of the other ones they will work as well
	
	
 
 //sortByNumberOfBedRooms(pProperty);
 //sortByRent(pProperty);
 
 sortByStreet(pProperty);
 
 
 
 
 pInfo = pProperty;
 
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
    //i was trying creating another struct like he said on the assignmet but just didn't work
    
    
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






compareByNumberOfBedRooms(info* pA, info* pB)
{    
     int diff = pA->numberOfBedrooms - pB->numberOfBedrooms;    
     if (diff == 0)
        diff = pA->pricePerBedRoom - pB->pricePerBedRoom;    
    return diff;      
}

void sortByNumberOfBedRooms( info* sort)
{    
     int boolean=0;      
     info *temp =sort;  
 
  
        
        //that number 10 will have to change and we need to add the number of the created nodes
        for (int i =0; i <10; i++){
        
        while (temp->pNext != NULL){         
            
            if(compareByNumberOfBedRooms(temp,temp->pNext)>0){               
                 swap(temp, temp->pNext);                 
                 boolean=0;              
            }            
            else             
            boolean=1;   
            temp = temp->pNext;            
        }  
            temp =sort;     
        }
    }






int compareByRent ( info* pA, info* pB)
{    
    int diff = pA->pricePerBedRoom - pB->pricePerBedRoom;    
    if (diff == 0)
        diff = pA->numberOfBedrooms - pB->numberOfBedrooms;    
    return diff;      
}

 void sortByRent( info* sort)
 {     
    info *temp =sort;
   
        
        //that number 10 will have to change and we need to add the number of the created nodes
        for (int i =0; i <10; i++){
        
        while (temp->pNext != NULL){         
            
            if(compareByRent(temp,temp->pNext)>0){               
                 swap(temp, temp->pNext);                 
                           
            }            
            else             
           
            temp = temp->pNext;            
        }  
            temp =sort;     
        }
   }






int compareByStreet(info* pA, info* pB)
{
    int diff = (strcmp(pA->streetName, pB->streetName ));    
    if (diff == 0)
        diff = pA->streetNumber - pB->streetNumber;    
    return diff;  
    
}

void sortByStreet( info* sort)
    
   {     
    info *temp =sort;
   
        
        //that number 10 will have to change and we need to add the number of the created nodes
        for (int i =0; i <10; i++){
        
        while (temp->pNext != NULL){         
            
            if(compareByStreet(temp,temp->pNext)>0){               
                 swap(temp, temp->pNext);                 
                           
            }            
            else             
           
            temp = temp->pNext;            
        }  
            temp =sort;     
        }
   }








void printList(info* array[], char *sortBy)
{    
    printf("\n%s", sortBy);
    printf("\t\t\t\t  # Rooms\tRent\n");
    printf("--------------------------  \t  -------    -------\n");
    
     for (int i = 0; i < 12; i++){
        printf("%2i %s",array[i]->streetNumber, array[i]->streetName);
        printf("\t\t\t\t%i\t %i\n", array[i]->numberOfBedrooms,array[i]->pricePerBedRoom);
    }    
}

