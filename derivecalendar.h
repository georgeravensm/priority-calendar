#ifndef DERIVECALENDAR_H
#define DERIVECALENDAR_H
#include "calendar.h"


class Assignment : public Calendar {
  private:
    string subject;
  public:
    Assignment(){
      subject = "";
    }

    Assignment(string s){
      subject = s;
    }

    void setSubject(string s)
    {subject = s;}

    string getSubject() const
    {return subject;}

};

class Holiday : public Calendar {
  private:
    string festivity;
  public:
    Holiday(){
      festivity = "";
    }

    Holiday(string s){
      festivity = s;
    }

    void setFestivity(string s)
    {festivity = s;}

    string getFestivity() const
    {return festivity;}

};

class Birthday : public Calendar {
  private:
    string age;
  public:
    Birthday(){
      age = " ";
    }

    Birthday(string s){
      age = s;
    }

    void setAge(string s)
    {age = s;}

    string getAge() const
    {return age;}

};

class Test : public Calendar {
  private:
    string subject;
  public:
    Test(){
      subject = "";
    }

    Test(string s){
      subject = s;
    }

    void setSubject(string s)
    {subject = s;}

    string getSubject() const
    {return subject;}

};

class Errand : public Calendar {
  private:
    string type;
  public:
    Errand(){
      type = "";
    }

    Errand(string s){
      type = s;
    }

    void setType(string s)
    {type = s;}

    string getType() const
    {return type;}

};

class Meeting : public Calendar {
  private:
    string group;
  public:
    Meeting(){
      group = "";
    }

    Meeting(string s){
      group = s;
    }

    void setGroup(string s)
    {group = s;}

    string getGroup() const
    {return group;}

};

#endif
