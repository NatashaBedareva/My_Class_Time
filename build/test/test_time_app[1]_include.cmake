if(EXISTS "C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test/test_time_app[1]_tests.cmake")
  include("C:/Users/Bedareva/Documents/STADING_NGU/OOP/kvadraturawn/build/test/test_time_app[1]_tests.cmake")
else()
  add_test(test_time_app_NOT_BUILT test_time_app_NOT_BUILT)
endif()