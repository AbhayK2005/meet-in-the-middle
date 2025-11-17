#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/median.hpp"

#include <fstream>

TEST_CASE("DynamicArray basic operations") {
    DynamicArray arr;

    SECTION("New array is empty") {
        REQUIRE(arr.is_empty());
        REQUIRE(arr.get_size() == 0);
    }

    SECTION("Can push and retrieve values") {
        arr.push_back(5);
        REQUIRE(arr.get_size() == 1);
        REQUIRE(arr.get(0) == 5);
        REQUIRE_FALSE(arr.is_empty());
    }

    SECTION("Can push multiple values") {
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);

        REQUIRE(arr.get_size() == 3);
        REQUIRE(arr.get(0) == 1);
        REQUIRE(arr.get(1) == 2);
        REQUIRE(arr.get(2) == 3);
    }

    SECTION("Throws exception for out of range access") {
        arr.push_back(1);
        REQUIRE_THROWS_AS(arr.get(1), std::out_of_range);
    }
}

TEST_CASE("Calculate median with odd number of elements") {
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(11);
    arr.push_back(27);
    arr.push_back(45);
    arr.push_back(71);
    arr.push_back(90);
    arr.push_back(104);

    double median = calculate_median(arr);
    REQUIRE(median == 11.0);
}

TEST_CASE("Calculate median with even number of elements") {
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(8);

    double median = calculate_median(arr);
    REQUIRE(median == 4.0); // (2 + 6) / 2 = 4
}

TEST_CASE("Calculate median with single element") {
    DynamicArray arr;
    arr.push_back(42);

    double median = calculate_median(arr);
    REQUIRE(median == 42.0);
}

TEST_CASE("Calculate median throws on empty array") {
    DynamicArray arr;
    REQUIRE_THROWS_AS(calculate_median(arr), std::invalid_argument);
}

TEST_CASE("Read CSV file") {
    // Create a test file
    std::string test_file = "test_data.csv";
    std::ofstream out(test_file);
    out << "1,2,6,8,9,11,27,45,71,90,104";
    out.close();

    DynamicArray arr;
    bool success = read_csv_file(test_file, arr);

    REQUIRE(success);
    REQUIRE(arr.get_size() == 11);
    REQUIRE(arr.get(0) == 1);
    REQUIRE(arr.get(5) == 11);
    REQUIRE(arr.get(10) == 104);

    // Clean up
    std::remove(test_file.c_str());
}

TEST_CASE("Read non-existent file returns false") {
    DynamicArray arr;
    bool success = read_csv_file("nonexistent_file.csv", arr);
    REQUIRE_FALSE(success);
}
