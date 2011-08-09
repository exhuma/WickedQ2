# Microsoft Developer Studio Project File - Name="gamex86" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=gamex86 - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gamex86.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gamex86.mak" CFG="gamex86 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gamex86 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release/gamex86"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GAMEX86_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GAMEX86_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x1007 /d "NDEBUG"
# ADD RSC /l 0x1007 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# Begin Target

# Name "gamex86 - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Source\g_ai.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_chase.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_cmds.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_combat.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_func.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_items.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_main.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_misc.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_monster.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_phys.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_save.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_spawn.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_svcmds.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_target.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_trigger.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_turret.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_utils.c
# End Source File
# Begin Source File

SOURCE=.\Source\g_weapon.c
# End Source File
# Begin Source File

SOURCE=.\Source\game.def
# End Source File
# Begin Source File

SOURCE=.\Source\m_actor.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_berserk.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss2.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss3.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss31.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss32.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_brain.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_chick.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_flash.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_flipper.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_float.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_flyer.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_gladiator.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_gunner.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_hover.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_infantry.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_insane.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_medic.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_move.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_mutant.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_parasite.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_soldier.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_supertank.c
# End Source File
# Begin Source File

SOURCE=.\Source\m_tank.c
# End Source File
# Begin Source File

SOURCE=.\Source\p_client.c
# End Source File
# Begin Source File

SOURCE=.\Source\p_hud.c
# End Source File
# Begin Source File

SOURCE=.\Source\p_say.c
# End Source File
# Begin Source File

SOURCE=.\Source\p_trail.c
# End Source File
# Begin Source File

SOURCE=.\Source\p_view.c
# End Source File
# Begin Source File

SOURCE=.\Source\p_weapon.c
# End Source File
# Begin Source File

SOURCE=.\Source\q_shared.c
# End Source File
# Begin Source File

SOURCE=.\Source\wicked.c
# End Source File
# Begin Source File

SOURCE=.\Source\wickedweapons.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Source\g_local.h
# End Source File
# Begin Source File

SOURCE=.\Source\game.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_actor.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_berserk.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss2.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss31.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_boss32.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_brain.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_chick.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_flipper.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_float.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_flyer.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_gladiator.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_gunner.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_hover.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_infantry.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_insane.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_medic.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_mutant.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_parasite.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_player.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_rider.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_soldier.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_supertank.h
# End Source File
# Begin Source File

SOURCE=.\Source\m_tank.h
# End Source File
# Begin Source File

SOURCE=.\Source\p_say.h
# End Source File
# Begin Source File

SOURCE=.\Source\q_shared.h
# End Source File
# Begin Source File

SOURCE=.\Source\wicked.h
# End Source File
# Begin Source File

SOURCE=.\Source\wickedweapons.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\Source\game.dsp
# End Source File
# End Target
# End Project
