// 基姆拉尔森计算公式（根据年月日计算是星期几）
// W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
// 注意m == 1 || m == 2时月份+12，年份-1
// 题目难度较大
// 代码源于网上，详情见注释
#include <iostream>
#include <stdlib.h>

using namespace std;

int calendar[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

class Date {
public:
    int year;
    int month;
    int day;

    // 构造函数
    Date() {
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    // 获得下一天
    Date getNextday() {
        Date nextday(year, month, day);

        int leapResult;
        if (isLeap()) leapResult = 1;
        else leapResult = 0;

        if (day < calendar[leapResult][month]) nextday.day++; // 下一天在当月
        else { // 下一天在下一月
            if (month < 12) {
                nextday.month++;
                nextday.day = 1;
            } else { // 下一天在下一年
                nextday.year++;
                nextday.month = 1;
                nextday.day = 1;
            }
        }
        return nextday;
    }

    // 闰年判断
    bool isLeap() {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
        else return false;
    }

    /**交易日判断
     * 要求：
     * 1.非周末
     * 2.非节假日（元旦、五一、十一）
     */
    bool isDealDay() {
        if (isWeekend()) return false;
        else if (isHoliday()) return false;
        else return true;
    }

    // 周末判断
    bool isWeekend() {
        int y = year, m = month, d = day;
        if (m == 1 || m == 2) {
            y--;
            m += 12;
        }
        // 基姆拉尔森计算公式，可根据日期计算这一天是星期几
        int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1; // 注意求余后加1
        if (week > 5) return true;
        else return false;
    }

    // 节假日判断
    bool isHoliday() {
        if (month == 1 && day == 1 || month == 5 && day >= 1 && day <= 3 || month == 10 && day >= 1 && day <= 7)
            return true;
        else return false;
    }

    // 计算一年的交易日
    int calDealDay() {
        // 一年的周末
        // 364 = 7 * 52：一年有52个整周，剩余的一或两天由平闰年决定
        // 平年判断12.30 12.31是否周末，闰年判断12.31
        int dd = 104, totalDay;
        Date d1(year, 12, 30), d2(year, 12, 31);
        if (isLeap()) {
            if (d1.isWeekend()) dd++;
            if (d2.isWeekend()) dd++;
            totalDay = 366;
        } else {
            if (d2.isWeekend()) dd++;
            totalDay = 365;
        }
        // 一年的节假日
        if (!Date(year, 1, 1).isWeekend()) dd++;
        for (int i = 1; i < 4; i++) {
            if (!Date(year, 5, i).isWeekend()) dd++;
        }
        for (int i = 1; i < 8; i++) {
            if (!Date(year, 10, i).isWeekend()) dd++;
        }
        return totalDay - dd;
    }
};

// 两个日期是否相等
bool equals(Date d1, Date d2) {
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

int main() {
    int n;
    cin >> n;
    string s1[n], s2[n];
    for (int i = 0; i < n; i++) {
        // 输入时有空格会默认为两个字符串，所以设为s1 s2
        cin >> s1[i];
        cin >> s2[i];

        // 分离string（2010-11-18 2010-11-20）中的年月日
        string sy1, sy2, sm1, sm2, sd1, sd2;
        sy1 = s1[i].substr(0, 4);
        sm1 = s1[i].substr(5, 2);
        sd1 = s1[i].substr(8, 2);
        sy2 = s2[i].substr(0, 4);
        sm2 = s2[i].substr(5, 2);
        sd2 = s2[i].substr(8, 2);
        int y1, y2, m1, m2, d1, d2;
        y1 = atoi(sy1.c_str()); // string->int，加<stdlib.h>头文件
        m1 = atoi(sm1.c_str());
        d1 = atoi(sd1.c_str());
        y2 = atoi(sy2.c_str());
        m2 = atoi(sm2.c_str());
        d2 = atoi(sd2.c_str());

        Date date1(y1, m1, d1), date2(y2, m2, d2), di;
        int dayNum = 0; // 交易日

        // 判断是否同年
        if (y1 == y2) {
            for (di = date1; !equals(di, date2.getNextday()); di = di.getNextday()) {
                if (di.isDealDay()) dayNum++;
            }
        } else {
            // 不同年，计算d1到年底的交易日+一年的交易日（若有）+年初到对d2的交易日
            for (di = date1; !equals(di, Date(y1 + 1, 1, 1)); di = di.getNextday()) {
                if (di.isDealDay()) dayNum++;
            }
            for (int i = y1 + 1; i < y2; i++) {
                Date temp(i, 1, 1);
                dayNum += temp.calDealDay();
            }
            for (di = Date(y2, 1, 1); !equals(di, date2.getNextday()); di = di.getNextday()) {
                if (di.isDealDay()) dayNum++;
            }
        }
        cout << dayNum << endl;
    }
}

