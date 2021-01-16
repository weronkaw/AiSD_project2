#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include<fstream>
#include<conio.h>
using namespace std;

const int N = 100; // Liczebnosc zbioru.

int d[N],p[N];

        // Procedura sortujaca ( sortowanie prze scalanie )
        //--------------------------------------------------

void MergeSort(int i_p, int i_k)
{
  int i_s,i1,i2,i;

  i_s = (i_p + i_k + 1) / 2;
  if(i_s - i_p > 1) MergeSort(i_p, i_s - 1);
  if(i_k - i_s > 0) MergeSort(i_s, i_k);
  i1 = i_p; i2 = i_s;
  for(i = i_p; i <= i_k; i++)
    p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++];
  for(i = i_p; i <= i_k; i++) d[i] = p[i];


}



        // procedura sortujaca (sortowanie szybkie)
        // ------------------------------------------

void QuickSort(int left, int right)
{
  int i,j,pivot;

  i = (left + right) / 2;
  pivot = d[i]; d[i] = d[right];
  for(j = i = left; i < right; i++)
  if(d[i] < pivot)
  {
    swap(d[i], d[j]);
    j++;
  }
  d[right] = d[j]; d[j] = pivot;
  if(left < j - 1)  QuickSort(left, j - 1);
  if(j + 1 < right) QuickSort(j + 1, right);


}

            // Program glowny
            //---------------

int main()
{
    int i;
    int answer=0;

cout << "Chcesz uzyc losowych liczb czy danych z pliku?(0/1): ";
cin >> answer;
cout<<endl;

    if(answer==0)
        {
        cout << "tablica nie posortowanych liczb:\n"
          "---------------------------\n";
        // Najpierw wypelniamy tablice d[] liczbami pseudolosowymi
        // a nastepnie wyswietlamy jej zawartosc

        srand((unsigned)time(NULL));

            for(i = 0; i < N; i++) d[i] = rand() % 1000;
            for(i = 0; i < N; i++) cout << setw(4) << d[i];
        cout << endl;
        }


    else if(answer==1)
    {
                //wczytywanie pliku
        fstream plik;
        string linia;

            plik.open("dane.txt", ios::in);
            if(plik.good() == true)
            {
    int temp;
    for(int i = 0; i < N && plik >> temp; ++i)
        {
        d[i] = temp;

    cout<<d[i]<<setw(4);
        }
            }
    plik.close();

    }
cout<<"czy chcesz wykonac MergeSort czy QuickSort?(0/1)";
cin>>answer;
 {

    if(answer==0)
    {
        MergeSort(0,N-1);

        cout << "Po sortowaniu MergeSort: \n\n";
        for(i = 0; i < N; i++) cout << setw(4) << d[i];

        cout << endl;
    }

    else if(answer==1)
    {
        QuickSort(0,N - 1);

        cout << "Po sortowaniu QuickSort:\n\n";
        for(i = 0; i < N; i++) cout << setw(4) << d[i];
        cout << endl;

    }
cout<<"czy chcesz zapisac dane do pliku? (0/1)";
cin>>answer;
cout<<endl;

    if(answer==0)
    {
        fstream plik1;

        plik1.open("wyniki.txt", ios::out);
        for(i = 0; i < N; i++)
        {
        plik1<<d[i]<<endl;
        }
        plik1.close();

    }
 }
getch();
return 0;
}
