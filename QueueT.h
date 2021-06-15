#include <iostream>
#include <stdexcept>
using namespace std;


class NodeT{
    public:
        int data;
        NodeT* next;
        NodeT(int n){
            data = n;
            next = nullptr;
        }
        NodeT(int n, NodeT* ptr){
            data = n;
            next = ptr;
        }
        ~NodeT(){
            delete next;
        }
};

class QueueT{
    int qsize;
    NodeT* front;
    NodeT* back;
    public:
        QueueT();
        QueueT(const QueueT&);
        ~QueueT();
        QueueT& operator= (const QueueT&);
        int size() const;
        bool empty() const;
        void print() const;
        QueueT concatenate(QueueT&, int);
        QueueT merge(QueueT&); 
        void enqueue(const int&);
        void addNode(NodeT*);
        int dequeue();
        NodeT* getFront();

};

QueueT::QueueT(){
    qsize = 0;
    front = nullptr;
    back = nullptr;
}

//helper
void QueueT::addNode(NodeT* new_node){
    if(back == nullptr){
        front = back = new_node;
        qsize++;
    }
    else{
        back->next = new_node;
        back = new_node;
        qsize++;
    }
}

void QueueT::enqueue(const int& num){
    addNode(new NodeT(num));
}

QueueT::QueueT(const QueueT& qt){
    NodeT* temp = qt.front;
    while(temp != nullptr){
        addNode(new NodeT(temp->data));
        temp = temp->next;
    }
}

QueueT::~QueueT(){
    NodeT* temp = front;
    while(temp != nullptr){
        front = front->next;
        delete temp;
        temp = front;
    }
}

QueueT& QueueT::operator= (const QueueT& qt){
    NodeT* temp = qt.front;
    qsize = 0;
    while(temp != nullptr){
        addNode(new NodeT(temp->data));
        temp = temp->next;
    }
}

int QueueT::size() const{
    return qsize;
}

bool QueueT::empty() const{
    return(qsize > 0);
}

void QueueT::print() const{
    NodeT* temp = front;
    if((front == nullptr) && (back == nullptr)){
        throw runtime_error("Queue is empty");
    }
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int QueueT::dequeue(){
    if(front == nullptr)
        throw runtime_error("Queue is empty");
    else{
        NodeT* temp = front;
        int val;
        if(temp->next != nullptr){
            val = front->data;
            front = front->next;
            qsize--;
            delete temp;
            return val;
        }
        
        else{
            val = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            qsize--;
            return val;
        }
    }
}

QueueT QueueT::concatenate(QueueT& qt, int num){

}

QueueT QueueT::merge(QueueT& qt){

}


NodeT* QueueT::getFront(){
    return front;
}