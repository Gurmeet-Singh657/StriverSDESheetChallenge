// Stack class.
class Stack {
    
public:
    int* arr;
    int size;
    int Top;
    Stack(int capacity) {
        arr=new int[capacity];
        size=capacity;
        Top=-1;
    }

    void push(int num) {
        if(Top+1>=size)
            return;
        Top++;
        arr[Top]=num;
    }

    int pop() {
        if(Top==-1)
            return -1;
        int ele=arr[Top];
        Top--;
        return ele;
    }
    
    int top() {
        if(Top==-1)
            return -1;
        return arr[Top];
    }
    
    int isEmpty() {
        return Top==-1;
    }
    
    int isFull() {
        return Top==size-1;
    }
    
};