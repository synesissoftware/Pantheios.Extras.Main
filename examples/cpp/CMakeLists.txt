add_subdirectory(example.cpp.main.1)
add_subdirectory(example.cpp.main.2)
if(WIN32)

	add_subdirectory(example.cpp.main.MFC)
	add_subdirectory(example.cpp.wmain)
endif(WIN32)
