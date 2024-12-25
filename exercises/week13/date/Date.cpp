#include "Date.h"
#include <string>


using namespace std;

Date::Date(){
    m_month = 1;
    m_day = 1;
    m_year = 2024;

}

Date::Date(int mon, int day, int year){
    
    m_month = mon;
    m_day = day;
    m_year = year;
}


bool Date:: changeDate(int mon, int day, int year){

    if(mon >= 4 && day >= 1 && year >= 2024){
        m_month = mon;
        m_day = day;
        m_year = year;
        return true;
    }

    return false;
}

string Date:: getDate(){

    string dateStr;
    string day = to_string(m_day);
    string month = to_string(m_month);
    string year = to_string(m_year);

    dateStr = month +'/'+ day +'/'+ year;

    return dateStr;
}

Date::~Date(){

}