add_test([=[TimeTestCosyruct.BasicAssertions3]=]  C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test/Debug/test_time_app.exe [==[--gtest_filter=TimeTestCosyruct.BasicAssertions3]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTestCosyruct.BasicAssertions3]=]  PROPERTIES WORKING_DIRECTORY C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTestSet.BasicAssertions]=]  C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test/Debug/test_time_app.exe [==[--gtest_filter=TimeTestSet.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTestSet.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTestNormilize.BasicAssertions2]=]  C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test/Debug/test_time_app.exe [==[--gtest_filter=TimeTestNormilize.BasicAssertions2]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTestNormilize.BasicAssertions2]=]  PROPERTIES WORKING_DIRECTORY C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  test_time_app_TESTS TimeTestCosyruct.BasicAssertions3 TimeTestSet.BasicAssertions TimeTestNormilize.BasicAssertions2)
