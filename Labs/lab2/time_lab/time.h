class Time {
public:
    Time();
    Time(int aHour, int aMinute, int aSecond);
    // ACCESSORS
    int getMinute() const;
    int getHour() const;
    int getSecond() const;
    // MODIFIERS
    void setMinute(int aMinute);
    void setHour(int aHour);
    void setSecond(int aSecond);
    void PrintAmPm();
private:  // REPRESENTATION (member variables)
    int hour;
    int minute;
    int second;
};