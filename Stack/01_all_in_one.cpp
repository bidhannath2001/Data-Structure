#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    int top;
    int arr[5];
    public:
    Stack()
    {
        top=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    //Empty check
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    //Full check
    bool isFull(){
        if(top==4)
            return true;
        else
            return false;
    }

    //push
    void push(int value){
        if(isFull()){
            cout<<"Stack overflow!"<<endl;
        }
        else{
            top++;
            arr[top]=value;
        }
    }

    //pop
    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow!"<<endl;
            return 0;
        }
        else{
            int pop_value = arr[top];
            arr[top]=0;
            top--;
            return pop_value;
        }
    }
    //count
    int count(){
        return top+1;
    }
    //peek
    int peek(int pos){
        if(isEmpty()){
            cout<<"Stack underflow!"<<endl;
        }
        else if(pos>top){
            cout<<"Invalid position"<<endl;
        }
        else{
            return arr[pos];
        }
    }
    //change
    void change(int pos, int value){
        arr[pos]==value;
        cout<<"value changed at location "<<pos<<endl;
    }
    //display
    void display(){
        if(top==-1){
            cout<<"Stack is empty!"<<endl;
        }
        else{
            cout<<"All values in the stack are "<<endl;
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<endl;
            }
        }
        
    }
};
int main ()
{
    Stack s;
    int option,position,value;
    do{
        cout<<"What operation do you want to perform? Select option number. ENter 0 to Exit"<<endl;
        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. peek()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. chnage()"<<endl;
        cout<<"8. dispay()"<<endl;
        cout<<"9. clear screen"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enter an item to push in the stack"<<endl;
            cin>>value;
            s.push(value);
            break;
        
        case 2:
            cout<<"pop funtion called-poped value:"<<s.pop()<<endl;
            break;
        
        case 3:
            if(s.isEmpty())
                cout<<"Stack is Empty!";
            else
                cout<<"Stack is Not Empty!";
            break;
        
        case 4:
            if(s.isFull())
                cout<<"Stack is Full!"<<endl;
            else
                cout<<"Stack is not full!"<<endl;
            break;

        case 5:
            cout<<"Enter position:"<<endl;
            cin>>position;
            cout<<"Peeked value: "<<s.peek(position)<<endl;
            break;
        
        case 6:
            cout<<"Number of Items "<<s.count()<<endl;
            break;
        
        case 7:
            cout<<"Enter positon of item you want to chnage: ";
            cin>>position;
            cout<<endl;
            cout<<"Enter value you want to change: ";
            cin>>value;
            s.change(position,value);
            break;
        
        case 8:
            s.display();
            break;

        case 9:
            system("cls");
            break;
        
        default:
            cout<<"Enter valid number"<<endl;
        }
    }while(option!=0);
    return 0;
}