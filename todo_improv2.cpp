#include<iostream>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<time.h>

using namespace std;

void gotoxy(int x, int y){
  COORD coord; 
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int hour = 0 ;
int minute = 0;
int seccond  = 0;

void Real_time(){
  time_t now = time(0);
  char* dt = ctime(&now);
  tm *lotm = localtime(&now);
  dt = asctime(lotm);
  int hour = lotm->tm_hour;
  int min = lotm->tm_min;
  int sec = lotm->tm_sec;

  while (hour>0|| min >0||sec >0)
  {
    gotoxy(50,2);
    cout<<hour<<":"<<min<<":"<<sec<<"\n";

    Sleep(1000);
    sec++;
    if (sec>59)
    {
       sec=0;
       min++;


    }else if (min>59)
    {
      min=0;
      hour++;
     
    }
    else if (hour>24)
    {
       hour= 0;
       min = 0;
       sec = 0;
    }     
    gotoxy(3,3);
    Real_time();
  }
 
}

void show_time_left(){
          gotoxy(50,4);
            cout<<"THE REMAINING TIME LEFT "<<"    ";
            cout<<hour<<":"<<minute<<":"<<seccond<<"\n";
  }

      void set_timmer(int hour_in,int  min_in, int sec){
          while (hour>0 || minute >0 || seccond > 0)
          { 
          show_time_left();
          Sleep(1000);
          sec--;
          if (sec<0)
          {
            sec = 59;
            min_in--;

          }
          
          else if (min_in<0)
          { 
            min_in = 60;
            hour_in--; 
          }
          else if (hour_in<0)
          {
            hour_in = 0;
            min_in = 0;
            sec = 0;

          }
          hour = hour_in;
          minute = min_in; 
          seccond = sec;
        }
           gotoxy(2,4);
}


void input_data(){
  string task;
        ofstream out("sample121.txt",ios::app);
        if (!out)
        {
          cout<<"Invalid opening the file ";
        }
        int v;
        cout<<"______________________________"<<endl;
        cout<<"Enter 1 for saving tasks"<<endl;
        cout<<"Enter 2 for adding timmer in task"<<endl;

        cout<<"Enter the choice ";
        cin>>v;
        cin.ignore();
    if (v==1)
    {  
      bool exitt = false;
       while (!exitt)
       {       
          int n;
             cout<<"Enter no of tasks "<<"\n";
             cin>>n;
             for (int i = 1; i <= n; i++)
            {
                cout<<"ENTER TASKS"<<"\n"<<i;
                getline(cin,task);
                out<<task<<"\n";
            }
                out.close();
              system("cls");
              exitt = true;
     }
        cout<<"Storing Tasks"<<endl;
        for (int i = 0; i < 3; i++)
        {       
          cout<<"."<<std::flush;
          Sleep(400);
        }
        system("cls");
        cout<<"your tasks are stored";  
    }
    else if (v==2)
          { string hour_H;
            string min_M;
            string sec_S;
            int H,M,S;
            ofstream Time("Time121.txt",ios::app);
            if (!Time)
            {
              cout<<"Error in opening"<<"\n";
            }
            
            cout<<"enter hour";
            getline(cin,hour_H);
            Time<<hour_H<<"\n";
            cout<<"Enter min"<<"\n";
            getline(cin,min_M);
            Time<<min_M<<"\n";
            cout<<"Enter sec"<<"\n";
            getline(cin,sec_S);
            Time<<sec_S<<"\n";
            H = stoi(hour_H);
            M = stoi(min_M);
            S = stoi(sec_S);
            hour = H;
            minute = M;
            seccond = S;
            Time.close();
            cout<<"Timer set!"<<"\n";
    }else{
      cout<<"invalid choice";
    } 
}   
void Display(){
         system("cls");
         gotoxy(2,1);
         cout<<"========Todays Tasks======="<<"\n";
        ifstream file("sample121.txt"); 
        string line;
        int y = 6;
        if (file.is_open())
          { 
            gotoxy(2,3);
            cout<<"Todays Tasks"<<"\n";
            while (getline(file,line))
          {   
            gotoxy(4,y);
            cout<<"-"<<line<<endl; 
            y += 2;
       
            } 
             file.close();             }   
         else {
            gotoxy(2,3);
            cout<<"Unable to open file \n";
              }  
             gotoxy(50,4);
            set_timmer(hour,minute,seccond);
            Real_time(); 
}

int main(){
 
  bool exit = false;
  while (!exit)
  {
          int val;
          cout<<"\tWelcome to our service "<<"\n";
          cout<<"____________________________________"<<endl;
          cout<<"\tPress 1 for input tasks"<<"\n";
          cout<<"\tPress 2 for view lists "<<"\n";
          cout<<"\tPress 3 to exit "<<"\n";
          cout<<"\tEnter your choice ";
          cin>>val;
          cin.ignore();
         if (val == 1)
         {
            input_data();
            system("cls");
            
         }else if (val == 2)
         {
              Display();
         }
         else if (val == 3)
          {
             cout<<"please wait";
         for ( int i = 0; i < 3; i++)
         {
            cout<<"."<<std::flush;
            Sleep(800);
         }
      
            system("cls");
            exit = true;
            cout<<"Thank you for Choosing our service"<<endl;
    }
    else{
      cout<<"Invalid choice";
    }
  }
return(0);
}
