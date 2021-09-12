#include <ctime>

#include <iostream>
#include <iomanip>    
#include <vector>
#include <algorithm>
#include <mutex>
#include <thread>

using namespace std;
mutex m;
//functions block

bool sortfunction_int(int& i, int& j) { return(i < j); }

auto threadfunction_simple_int_1(int& x1, int& x2, int& size, int& tik, vector<int>& example, vector<int>& a11/*, vector<int>& finish*/) {
    int siize = size;
    int tik_tak = tik;
    tik_tak -= 1;
    int xx1 = x1 - (x2 - x1);
    int xx2 = x1;
    xx2 = siize / 8 * tik_tak;
    int schetchik = 0;


    for (size_t j = xx1; j < xx2; ++j) {
        a11[schetchik] = example[j];
        ++schetchik;
    }
    sort(a11.begin(), a11.end(), sortfunction_int);

}
auto threadfunction_simple_int_2_2(int& size, int& x1, int& x2, int& tik, size_t& i, vector<int>& a22,
    vector<int>example/*, vector<int>finish*/) {

    int schet = 0;
    int sizi = 8;
    int schetchik = 0;
    int siize = size;
    int tik_tak = tik;
    int xx1 = x1, xx2 = x2;
    size_t ii = i;

    if (ii == ((sizi / 2) - 1)) {

        for (size_t t = 0; t < (siize % 8); ++t) {
            a22.push_back(0);
        }
        for (size_t k = x1; k < siize; ++k) {
            a22[schetchik] = example[k];
            ++schetchik;
        }
        schetchik = 0;
        sort(a22.begin(), a22.end(), sortfunction_int);
    }
    else {
        schetchik = 0;
        for (size_t k = x1; k < x2; ++k) {
            a22[schetchik] = example[k];
            ++schetchik;
        }
        schetchik = 0;
        sort(a22.begin(), a22.end(), sortfunction_int);
    }
}

//class block
class ex {
    int example_int_number_;
    vector<int>example_int_;
    vector<int>finish_int_;
public:
    ex() {
        example_int_number_ = 0;
    }
    ex(vector<int>& example) {
        example_int_number_ = 0;
        example_int_.resize(example.size());
        for (size_t i = 0; i < example.size(); ++i) {
            example_int_[i] = example[i];
        }
    }

    auto get_example_int_() { return example_int_; }
    auto set_finish_int_(vector<int>& finish) {
        finish_int_.resize(finish.size());
        for (size_t i = 0; i < finish.size(); ++i) {
            finish_int_[i] = finish[i];
        }
    }

    auto get_int_() const { return example_int_number_; }
    auto set_int_(int& res) { example_int_number_ = res; }

    void visualisation1_int_ex() {
        for (size_t i = 0; i < example_int_.size(); ++i) {
            cout << "|";
            for (int j = 0; j < 100; ++j) {
                if (j == example_int_[i]) { cout << "*"; }
                else { cout << ' '; }
            }
            cout << "|" << endl;
        }
    }
    void visualisation2_int_ex() {
        cout << "[";
        for (size_t i = 0; i < example_int_.size(); ++i) {
            cout << " " << example_int_[i] << " ";
        }
        cout << "]\n";
    }

    void visualisation1_int_fin() {
        for (size_t i = 0; i < finish_int_.size(); ++i) {
            cout << "|";
            for (int j = 0; j < 100; ++j) {
                if (j == finish_int_[i]) { cout << "*"; }
                else { cout << ' '; }
            }
            cout << "|" << endl;
        }
    }
    void visualisation2_int_fin() {
        cout << "[";
        for (size_t i = 0; i < finish_int_.size(); ++i) {
            cout << " " << finish_int_[i] << " ";
        }
        cout << "]\n";
    }
};


bool sortfunction_classes(ex const& a1, ex const& a2) {
    return a1.get_int_() < a2.get_int_();
}
void classes_visualisation(vector<ex>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (i % 5 == 0) { cout << endl; }
        cout << setw(3) << a[i].get_int_() << "     ";
    }
    cout << endl;
}
void visualisation_classes_1(vector<ex>& finish) {
    for (size_t i = 0; i < finish.size(); ++i) {
        cout << "|";
        for (int j = 0; j < 100; ++j) {
            if (j == finish[i].get_int_()) { cout << "*"; }
            else { cout << ' '; }
        }
        cout << "|" << endl;
    }
}

auto thread_function_classes_1(int& x1, int& x2, int& tik, int& size, vector<ex>& vec1, vector<ex>& vector_of_classes) {
    int z;
    int siize = size;
    int tik_tak = tik - 1;
    int xx1 = x1 - (x2 - x1);
    int xx2 = x1;
    xx2 = siize / 8 * tik_tak;
    int schetcik = 0;

    for (size_t j = xx1; j < xx2; ++j) {
        z = vector_of_classes[j].get_int_();
        vec1[schetcik].set_int_(z);
        schetcik += 1;
    }
    sort(vec1.begin(), vec1.end(), sortfunction_classes);

}
auto thread_function_classes_2(int& x1, vector<ex>& vec2, int& x2, size_t& i, int& tik, int& size, vector<ex>& vector_of_classes) {
    int sizi = 8;
    int schetchik = 0;
    int siize = size;
    int tik_tak = tik;
    int xx1 = x1, xx2 = x2;
    size_t ii = i;
    int z = 0;

    if (ii == ((sizi / 2) - 1)) {

        for (size_t t = 0; t < (siize % 8); ++t) {
            vec2.push_back(ex());
        }
        for (size_t k = x1; k < siize; ++k) {
            z = vector_of_classes[k].get_int_();
            vec2[schetchik].set_int_(z);
            ++schetchik;
        }
        schetchik = 0;
        sort(vec2.begin(), vec2.end(), sortfunction_classes);
    }
    else {
        schetchik = 0;
        for (size_t k = x1; k < x2; ++k) {
            z = vector_of_classes[k].get_int_();
            vec2[schetchik].set_int_(z);
            ++schetchik;
        }
        schetchik = 0;
        sort(vec2.begin(), vec2.end(), sortfunction_classes);
    }
}


//main block
int main()
{
    int flag;
    cout << "enter example data type:\n";
    cout << " 1) int vector\n 2) vector of classes sorted by ints\n";
    cin >> flag;
    //example of sort and visualisation on typical data 
    if (flag == 1) {
        unsigned int start_time = clock();
        //creation block
        vector<int> example;
        int a = 0;
        int size = 50;
        for (size_t i = 0; i < size; ++i) {
            a = rand() % 100;
            example.push_back(a);
        }
        ex Void_(example);

        Void_.visualisation1_int_ex();
        Void_.visualisation2_int_ex();
        cout << example.size() << endl;

        //merge
        int tik = 1;
        int x1, x2;
        vector<int> finish;
        vector<int>a11, a22;
        x1 = 0;
        x2 = size / 8 * tik;

        int schetchik = 0;
        int sizi = 8;
        int schet = 0;

        for (size_t i = 0; i < x2; ++i) {
            a11.push_back(0);
        }
        for (size_t i = 0; i < x2; ++i) {
            a22.push_back(0);
        }



        for (size_t i = 0; i < sizi / 2; ++i) {
            tik += 1;
            x1 = x2;
            x2 = size / 8 * tik;

            thread threadik1(threadfunction_simple_int_1, ref(x1), ref(x2), ref(size), ref(tik), ref(example), ref(a11)/*, ref(finish)*/);
            thread threadik2(threadfunction_simple_int_2_2, ref(size), ref(x1), ref(x2), ref(tik), ref(i), ref(a22), ref(example));

            threadik1.join();
            threadik2.join();

            for (size_t i = 0; i < a11.size(); ++i) {
                finish.push_back(a11[i]);
            }

            for (size_t i = 0; i < a22.size(); ++i) {
                finish.push_back(a22[i]);
            }
            sort(finish.begin(), finish.end(), sortfunction_int);

            tik += 1;
            x1 = x2;
            x2 = size / 8 * tik;

        }
        cout << "\n";
        cout << finish.size() << endl;
        Void_.set_finish_int_(finish);
        Void_.visualisation2_int_fin();
        Void_.visualisation1_int_fin();

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << "block's working time " << search_time << endl;

    }

    if (flag == 2) {
        unsigned int start_time = clock();
        int a = (rand() % 50);
        int size = a;
        cout << endl << "(" << a << ")";

        vector<ex> vector_of_classes(a);
        for (size_t i = 0; i < vector_of_classes.size(); ++i) {
            a = rand() % 100;
            vector_of_classes[i].set_int_(a);
        }
        classes_visualisation(vector_of_classes);
        visualisation_classes_1(vector_of_classes);

        vector<ex> vec1(size / 8);
        vector<ex> vec2(size / 8);
        int tik = 1;
        int x1, x2, z = 0;
        x1 = 0;
        x2 = size / 8 * tik;

        vector<ex> finish;

        int siize = size;

        for (size_t i = 0; i < 4; ++i) {
            tik += 1;
            x1 = x2;
            x2 = size / 8 * tik;


            thread t1(thread_function_classes_1, ref(x1), ref(x2), ref(tik), ref(size), ref(vec1), ref(vector_of_classes));
            thread t2(thread_function_classes_2, ref(x1), ref(vec2), ref(x2), ref(i), ref(tik), ref(size), ref(vector_of_classes));


            t1.join();
            t2.join();


            for (size_t i = 0; i < vec1.size(); ++i) {
                finish.push_back(vec1[i]);
            }

            for (size_t i = 0; i < vec2.size(); ++i) {
                finish.push_back(vec2[i]);
            }

            sort(finish.begin(), finish.end(), sortfunction_classes);
            tik += 1;
            x1 = x2;
            x2 = size / 8 * tik;
        }

        cout << endl << "(" << finish.size() << ")";
        classes_visualisation(finish);
        visualisation_classes_1(finish);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << "block's working time " << search_time << endl;
    }
    cout << "\n\nProgramm finished working.\n";
}


//  1)  без многопоточности стандартные данные - 631
//  2)  с многопоточностью стандартные данные - 552
//  3)  без многопоточности нестандартные данные - 640
//  4)  с многопоточностью нестандартные данные - 491
