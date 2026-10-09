# Pantheios.Extras.Main - Changes <!-- omit in toc -->


## Unreleased

* Applied **misc-dev-scripts** **0.6.0** editor/Git/`.sis` drop-in templates on **boilerplate**;
* Restored historical **.gitignore** patterns as a sorted union with **misc-dev-scripts** gold section layout;
* Modernised CMake helpers to the Phase 4b dialect (`SisClr_*` / `-A`, `sis_cmake_build`, no MinGW-from-`MSYSTEM`), retaining **`--stlsoft-root-dir`** and **`--wide-strings`** as project-specific **prepare_cmake.sh** flags;
* Native Windows **`run_all_*.cmd`** runners (no Bash wrap); aggregate **`run_all_automated_tests.*`**, with **`run_all_unit_tests.*`** now unit-only;
* Removed superseded **execute_performance_tests.sh** (replaced by **run_all_performance_tests.sh**);
* Renamed the scratch version-reporter target to **`test.scratch.versions`**, and added its **`efferent dependencies:`** block (**Pantheios**, **STLSoft**);
