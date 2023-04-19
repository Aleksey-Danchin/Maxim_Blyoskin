#include <iostream>
#include <fstream>
#include <cstring>

#define BASE_FILE_NAME "base.txt"

using namespace std;

// Класс Студент
class Student {
    public:
        char* firstname;
        char* lastname;
        char* birthday;
        char* studentCard;
        char* groupNumber;
        int course;

        int counter; // Счетчик объектов класса

        static int _counter; // Статический счетчик объектов класса

        // Конструктор без параметров для динамического массива
        Student () {}

        // Конструктор с параметрами для экземпляров
        Student (
            char* p_firstname, // property_firstname
            char* p_lastname,
            char* p_birthday,
            char* p_studentCard,
            char* p_groupNumber,
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

        // Статический метод для ручного создания пользователя
        static Student enter () {
            char* firstname = new char[20];
            cout << "Firstname = ";
            cin >> firstname;

            char* lastname = new char[20];
            cout << "Lastname = ";
            cin >> lastname;

            char* birthday = new char[20];
            cout << "Birthday = ";
            cin >> birthday;

            char* studentCard = new char[20];
            cout << "StudentCard = ";
            cin >> studentCard;

            char* groupNumber = new char[20];
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

// Инициализация статического счетчика
int Student::_counter = 0;

// Класс база студенотов
class StudentsBase {
    public:
        int counter; // Счетчик студентов в базе данных
        Student* students; // Динамический массив стедентов базы

        // Читаем файл студентов
        int read_file (char* file_name) {
            ifstream file;
            file.open(file_name);

            if (!file.is_open()) {
                return 1;
            }

            char* firstname;
            char* lastname;
            char* birthday;
            char* studentCard;
            char* groupNumber;
            int course;

            // Считаем количество записей в файле
            int file_counter = 0;
            while (!file.eof()) {
                firstname = new char[100];
                lastname = new char[100];
                birthday = new char[100];
                studentCard = new char[100];
                groupNumber = new char[100];
                course = 0;

                file >> firstname;
                file >> lastname;
                file >> birthday;
                file >> studentCard;
                file >> groupNumber;
                file >> course;

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

            // Инициализируем данные экземпляра
            counter = file_counter;
            students = new Student[counter];

            // Возвращаем коретку в начало файла
            // чтобы заново его прочитать
            file.clear();
            file.seekg(0);

            // Создаем студентов и записываем в базу данных
            int i = 0;
            while (!file.eof()) {
                firstname = new char[100];
                lastname = new char[100];
                birthday = new char[100];
                studentCard = new char[100];
                groupNumber = new char[100];
                course = 0;

                file >> firstname;
                file >> lastname;
                file >> birthday;
                file >> studentCard;
                file >> groupNumber;
                file >> course;

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
                    
                    students[i] = student;
                    i++;
                }
            }

            file.close();
            return 0;
        }

        // Записываем файл студентов
        int write_file (char* file_name) {
            ofstream file;
            file.open(file_name);

            if (!file.is_open()) {
                return 1;
            }

            for (int i = 0; i < counter; i++) {
                file << students[i].firstname << " ";
                file << students[i].lastname << " ";
                file << students[i].birthday << " ";
                file << students[i].studentCard << " ";
                file << students[i].groupNumber << " ";
                file << students[i].course << endl;
            }

            file.close();
            return 0;
        }

        // Добавляем студента в базу
        void add (Student new_student) {
            Student* next_students = new Student[counter + 1];

            for (int i = 0; i < counter; i++) {
                next_students[i] = students[i];
            }

            next_students[counter] = new_student;

            counter += 1;
            students = next_students;
        }

        // Поиск по имени или фамилии и вывод
        void search_and_print (char* str) {
            int search_counter = 0;

            for (int i = 0; i < counter; i++) {
                if (strcmp(students[i].firstname, str) == 0 || strcmp(students[i].lastname, str) == 0) {
                    search_counter++;
                }
            }

            if (search_counter == 0) {
                cout << "Not founded." << endl;
                return;
            }

            cout << "| Firstname | LstName | Birthday | StudentID | Group | Course | Counter |" << endl;
            cout << "|-----------|---------|----------|-----------|-------|--------|---------|" << endl;

            for (int i = 0; i < counter; i++) {
                if (strcmp(students[i].firstname, str) == 0 || strcmp(students[i].lastname, str) == 0) {
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
        }

        // Сортировка по имени
        void sort_by_firstname () {
            for (int i = 0; i < counter - 1; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if (strcmp(students[i].firstname, students[j].firstname) > 0) {
                        Student a = students[i];
                        students[i] = students[j];
                        students[j] = a;
                    }
                }
            }
        }

        // Сортировка по фамилии
        void sort_by_lastname () {
            for (int i = 0; i < counter - 1; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if (strcmp(students[i].lastname, students[j].lastname) > 0) {
                        Student a = students[i];
                        students[i] = students[j];
                        students[j] = a;
                    }
                }
            }
        }

        // Сортировка по курсу
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

        // Распечатать базу данных студентов
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

// Вывод меню
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

        // Очистка кеша
        cin.clear();
        cin.ignore(10, '\n');
    }
}

int main () {
    StudentsBase base = StudentsBase();

    // Если не смогли прочитать файл, то конец программы
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
            char* str = new char[20];
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
            if (base.write_file(BASE_FILE_NAME) != 0) {
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
