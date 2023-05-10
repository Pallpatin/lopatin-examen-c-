
#include <iostream>
#include <string>
#include <fstream>
#include <string>

#define random(min,max) min+rand()%(max-min+1)

using namespace std;

#define task 14

string colavalible[5]{ "red","green","blue","black","white" };
string modelavalible[5]{ "mersedes","toyota","mazda","BMW","opel" };

struct automobile {

    string color;
    string model;

    void showauto() {
        cout << endl << color << '\t' << model;
    }
};





void firsttask(float a,float b, float c, float d) {
    cout <<endl<< (a + b + c + d / 4);
}

void secondtask() {
    for (int i = 2; i <= 40; i += 2)cout << i << "\t";
}

void thriedtask(int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++)cout << "* ";
        cout << endl;
    }
}

int fourtask(int num) {
    return size(to_string(num));
}

void sixtask(int hig,int wid) {
    int** arr = new int* [hig];
    for (int i = 0; i < hig; i++)arr[i] = new int[wid];
    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < wid; j++) {
            arr[i][j] = random(1, 100);
        }
    }
    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < wid; j++) {
            cout << arr[i][j]<< "\t";
        }
        cout << endl;
    }
    int imax = 0,max= INT_MIN;

    for (int i = 0,sum=0; i < hig; i++,sum=0) {
        for (int j = 0; j < wid; j++) {
            sum += arr[i][j];
        }
        if (max < sum) {
            max = sum;
            imax = i;
        }
        cout << endl;
    }
    cout << "\n number of max element summ row is " << imax + 1;
}

void seventask(int**& arr1,int**& arr2) {
    int sizhig = _msize(arr1) / sizeof(arr1[0]);
    int sizwid = _msize(arr1[0]) / sizeof(arr1[0][0]);
    for (int i = 0; i < sizhig; i++) {
        for (int j = 0; j < sizwid; j++)arr2[i][j] = arr1[i][j];
    }
}

void eighttask(int*& arr, int num) {
    int siz = _msize(arr) / sizeof(arr[0]);
    if (num < siz) {
        int* buf = new int[siz-1];
        for (int i = 0; i < num; i++)buf[i] = arr[i];
        for (int i = num + 1; i < siz; i++)buf[i - 1] = arr[i];
        delete[]arr;
        arr = buf;
    }
}

void ninetask(int**& arr, int* toinsert, int pozition) {
    int siz = _msize(arr) / sizeof(arr[0]);
    if (pozition <= siz) {
        int** buf = new int* [siz + 1];
        for (int i = 0; i < pozition; i++)buf[i] = arr[i];
        buf[pozition] = toinsert;
        for (int i = pozition+1; i < siz+1; i++)buf[i] = arr[i-1];
        delete[]arr;
        arr = buf;
    }
}

void tentask(int**& arr, int stolb) {
    int hig = _msize(arr) / sizeof(arr[0]);
    int wid = _msize(arr[0]) / sizeof(arr[0][0]);
    int** buf = new int* [hig];
    for (int i = 0; i < hig; i++)buf[i] = new int[wid - 1];
    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < stolb; j++)buf[i][j] = arr[i][j];
        for (int j = stolb+1; j < wid; j++)buf[i][j-1] = arr[i][j];
    }
    delete[]arr;
    arr = buf;
}

void eleven(int**& arr) {
    int hig = _msize(arr) / sizeof(arr[0]);
    int wid = _msize(arr[0]) / sizeof(arr[0][0]);
    int min = arr[0][0];
    int imin = 0;
    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < wid; j++) {
            if (min > arr[i][j]) {
                min = arr[i][j];
                imin = i;
            }
        }
    }

    int** buf = new int*[hig-1];
    for (int i = 0; i < imin; i++)buf[i] = arr[i];
    for (int i = imin + 1; i < hig; i++)buf[i - 1] = arr[i];
    delete[]arr[imin];
    delete[]arr;
    arr = buf;



}

int tvelve(string str, string wor) {
    bool flag;
    for (int i = 0; i < size(str); i++) {
        flag = 0;
        if (str[i]==wor[0])
        {
            flag = 1;
            for (int j = 1; j < size(wor); j++) {
                if (str[i + j] != wor[j]) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)return i;
    }
    return -1;
}

int main()
{
    srand(time(0));
#if task==1
    float ar1[4];
    for (int i = 0; i < 4; i++)cin>>ar1[i];
    firsttask(ar1[0], ar1[1], ar1[2], ar1[3]);

#elif task==2
    secondtask();
#elif task==3
    int tas3=0;
    cin >> tas3;
    thriedtask(tas3);
#elif task==4
    int tas4 = 0;
    cin >> tas4;
    cout << endl << fourtask(tas4);
#elif task==5
    
    const int SIZ = 10;

    int arr[SIZ];
    int min = 0, max = 10;

    cout << " input min = ";
    cin >> min;
    cout << " input max = ";
    cin >> max;
    if (min > max)swap(min, max);
    for (int i = 0; i < SIZ; i++)arr[i] = random(min, max);
    for (int i = 0; i < SIZ; i++)cout <<arr[i]<<'\t';
#elif task==6

    sixtask(5, 10);

#elif task==7

    int hig = 10;
    int wid = hig;

    int** arr1 = new int* [hig];
    for (int i = 0; i < hig; i++)arr1[i] = new int[wid];
    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < wid; j++) {
            arr1[i][j] = random(1, 100);
        }
    }

    int** arr2 = new int* [hig];
    for (int i = 0; i < hig; i++)arr2[i] = new int[wid];

    seventask(arr1, arr2);

    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < wid; j++) {
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < hig; i++) {
        for (int j = 0; j < wid; j++) {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
#elif task==8

    int* arr = new int[5]{ 1,2,3,4,5 };
    for (int i = 0; i < _msize(arr) / sizeof(arr[0]); i++)cout << arr[i] << '\t';
    eighttask(arr, 3);
    cout << endl;
    for (int i = 0; i < _msize(arr) / sizeof(arr[0]); i++)cout << arr[i] << '\t';

#elif task==9

    int* toinser = new int[4]{ 1,2,3,4 };
    int** arr = new int*[3];
    for (int i = 0; i < 3; i++)arr[i] = new int[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)arr[i][j] = random(1, 9);
    }

    for (int i = 0; i < _msize(arr) / sizeof(arr[0]); i++) {
        for (int j = 0; j < _msize(arr[i]) / sizeof(arr[i][0]); j++)cout << arr[i][j] << '\t';
        cout << endl;
    }

    ninetask(arr, toinser, 1);
    cout << endl;

    for (int i = 0; i < _msize(arr)/sizeof(arr[0]); i++) {
        for (int j = 0; j < _msize(arr[i]) / sizeof(arr[i][0]); j++)cout << arr[i][j] << '\t';
        cout << endl;
    }


#elif task==10

    int** arr = new int* [3];
    for (int i = 0; i < 3; i++)arr[i] = new int[4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)arr[i][j] = random(1, 9);
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)cout<<arr[i][j];
        cout << endl;
    }
    cout << endl;
    tentask(arr, 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)cout << arr[i][j];
        cout << endl;

    }


#elif task==11

int** arr = new int* [4];
for (int i = 0; i < 4; i++)arr[i] = new int[4];

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)arr[i][j] = random(1, 9);
}



for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)cout << arr[i][j];
    cout << endl;
}

eleven(arr);
cout << endl;

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++)cout << arr[i][j];
    cout << endl;
}
#elif task==12

cout<<tvelve("Amadeus", "deus");

#elif task==13

string path = "C:\\Users\\Взрослая академия\\Desktop\\key.txt";
ifstream in(path);
string buf;
int count = 0;

while (getline(in, buf)) count += size(buf);
cout << count;

#elif task ==14

automobile ar[3];
for (int i = 0; i < 3; i++)ar[i].color = colavalible[random(0, 5)];
for (int i = 0; i < 3; i++)ar[i].model = modelavalible[random(0, 5)];
for (int i = 0; i < 3; i++)ar[i].showauto();


#endif
}
