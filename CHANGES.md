# Pantheios.Extras.Main - Changes <!-- omit in toc -->


## 0.2.1-beta2 - 13th October 2026

* Advanced the library version to **0.2.1-beta2** (`PANTHEIOS_EXTRAS_MAIN_VER_0_2_1_BETA_2`, `PANTHEIOS_EXTRAS_MAIN_VER_RELSTATUS` **0x82**);
* Migrated the version low-byte macro to **`PANTHEIOS_EXTRAS_MAIN_VER_RELSTATUS`**, retaining **`PANTHEIOS_EXTRAS_MAIN_VER_ALPHABETA`** as a documentation-skip alias;
* Gold-copied tip **`run_all_examples.*`** / **`run_all_scratch_tests.*`** (**misc-dev-scripts** `@dfa6add` ATF dialect); left optional **`.sis`** ATF lists absent;
* Re-synced tip **`run_all_examples.sh`** / **`run_all_scratch_tests.*`** / **`run_all_unit_tests.sh`** from **misc-dev-scripts** `cmake-helpers` `@0754c23` (kept tip **`run_all_examples.cmd`**);
* Added modular GitHub Actions CI (**`ci.yml`** + **`ci-cell.yml`** + **`install-sis-deps`**): artifact split, execute-bit restore, Windows **`.cmd`** dogfood; deps **`STLSoft shwild xTests Pantheios`** (no **b64**); README CI badge targets **`ci.yml`**;
* Exported **`Pantheios.Extras.Main`** now **INTERFACE**-links **STLSoft** / **Pantheios** when found as packages, with matching **`find_dependency()`** in the installed config (xTests remains test-only);
* Gated **`example.cpp.main.MFC`** on **`find_package(MFC)`** and **`example.cpp.wmain`** on **`PANTHEIOS_USE_WIDE_STRINGS`**; MSVC unit-test const/`fopen` hygiene;


## 0.2.1-beta1 - 9th October 2026

* Advanced the library version to **0.2.1-beta1** (`PANTHEIOS_EXTRAS_MAIN_VER_0_2_1_BETA_1`, `PANTHEIOS_EXTRAS_MAIN_VER_ALPHABETA` **0x81**);
* Applied **misc-dev-scripts** **0.6.0** editor/Git/`.sis` drop-in templates on **boilerplate**;
* Restored historical **.gitignore** patterns as a sorted union with **misc-dev-scripts** gold section layout;
* Modernised CMake helpers to the Phase 4b dialect (`SisClr_*` / `-A`, `sis_cmake_build`, no MinGW-from-`MSYSTEM`), retaining **`--stlsoft-root-dir`** and **`--wide-strings`** as project-specific **prepare_cmake.sh** flags;
* Native Windows **`run_all_*.cmd`** runners (no Bash wrap); aggregate **`run_all_automated_tests.*`**, with **`run_all_unit_tests.*`** now unit-only;
* Removed superseded **execute_performance_tests.sh** (replaced by **run_all_performance_tests.sh**);
* Renamed the scratch version-reporter target to **`test.scratch.versions`**, and added its **`efferent dependencies:`** block (**Pantheios**, **STLSoft**);


<!-- ########################### end of file ########################### -->
