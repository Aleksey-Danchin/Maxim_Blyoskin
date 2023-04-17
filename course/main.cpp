#include <iostream>
#include <fstream>

#define BASE_FILE_NAME "base.txt"

using namespace std;

class Student {
    public:
        string firstname;
        string lastname;
        string birthday;
        string studentCard;
        string groupNumber;
        int course;

        int counter;

        static int _counter;

        Student () {}

        Student (
            string p_firstname,
            string p_lastname,
            string p_birthday,
            string p_studentCard,
            string p_groupNumber,
            int p_course
        ) {
            firstname = p_firstname;
            lastname = p_lastname;
            birthday = p_birthday;
            studentCard = p_studentCard;
            groupNumber = p_groupNumber;
            course = p_course;

            counter = ++Student::_counter;
        }

        static Student enter () {
            string firstname;
            cout << "Firstname = ";
            cin >> firstname;

            string lastname;
            cout << "Lastname = ";
            cin >> lastname;

            string birthday;
            cout << "Birthday = ";
            cin >> birthday;

            string studentCard;
            cout << "StudentCard = ";
            cin >> studentCard;

            string groupNumber;
            cout << "GroupNumber = ";
            cin >> groupNumber;

            int course;
            cout << "Course = ";
            cin >> course;

            return Student(
                firstname,
                lastname,
                birthday,
                studentCard,
                groupNumber,
                course
            );
        }
};

int Student::_counter = 0;

class StudentsBase {
    public:
        int counter;
        Student* students;

        int read_file (string file_name) {
            ifstream ifile;
            ifile.open(file_name);

            if (!ifile.is_open()) {
                return 1;
            }

            string firstname;
            string lastname;
            string birthday;
            string studentCard;
            string groupNumber;
            int course;

            int file_counter = 0;
            while (!ifile.eof()) {
                firstname = "";
                lastname = "";
                birthday = "";
                studentCard = "";
                groupNumber = "";
                course = 0;

                ifile >> firstname;
                ifile >> lastname;
                ifile >> birthday;
                ifile >> studentCard;
                ifile >> groupNumber;
                ifile >> course;

                if (
                    firstname != ""
                    && lastname != ""
                    && birthday != ""
                    && studentCard != ""
                    && groupNumber != ""
                    && course != 0
                ) {
                    file_counter++;
                }
            }

            counter = file_counter;
            students = new Student[counter];

            ifile.clear();
            ifile.seekg(0);

            int i = 0;
            while (!ifile.eof()) {
                firstname = "";
                lastname = "";
                birthday = "";
                studentCard = "";
                groupNumber = "";
                course = 0;

                ifile >> firstname;
                ifile >> lastname;
                ifile >> birthday;
                ifile >> studentCard;
                ifile >> groupNumber;
                ifile >> course;

                if (
                    firstname != ""
                    && lastname != ""
                    && birthday != ""
                    && studentCard != ""
                    && groupNumber != ""
                    && course != 0
                ) {
                    Student student = Student(
                        firstname,
                        lastname,
                        birthday,
                        studentCard,
                        groupNumber,
                        course
                    );
                    
                    students[i++] = student;
                }
            }

            ifile.close();
            return 0;
        }

        int write_to_file (string file_name) {
            ofstream ofile;
            ofile.open(file_name);

            if (!ofile.is_open()) {
                return 1;
            }

            for (int i = 0; i < counter; i++) {
                ofile << students[i].firstname << " ";
                ofile << students[i].lastname << " ";
                ofile << students[i].birthday << " ";
                ofile << students[i].studentCard << " ";
                ofile << students[i].groupNumber << " ";
                ofile << students[i].course << endl;
            }

            ofile.close();
            return 0;
        }

        void add (Student new_student) {
            Student* next_students = new Student[counter + 1];

            for (int i = 0; i < counter; i++) {
                next_students[i] = students[i];
            }

            next_students[counter] = new_student;

            counter += 1;
            this->students = next_students;
        }

        void search_and_print (string str) {
            int search_counter = 0;

            for (int i = 0; i < counter; i++) {
                if (students[i].firstname == str || students[i].lastname == str) {
                    search_counter++;
                }
            }

            if (!search_counter) {
                cout << "Not founded." << endl;
                return;
            }

            StudentsBase search_base = StudentsBase();
            search_base.counter = search_counter;
            search_base.students = new Student[search_counter];

            int j = 0;
            for (int i = 0; i < counter; i++) {
                if (students[i].firstname == str || students[i].lastname == str) {
                    search_base.students[j++] = students[i];
                }
            }

            search_base.print();
        }

        void sort_by_firstname () {
            for (int i = 0; i < counter - 1; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if (students[i].firstname.compare(students[j].firstname) > 0) {
                        Student a = students[i];
                        students[i] = students[j];
                        students[j] = a;
                    }
                }
            }
        }

        void sort_by_lastname () {
            for (int i = 0; i < counter - 1; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if (students[i].lastname.compare(students[j].lastname) > 0) {
                        Student a = students[i];
                        students[i] = students[j];
                        students[j] = a;
                    }
                }
            }
        }

        void sort_by_course () {
            for (int i = 0; i < counter - 1; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if (students[i].course > students[j].course) {
                        Student a = students[i];
                        students[i] = students[j];
                        students[j] = a;
                    }
                }
            }
        }

        void print () {
            if (counter == 0) {
                cout << "Base is empty." << endl;
                return;
            }

            cout << "| Firstname | LstName | Birthday | StudentID | Group | Course | Counter |" << endl;
            cout << "|-----------|---------|----------|-----------|-------|--------|---------|" << endl;

            for (int i = 0; i < counter; i++) {
                cout << "| ";
                cout << students[i].firstname << " | ";
                cout << students[i].lastname << " | ";
                cout << students[i].birthday << " | ";
                cout << students[i].studentCard << " | ";
                cout << students[i].groupNumber << " | ";
                cout << students[i].course << " | ";
                cout << students[i].counter << " |";
                cout << endl;
            }
        }
};

int get_menu_option () {
    int n;

    while (true) {
        cout << endl;
        cout << "1) Add studnet" << endl;
        cout << "2) Print students base" << endl;
        cout << "3) Search by firstname or secondname" << endl;
        cout << "4) Sort by firstname" <<  endl;
        cout << "5) Sort by lastname" << endl;
        cout << "6) Sort by course" << endl;
        cout << "7) Save base" << endl;
        cout << "8) Save base and exit." << endl;

        cout << ">> ";
        cin >> n;

        if (1 <= n && n <= 8) {
            return n;
        }

        cout << "Command not recognize. Try again." << endl;

        cin.clear();
        cin.ignore(10, '\n');
    }
}

int main () {
    StudentsBase base = StudentsBase();

    if (base.read_file(BASE_FILE_NAME) != 0) {
        cout << "Can't read file" << endl;
        return 1;
    }

    int command = 0;

    while (command != 8) {
        command = get_menu_option();

        if (command == 1) {
            Student student = Student::enter();
            base.add(student);
            cout << "Studen added." << endl;
        }

        if (command == 2) {
            base.print();
        }

        if (command == 3) {
            cout << "Enter firstname or lastname >> ";
            string str;
            cin >> str;

            base.search_and_print(str);
        }

        if (command == 4) {
            base.sort_by_firstname();
            base.print();
        }

        if (command == 5) {
            base.sort_by_lastname();
            base.print();
        }

        if (command == 6) {
            base.sort_by_course();
            base.print();
        }

        if (command == 7 || command == 8) {
            if (base.write_to_file(BASE_FILE_NAME) != 0) {
                cout << "Can't write file" << endl;
            } else {
                cout << "Database booked." << endl;
            }

            if (command == 8) {
                cout << "Goodbye!" << endl;
                return 0;
            }
        }
    }    
}
