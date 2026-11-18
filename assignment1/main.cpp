#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

const int N = 100000;

template <typename Task> //template so we can pass any code (lambda)
double timeTaken(Task task) { //to find time in ms
    auto start = steady_clock::now();
    task();
    auto end = steady_clock::now();

    return duration<double, milli>(end - start).count();
}

void insertAll(vector<int>& c, vector<int>& data) //same name for 3 containers (function overloading)
{
    for (int x : data)
        c.push_back(x);
}
void insertAll(list<int>& c, vector<int>& data)
{
    for (int x : data) {
        c.push_back(x);
    }
}


void insertAll(forward_list<int>& c, vector<int>& data) {
    auto last = c.before_begin(); //no push_back in forward_list so keep last node
    for (int x : data)
        last = c.insert_after(last, x); //insert after last node
}

void stlSort(vector<int>& c) { sort(c.begin(), c.end()); } //vector dont have sort() so using std::sort
void stlSort(list<int>& c) { c.sort(); } //list have its own sort()
void stlSort(forward_list<int>& c) { c.sort(); }

template <typename T> //T can be vector,list or forward_list
void runPart1(vector<int>& asc, vector<int>& desc, vector<int>& randC, vector<int>& randG)
{
    T A, B, C, E, F, G;

    cout << "a) insert ascending in A: " << timeTaken([&] { insertAll(A, asc); }) << " ms" << endl; //[&] means lambda can use A,B,C etc from outside
    cout << "b) insert descending in B: " << timeTaken([&] { insertAll(B, desc); }) << " ms" << endl;
    cout << "c) insert random in C: " << timeTaken([&] { insertAll(C, randC); }) << " ms" << endl;

    double t;
    t = timeTaken([&] { stlSort(A); });
    cout << "d) stl sort A (ascending): " << t << " ms" << endl;
    t = timeTaken([&] {stlSort(B); });
    cout << "d) stl sort B (descending): " << t << " ms" << endl;
    t = timeTaken([&] { stlSort(C); });
    cout << "d) stl sort C (random): " << t << " ms" << endl;


    cout << "e) insert ascending in E: " << timeTaken([&] { insertAll(E, asc); }) << " ms" << endl;

    cout << "f) insert descending in F: " << timeTaken([&] {insertAll(F, desc); }) << " ms" << endl;
    cout << "g) insert random in G: "
        << timeTaken([&] { insertAll(G, randG); }) << " ms" << endl;

    auto isOdd = [](int x) { return x % 2 != 0; }; //lambda for odd numbers
    cout << "h) erase odd from E: " << timeTaken([&] { erase_if(E, isOdd); }) << " ms" << endl; //erase_if removes all odd ( This function work only in 20+ versions so sir please run it accordingly if you got any error.

    cout << "h) erase odd from F: " << timeTaken([&] { erase_if(F, isOdd); }) << " ms" << endl;

    cout << "h) erase odd from G: " << timeTaken([&] { erase_if(G, isOdd); }) << " ms" << endl;
}

void heapify(vector<int>& arr, int n, int root) //make parent bigger than its children
{
    int big = root; //assume parent is biggest
    int l = 2 * root + 1; //left child
    int r = 2 * root + 2; //right child

    if (l < n && arr[l] > arr[big])
        big = l;
    if (r < n && arr[r] > arr[big])
        big = r;
    if (big != root) { //child is bigger so swap and check again
        swap(arr[root], arr[big]);
        heapify(arr, n, big);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) //build max heap
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); //largest goes to end
        heapify(arr, i, 0); //fix heap for remaining part
    }
}

void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) //shift bigger values one step right
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; //put temp at its place
    }
}

void runPart2(vector<int>& asc, vector<int>& desc, vector<int>& randC, vector<int>& randG)
{
    vector<int> A = asc, B = desc, C = randC; //new copies bcz part 1 ones are already sorted
    cout << "c) heap sort A (ascending): " << timeTaken([&] { heapSort(A); }) << " ms" << endl;
    cout << "c) heap sort B (descending): " << timeTaken([&] { heapSort(B); }) << " ms" << endl;
    cout << "c) heap sort C (random): " << timeTaken([&] { heapSort(C); }) << " ms" << endl;

    vector<int> E = asc, F = desc, G = randG;

    cout << "d) insertion sort E (ascending): " << timeTaken([&] { insertionSort(E); }) << " ms" << endl;
    cout << "d) insertion sort F (descending): " << timeTaken([&] { insertionSort(F); }) << " ms" << endl; //this one takes long
    cout << "d) insertion sort G (random): "
        << timeTaken([&] { insertionSort(G); }) << " ms" << endl;
}

int main() {
    mt19937 randnum(time(0)); //random generator, time(0) so numbers change every run
    uniform_int_distribution<int> range(1, 1000000); //numbers from 1 to 1000000

    vector<int> asc, desc, randC, randG; //data made once so all containers get same values
    for (int i = 1; i <= N; i++)
    {
        asc.push_back(i);
        desc.push_back(N - i + 1);
        randC.push_back(range(randnum));
        randG.push_back(range(randnum));
    }

    cout << "Part 1 - vector" << endl;
    runPart1<vector<int>>(asc, desc, randC, randG);

    cout << endl << "Part 1 - list" << endl;
    runPart1<list<int>>(asc, desc, randC, randG);
    cout << endl << "Part 1 - forward_list" << endl;
    runPart1<forward_list<int>>(asc, desc, randC, randG);

    cout << endl << "Part 2 - vector" << endl;
    runPart2(asc, desc, randC, randG);

    return 0;
}