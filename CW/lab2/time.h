//

class Time {
    private:
        int hour, minute, second;


    public:
        Time();
        Time(int ahour, int aminute, int asecond);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;

        void setHour(int s_hour);
        void setMinute(int s_minute);
        void setSecond(int s_second);

        void PrintAMPM() const; 

};

bool IsEarlierThan(const Time& t1, const Time& t2);