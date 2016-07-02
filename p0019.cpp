#include <iostream>

using namespace std;

bool determineLeap(int);
int calcSun(int, int);
void setNextDay(int, int&);
int calcSunInAYear(int nextday, int yr);
int main()
{
    int sumSunDay = 0;
    int nextDay = 2;
    int i;
    int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int notLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int leapFirstDays[12] = {1};
    int notleapFirstDays[12] = {1};

    for(i = 1; i < 12; i++){
        leapFirstDays[i] = 1 + leap[i - 1];
        leapFirstDays[i] = 7;
        notleapFirstDays[i] = 1 + notLeap[i - 1];
        notleapFirstDays[i] %= 7;
    }

    // cout << "year -- leap -- FD -- SD" << endl;
    for(int yr = 1901; yr <= 2000; yr++){
        sumSunDay += calcSun(nextDay, yr);
        /*cout << yr << " --  " << determineLeap(yr)
             << "  --  " << nextDay
             << " -- " << calcSun(nextDay, yr)
             << "  " << sumSunDay << endl;
        */

        setNextDay(yr, nextDay);
    }

    cout << sumSunDay << endl;

    return 0;
}

int calcSun(int firstDay, int yr){
    int sundays = 0;
    if (firstDay == 7){
        sundays++;
    }
    int notLeap[7] = {};
    if (determineLeap(yr) == false) {
        switch(firstDay){
            case 7: sundays += 1;
                    break;
            case 6: sundays += 1;
                    break;
            case 5: sundays += 1;
                    break;
            case 4: sundays += 3;
                    break;
            case 3: sundays += 1;
                    break;
            case 2: sundays += 2;
                    break;
            case 1: sundays += 2;
                    break;
        }
    } else {
        switch(firstDay){
            case 7: sundays += 2;
                    break;
            case 6: sundays += 1;
                    break;
            case 5: sundays += 1;
                    break;
            case 4: sundays += 2;
                    break;
            case 3: sundays += 2;
                    break;
            case 2: sundays += 1;
                    break;
            case 1: sundays += 2;
                    break;
        }
    }
    return sundays;
}

int calcSunInAYear(int nextday, int yr){
    int sun;
    if (nextday == 7){
        sun = 53;
    } else if (nextday == 6 && determineLeap(yr) == true){
        sun = 53;
    } else {
        sun = 52;
    }
    return sun;
}
void setNextDay(int yr, int &nextday){
    if (!determineLeap(yr)){
        if (nextday == 7){
            nextday = 0;
        }
        nextday++;
    } else {
        if (nextday == 6){
            nextday = -1;
        } else if (nextday == 7){
            nextday = 0;
        }
        nextday += 2;
    }
}
bool determineLeap(int yr){
    bool leap = true;

    if(yr % 400 == 0){
        leap = true;
    } else if (yr % 100 == 0){
        leap = false;
    } else if (yr % 4 == 0){
        leap = true;
    } else {
        leap = false;
    }

    return leap;
}
