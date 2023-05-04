/*
Student Name: Mazin Mohammad Mostafa
ID: 200011389
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
template <class t>
class Stack{
    
    int top;
    t item[MAX_SIZE];
    
    public:

    Stack() : top(-1) {};       // constructor

    void push(t newElement){
        
        if (isFull())
            cout << "Stack full on push" << endl;
        else{
        top++;
        item[top] = newElement; 
        }
    }

    bool isFull(){
        return top >= MAX_SIZE - 1;
    }

    bool isEmpty(){
        return top < 0;
    }

    void pop(){
        if (isEmpty())
            cout << "Stack is empty on pop \n";
        else
            top--;
    }

    int getTop(){
        return item[top];
    }
};


int calc(string postfix)
{   
    Stack<int> s;
    int len = postfix.length();
    
    for (int i = 0; i < len; i++) {
		
        if (isdigit(postfix[i])){
            
            int num = 0;

            while (isdigit(postfix[i])) {
                num = num * 10 + (int)(postfix[i] - '0');
                i++;
            }
            i--;
 
            s.push(num);
        }
        else if (isspace(postfix[i])){
            continue;
        }
        
        else{
			int n1 = s.getTop();
			s.pop();
			int n2 = s.getTop();
			s.pop();

            switch (postfix[i]) {
                case '^':
                    s.push(pow(n2,n1));
                    break;
                case '+':
                    s.push(n2 + n1);
                    break;
                case '-':
                    s.push(n2 - n1);
                    break;
                case '*':
                    s.push(n2 * n1);
                    break;
                case '/':
                    s.push(n2 / n1);
                    break;
                default:{
                    cerr << "Invalid operator";
                    return 1;
                }
                break;
            }
		}
	}
	return s.getTop();
}


int main()
{
	string postfix;
    cout << "(Please make sure all operators and operands are seperated by a space, for example: 30 2 + 5 * \n";
    cout << "Enter the postfix expression you'd like me to calculate: ";
	getline(cin, postfix);

	cout << "result: " << calc(postfix);
	return 0;
}


//Another Solution

/*
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
template <class t>
class Stack{
    
    int top;
    t item[MAX_SIZE];
    
    public:

    Stack() : top(-1) {};       // constructor

    void push(t newElement){
        
        if (isFull())
            cout << "Stack full on push" << endl;
        else{
        top++;
        item[top] = newElement; 
        }
    }

    bool isFull(){
        return top >= MAX_SIZE - 1;
    }

    bool isEmpty(){
        return top < 0;
    }

    void pop(){
        if (isEmpty())
            cout << "Stack is empty on pop \n";
        else
            top--;
    }

    int getTop(){
        return item[top];
    }
};


int evaluatePostfix(string postfix) {
    stack<int> operands;
    int num = 0;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }
        else if (isspace(ch)) {
            if (num != 0) {
                operands.push(num);
                num = 0;
            }
        }
        else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (ch) {
                case '^':
                    operands.push(pow(operand1,operand2));
                    break;
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                default:{
                    cerr << "Invalid operator";
                    return 1;
                }
                break;
            }
        }
    }

    if (num != 0) {
        operands.push(num);
    }

    return operands.top();
}


int main()
{
	string postfix;
    cout << "Enter the postfix expression you'd like me to calculate: ";
	getline(cin, postfix);

	cout << "result: " << evaluatePostfix(postfix);
	return 0;
}
*/



/*
line 202:
throw runtime_error("Invalid operator: " + string(1, ch));
*/