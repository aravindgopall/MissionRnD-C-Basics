/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
int valid_date(int, int, int);
int isOlder(char *dob1, char *dob2) 
{
	int day1=0, day2=0, mon1=0, mon2, yea1, yea2, vali1, vali2;
	day1 = (((int)dob1[0]) - 48) * 10 + (int)dob1[1] - 48;;
	day2 = (((int)dob2[0])-48) * 10 + (int)dob2[1]-48;
	mon1 = (((int)dob1[3])-48) * 10 + (int)dob1[4]-48;
	mon2 = (((int)dob2[3])-48) * 10 + (int)dob2[4]-48;
	yea1= (((int)dob1[6])-48) * 1000 + (((int)dob1[7])-48) * 100 + (((int)dob1[8])-48) * 10 +((int)dob1[9])-48;
	yea2 = (((int)dob2[6])-48) * 1000 + (((int)dob2[7])-48) * 100 + (((int)dob2[8])-48) * 10 + ((int)dob2[9])-48;
	vali1 = valid_date(day1, mon1, yea1);
	vali2 = valid_date(day2, mon2, yea2);
	if (vali1 != 0 && vali2 != 0)
	{
		if (yea1 > yea2)
			return 2;
		else if (yea1 < yea2)
			return 1;
		else
		{
			if (mon1 > mon2)
				return 2;
			else if (mon1 < mon2)
				return 1;
			else
			{
				if (day1 > day2)
					return 2;
				else if (day1 < day2)
					return 1;
				else
					return 0;
			}

		}
			return 0;
	} 
	else
	   return -1;
}

int valid_date(int d, int m, int y)
{
	if (d>0 && m > 0 && m < 13 && y > 999 && y < 10000){
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
			if (d < 32)
				return 1;
			else
				return 0;
		}
		else if (m == 2)
		{
			if (y % 100 == 0 || y % 400 == 0 || y % 4 == 0)
			{
				if (d < 30)
					return 1;
				else
					return 0;
			}
			else
			{
				if (d < 29)
					return 1;
				else
					return 0;
			}
		}
		else
		{
			if (d < 31)
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}