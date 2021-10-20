#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ENQUEUE 1
#define DEQUEUE 2
#define PRINT 3

class Queue{
    private: 
        stack<int> s1, s2;
    public:
        bool isEmpty(){
            return s1.empty() && s2.empty();
        }
        void enqueue(int v){
            // push element to the first stack
            s1.push(v);
            //cout << "enqueue(" << v << ") : size stack : " << size() << endl;
        }   
        int dequeue(){
            int elem;
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if(!s2.empty()){
                elem = s2.top();
                s2.pop();
                //cout << "dequeue(" << elem << ") : size stack : " << size() << endl;

                return elem;        
            }
            return -1;
        }
        int size(){
            return s1.size() + s2.size();
        }
        int front(){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if(!s2.empty()){
                return(s2.top());    
            }
            else{
                return -1;
            }
            
        }            
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q, type, x;
    cin >> q;
    Queue queue;
    
    while(q != 0){
        cin >> type;
        switch(type){
            case ENQUEUE:
                cin >> x;
                queue.enqueue(x);
                //cout << "enqueue(" << x << ")" << endl;
                break;
            case DEQUEUE:
                int elem;
                elem = queue.dequeue();
                //cout << "dequeue--> " << elem << endl;
                break;
            case PRINT:
                cout << queue.front() << endl;
                break;
        }
        //cout << queue.front() << endl;
        q--;
    }
    return 0;
}
