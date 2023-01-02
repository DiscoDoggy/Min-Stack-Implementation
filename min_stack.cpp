#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class stack_element {

public:
    stack_element(int val) {
        value = val;
        next_min_element = nullptr;
    }
    int get_val() {return value;}
    stack_element* get_next_min_element() {return next_min_element;}
    void assign_next_min (stack_element* next_min) {next_min_element = next_min;}

private:
    int value;
    stack_element* next_min_element;


};



class MinStack {
public:
    MinStack() {
        currentMin = nullptr;
    }
    
    void push(int val) {
        stack_element* new_stack_element = new stack_element(val);

        if(stack_elements.empty()) {
            currentMin = new_stack_element;
            stack_elements.push_back(new_stack_element);
            return;

        }

        else if (new_stack_element->get_val() <= currentMin->get_val()) {
            new_stack_element->assign_next_min(currentMin);
            currentMin = new_stack_element;
            stack_elements.push_back(new_stack_element);
            return;
        }

        else {
            stack_elements.push_back(new_stack_element);
        }

        return;
    }
    
    void pop() {
        if (stack_elements.at(stack_elements.size() - 1) == currentMin) {
            currentMin = currentMin->get_next_min_element();
        }

        delete(stack_elements.at(stack_elements.size() - 1));
        stack_elements.pop_back();
    }
    
    int top() {
        return stack_elements.at((stack_elements.size() - 1))->get_val();
    }
    
    int getMin() {
        return currentMin -> get_val();
    }

private:
    vector<stack_element*> stack_elements;
    stack_element *currentMin;

};




int main() {
//Your MinStack object will be instantiated and called as such:
    int val = 0;
    int param_3 = 9999;
    int param_4 = 9999;
    MinStack* obj = new MinStack();
    for (int i = 0; i < 20; i++) {
        val = 1 + (rand() % 50);
        
        obj->push(val);
        param_3 = obj->top();
        param_4 = obj->getMin();

        cout << "Top of stack: " << param_3 << endl;
        cout << "Min of Stack: " << param_4 << endl;

        cout << endl;
    }

    cout << endl << endl;
    cout << "Popping from Min Stack..." << endl;

    for (int i = 0; i < 19; i++) {
        obj->pop();

        param_3 = obj->top();
        param_4 = obj->getMin();

        cout << "Top of stack: " << param_3 << endl;
        cout << "Min of Stack: " << param_4 << endl;
        cout << endl;
    }
    
    return 0;
}