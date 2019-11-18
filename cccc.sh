#!/bin/bash

COVERAGE_FILE=coverage.info

REPORT_FOLDER=coverage_report

rm ${COVERAGE_FILE}
rm ${COVERAGE_FILE}_tmp
rm -rf ${REPORT_FOLDER}
lcov --rc lcov_branch_coverage=1 -c -d "build/CMakeFiles/main.dir" -o ${COVERAGE_FILE}_tmp
lcov --rc lcov_branch_coverage=1 -c -d "build/test/CMakeFiles/unittest.dir" -o ${COVERAGE_FILE}_tmp

lcov --rc lcov_branch_coverage=1 -e ${COVERAGE_FILE}_tmp "*src*" -o ${COVERAGE_FILE}

genhtml --rc genhtml_branch_coverage=1 ${COVERAGE_FILE} -o ${REPORT_FOLDER}
cd ${REPORT_FOLDER}
open index.html