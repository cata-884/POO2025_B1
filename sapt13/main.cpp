#include <iostream>

#include"CatalogRo.h"
#include"Infomatica.h"
#include"Matematica.h"
#include"Romana.h"
#include"Student.h"

int main() {
    Student st("Marcel", 103125, new Romana(), 10);
    (st+= {new Matematica(), 10})+={new Infomatica(), 5};
    Student st1("Anastasia", -999999);
    (st1+= {new Romana(), -2})+={new Matematica(), 11};
    CatalogRo cat;
    cat+=st;
    cat+=st1;
    cat.printStudents();
    cout<<endl<<cat.getMedie(&st1);
    cout<<endl;
    vector<Student*> stud = cat.filter([](const Student *s1){return s1->getMedie() > 5;});
    for(auto i : stud) {
        i->printData();
    }
    initializer_list<int> l = {1, 2, 3, 4, 5};
    for(auto i : l) {
        cout<<i<<" nigus ";
    }
    return 0;
}
