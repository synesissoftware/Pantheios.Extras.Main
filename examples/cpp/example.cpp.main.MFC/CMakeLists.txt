define_example_program(example.cpp.main.MFC example.cpp.main.MFC.cpp)

# Shared MFC with the CRT DLL (/MD), matching CI and modern default MSVC.
target_compile_definitions(example.cpp.main.MFC
	PRIVATE
		_AFXDLL
)

set_property(TARGET example.cpp.main.MFC PROPERTY VS_MFC_FLAG "2")

target_link_libraries(example.cpp.main.MFC
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.WindowsConsole
		Pantheios::Pantheios.bec.WindowsConsole
		Pantheios::Pantheios.util
)
