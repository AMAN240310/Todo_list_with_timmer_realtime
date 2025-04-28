#include<iostream>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<time.h>

using namespace std;
// this function deterime which part is going to be where
// it helps to use cls more clearly 
// it helps to identify whih part should erase and which no
void gotoxy(int x, int y){
  COORD coord; // defines a coordinate structure (x,y)
  // for the console
  // set desire s and y positions 

  coord.X = x;
  coord.Y = y;
  // windows api function that 
  // moves the console cursor to specifi cordiantes
  // gets the output handle
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int hour = 0 ;
int minute = 0;
int seccond  = 0;

void Real_time(){
  time_t now = time(0);
  // get the function time 

  char* dt = ctime(&now);
  // convert the time to the string

  tm *lotm = localtime(&now);
  //convert the time to a tm structure containing local time componets (ours ,minute , seconds etc)
  dt = asctime(lotm);
   //convert tm structure to a string
  int hour = lotm->tm_hour;
  // extract the corrent timme like hours minutes and secconds
  int min = lotm->tm_min;
  int sec = lotm->tm_sec;

  while (hour>0|| min >0||sec >0)
  {
    // system("cls");
    // cout<<h<<":"<<m<<":"<<s<<endl;
    // gotoxy(1,1);
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
        // system("cls");
        // cout<<hour_in<<":"<<min_in<<":"<<sec<<endl;
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
          // show_time_left();
         
    
}


void input_data(){
  string task;
        ofstream out("sample121.txt",ios::app);
        if (!out)
        {
          // gotoxy(2,2);
          cout<<"Invalid opening the file ";
        }
        int v;
        cout<<"______________________________"<<endl;
        cout<<"Enter 1 for saving tasks"<<endl;
        cout<<"Enter 2 for adding timmer in task"<<endl;

        cout<<"Enter the choice ";
        cin>>v;
        cin.ignore();// for new line in file
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
     // just simple animation-- 
        cout<<"Storing Tasks"<<endl;
        for (int i = 0; i < 3; i++)
        {       
          cout<<"."<<std::flush;
          Sleep(400);
        }
        system("cls");
        //  exit = true;
        cout<<"your tasks are stored";  
    }
    else if (v==2)
          { string hour_H;
            string min_M;
            string sec_S;
            int H,M,S;
            // set time limit for yours tasks 
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
            // system("cls");
    }else{
      cout<<"invalid choice";
    } 
}   
void Display(){
         system("cls");
         gotoxy(2,1);
         cout<<"========Todays Tasks======="<<"\n";
         // display tasks
        ifstream file("sample121.txt"); // open file to read 
        string line;
        int y = 6;// staring y position 
        if (file.is_open())
          { 
            gotoxy(2,3);
            cout<<"Todays Tasks"<<"\n";
            while (getline(file,line))
          {   
            gotoxy(4,y);//set place in console 
            cout<<"-"<<line<<endl; 
            y += 2;
       
            } 
             file.close(); 
            //  Sleep(5000);
            }   
         else {
            gotoxy(2,3);
            cout<<"Unable to open file \n";
              }  
            // gotoxy(2,2);// set place in console 
            // ifstream time("Time.txt");
            // if (time.is_open())
            // {  
            //   gotoxy(1,y+2);
            //    cout<<"REMAINING TIME "<<"\n";

            // }
            // else{
            //   cout<<"Unable to open"<<"\n";
            // }
            // // timer
             gotoxy(50,4);
            set_timmer(hour,minute,seccond);

            // gotoxy(3,3);
            Real_time(); // do you the problem if you use one of the time 
            // the other one will not work bcz
            // when you use remaing time the loop will ocntinue 
            // until it got its time and when you use real time 
            // the real time loop contiue 
            // thats why you can only use one loop at a time 
            // this implies you can use only real time of eather remianing time

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
    //it take value for functioning 
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