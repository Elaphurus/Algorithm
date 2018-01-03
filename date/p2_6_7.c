/*
date

the difference between two date
input1:
20110412
20110422
output2:
11

day of weak
input2:
9 October 2001
14 October 2001
output2:
Tuesday
Sunday
*/
#include <stdio.h>
#include <math.h>

#include <string.h>

// macro for test leap year
#define ISLEAP(x) x%100!=0 && x%4==0 || x%400==0 ? 1 : 0
int dayOfMonth[13][2] = {
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
struct Date {
	int day;
	int month;
	int year;
};
void nextDay(struct Date* date) {
	date->day++;
	if(date->day > dayOfMonth[date->month][ISLEAP(date->year)]) {
		date->day = 1;
		date->month++;
		if(date->month > 12) {
			date->month = 1;
			date->year++;
		}
	}
}
int buf[3001][13][32]; // save pre-treated date, must be global, or will cause stack overflow

char monthName[13][20] = {
	"",
	"January",
	"Februray",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
char weekName[7][20] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thurday",
	"Friday",
	"Saturday"
};

int main() {
	struct Date date;
	int cnt = 0;

	int d1, m1, y1;
	int d2, m2, y2;
/*
	int d, m, y;
	char s[20];
	int days;
*/
	date.day = 1;
	date.month = 1;
	date.year = 1000;
	while(date.year <= 3000 && date.year >= 1000) {
		printf("%4d%2d%2d - %d\n", date.year, date.month, date.day, cnt);
		buf[date.year][date.month][date.day] = cnt;
		nextDay(&date);
		cnt++;
	}

	while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		printf("%d\n", abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1);
	}
/*
	while(scanf("%d%s%d", &d, s, &y) != EOF) {
		for(m = 1; m <= 12; m++) {
			if(strcmp(s, monthName[m]) == 0) {
				break;
			}
		}
		days = buf[y][m][d] - buf[2018][1][1] + 1; // 2018.1.1 Monday
		puts(weekName[(days % 7 + 7) % 7]);
	}
*/
	return 0;
}