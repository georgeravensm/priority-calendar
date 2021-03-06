#include <iostream>
#include <string>
#include<fstream>
#include "event.h"
#include "derivecalendar.h"
#include "calendar.h"
using namespace std;

void todo(){
  int placeholder = 0;
}
void prioritzer(){
  int fm, fd, fy, counter;
  int month, day, year, imp, daysLeft;
  string Type, name, attribute;
  Assignment a;
  Holiday h;
  Birthday b;
  Meeting m;
  Test t;
  Errand e;
  Calendar c;
  Eventlist list;

  cout << "Enter today's month, day and year (numerical): " << endl;
  cin >> month;
  cin >> day;
  cin >> year;

  char yesno = 'y';
  while (yesno == 'y' || yesno == 'Y'){
    cout << "Import event from file?(y/n)" << endl;
    cin >> yesno;
    if (yesno == 'y' || yesno == 'Y'){
      ifstream file;
      file.open("events.txt");
      if(file.is_open()){
        int size;
        cout << "How Many events are on the file?" << endl;
        cin >> size;
        for(int i=0; i<size; i++){
          file >> name >> Type >> fm >> fd >> fy >> attribute;
          if (Type == "Holiday" || Type == "holiday" || Type == "h"){
            h.setFestivity(attribute);
            h.setName(name);
            h.setType(Type);
            h.setMonth(fm);
            h.setDay(fd);
            h.setYear(fy);
            daysLeft = amountofDays(month, day, year, h.getMonth(), h.getDay(), h.getYear(), 0);
            imp = importanceLevel(daysLeft, h.getType());
            list.insert(h.getName(), h.getType(), imp, daysLeft, h.getFestivity());
          }
          else if(Type == "Test" || Type == "test" || Type == "t"){
            t.setSubject(attribute);
            t.setName(name);
            t.setType(Type);
            t.setMonth(fm);
            t.setDay(fd);
            t.setYear(fy);
            daysLeft = amountofDays(month, day, year, t.getMonth(), t.getDay(), t.getYear(), 0);
            imp = importanceLevel(daysLeft, t.getType());
            list.insert(t.getName(), t.getType(), imp, daysLeft, t.getSubject());
          }
          else if(Type == "Assignment" || Type == "assignment" || Type == "a"){
            a.setSubject(attribute);
            a.setName(name);
            a.setType(Type);
            a.setMonth(fm);
            a.setDay(fd);
            a.setYear(fy);
            daysLeft = amountofDays(month, day, year, a.getMonth(), a.getDay(), a.getYear(), 0);
            imp = importanceLevel(daysLeft, a.getType());
            list.insert(h.getName(), a.getType(), imp, daysLeft, a.getSubject());
          }
          else if(Type == "meeting" || Type == "Meeting" || Type== "m"){
            m.setGroup(attribute);
            m.setName(name);
            m.setType(Type);
            m.setMonth(fm);
            m.setDay(fd);
            m.setYear(fy);
            daysLeft = amountofDays(month, day, year, m.getMonth(), m.getDay(), m.getYear(), 0);
            imp = importanceLevel(daysLeft, m.getType());
            list.insert(m.getName(), m.getType(), imp, daysLeft, m.getGroup());
          }
          else if(Type == "errand" || Type == "Errand" || Type == "e"){
            e.setType(attribute);
            e.setName(name);
            e.setType(Type);
            e.setMonth(fm);
            e.setDay(fd);
            e.setYear(fy);
            daysLeft = amountofDays(month, day, year, e.getMonth(), e.getDay(), e.getYear(), 0);
            imp = importanceLevel(daysLeft, e.getType());
            list.insert(e.getName(), e.getType(), imp, daysLeft, e.getTypee());
          }
          else if(Type == "Birthday" || Type == "birthday" || Type == "b"){
            b.setAge(attribute);
            b.setName(name);
            b.setType(Type);
            b.setMonth(fm);
            b.setDay(fd);
            b.setYear(fy);
            daysLeft = amountofDays(month, day, year, b.getMonth(), b.getDay(), b.getYear(), 0);
            imp = importanceLevel(daysLeft, b.getType());
            list.insert(b.getName(), b.getType(), imp, daysLeft, b.getAge());
          }
      }
      file.close();
      }
    }else{
      cout << "What is the name of the event: " << endl;
      cin.ignore();
      getline(cin, name);
      cout << "What type of event is it? (Holiday, Birthday, Assignment, Test, Meeting, Errand): " << endl;
      getline(cin, Type);
      cout << "Enter Event month day and year: " << endl;
      cin >> fm;
      cin >> fd;
      cin >> fy;
      cout<<"check 1" << endl;
      if (Type == "Holiday" || Type == "holiday" || Type == "h"){
        cout << "Enter Holiday Festivity"<< endl;;
        cin.ignore();
        getline(cin, attribute);
        h.setFestivity(attribute);
          }
      else if(Type == "Test" || Type == "test" || Type == "t"){
        cout << "Enter Test Subject"<< endl;;
        cin.ignore();
        getline(cin, attribute);
        t.setSubject(attribute);
      }
      else if(Type == "Assignment" || Type == "assignment" || Type == "a"){
        cout << "Enter Subject of Assignment"<< endl;;
        cin.ignore();
        getline(cin, attribute);
        a.setSubject(attribute);
      }
      else if(Type == "meeting" || Type == "Meeting" || Type== "m"){
        cout << "Enter Group you are meeting with"<< endl;;
        cin.ignore();
        getline(cin, attribute);
        m.setGroup(attribute);
      }
      else if(Type == "errand" || Type == "Errand" || Type == "e"){
        cout << "Enter Type of Errand" << endl;
        cin.ignore();
        getline(cin, attribute);
        e.setType(attribute);
      }
      else if(Type == "Birthday" || Type == "birthday" || Type == "b"){
        cout << "Enter Age they/you are turning"<< endl;;
        cin.ignore();
        getline(cin, attribute);
        b.setAge(attribute);
      }
      daysLeft = amountofDays(month, day, year, fm, fd, fy, 0);
      imp = importanceLevel(daysLeft, Type);
      list.insertNode(name, Type, imp, daysLeft, attribute);
    }
    cout << "Enter another event? (y/n)" << endl;
    cin >> yesno;
  }
  cout << endl << endl << "YOUR PRIORITY LIST:" << endl;
  list.displayList();
  list.fileoNode();
}

int importanceLevel(int daysL, string TypeofEvent){
  int importance;
  if(TypeofEvent == "Test" || TypeofEvent == "test" || TypeofEvent == "t"){
    importance = 5;
  }
  if(TypeofEvent == "Assignment" || TypeofEvent == "assignment" || TypeofEvent == "a"){
    importance = 4;
  }
  if(TypeofEvent == "meeting" || TypeofEvent == "Meeting" || TypeofEvent == "m"){
    importance = 4;
  }
  if(TypeofEvent == "errand" || TypeofEvent == "Errand" || TypeofEvent == "e"){
    importance = 3;
  }
  if(TypeofEvent == "Birthday" || TypeofEvent == "birthday" || TypeofEvent == "b"){
      importance = 2;
  }
  if(TypeofEvent == "Holiday" || TypeofEvent == "holiday" || TypeofEvent == "h"){
    importance = 1;
  }

  if(daysL > 30){
    importance = importance + 1;
  }
  if(daysL > 21 && daysL <= 30){
    importance = importance + 2;
  }
  if(daysL > 14 && daysL <= 21){
    importance = importance + 3;
  }
  if(daysL > 7 && daysL <= 14){
    importance = importance + 4;
  }
  if(daysL >= 0 && daysL <= 7){
    importance = importance + 5;
  }

  return importance;
}

int amountofDays(int m, int d, int y, int fm, int fd, int fy, int counter){
  //If the day is the same as the day of the event, RETURN THE AMOUNT OF DAYS BETWEEN
  if(fm == m && fd == d && fy == y){
    return counter;
  }
  //INCREMENT THE DAY AND AMOUNT OF DAYS UNTIL THE EVENT
  d++;
  counter++;
  //(LEAP YEAR) CHECKS DAY ACCORDING TO MAKE SURE THE DAY RESTARTS IF REACHES OUT OF MONTH
  if(y % 4 == 0){
    if (m == 2)
      if (d == 30){
        m++;
        d = 1;
      }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
      if (d == 32){
        m++; 
        d = 1;
      }
    if (m == 4 || m == 6 || m == 9 || m == 11)
      if (d == 31){
        m++;
        d = 1;
      }
  }else{
    if (m == 2)
      if (d == 29){
        m++;
        d = 1;
      }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
      if (d == 32){
        m++; 
        d = 1;
      }
    if (m == 4 || m == 6 || m == 9 || m == 11)
      if (d == 31){
        m++;
        d = 1;
      }
  }
  return amountofDays(m, d, y, fm, fd, fy,counter);
}

Event::Event(){
  front = nullptr;
  rear = nullptr;
  numItems = 0;
}

Event::~Event(){
  clear();
}

void Event::enqueue(string n, string t, int i, int d, string ea){
  QueueNode *newNode = nullptr;

  newNode = new QueueNode;
  newNode->name = n;
  newNode->importance = i;
  newNode->Type = t;
  newNode->days = d;
  newNode->eventAtrribute = ea;
  newNode->next = nullptr;

  if(isEmpty()){
    front = newNode;
    rear = newNode;
  }
  else{
    rear->next=newNode;
    rear = newNode;
  }
  numItems++;
}

void Event::dequeue(string &n, string &t, int &i, int &d, string &ea){
  QueueNode *temp = nullptr;
  if (isEmpty()){
    cout << "The queue is empty" << endl;
  }
  else{
    n = front->name;
    t = front->Type;
    i = front->importance;
    d = front->days;
    ea = front->eventAtrribute;
    temp = front;
    front = front->next;
    delete temp;
    numItems -= 1;
  }
}

void Event::clear(){
  string value, value2, value5;
  int value3, value4;
  while(!isEmpty()){
    dequeue(value, value2, value3, value4, value5);
  }
}

bool Event::isEmpty() const{
  bool status;
  if(numItems >0){
    status = false;
  }
  else{
    status = true;
  }
  return status;
}

