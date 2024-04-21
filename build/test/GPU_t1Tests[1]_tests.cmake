add_test([=[CPPLib.MatrixCreate]=]  /home/leo/Desktop/FCFM/GPU/GPU_t1/build/test/GPU_t1Tests [==[--gtest_filter=CPPLib.MatrixCreate]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CPPLib.MatrixCreate]=]  PROPERTIES WORKING_DIRECTORY /home/leo/Desktop/FCFM/GPU/GPU_t1/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  GPU_t1Tests_TESTS CPPLib.MatrixCreate)
