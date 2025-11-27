//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
// vrad_launcher.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <direct.h>
//#include "tier1/strtools.h"
#include "tier0/icommandline.h"
#include "vrad.h"


int main(int argc, char* argv[])
{
	CommandLine()->CreateCmdLine(argc, argv);

	// check whether they used the -both switch. If this is specified, vrad will be run
	// twice, once with -hdr and once without
	int both_arg=0;
	for(int arg=1;arg<argc;arg++)
		if (Q_stricmp(argv[arg],"-both")==0)
		{
			both_arg=arg;
		}

	int returnValue = 0;
	
	for(int mode=0;mode<2;mode++)
	{
		if (mode && (! both_arg))
			continue;
		
		if (both_arg)
			strcpy(argv[both_arg],(mode)?"-hdr":"-ldr");
		returnValue = VRAD_Main( argc, argv );
	}

	return returnValue;
}

