#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int enumeratedYears;
int enumeratedMonths;
int enumeratedDays;
int error{ 0 };

bool isLeapYear(int year) //determine if the year is a leap year
{
	// Only valid on or after Thursday, September 14, 1752
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	else
		return true;
}

int enumerateMonths(int month, bool isLeapYear) // months into days into the year
{
	if (!isLeapYear) //if it is not a leap year
	{
		switch (month)
		{
		case 1: return 0;
		case 2: return 31;
		case 3: return 59;
		case 4: return 90;
		case 5: return 120;
		case 6: return 151;
		case 7: return 181;
		case 8: return 212;
		case 9: return 243;
		case 10: return 273;
		case 11: return 304;
		case 12: return 334;
		default: return 0;
		}
	}
	else // if it is a leap year
	{
		switch (month)
		{
		case 1: return 0;
		case 2: return 31;
		case 3: return 60;
		case 4: return 91;
		case 5: return 121;
		case 6: return 152;
		case 7: return 182;
		case 8: return 213;
		case 9: return 244;
		case 10: return 274;
		case 11: return 305;
		case 12: return 335;
		default: return 0;
		}
	}
}

int enumerateCurrentNegativeMonth(int month, bool bIsLeapYear) // months into days into the year
{
	if (!isLeapYear) //if it is not a leap year
	{
		switch (month)
		{
		case 1: return -31;
		case 2: return -28;
		case 3: return -31;
		case 4: return -30;
		case 5: return -31;
		case 6: return -30;
		case 7: return -31;
		case 8: return -31;
		case 9: return -30;
		case 10: return -31;
		case 11: return -30;
		case 12: return -31;

		}
	}
	else // if it is a leap year
	{
		switch (month)
		{
		case 1: return -31;
		case 2: return -29;
		case 3: return -31;
		case 4: return -30;
		case 5: return -31;
		case 6: return -30;
		case 7: return -31;
		case 8: return -31;
		case 9: return -30;
		case 10: return -31;
		case 11: return -30;
		case 12: return -31;

		}
	}
}

int enumerateNegativeMonth_1752(int month) // months into days into the year
{
	switch (month)
	{
	case 3: return -156;
	case 4: return -126;
	case 5: return -95;
	case 6: return -65;
	case 7: return -34;
	case 8: return -3;
	}
}

int enumerateNegativeMonth(int month, bool isLeapYear) // months into days into the year
{
	if (!isLeapYear) //if it is not a leap year
	{
		switch (month)
		{
		case 1: return -282;
		case 2: return -313;
		case 3: return -341; // If <25 only
		case 4: return -7;
		case 5: return -37;
		case 6: return -68;
		case 7: return -98;
		case 8: return -129;
		case 9: return -160;
		case 10: return -190;
		case 11: return -221;
		case 12: return -252;
		}
	}
	else // if it is a leap year
	{
		switch (month)
		{
		case 1: return -282;
		case 2: return -313;
		case 3: return -342; // If <25 only
		case 4: return -7;
		case 5: return -37;
		case 6: return -68;
		case 7: return -98;
		case 8: return -129;
		case 9: return -160;
		case 10: return -190;
		case 11: return -221;
		case 12: return -252;
		}
	}
}

// Calculate date enumeration 
int enumerateDate(int inputYear, int inputMonth, int inputDay)
{

	// Check to make sure the date is valid
	if (inputMonth > 12)
	{
		error = 3;
	}
	else if (inputDay > 31)
	{
		error = 4;
	}
	else if (inputMonth == 2 && inputDay > 29)
	{
		error = 4;
	}
	else if ((inputMonth == 4 || inputMonth == 6 || inputMonth == 9 || inputMonth == 11) && inputDay > 30)
	{
		error = 4;
	}

	// If it is a new style date (>= 14 Sept 1752)
	else if (inputYear > 1752 || (inputYear == 1752 && (inputMonth > 9 || (inputMonth == 9 && inputDay > 13))))
	{
		int numberOfYears = inputYear - 1753;

		// If is in 1752
		if (inputYear == 1752)
		{

			// If it is in September
			if (inputMonth == 9)
			{
				return (inputDay - 14);
			}
			// If it is in October
			else if (inputMonth == 10)
			{
				return (16 + inputDay);
			}
			// If it is in November
			else if (inputMonth == 11)
			{
				return (47 + inputDay);
			}
			// If it is in December
			else if (inputMonth == 12)
			{
				return (77 + inputDay);
			}
		}
		// If it is between 1 Jan 1753 and 31 Dec 1799 (take into account all leap days)
		else if (inputYear < 1800)
		{
			enumeratedYears = 109 + 365 * numberOfYears + numberOfYears / 4;
			return enumeratedYears + (enumerateMonths(inputMonth, isLeapYear(inputYear)) + inputDay - 1);
		}
		// If it is in the 19th century (remove a leap day for 1800)
		else if (inputYear < 1900)
		{
			enumeratedYears = 109 + 365 * numberOfYears + numberOfYears / 4 - 1;
			return enumeratedYears + (enumerateMonths(inputMonth, isLeapYear(inputYear)) + inputDay - 1);
		}
		// If it is in the 20th or 21st centuries (remove a leap day for 1900 but allow for 2000)
		else
		{
			enumeratedYears = 109 + 365 * numberOfYears + numberOfYears / 4 - 2;
			return enumeratedYears + (enumerateMonths(inputMonth, isLeapYear(inputYear)) + inputDay - 1);
		}
	}

	// If the date is in 1752 (the short year)
	if (inputYear == 1752 && (inputMonth < 9 || inputMonth == 9 && inputDay < 3))
	{
		// If it is in September
		if (inputMonth == 9)
		{
			// If it is the 2nd
			if (inputDay == 2)
			{
				return -1;
			}
			// If it is the 1st
			else if (inputDay == 1)
			{
				return -2;
			}
		}
		// If it is before September
		else
		{
			// If it is April - September
			if (inputMonth > 3)
			{
				return (enumerateNegativeMonth_1752(inputMonth) + enumerateCurrentNegativeMonth(inputMonth, false) + inputDay);
			}
			// If it is March
			else if (inputMonth == 3)
			{
				// If it is after the 25th (the new year and a very short 'month' of 7 days)
				if (inputDay >= 25)
				{
					return (-187 + inputDay);
				}
			}
		}
	}

	// If it is an old style date (1155 < x < 1752)
	else if (inputYear > 1154 && inputYear < 1752)
	{
		// Go back 161 days, plus 365 days per year before 1752, plus a leap day for each leap year before 1752
		enumeratedDays = -161 + ((1752 - inputYear) * 365) + ((1752 - inputYear) / 4);

		// If it is a leap year
		if (inputYear % 4 == 0)
		{
			// If it is the later half of March (new year)
			if (inputMonth == 3 && inputDay >= 25) // year change!
			{
				// Use short month calculation
				return (enumeratedDays - 26 + inputDay);
			}

			// Otherwise, use the leap-year lookup table to find the point back *through* that month and then add (go forward) the input day
			return enumeratedDays + enumerateNegativeMonth(inputMonth, true)
				- inputDay;
		}

		// If it isn't a leap year
		else
		{
			// If it is the latter half of March (new year)
			if (inputMonth == 3 && inputDay >= 25)
			{
				// Use short month calculation
				return (enumeratedDays - 26 + inputDay);
			}

			// Otherwise, use the non-leap-year lookup table to find the point back *through* that month and then add (go forward) the input day
			return enumeratedDays + enumerateNegativeMonth(inputMonth, false)
				- inputDay;
		}
	}

	// If before 1155
	else if (inputYear < 1155)
	{
		// Sorry, my calculator doesn't work pre 1155 yet
		error = 2;
	}

	// If something else went wrong that I didn't anticipate
	else
	{
		error = 1;
	}
}

[STAThread]
void Main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DateDistance::MyForm form;
	Application::Run(%form);
}

