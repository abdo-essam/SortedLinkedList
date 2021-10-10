#include <iostream>
using namespace std ;
class Student{
    string name ;
    int id ;
    float gpa ;
public:
    Student(string name , int id , double gpa){
        this->name = name ;
        this->id = id ;
        this->gpa = gpa ;
    }
    void getInfo(){
        cout << "Name is " << name << endl;
        cout << "Id is " << id << endl;
        cout << "GPA is " << gpa << endl;
    }
    int getID(){
        return id ;
    }

    string getName(){
        return name ;
    }
    Student(){}
};

class StudentList{
private:
    struct Node{

        Student data ;
        Node *next ;
    };
    Node *head ;
    int length ;
public:
    StudentList(){
        head = NULL ;
        length = 0 ;
    }

    void insert(Student obj){
        Node *newNode = new Node;
        Node *current = head;
        Node *trailCurrent = head ;
        newNode->data = obj ;
        if (length == 0) {
            head  = newNode;
            newNode->next = NULL;
            length++;
            return;
        }
        else {
            if(head->data.getID() > obj.getID()){
                        newNode->next = head ;
                        head = newNode ;
                        length++;
                         return;
            }
            current = current->next ;
            for (int i = 0; i < length-1 ; ++i) {
                if ( current->data.getID() > obj.getID()){
                    break ;
                }
                current = current->next ;
                trailCurrent = current;
            }
            if (current == NULL){
                trailCurrent->next = newNode ;
                newNode->next = NULL ;
            } else{
                trailCurrent->next = newNode ;
                newNode->next = current ;
            }
        }
        length++;
    }


    void Delete(int id){
            Node *current ;
            Node *trailCurrent ;
            if (length == 0)
                cout << "ERROR: EMPTY LIST" << endl;
            else if (length == 1)
            {
                delete head;
                head  = NULL;
                length--;
            } else{
                current = head;
                trailCurrent = head;
                for (int i = 0; i <length; ++i) {
                    if (current->data.getID() == id)
                        break;
                    trailCurrent = current;
                    current = current->next;
                }
                if(current == NULL){
                    cout << "Student not found" <<endl;
                } else{
                    trailCurrent->next = current->next ;
                    current->next = NULL ;
                    delete current ;
                    length -- ;
                }

            }

    }
    void Display(){
        Node *current = head;
        for (int i = 0; i <length ; ++i) {
            cout <<endl;
            current->data.getInfo() ;
            cout <<endl;
            current = current->next;

        }
    }

    bool Search(string name){
        Node *current = head;
        while (current != NULL)
        {
            if (current->data.getName() == name)
            {
                current->data.getInfo() ;
                return true;
            }
            current = current->next;
        }
        cout << "Not Found" <<endl;
        return false;
    }

    bool Search(int id)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->data.getID() == id)
            {
                current->data.getInfo() ;
                return true;
            }

            current = current->next;
        }
        cout << "Not Found" <<endl;
        return false;
    }

};


int main() {

    Student s1("Ahmed"  , 20190001 , 3.4) ;
    Student s2("Menna"  , 20190010 , 3.5) ;
    Student s3("Yousef" , 20190003 , 1.4) ;
    Student s4("abdo"   , 20100001 , 1.6) ;
    Student s5("abdokamal" , 20180147, 3.9) ;

    StudentList list ;
    list.insert(s1) ;
    list.insert(s2) ;
    list.insert(s3) ;
    list.insert(s4) ;
    list.insert(s5) ;
    list.Display() ;
    cout <<"****************************************" <<endl;
    list.Delete(20180147) ;
    list.Display() ;
    cout <<"----------------------------------------" <<endl;
    Student s6("ahmed gamal" , 20180155, 4) ;
    list.insert(s6) ;
    list.Search(20180144) ;
    list.Search("Menna") ;
    return 0;
}