#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

//Heapsort implementing MAX HEAP

using namespace std;

class MaxHeap
{
private:
    vector<int> heap;
    size_t heapsize;
    const int rootindex = 1;

    /// Funzioni di utility
    void enlarge()
    {
        if (heapsize >= heap.size() - 1)
            heap.resize(heapsize * 2, INT_MIN);
    }

    void shrink()
    {
        if (heapsize < ((int)(heap.size() / 2)))
            heap.resize(heap.size() / 2);
    }

    int parent(int index) const
    {
        return index / 2;
    }

    int left(int index) const
    {
        return index * 2;
    }

    int right(int index) const
    {
        return left(index) + 1;
    }

    int size() const
    {
        return heap.size();
    }
    /*Fine funzioni di utility*/

    /**
     * Funzione per sistemare la proprietà dell'heap scambiando l'elemento ad index con il più grande dei suoi due figli. 
    */
    void maxheapify(int index)
    {

        if (index > size())
            return;

        int l, r, largest;
        largest = index;
        l = left(index), r = right(index);

        if (l < size() && heap[l] > heap[index])
            largest = l;
        if (r < size() && heap[r] > heap[largest])
            largest = r;


        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            maxheapify(largest);
        }
    }

    /**
     * Funzione custom per il float-up del figlio. Il figlio viene scambiato col parent solo se figlio.key > parent.key
    */
    void reverse_maxheapify(int index)
    {
        int padre;
        bool flag;

        flag = true;
        padre = parent(index);
        while (padre != 0 && flag)
        {
            flag = heap[index] > heap[padre];
            if (flag)
            {
                swap(heap[index], heap[padre]);
                index = padre;
                padre = parent(padre);
            }
        }
    }

public:
    MaxHeap()
    {
        MaxHeap(2);
    }

    MaxHeap(size_t size)
    {
        heapsize = size;
        heap = vector<int>(size * 2);
    }

    MaxHeap(vector<int> v)
    {
        heapsize = 1;
        heap = vector<int>(heapsize * 2);

        for (auto integer : v) //O(n * log(n))
        {
            heap_insert(integer); //O(log(n))
        }
    }

    ~MaxHeap() {}

    void heap_insert(int k)
    {
        if (heapsize == 0)
        {
            heap[1] = k;
        }
        else
        {
            heap[heapsize] = k;
            reverse_maxheapify(heapsize); //O(log(n))
        }
        heapsize++;
        enlarge();
    }

    void heap_delete(int k)
    {
        if (heapsize > 0)
        {
            heap[k] = INT_MIN;
            if (heapsize != 1)
            {
                maxheapify(k); //O(log(n))
            }
            heapsize--;
        }
    }

    int extract(int i)
    {
        int h = heap[i];
        heap_delete(i);
        return h;
    }

    int extractmax()
    {
        int h = extract(rootindex);
        return h;
    }

    bool isheapaux(int i)
    {
        if (i < heapsize)
        {
            int p = parent(i);

            return heap[p] > heap[i] && isheapaux(left(i)) && isheapaux(right(i));
        }
        return true;
    }

    bool isheap()
    {
        if (heapsize <= 1)
        {
            return true;
        }

        return isheapaux(left(rootindex)) && isheapaux(right(rootindex));
    }
};

// Roba di utility per l'heapsort
#include <stdlib.h>
#include <time.h>

#define U_LIMIT 516
#define L_LIMIT 0

void populate(vector<int> &v)
{
    srand(time(NULL));

    for (auto &c : v)
    {
        c = ((rand()) % U_LIMIT) + L_LIMIT;
    }
}

vector<int> heapsort(vector<int> &v)
{
    vector<int> res(v.size());
    int i;
    MaxHeap p(v);

    for (auto &c : res)
        c = p.extractmax();

    return res;
}