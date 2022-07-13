#include<stdio.h>
#include<stdlib.h>
#include"moviedetails.c"
#include"decleration.c"
#include<string.h>

struct moviedetails person[300];
int count=0,len;
char str[30];
int id2=1000;
int main()
{
	int **seat,choice,price=500,selection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;
			case 3:
				selection=movie();
				reservation(seat[selection-1],price,selection);
				count++;
				break;
			case 4:
				selection=cmovie();
				cancel(seat[selection-1]);
				break;
			case 5:
				x=5;
				break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}
int changeprize(int prize)
{
	char pass[10],pak[10]="pass";
	printf("Enter the password to change price of ticket: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&prize);
		system("PAUSE");
		system("CLS");
	}
	else
		printf("The entered password is wrong!");
	return prize;
}
void reservation(int *array,int price,int selection)
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("*\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please Enter your Name : ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("Please Enter your Mobile Number: ");
		jump1:
		scanf("%s",&person[count].phone);	

		int len=strlen(person[count].phone);

		if(len>10 || len<10)
		{
		printf("\n Invalid Mobile Number, Please input valid number.....\n");
		goto jump1;
		}

		printf("Which seat number you want : ");
		jump2:
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				goto jump2;
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				goto jump2;
			}
		else
		{
			array[j]=1;
		person[count].seat=j;
		if (selection==1)
			ticket1(j,person[count].name,id2,price);
		else if (selection==2)
			ticket2(j,person[count].name,id2,price);
		else if(selection==3)
			ticket3(j,person[count].name,id2,price);
		id2++;
		}		
}
int choice1(void)
{
	int choice;
	printf(" _____________________  WELCOME TO MULTIPLEX _______________________\n");
	printf("        --------------- Movie Ticket Booking ---------------        \n");
	printf(" ----------------------------------------------------------------- \n");
	printf("               1- To edit price of ticket (only admin):             \n");
	printf("               2- To view reserved tickets (only admin):            \n");
	printf("               3- To purchase ticket:                                \n");
	printf("               4- To cancel the seat:                               \n");
	printf("               5- Exit system:                                      \n");
	printf(" -----------------------------------------------------------------  \n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,stop=1;
	  printf("Please enter ID number of ticket: ");
	  jump1:
	  scanf("%d",&Cseat);
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat is %d cancelled.\n",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  {
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
			goto jump1;
	  }
}
void ticket1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t------------------------- MOVIE TICKET -------------------------\n");
        printf("\t-----------------------------------------------------------------\n");
        printf("\t Booking ID : %d \t\t\tShow Name : PAVANKHIND\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 29-06-2022\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No  : %d  \n",choice);
        printf("\t                                              price     : %d  \n\n",price);
		person[count].id=id2;
        printf("\t-----------------------------------------------------------------\n");
        return;
}
void details(void)
{
	int i;
	char pass[10],pak[10]="pass";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");

}
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for PAVANKHIND\n\n");
	printf("\t\t\tpress 2 for PUSHPA\n\n");
	printf("\t\t\tpress 3 for SPIDER-MAN - NO WAY HOME\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t------------------------- MOVIE TICKET -------------------------\n");
        printf("\t-----------------------------------------------------------------\n");
        printf("\t Booking ID : %d \t\t\tShow Name : PUSHPA\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 29-06-2022\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No  : %d  \n",choice);
        printf("\t                                              price     : %d  \n\n",price);
        person[count].id=id2;
        printf("\t-----------------------------------------------------------------\n");
        return;
}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for PAVANKHIND\n\n");
	printf("\t\t\tpress 2 for PUSHPA\n\n");
	printf("\t\t\tpress 3 for SPIDER-MAN - NO WAY HOME\n");
	scanf("%d",&i);
	return i;
}
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t------------------------- MOVIE TICKET -------------------------n");
        printf("\t-----------------------------------------------------------------\n");
        printf("\t Booking ID : %d \t\t\tShow Name : SPIDER-MAN - NO WAY HOME \n",id2);
        printf("\t Customer   : %s\n",name);
        printf("\t\t\t                              Date      : 29-06-2022\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price     : %d  \n\n",price);
        person[count].id=id2;
        printf("\t-----------------------------------------------------------------\n");
        return;
}