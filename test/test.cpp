#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "../MergeSort.h"
#include "../MergeSort.cpp"

// Function to be tested
void sortArray(std::vector<int>& arr) {
    MergeSort mergeSort(arr.size(), arr.data());
    mergeSort.mergeSort(arr.data(), 0, arr.size() - 1);
}

// Test case: zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco
TEST(SortArrayTest, AlreadySortedArray) {
    std::cout << "Running AlreadySortedArray test" << std::endl;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = arr;
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: sortuje tablicę z elementami w odwrotnej kolejności
TEST(SortArrayTest, ReverseSortedArray) {
    std::cout << "Running ReverseSortedArray test" << std::endl;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: sortuje tablicę z jednym elementem
TEST(SortArrayTest, SingleElementArray) {
    std::cout << "Running SingleElementArray test" << std::endl;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: sortuje tablicę z powtarzającymi się elementami
TEST(SortArrayTest, RepeatedElementsArray) {
    std::cout << "Running RepeatedElementsArray test" << std::endl;
    std::vector<int> arr = { 5, 5, 1, 5, 5 };
    std::vector<int> expected = { 1, 5, 5, 5, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: sortuje pustą tablicę
TEST(SortArrayTest, EmptyArray) {
    std::cout << "Running EmptyArray test" << std::endl;
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(SortArrayTest, NegativeNumbersArray) {
    std::cout << "Running NegativeNumbersArray test" << std::endl;
    std::vector<int> arr = { -5, -1, -3, -2, -4 };
    std::vector<int> expected = { -5, -4, -3, -2, -1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(SortArrayTest, MixedNegativePositiveArray) {
    std::cout << "Running MixedNegativePositiveArray test" << std::endl;
    std::vector<int> arr = { -1, 2, -3, 4, -5 };
    std::vector<int> expected = { -5, -3, -1, 2, 4 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablicę z duplikatami liczb
TEST(SortArrayTest, DuplicatesArray) {
    std::cout << "Running DuplicatesArray test" << std::endl;
    std::vector<int> arr = { 3, 1, 2, 3, 1, 2 };
    std::vector<int> expected = { 1, 1, 2, 2, 3, 3 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice ujemną z duplikatami
TEST(SortArrayTest, NegativeDuplicatesArray) {
    std::cout << "Running NegativeDuplicatesArray test" << std::endl;
    std::vector<int> arr = { -3, -1, -2, -3, -1, -2 };
    std::vector<int> expected = { -3, -3, -2, -2, -1, -1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(SortArrayTest, MixedDuplicatesArray) {
    std::cout << "Running MixedDuplicatesArray test" << std::endl;
    std::vector<int> arr = { -1, 2, -3, 4, -5, 2, -1, 4 };
    std::vector<int> expected = { -5, -3, -1, -1, 2, 2, 4, 4 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej
TEST(SortArrayTest, TwoElementsArray) {
    std::cout << "Running TwoElementsArray test" << std::endl;
    std::vector<int> arr = { 2, 1 };
    std::vector<int> expected = { 1, 2 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów
TEST(SortArrayTest, LargeArrayOver100) {
    std::cout << "Running LargeArrayOver100 test" << std::endl;
    std::vector<int> arr(150);
    std::iota(arr.begin(), arr.end(), 0);
    std::vector<int> expected = arr;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

// Test case: poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(SortArrayTest, LargeMixedArrayOver100) {
    std::cout << "Running LargeMixedArrayOver100 test" << std::endl;
    std::vector<int> arr(150);
    std::generate(arr.begin(), arr.end(), []() { return rand() % 200 - 100; });
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}