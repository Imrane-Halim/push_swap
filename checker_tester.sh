#!/bin/bash

# Default values
ITERATIONS=5  # Default number of iterations
VERBOSE=0     # Default verbose mode off

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Help function
show_help() {
    echo "Usage: $0 [OPTIONS]"
    echo "Options:"
    echo "  -i, --iterations N    Number of iterations for each test (default: 5)"
    echo "  -v, --verbose        Enable verbose output"
    echo "  -h, --help           Show this help message"
}

# Parse command line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -i|--iterations) ITERATIONS="$2"; shift ;;
        -v|--verbose) VERBOSE=1 ;;
        -h|--help) show_help; exit 0 ;;
        *) echo "Unknown parameter: $1"; show_help; exit 1 ;;
    esac
    shift
done

# Function to generate random numbers
generate_random_numbers() {
    local count=$1
    local numbers=()
    while [ ${#numbers[@]} -lt $count ]; do
        num=$((RANDOM % 1000 - 500)) # Generate numbers between -500 and 499
        # Check if number already exists in array
        if [[ ! " ${numbers[@]} " =~ " ${num} " ]]; then
            numbers+=($num)
        fi
    done
    echo "${numbers[@]}"
}

# Function to run test case
run_test() {
    local numbers="$1"
    local test_name="$2"
    
    if [ $VERBOSE -eq 1 ]; then
        echo "Testing $test_name..."
    fi
    
    # Run push_swap and pipe to both checkers
    output_yours=$(./push_swap $numbers | ./checker $numbers)
    output_ref=$(./push_swap $numbers | ./checker_linux $numbers)
    
    if [ "$output_yours" == "$output_ref" ]; then
        if [ $VERBOSE -eq 1 ]; then
            echo -e "${GREEN}✓ Test passed: Both checkers output '$output_yours'${NC}"
        fi
        return 0
    else
        echo -e "${RED}✗ Test failed on: $test_name${NC}"
        echo "Your checker output: '$output_yours'"
        echo "Reference output  : '$output_ref'"
        echo "Input numbers: $numbers"
        return 1
    fi
}

# Counter for passed tests
passed_tests=0
total_tests=0

echo "Starting tests with $ITERATIONS iterations per test case..."

# Test 1: Empty input
if [ $VERBOSE -eq 1 ]; then
    echo "=== Test with empty input ==="
fi

output_yours=$(./checker)
output_ref=$(./checker_linux)
((total_tests++))
if [ "$output_yours" == "$output_ref" ]; then
    if [ $VERBOSE -eq 1 ]; then
        echo -e "${GREEN}✓ Empty input test passed${NC}"
    fi
    ((passed_tests++))
else
    echo -e "${RED}✗ Empty input test failed${NC}"
fi

# Test 2: Invalid input
if [ $VERBOSE -eq 1 ]; then
    echo -e "\n=== Test with invalid input ==="
fi

test_cases=(
    "a b c"
    "1 2 abc"
    "1 2 2"  # duplicate
    "2147483648"  # bigger than INT_MAX
    "-2147483649" # smaller than INT_MIN
)

for test in "${test_cases[@]}"; do
    ((total_tests++))
    if [ $VERBOSE -eq 1 ]; then
        echo "Testing input: $test"
    fi
    output_yours=$(./checker $test 2>&1)
    output_ref=$(./checker_linux $test 2>&1)
    
    if [ "$output_yours" == "$output_ref" ]; then
        if [ $VERBOSE -eq 1 ]; then
            echo -e "${GREEN}✓ Invalid input test passed${NC}"
        fi
        ((passed_tests++))
    else
        echo -e "${RED}✗ Invalid input test failed${NC}"
        echo "Input: $test"
        echo "Your checker output: '$output_yours'"
        echo "Reference output  : '$output_ref'"
    fi
done

# Test 3: Valid inputs with different operations
if [ $VERBOSE -eq 1 ]; then
    echo -e "\n=== Test with valid inputs ==="
fi

test_cases=(
    "3 2 1"
    "1 2 3"
    "42"
    "-42"
)

for ((i=1; i<=$ITERATIONS; i++)); do
    for numbers in "${test_cases[@]}"; do
        ((total_tests++))
        run_test "$numbers" "numbers: $numbers (iteration $i)"
        if [ $? -eq 0 ]; then
            ((passed_tests++))
        fi
    done
done

# Test 4: Random number tests
if [ $VERBOSE -eq 1 ]; then
    echo -e "\n=== Random number tests ==="
fi

sizes=(3 5 10 100)

for ((i=1; i<=$ITERATIONS; i++)); do
    for size in "${sizes[@]}"; do
        ((total_tests++))
        numbers=$(generate_random_numbers $size)
        run_test "$numbers" "$size random numbers (iteration $i)"
        if [ $? -eq 0 ]; then
            ((passed_tests++))
        fi
    done
done

# Print summary
echo -e "\n=== Summary ==="
echo "Passed tests: $passed_tests/$total_tests"
if [ $passed_tests -eq $total_tests ]; then
    echo -e "${GREEN}All tests passed!${NC}"
else
    echo -e "${RED}Some tests failed.${NC}"
fi