if(EXISTS "C:/Users/Leone/Escritorio/FCFM/9no_Semestre/GPU/GPU_t1/out/build/x64-Debug/test/GPU_t1Tests[1]_tests.cmake")
  include("C:/Users/Leone/Escritorio/FCFM/9no_Semestre/GPU/GPU_t1/out/build/x64-Debug/test/GPU_t1Tests[1]_tests.cmake")
else()
  add_test(GPU_t1Tests_NOT_BUILT GPU_t1Tests_NOT_BUILT)
endif()