# Microsoft Developer Studio Project File - Name="example.cpp.main.1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=example.cpp.main.1 - Win32 Unicode Debug wmain
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "example.cpp.main.1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "example.cpp.main.1.mak" CFG="example.cpp.main.1 - Win32 Unicode Debug wmain"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "example.cpp.main.1 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "example.cpp.main.1 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "example.cpp.main.1 - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "example.cpp.main.1 - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "example.cpp.main.1 - Win32 Unicode Debug wmain" (based on "Win32 (x86) Application")
!MESSAGE "example.cpp.main.1 - Win32 Unicode Release wmain" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "example.cpp.main.1 - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "NDEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_MBSC" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "NDEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_MBSC" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "example.cpp.main.1 - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "_DEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_MBSC" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "_DEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_MBSC" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"Debug/example.cpp.main.1.debug.exe" /pdbtype:sept /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "example.cpp.main.1 - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "_DEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "_DEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"Debug/example.cpp.main.1.debug.exe" /pdbtype:sept /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"Debug/example.cpp.main.1.debug.exe" /pdbtype:sept /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "example.cpp.main.1 - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU"
# PROP BASE Intermediate_Dir "ReleaseU"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU"
# PROP Intermediate_Dir "ReleaseU"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "NDEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "WIN32" /D "NDEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "example.cpp.main.1 - Win32 Unicode Debug wmain"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU_wmain"
# PROP BASE Intermediate_Dir "DebugU_wmain"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU_wmain"
# PROP Intermediate_Dir "DebugU_wmain"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "USE_wmain" /D "WIN32" /D "_DEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "USE_wmain" /D "WIN32" /D "_DEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"Debug/example.cpp.main.1.debug.exe" /pdbtype:sept /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /debug /machine:I386 /out:"DebugU_wmain/example.cpp.main.1.debug.exe" /pdbtype:sept /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "example.cpp.main.1 - Win32 Unicode Release wmain"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU_wmain"
# PROP BASE Intermediate_Dir "ReleaseU_wmain"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU_wmain"
# PROP Intermediate_Dir "ReleaseU_wmain"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "USE_wmain" /D "WIN32" /D "NDEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "$(PANTHEIOS_EXTRAS_MAIN_ROOT)/include" /I "$(PANTHEIOS_ROOT)/include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "USE_wmain" /D "WIN32" /D "NDEBUG" /D "STLSOFT_FORCE_C_COMPILATION_IN_BETA" /D "STRICT" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 advapi32.lib comdlg32.lib gdi32.lib kernel32.lib odbc32.lib odbccp32.lib ole32.lib oleaut32.lib shell32.lib user32.lib uuid.lib winspool.lib ws2_32.lib /nologo /version:0.1 /subsystem:console /map /machine:I386 /libpath:"$(PANTHEIOS_ROOT)/lib" /libpath:"$(UNIXEM)/lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "example.cpp.main.1 - Win32 Release"
# Name "example.cpp.main.1 - Win32 Debug"
# Name "example.cpp.main.1 - Win32 Unicode Debug"
# Name "example.cpp.main.1 - Win32 Unicode Release"
# Name "example.cpp.main.1 - Win32 Unicode Debug wmain"
# Name "example.cpp.main.1 - Win32 Unicode Release wmain"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\example.cpp.main.1.cpp
# End Source File
# Begin Source File

SOURCE=..\implicit_link.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\..\..\..\STLSoft\Releases\1.10\STLSoft\include\stlsoft\memory\util\allocator_features.hpp
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_selector.hpp"
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\..\..\..\..\STLSoft\Releases\1.10\STLSoft\include\stlsoft\memory\util\allocator_selector.hpp
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\std\alt.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\auto_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\c_string.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\capabilities.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\char_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\collections\util\collections.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\constraints.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\conversion_error.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\quality\cover.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\fwd.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\head_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_integral_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_pointer_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_same_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_helper.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\lead_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\library_discriminator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\util\meta_.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\msvc.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\n_types.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\obsolete.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\pod.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\safestr.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\smartptr\scoped_handle.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\shim_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\sign_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\size_of.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\size_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std_swap.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_slice.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\yesno.hpp"
# End Source File
# End Group
# Begin Group "PlatformSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\filesystem\path_functions.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\platformstl.h"
# End Source File
# End Group
# Begin Group "WinSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\winstl.h"
# End Source File
# End Group
# End Group
# Begin Group "Pantheios Header Files"

# PROP Default_Filter ""
# Begin Group "Pantheios::Extras"

# PROP Default_Filter ""
# Begin Group "Pantheios::Extras::Main"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\internal\common.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\internal\common.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\invoke.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_EXTRAS_MAIN_ROOT)\include\pantheios\extras\main\internal\stlsoft.h"
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\be.console.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\be.WindowsConsole.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\bec.WindowsConsole.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\quality\contract.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\core.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\fe.simple.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\implicit_link\implicit_link_base_.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\severity\levels.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\generated\log_functions.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\shims\access\string\core\pan_severity_t.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\shims\access\string\core\pan_slice_t.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\pantheios.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\safestr.h"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\shim_declarations.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\slice.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\stock_levels.hpp"
# End Source File
# Begin Source File

SOURCE="$(PANTHEIOS_ROOT)\include\pantheios\internal\string_encoding.h"
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
