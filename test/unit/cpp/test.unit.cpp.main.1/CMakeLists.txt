
add_executable(test.unit.cpp.main.1
	test.unit.cpp.main.1.cpp
	test_throw_int_NO_CATCHALL.cpp
	test_throw_int_USE_CATCHALL.cpp
)

target_link_libraries(test.unit.cpp.main.1
	PRIVATE
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
		$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
)

if(WIN32)

	target_link_libraries(test.unit.cpp.main.1
		PRIVATE
			wininet
	)
endif(WIN32)

list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	writable-strings
	write-strings
)

define_target_compile_options(test.unit.cpp.main.1)

target_link_libraries(test.unit.cpp.main.1
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.lrsplit
		Pantheios::Pantheios.ber.test
		Pantheios::Pantheios.bel.null
		Pantheios::Pantheios.bec.null
		Pantheios::Pantheios.bec.test
		Pantheios::Pantheios.util
)
