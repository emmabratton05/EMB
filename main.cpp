//Emma Bratton
//Throttle Program
//08-20-19
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ofstream outfile;
class throttle
{
    public:
   throttle()   //constructor for car (default constructor)
        {
            maxpos=6.0;
            position=0.0;
        }
    throttle(int max)  // constructor for truck(one argument)
        {
            if(max>0)
                maxpos=max;
                position=0;
        }
    throttle(int max,int pos) //constructor for shuttle (two arguments)
        {
            maxpos=max;
            position=pos;
        }
    throttle(throttle& t2)
    {
        maxpos=t2.getmax();
        position=t2.getpos();
    }
    double getpos() {return position;} //getter functions
    double getmax(){return maxpos;}
    void shift(int gear)
    {
        position+=gear;
        if(position<0)     //bottom boundaries
        {    position=0;
        }
        if(position>maxpos)   //top boundaries
        {
            position=maxpos;
        }
    }
    double flow(){return position/double (maxpos);}
     bool operator==(throttle& t2)
    {
        return
        (maxpos==t2.getmax())
        &&
        (position==t2.getpos());
    }
    friend bool operator!=(throttle& temp1, throttle& temp2);
    friend ostream& operator<<(ostream& outs, throttle& t);
    private:
        int maxpos;
        int position;
};
bool operator!=(throttle& temp1, throttle& temp2)
{
    return !(temp1==temp2);
}
ostream& operator<<(ostream& outs, throttle& t)
{
    outs<<" Top positon= "<<t.getmax();
    outs<<" Current position= "<<t.getpos();
    return outs;
}
int main()
{
    outfile.open("shiftoutput.txt");
    int tmax=30.0;
    int smax=20.0;
    int spos=6.0;
    throttle car;
    throttle truck(tmax);
    throttle shuttle(smax,spos);
    throttle truck2(truck);
    //-----------------------CAR THROTTLE----------------------------
    outfile<<setw(16)<<"*CAR*"<<endl;
    outfile<<"Max Position: "<<car.getmax()<<endl<<"Current Position: "<<car.getpos()<<endl;
    // FIRST SHIFT
    car.shift(4);
    outfile<<"-Shifting Car up 4 gears"<<endl<<setw(20)<<"New Position: "<<car.getpos()<<endl<<"Flow: "<<car.flow()<<endl;;
    //SECOND SHIFT
    car.shift(-5); //-----testing boundaries
    outfile<<"--Shifting Car down 5 gears"<<endl<<setw(20)<<"New Position: "<<car.getpos()<<endl<<"Flow: "<<car.flow()<<endl;
    //---------------------TRUCK THROTTLE---------------------------
    outfile<<setw(18)<<" *TRUCK* "<<endl;
    outfile<<"Max Position: "<<truck.getmax()<<endl<<"Current Position: "<<truck.getpos()<<endl;
    //FIRST SHIFT
    truck.shift(31); //-----testing boundaries
    outfile<<"-Shifting Truck up 31 gears"<<endl<<setw(20)<<"New Position: "<<truck.getpos()<<endl<<"Flow: "<<truck.flow()<<endl;
    //SECOND SHIFT
    truck.shift(-15);
    outfile<<"--Shifting Truck down 15 gears"<<endl<<setw(20)<<"New Position: "<<truck.getpos()<<endl<<"Flow: "<<truck.flow()<<endl;    //--------------------SHUTTLE THROTTLE--------------------------
    outfile<<setw(20)<<" *SHUTTLE* "<<endl;
    outfile<<"Max Position: "<<shuttle.getmax()<<endl<<"Current Position: "<<shuttle.getpos()<<endl<<"Flow: "<<shuttle.flow()<<endl;    //FIRST SHIFT
    shuttle.shift(-7); //------testing boundaries
    outfile<<"-Shifting Shuttle down 7 gears "<<endl<<setw(20)<<"New Position: "<<shuttle.getpos()<<endl<<"Flow: "<<shuttle.flow()<<endl;
    //SECOND SHIFT
    shuttle.shift(17);
    outfile<<"--Shifting Shuttle up 17 gears"<<endl<<setw(20)<<"New Position: "<<shuttle.getpos()<<endl<<"Flow: "<<shuttle.flow()<<endl;
    //------compare two throttles
    outfile<<"A.)Comparing car and truck: "<<endl<<"*Syntax sugar"<<endl;
    if(car==truck)          //---------------nice syntax sugar way------
        {
            outfile<<"objects are equal"<<endl;
        }
        else
            outfile<<"objects are not equal."<<endl;
    outfile<<"**Function call"<<endl;
    if(car.operator==(truck))   //-----------calling the funcation way--------
        {
            outfile<<"Objects are equal"<<endl;
        }
        else
            outfile<<"objects are not equal"<<endl;
    // --------!= operator
    outfile<<"B.) testing != operator"<<endl<<"*Function call"<<endl;
    if(operator!=(car,truck))
        {
            outfile<<"objects are not equal"<<endl;
        }
        else
            outfile<<"objects are equal"<<endl;
    outfile<<"**syntax sugar"<<endl;
    if(car!=truck2)
        {
            outfile<<"objects are not equal"<<endl;
        }
        else
         outfile<<"objects are equal"<<endl;
    
    outfile<<"C.) testing << operator"<<endl<<"**Shuttle: "<<shuttle<<endl;
    outfile.close();
}
