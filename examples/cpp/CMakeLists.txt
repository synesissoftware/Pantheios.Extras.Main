add_subdirectory(example.cpp.main.1)
add_subdirectory(example.cpp.main.2)
if(WIN32)

	# Requires shared MFC (/MD + _AFXDLL). CI cells pass
	# -DCMAKE_DISABLE_FIND_PACKAGE_MFC=TRUE, so the example is skipped there.
	find_package(MFC QUIET)
	if(MFC_FOUND)

		set(CMAKE_MFC_FLAG 2)
		add_subdirectory(example.cpp.main.MFC)
	else(MFC_FOUND)

		message(STATUS "MFC not found; skipping example.cpp.main.MFC")
	endif(MFC_FOUND)

	# wmain + wchar_t invoke overloads need a wide-string Pantheios build
	if(PANTHEIOS_USE_WIDE_STRINGS)

		add_subdirectory(example.cpp.wmain)
	else(PANTHEIOS_USE_WIDE_STRINGS)

		message(STATUS "PANTHEIOS_USE_WIDE_STRINGS off; skipping example.cpp.wmain")
	endif(PANTHEIOS_USE_WIDE_STRINGS)
endif(WIN32)
