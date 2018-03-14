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
    float baseDistance;   // this has to be a float
    struct info *pNext;
        
}info ;

typedef struct node{
    
    info *pInfo;
    struct node *pNext;
    
}node;







void printList(info* sort, char *sortBy)
{    
    
    printf("\n%s\n", sortBy);
    printf("Address\t\t");
    printf("\t\t  # Rooms\tRent/Rooms\tDistance\n");
    printf("--------------------------  \t  -------       -------   \t-------\n");
    
     while(sort !=NULL){
        printf("%i %s",sort->streetNumber, sort->streetName);
        printf("\t\t\t\t%d\t %d \t\t%.2f\n", sort->numberOfBedrooms,sort->pricePerBedRoom, sort->baseDistance);
        
        sort= sort->pNext;
    }    
}


void swap(  info* a,  info* b )
{
    
    //i know there is another way to swap the nodes, i tried alot of things i honestly could't make it work
    //i was trying creating another struct like he said on the assignmet but just didn't work
    
    
   char* tempStreetName = a->streetName;
    int tempStreetNumber = a->streetNumber;
    int tempNumberOfBedrroms = a->numberOfBedrooms;
    float tempBaseDistance = a->baseDistance;
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






//descending order

float compareByNumberOfBedRooms(info* pA, info* pB)
{    
     float diff = pB->numberOfBedrooms- pA->numberOfBedrooms;    
     if (diff == 0)
        diff = pA->pricePerBedRoom - pB->pricePerBedRoom;    
    return diff;      
}

void sortByNumberOfBedRooms( info* sort)
{    
    char* message= "Sorted by Rooms   ";      
     info *temp =sort; 
        
        //that number 10 will have to change and we need to add the number of the created nodes
        for (int i =0; i <10; i++){
        
        while (temp->pNext != NULL){         
            
            if(compareByNumberOfBedRooms(temp,temp->pNext)>0){               
                 swap(temp, temp->pNext);                 
                               
            }            
            else             
             
            temp = temp->pNext;            
        }  
            temp =sort;     
        }
        
         printList(temp,message);
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
   char* message= "Sorted by Rent   ";
        
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
        
         printList(temp,message);
   }






int compareByStreet(info* pA, info* pB)
{
    int diff = (strcmp(pA->streetName, pB->streetName ));    
    if (diff == 0)
        diff = pA->streetNumber - pB->streetNumber;    
    return diff;  
    
}

void sortByStreet ( info* sort)
    
   {     
    info *temp =sort;
   
   char* message= " Sorted by street name";
        
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
        
        printList(temp,message);
        
   }







int compareByDistance(info* pA, info* pB)
{
    int diff = pA->baseDistance - pB->baseDistance;    
    if (diff == 0)
        diff = pA->streetNumber - pB->streetNumber;    
    return diff;  
    
}

void sortByDistance ( info* sort)
    
   {     
    info *temp =sort;
   
   char* message= " Sorted by distance";
        
        //that number 10 will have to change and we need to add the number of the created nodes
        for (int i =0; i <10; i++){
        
        while (temp->pNext != NULL){         
            
            if(compareByDistance(temp, temp->pNext)>0){               
                 swap(temp, temp->pNext);                 
                           
            }            
            else             
           
            temp = temp->pNext;            
        }  
            temp =sort;     
        }
        
        printList(temp,message);
        
   }



int main ()
{    
    int count=0;
    srand( time(NULL) );  
    
    info infoArray []={
        
        {"Elon Ave", 0, 0, 0,0, NULL},
        {"Dog St", 0, 0, 0,0, NULL},
        {"Sussex Dr.", 0, 0,0,0, NULL}, 
        {"Cat St", 0, 0, 0,0, NULL},
        {"Fish Lane", 0, 0, 0,0, NULL},
        {"Robin Road", 0, 0, 0,0, NULL},
        {"Tesla st", 0, 0, 0,0, NULL},
        {"C Road", 0, 0, 0,0, NULL},
        {"Maple St", 0, 0, 0,0, NULL},
        {"First Road", 0, 0, 0,0, NULL},
        {"Abbey Road", 0, 0, 0,0, NULL},
        {"Foxx St", 0, 0, 0,0, NULL},
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
             pInfo->baseDistance= (rand() % (4)+0.5); // This has to be fix is not ok
             pInfo->pricePerBedRoom =(rand() % (6)+2)*100; // this has to be fix
             
             
            //  printf("%d %s %d %d %d\n\n", pInfo->streetNumber, pInfo->streetName, pInfo->numberOfBedrooms, pInfo->pricePerBedRoom, pInfo->baseDistance );
            
             
              
             pInfo= pInfo->pNext;
         
         count++;
     }
 
 
 
 
 sortByNumberOfBedRooms(pProperty);
 //sortByRent(pProperty);
 //sortByDistance(pProperty);
 //sortByStreet(pProperty);
 
 
 
 
// pInfo = pProperty;
// 
// while ( pInfo != NULL )
// {
//  
//  printf("%d %s %d %d %d\n", pInfo->streetNumber, pInfo->streetName, pInfo->numberOfBedrooms, pInfo->pricePerBedRoom, pInfo->baseDistance );
//
//  pInfo= pInfo->pNext;
// 
// 
// }

    
    return 0;    
}






