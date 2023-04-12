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
    // string temp = "";
    // int num = 0;

    for (int i = 0; i < len; i++) {
		// if (postfix[i] >= '0' &&  postfix[i] <= '9'){
			
        //     temp += postfix[i];
        // }
        
        // else if (postfix[i] == ' '){
        //     num = stoi(temp);
        //     s.push(num);
        //     temp = "";
        //     num = 0;
        // }
        if (postfix[i] >= '0' &&  postfix[i] <= '9'){
            
            int num = 0;

            while (postfix[i] >= '0' &&  postfix[i] <= '9') {
                num = num * 10 + (int)(postfix[i] - '0');
                i++;
            }
            i--;
 
            s.push(num);
        }
        else if (postfix[i] == ' '){
            continue;
        }
        
        else{
			int n1 = s.getTop();
			s.pop();
			int n2 = s.getTop();
			s.pop();

            if (postfix[i] == '^'){
                s.push(pow(n2,n1));
            }
            else if (postfix[i] == '*'){
                s.push(n2 * n1);
            }
            else if (postfix[i] == '/'){
                s.push(n2 / n1);
            }
            else if (postfix[i] == '+'){
                s.push(n2 + n1);
            }
            else if(postfix[i] == '-'){
                s.push(n2 - n1);
            }
		}
	}
	return s.getTop();
}


int main()
{
	string postfix;
	getline(cin, postfix);

	cout << "result: " << calc(postfix);
	return 0;
}