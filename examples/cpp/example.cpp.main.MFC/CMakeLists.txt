define_example_program(example.cpp.main.MFC example.cpp.main.MFC.cpp)

target_link_libraries(example.cpp.main.MFC
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.WindowsConsole
		Pantheios::Pantheios.bec.WindowsConsole
		Pantheios::Pantheios.util
)
