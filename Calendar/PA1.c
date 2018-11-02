/* PA1.c -- Kamil Gumienny*/

#include <stdio.h>

int testLeap(int year){
	if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
		return 1;
	else 
		return 0;
}

int printMonthName(int year, int month){
	int isLeap = testLeap(year);
	switch(month){
		case 0:
			printf("January %d \n\n", year);
			return 31;
		case 1:
			printf("February %d \n\n", year);
			if(isLeap == 1)
				return 29;
			else
				return 28;
		case 2:
			printf("March %d \n\n", year);
			return 31;
		case 3:
			printf("April %d \n\n", year);
			return 30;
		case 4:
			printf("May %d \n\n", year);
			return 31;
		case 5:
			printf("June %d \n\n", year);
			return 30;
		case 6:
			printf("July %d \n\n", year);
			return 31;
		case 7:
			printf("August %d \n\n", year);
			return 31;
		case 8:
			printf("September %d \n\n", year);
			return 30;
		case 9:
			printf("October %d \n\n", year);
			return 31;
		case 10:
			printf("November %d \n\n", year);
			return 30;
		case 11:
			printf("December %d \n\n", year);
			return 31;
		}
		
	return 0;
}



int printMonth(int firstDay, int month, int year){
	int numberOfDays = printMonthName(year, month);
	int firstDayOfNextMonth;
	int tracker = 1;
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	for(int i=0; i < numberOfDays; i++){
		/* The loop invariant in this loop is: 
			i >= 0 && i< days in the month
		*/
		if(i < firstDay && i==0)
			for(int weekDay = 0; weekDay < firstDay; weekDay++){
			/* The loop invariant in this loop is 	 
				weekday >= 0 && weekday < firstDay
			*/
				if(weekDay==0)
					printf("   ");
				else
					printf("     ");
				tracker++;
			}
		

		if(((tracker-1)%7 == 0 && i != 0) || (i==0 && firstDay==0))
			printf("%3d", i+1);
		else
			printf("%5d", i+1);

		if(tracker != 0 && tracker % 7 == 0)
			printf("\n");

	firstDayOfNextMonth = (((i+1)+firstDay)%7);
	tracker++;
	}
	
	printf("\n\n");
	return firstDayOfNextMonth;

}


void printCalendar(int year, int firstDay){
	printf("  ***      CALENDAR for %d     ***\n\n", year);
	int lastDayOfMonth = firstDay;
	for(int month=0; month<12; month++){
		/* The loop invariant is 
			month>=0 && month < 12 
		*/
		lastDayOfMonth = printMonth(lastDayOfMonth, month, year);
	}
}


int calculateFirstDay(int year){
	int centuryNumber = year/100;
	int yearNumber = (year%100)-1;
	int firstDay = ((1+(((13*11)-1)/5)) + yearNumber + (yearNumber/4) + 
(centuryNumber/4)) - 2*centuryNumber;
	if(firstDay < 0)
		firstDay *= -1;
	return firstDay%7;
}



int main(){
	int year;
	printf("Please enter year for this calendar:- "); 
	scanf("%d", &year);
	if(year < 0){
		printf("Invalid year. Please enter a non negative year");
		main();
	}
	int firstDay = calculateFirstDay(year);
	printCalendar(year, firstDay);


	return 0;
	

}
