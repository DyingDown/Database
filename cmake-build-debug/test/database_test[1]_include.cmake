if(EXISTS "D:/Study/Code/Database/Database/cmake-build-debug/test/database_test[1]_tests.cmake")
  include("D:/Study/Code/Database/Database/cmake-build-debug/test/database_test[1]_tests.cmake")
else()
  add_test(database_test_NOT_BUILT database_test_NOT_BUILT)
endif()
