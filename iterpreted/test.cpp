#include <algorithm>
#include <iostream>
#include <list>    
#include <stdio.h>
#include <string> 
#include <string.h> 
#include <signal.h>
#include <functional>
#include <QHash>
#include <QDebug>
using namespace std;


enum TypeVal{
    Vint,
    Vdouble,
    Vstring,
    Vbool
};
struct multiVar{
    TypeVal type{Vint};
    int  Int{0};
    double Double{0};
    bool Bool{false};
    string String{""};
};
int defalut=5; //zmizí
void callBlock(int id);
QHash<int,QHash<QString,multiVar>> memory;


void function0(int id){
    //generováno
    //inputs
    if(memory.constFind(1)!=QHash::constEnd())
        int input1=(memory[id])["input1"].Int;
    else
        int input1=defalut;
    qDebug()<<input1;
    //outputs
    int output1;
    //generováno

    /*user code*/
    output1=input1+10;

    /*user code*/

    memory[2]["input1"].Int=output1;

}
void function1(int id){
    //generováno
    int input1=(memory[id])["input1"].Int;
    callBlock(0);
    //generováno

}

void callBlock(int id){
    switch (id) {
    //generováno
        case 0:
        function0(id);
        break;
        case 1:
        function1(id);
        break;
     //generováno

    }
}
//list<std::function<void()>> intstuctionsLine;
int main(int argc, char **argv) {
    /*
    string var="hi";
    intstuctionsLine.push_back(&var);

    while(!intstuctionsLine.empty()){
        intstuctionsLine.front()();
    }
    */
   callBlock(0);

    return 0;
}
