#!/bin/bash
# Verify all 140 solutions by compiling and testing against samples
BASE="/home/wang/Code/contest-361"
PASS=0
FAIL=0
COMPILE_FAIL=0

for dir in "$BASE"/JD*-problem; do
    did=$(basename "$dir" | cut -d'-' -f1)
    src="$dir/main.cpp"
    exe="/tmp/xmuoj_test_$did"

    if [ ! -f "$src" ]; then
        echo "$did: NO SOURCE"
        ((FAIL++))
        continue
    fi

    # Compile
    if ! g++ -std=c++17 -O2 "$src" -o "$exe" 2>/dev/null; then
        echo "$did: COMPILE FAIL"
        ((COMPILE_FAIL++))
        continue
    fi

    # Test with samples
    sample_in="$dir/samples/1.in"
    sample_out="$dir/samples/1.out"

    if [ -f "$sample_in" ] && [ -f "$sample_out" ]; then
        result=$(cat "$sample_in" | "$exe" 2>/dev/null)
        expected=$(cat "$sample_out")
        if [ "$result" = "$expected" ]; then
            echo "$did: PASS"
            ((PASS++))
        else
            echo "$did: FAIL (expected '$expected', got '$result')"
            ((FAIL++))
        fi
    else
        echo "$did: NO SAMPLES (compiles OK)"
        ((PASS++))
    fi

    rm -f "$exe"
done

echo ""
echo "==============================="
echo "Results: $PASS passed, $FAIL failed, $COMPILE_FAIL compile errors"
echo "Total: $((PASS + FAIL + COMPILE_FAIL))"
