#include <iostream> 
 //var2
using namespace std;
 
class stack {
private:
    int size;
    int* data;
    size_t ptr;
public:
 
    stack(int valid_stack_size) {
        this->size = valid_stack_size;
        this->ptr = 0;
        this->data = new int[valid_stack_size];
    }
 
    ~stack() {
        delete[] this->data;
    }
 
    void push(int value) {
        if (this->ptr >= (size_t)this->size)
            throw "stack is full\n";
        this->data[this->ptr++] = value;
 
    }
	int s()
	{return (this->ptr);}

	int top() { 
        if (this->ptr == 0) {
            cerr << "Error! The stack is empty!\n";
            return -1;
        }
        return data[this->ptr-1];
    }
 
    int pop() {
        if (this->ptr == 0)
            throw "stack is empty";
 
        return this->data[--this->ptr];
 
    }
};
 
int main() {
    stack* f=new stack(10);
    int n, m, val;
    f->push(1);
    f->push(2);
    f->push(3);
	cout<<f->pop()<<endl;
    cout<<f->pop()<<endl;
    cout<<f->pop()<<endl;
    
   stack s1, s2, s3;
    cout << "Enter the 1-st array size:\n";
    cout << "n = ";
    cin >> n;
    cout << "Enter the 1-st array:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        s1.push(val); 
    }
    cout << "Enter the 2-nd array size:\n";
    cout << "m = ";
    cin >> m;
    cout << "Enter the 2-nd array:\n";
    for (int i = 0; i < m; i++) {
        cin >> val;
        s2.push(val); 
    }
    
    while ((s1.s() > 0) || (s2.s() > 0)) {
        if ((s1.s() > 0) && (s2.s() > 0)) {
            if (s1.top() < s2.top()) {
                s3.push(s2.top());
                s2.pop();
            } else {
                s3.push(s1.top());
                s1.pop();
            }
        } else if (s1.s() > 0) {
            s3.push(s1.top());
            s1.pop();
        } else {
            s3.push(s2.top());
            s2.pop();
        }
    }
    cout << "Output of the program:\n";
    while (s3.s()) {
        cout << s3.top() << " "; 
        s3.pop();
    }
    system("pause");
    return 0;
}