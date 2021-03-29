#include<stdio.h>
#include<stdbool.h>

unsigned int convertTimeToEpoch(char *dateTime);
int days(int,int,int,int,int,int);
int month(int,int);
bool isleapyear(int);

unsigned int convertTimeToEpoch(char* dateTime)
{
    int char2num(char);
    int i,y=0,m=0,d,h,min,sec,day;
    unsigned int time;

    d = char2num(dateTime[0])*10 + char2num(dateTime[1]);
    m = char2num(dateTime[3])*10 + char2num(dateTime[4]);
    y = char2num(dateTime[6])*1000 + char2num(dateTime[7])*100
        + char2num(dateTime[8])*10 + char2num(dateTime[9]);
    h = char2num(dateTime[11])*10 + char2num(dateTime[12]);
    min = char2num(dateTime[14])*10 + char2num(dateTime[15]);
    sec = char2num(dateTime[17])*10 + char2num(dateTime[18]);
    day = days(1970,y,1,m,1,d);

    time = ((day*24 + h) * 60 + min) * 60 + sec;

    return time;
}

int days(int y1,int y2,int m1,int m2,int d1,int d2)
{
    int count = 0, i;

    for(i = y1; i < y2; i++) {
        if(isleapyear(i))
            count += 366;
        else
            count += 365;
    }

    count -= month(m1,y1);
    count -= d1;
    count += month(m2,y2);
    count += d2;

    if (count < 0)
        count = count*-1;

    return count;
}

int month(int a,int yy)
{
    int x=0,c;
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    for(c = 0; c < a-1; c++) {
        if(c == 1) {
            if(isleapyear(yy))
                x+=29;
            else
                x+=28;
            }
        else
            x+=mon[c];
    }

    return(x);
}

bool isleapyear(int year)
{
    bool i;

    if ( year%400 == 0)
        i=true;
    else if ( year%100 == 0)
        i=false;
    else if ( year%4 == 0 )
        i=true;
    else
        i=false;
    return i;
}

int char2num(char c)
{
    int i;
    i = (int) c-48;
    return i;
}

void main()
{
    char dtArr[19];
    char *dateTime;
    unsigned int epoc;

    dateTime = dtArr;
    printf("\nEnter Date time as(DD/MM/YYYY HH:MM:SS)");
    scanf(" %[^\n]s",dtArr);
    epoc = convertTimeToEpoch(dateTime);
    printf("\nepoc time:%d\n",epoc);
}

