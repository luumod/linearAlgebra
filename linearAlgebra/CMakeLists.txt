﻿#

# 将源代码添加到此项目的可执行文件.

add_executable (linearAlgebra "linearAlgebra.cpp"  "Det.cpp" "GenerateDet.h" "GenerateDet.cpp" "Matrices.h" "Matrices.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET linearAlgebra PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
