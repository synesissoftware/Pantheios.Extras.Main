define_example_program(example.cpp.main.2 example.cpp.main.2.cpp)

target_link_libraries(example.cpp.main.2
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.fprintf
		Pantheios::Pantheios.bec.fprintf
		Pantheios::Pantheios.util
)
