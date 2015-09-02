// Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pong.h"


int main(int argc, char *args[])
{
	Pong* pong = Pong::instance();
	pong->gameLoop();

    return 0;
}

