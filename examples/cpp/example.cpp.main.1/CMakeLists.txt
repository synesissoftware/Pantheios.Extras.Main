define_example_program(example.cpp.main.1 example.cpp.main.1.cpp)

target_link_libraries(example.cpp.main.1
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.fprintf
		Pantheios::Pantheios.bec.fprintf
		Pantheios::Pantheios.util
)
