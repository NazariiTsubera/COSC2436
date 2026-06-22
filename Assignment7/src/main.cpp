#include <chrono>
#include <iostream>
#include <vector>


void heapify(std::vector<int>& input, size_t node, size_t heapSize) {
    size_t leftChild = node * 2 + 1;
    size_t rightChild = node * 2 + 2;

    size_t greatestIndex = node;

    if (leftChild < heapSize && input[leftChild] > input[greatestIndex]) {
        greatestIndex = leftChild;
    }

    if (rightChild < heapSize && input[rightChild] > input[greatestIndex]) {
        greatestIndex = rightChild;
    }

    if (greatestIndex != node) {
        std::swap(input[node], input[greatestIndex]);
        heapify(input, greatestIndex, heapSize);
    }
}

void buildMaxHeap(std::vector<int>& input) {
    if (input.empty()) {
        return;
    }

    for (int node = static_cast<int>(input.size()) / 2 - 1; node >= 0; --node) {
        heapify(input, static_cast<size_t>(node), input.size());
    }
}

std::vector<int> heapSort(const std::vector<int>& input) {
    std::vector<int> heap = input;

    if (heap.size() <= 1) {
        return heap;
    }

    buildMaxHeap(heap);

    for (size_t heapSize = heap.size(); heapSize > 1; --heapSize) {
        std::swap(heap[0], heap[heapSize - 1]);
        heapify(heap, 0, heapSize - 1);
    }

    return heap;
}

std::vector<int> bubbleSort(const std::vector<int>& bubble) {
    std::vector<int> input = bubble;

    for (size_t pass = 0; pass < input.size(); pass++) {
        for (size_t j = 0; j + 1 < input.size() - pass; j++) {
            if (input[j] > input[j + 1]) {
                std::swap(input[j], input[j + 1]);
            }
        }
    }

    return input;
}

void printArray(const std::vector<int>& input) {
    for (int value : input) {
        std::cout << value << " ";
    }

    std::cout << std::endl;
}

long long trial(
    const std::vector<int>& v,
    std::vector<int> (*func)(const std::vector<int>&)
) {
    auto start = std::chrono::steady_clock::now();

    std::vector<int> result = func(v);

    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> input(size);

    for (size_t i = 0; i < size; i++) {
        input[i] = rand() % 100;
    }

    return input;
}

int main() {
    std::vector<int> random = generateRandomVector(100000);

    for (int i = 1, number = 5000; number < random.size(); i++, number = i * 5000) {
        std::vector<int> caseOne(random.begin(), random.begin() + number);

        std::cout << "Case " << i << " - " << number << " elements" << std::endl;

        std::cout << "HeapSort   : " << trial(caseOne, heapSort) << " microseconds" << std::endl;
        std::cout << "BubbleSort : " << trial(caseOne, bubbleSort) << " microseconds" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}