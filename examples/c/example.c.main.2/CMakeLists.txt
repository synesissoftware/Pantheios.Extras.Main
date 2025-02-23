define_example_program(example.c.main.2 example.c.main.2.c)

target_link_libraries(example.c.main.2
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.fprintf
		Pantheios::Pantheios.bec.fprintf
		Pantheios::Pantheios.util
)
