define_example_program(example.cpp.wmain example.cpp.wmain.cpp)

target_link_libraries(example.cpp.wmain
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.WindowsConsole
		Pantheios::Pantheios.bec.WindowsConsole
		Pantheios::Pantheios.util
)
