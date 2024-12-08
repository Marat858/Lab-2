#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void shell_sort(int* arr, int n) {
    int step = 1;
    while (step < n / 3) {
        step = 3 * step + 1;
    }
    while (step != 0) {
        for (int i = step; i < n; i++) {
            int t = arr[i];
            int j = i;
            while (j >= step && arr[j - step] > t) {
                arr[j] = arr[j - step];
                j -= step;
            }
            arr[j] = t;
        }
        step = (step - 1) / 3;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(0)); 
    const int n = 100;
    int a[n], b[n];
    for (int i = 0; i < 100; i++) {
        a[i] = rand() % 199 - 99;
        b[i] = a[i];
        
    }

    steady_clock::time_point start = steady_clock::now();
    shell_sort(b, n);
    /*
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (b[j] > b[j + 1])
                swap(b[j], b[j + 1]);
        }
    }
    */
    steady_clock::time_point finish = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(finish - start);
    cout << "Sorting time (in seconds): " << time_span.count() << endl;

   

    /*
    for (int i = 0; i < 100; i++)
        cout << a[i] << " ";
    */
    start = steady_clock::now();
    int minimum_sort = a[0], maximum_sort = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minimum_sort)
            minimum_sort = a[i];
        if (a[i] > maximum_sort)
            maximum_sort = a[i];
    }
    finish = steady_clock::now();
    time_span = duration_cast<duration<double>>(finish - start);
    cout << "Finding max and min in unsorted array (in seconds): " << time_span.count() << endl;
    cout << "max = " << maximum_sort << ", min = " << minimum_sort << endl << endl;

    start = steady_clock::now();
    int minimum_unsort = b[0], maximum_unsort = b[n - 1];
    finish = steady_clock::now();
    time_span = duration_cast<duration<double>>(finish - start);
    cout << "Finding max and min in sorted array (in seconds): " << time_span.count() << endl;
    cout << "max = " << maximum_unsort << ", min = " << minimum_unsort << endl << endl;
    //4
    int srednee = (maximum_sort + minimum_sort) / 2;
    cout << "srednee = " << srednee << endl;
    start = steady_clock::now();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == srednee) {
            cout << "i = " << i << endl;
            count++;
        }
    }
    finish = steady_clock::now();
    time_span = duration_cast<duration<double>>(finish - start);
    cout << "Time of finding srednee: " << time_span.count() << endl;
    cout << "count = " << count << endl;
    //5
        
    int a_, stop = 0;
    cin >> a_;
    for (int i = 0; i < n; i++) {
        if (b[i] >= a_) {
            stop = i;
            break;
        }
    }
    cout << "num of min = " << stop << endl;

    int b_, pause = 0;
    cin >> b_;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] <= b_) {
            pause = n - i - 1;
            break;
        }
    }
    cout << "num of max = " << pause << endl;

    // 7 задание

    int to_find_number;
    cin >> to_find_number;
    start = steady_clock::now();
    int i_ = 0, j_ = n - 1;
    bool flag = false;
    while (i_ <= j_ && flag != true) {
        int mid = (i_ + j_) / 2;
        if (b[mid] == to_find_number) {
            flag = true;
        }
        else if (b[mid] < to_find_number) {
            i_ = mid + 1;
        }
        else {
            j_ = mid - 1;
        }
    }
    finish = steady_clock::now();
    time_span = duration_cast<duration<double>>(finish - start);
    cout << "Binary search: " << time_span.count() << endl;
    if (flag == true) {
        cout << "There is a element in array b." << endl;
    }
    else {
        cout << "No element in array b." << endl;
    }
    cout << endl;

    start = steady_clock::now();
    flag = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == to_find_number) {
            flag = true;
        }
    }
    finish = steady_clock::now();
    time_span = duration_cast<duration<double>>(finish - start);
    cout << "Time of perebor: " << time_span.count() << endl;
    if (flag == true) {
        cout << "There is a element in array b." << endl;
    }
    else {
        cout << "No element in array b." << endl;
    }

    int x, y;
    cin >> x >> y;
    start = steady_clock::now();
    swap(a[x], a[y]);
    finish = steady_clock::now();
    time_span = duration_cast<duration<double>>(finish - start);
    cout << "Time of swap: " << time_span.count() << endl;
}
