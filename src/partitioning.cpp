#include "assignment/partitioning.hpp"

#include <utility>  // swap
#include <cassert>  // assert
#include <algorithm>  // sort
#include <vector>

namespace assignment {

  int median_of_three(const std::vector<int>& arr, int start, int stop) {
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    // вычисляем размер области
    const int size = stop - start + 1;

    // В случае отсутствия как минимум 3 элементов в указанной области,
    // возвращаем индекс правой границы.
    if (size < 3) {
      return stop;
    }

    const int middle = middle_of(start, stop);

    if (arr[start] >= arr[middle] && arr[start] <= arr[stop] || arr[start] <= arr[middle] && arr[start] >= arr[stop]) {
      return start;
    }

    if (arr[start] >= arr[middle] && arr[middle] >= arr[stop] || arr[start] <= arr[middle] && arr[middle] <= arr[stop]) {
      return middle;
    }

    if (arr[start] <= arr[stop] && arr[middle] >= arr[stop] || arr[start] >= arr[stop] && arr[middle] <= arr[stop]) {
      return middle;
    }

  }

  int partition(std::vector<int>& arr, int start, int stop, int pivot) {
    assert(pivot >= start && pivot <= stop);
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    // Tips:
    // 1. Переместите опорный элемент в конец области (потом вернем на нужно место)
    // 2. Заведите переменную "индекс опорного элемента" = начало области (он будет обновляться)
    // 3. Пройдитесь в цикле по всем индексам (конец исключительно) и произведите разбиение,
    //    передвигая "индекс опорного элемента" в определенных случая вправо.
    // 4. По завершении цикла в "индексе опорного элемента" находится значение корректной позиции для опорного элемента,
    //    переместите опорный элемент на корректную позицию.

    // значение опорного элемента
    const int pivot_value = arr[pivot];

    // переместить опорный элемент в конец (чтобы не мешался)
    std::swap(arr[pivot], arr[stop]);

    // индекс опорного элемента (будет вычисляться далее, изначально находится в начале области)
    int curr_pivot_index = start;

    // вычисление индекса опорного элемента и перемещение элементов по правилу разбиения
    for (int index = start; index < stop; index++) {

      if (arr[index] < pivot_value) {
        std::swap(arr[index], arr[curr_pivot_index]);
        curr_pivot_index++;
      }
    }

    // разбиение завершилось, перемещаем выбранный опорный элемент на вычисленное ранее место
    std::swap(arr[curr_pivot_index], arr[stop]);

    // возвращаем индекс опорного элемента
    return curr_pivot_index; /* здесь что-то не так ... */;
  }

}  // namespace assignment