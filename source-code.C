#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int no(int d,int m,int y);

char *dayName(int day);

typedef struct
{
	int day;
	int month;
	int year;
	char note[255];
}Note;

int isLeapYear(int y);
int leapYears(int y);
int todayOf(int y,int m,int d);
long days(int y,int m,int d);
void calender(int m,int y,int d1,int m1,int y1,char *note);

void main()
{
	int year,month,day,ch;
	Note note1;
	clrscr();
	while(1)
	{
		printf("1.Find the day\n2.Print calender of the month\n3.Add note\n4.Exit\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the day,month,year:");
				scanf("%d %d %d",&day,&month,&year);
				printf("The day is:%s\n",dayName(no(day,month,year)));
				break;
			
case 2: printf("Enter month and year:");
				scanf("%d %d",&month,&year);
				printf("Enter 'n'to see the notes\nEnter any key to continue:");
						calender(month,year,note1.day,note1.month,note1.year,note1.note);
				break;
			
case 3: printf("Enter day,month,year:");
scanf("%d %d %d",&note1.day,&note1.month,&note1.year);
				printf("Enter the note:");
				scanf("%s",&note1.note);
				printf(“Note added successfully.\n”);
				break;

			case 4: exit(0);
				break;

			default:printf("Not a valid entry\n");
				break;
		}
	}

}

int no(int d,int m,int y)
{
	static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
	y-=m<3;
	return((y+y/4-y/100+y/400+t[m-1]+d)%7);
}

char *dayName(int day)
{
	switch(day)
	{
		case 0:return("Sunday");
		case 1:return("Monday");
		case 2:return("Tuesday");
		case 3:return("Wednesday");
		case 4:return("Thrusday");
		case 5:return("Friday");
		case 6:return("Saturday");
		default:return("Error:Invalid arguments passed...\n");
	}
}

int isLeapYear(int y)
{
	return((y%400==0)||((y%4==0)&&(y%100!=0)));
}

int leapYears(int y)
{
	return(y/4-y/100+y/400);
}

int todayOf(int y,int m,int d)
{
	static int dom[]={-1,0,31,59,90,120,151,181,212,243,273,304,334};
	return(dom[m]+d+((m>2&&isLeapYear(y))?1:0));
}

long days(int y,int m,int d)
{
	int lastYear;
	lastYear=y-1;
	return(365L*lastYear+leapYears(lastYear)+todayOf(y,m,d));
}

void calender(int m,int y,int d1,int m1,int y1,char *note)
{
	const char *nom[]={NULL,"January","February","March","April","May","June","July","August","September","October","November","December"};
	char week[]="  Sun  Mon  Tue  Wed  Thu  Fri  Sat";
	char ch;
	int dom[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
	int w,i,day,hasNote;
	w=(days(y,m,1))%7;
	if(isLeapYear(y))
		dom[2]=29 ;
	printf("\n          %s  %d\n%s\n",nom[m],y,week);
	for(i=0;i<w;i++)
		printf("     ");
	
for(i=w,day=1;day<=dom[m];i++,day++)
	{
		if((y1==y)&&(m1==m))
		{
			if(d1==day)
			{
				printf(" |%2d|",day);
			}
			
else
			{
				printf("%5d",day);
			}
		}
		
else
		{
			printf("%5d",day);
		}
		
if(i%7==6)
			printf("\n");
	}
	
printf("\n");
	scanf("\n%c",&ch);
	if(ch=='n')
	{
		if(note!='\0')
		{
			printf("Here are list of notes for %d %d\n",m,y);
			printf("%d:",d1);
			
while(*note!='\0')
			{
				printf("%c",*note);
				note++;
			}
			
printf("\n");
		}
		
else
		{
			printf("No notes to display!!!");
		}
	}
	
else
		return;
}
