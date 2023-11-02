/*
Необходимо реализовать структуру данных Куча поддерживающую следующие операции:

CLEAR — сделать кучу пустой.
ADD n — добавить в кучу число n.
EXTRACT — удалить из кучи максимальное значение и вывести на экран данное значение.
Если куча была пустой, необходимо вывести слово "CANNOT".

Суммарное количество всех операций не превышает 200000.
*/


#include <iostream>
#include <vector>
#include <sstream>

class MaxHeap {
public:
    MaxHeap() {}

    void clear()
    {
        heap.clear();
    }

    void add(int key)
    {
        heap.push_back(key);
        int c_id = heap.size();
        if (c_id == 1) return;
        while (c_id > 1)
        {
            int p_id = c_id / 2;
            if (heap[c_id - 1] > heap[p_id - 1])
            {
                std::swap(heap[p_id - 1], heap[c_id - 1]);
                c_id = p_id;
            }
            else break;
        }
    }

    void extract()
    {
        if (heap.empty())
        {
            std::cout << "CANNOT" << std::endl;
            return;
        }

        int maxVal = heap[0];
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0);
        std::cout << maxVal << std::endl;
    }

private:
    std::vector<int> heap;

    void heapify(int i)
    {
        int max = i;
        int n = heap.size();
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[max]) max = left;
        if (right < n && heap[right] > heap[max]) max = right;
        if (max != i)
        {
            std::swap(heap[i], heap[max]);
            heapify(max);
        }
        return;
    }
};

int main()
{
    MaxHeap heap;

    std::string str, func_name;
    int func_val;
    while(std::getline(std::cin, str))
    {
        std::istringstream iss(str);
        if (iss >> func_name)
        {
            if (iss >> func_val)
                heap.add(func_val);
            else if (func_name == "CLEAR")
                heap.clear();
            else if (func_name == "EXTRACT")
                heap.extract();
            else continue;
        }
        else break;
    }
    return 0;
}
