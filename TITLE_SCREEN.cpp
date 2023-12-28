#include <ctime>
#include <limits>
#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>
using namespace std;

HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY_BUS ( int BUS_X_axis, int BUS_Y_axis );

void gotoXY_BUS ( int BUS_X_axis, int BUS_Y_axis ) 
{ 
	CursorPosition.X = BUS_X_axis; // Locates column
	CursorPosition.Y = BUS_Y_axis; // Locates Row
	SetConsoleCursorPosition( console, CursorPosition ); // Sets position for next thing to be printed (where cursor is loading)
	
}

void gotoXY_BORDER ( int BORDER_X_axis, int BORDER_Y_axis ) 
{
	CursorPosition.X = BORDER_X_axis;
	CursorPosition.Y = BORDER_Y_axis;
	SetConsoleCursorPosition( console, CursorPosition );
	
}

void gotoXY_STRING ( int STRING_X_axis, int STRING_Y_axis )
{
	CursorPosition.X = STRING_X_axis;
	CursorPosition.Y = STRING_Y_axis;
	SetConsoleCursorPosition( console, CursorPosition );
}

void WaitKey()
{
   while (_kbhit()) _getch(); // Empty the input buffer
   _getch(); // Wait for a key
   while (_kbhit()) _getch(); // Empty the input buffer (some keys sends two messages)
   
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main () // =============================================================================================== MAIN PROGRAM 
{
    system( "title MNL GOJO BUSLINE" ); // ==================================================================== TITLE OF THE PROGRAM
    ShowConsoleCursor(false);	// hide cursor
    
    int STRING_X_axis = 0, STRING_Y_axis = 0;
    
    WINDOW_SIZE: // ========================================================================================= FIXED WINDOW SIZE
	{
		SMALL_RECT rect;
	    COORD coord;
	    coord.X = 150; // Defining our X and
	    coord.Y = 50;  // Y size for buffer.
	
	    rect.Top = 0;
	    rect.Left = 0;
	    rect.Bottom = coord.Y-1; // height for window
	    rect.Right = coord.X-1;  // width for window
	
	    HANDLE hwnd = GetStdHandle( STD_OUTPUT_HANDLE ); // get handle
	    SetConsoleScreenBufferSize( hwnd, coord );       // set buffer size
	    SetConsoleWindowInfo( hwnd, TRUE, &rect );       // set window size
	}
	
	
	INTERFACE_BORDERS_TITLE: // =================================================================================== INTERFACE BORDERS (title screen)
	{
		int BORDER_X_axis = 0, BORDER_Y_axis = 0;
		
		for( BORDER_X_axis = 4 ; BORDER_X_axis < 146 ; BORDER_X_axis++ ) 
		{
			gotoXY_BORDER ( BORDER_X_axis, 2 ) ; printf( "%c", 223 );
			
			gotoXY_BORDER ( BORDER_X_axis, 48 ) ; printf( "%c", 220 );
			
		}
		
		for( BORDER_X_axis = 4, BORDER_Y_axis = 2 ; BORDER_X_axis < 80 && BORDER_Y_axis < 49 ; BORDER_X_axis++, BORDER_Y_axis++ )
		{
			gotoXY_BORDER( 2, BORDER_Y_axis ) ; printf( "%c", 219 ); // left side
			
			gotoXY_BORDER( 4, BORDER_Y_axis ) ; printf( "%c", 221);
			
			gotoXY_BORDER( 147, BORDER_Y_axis ) ; printf( "%c",219 ); // right side
			
			gotoXY_BORDER( 145, BORDER_Y_axis ) ; printf( "%c", 222 );
		}
	}
	
	
	TITLE: // ============================================================================================== TITLE SCREEN
	{
		SetConsoleTextAttribute ( hConsole, 11 ); // title color
		
			gotoXY_BORDER ( 40, 6) ; printf ( "  __  __ _   _ _         ____  _    _  _____ _      _____ _   _ ______ ");
			gotoXY_BORDER ( 40, 7) ; printf ( " |  \\/  | \\ | | |       |  _ \\| |  | |/ ____| |    |_   _| \\ | |  ____|");
			gotoXY_BORDER ( 40, 8) ; printf ( " | \\  / |  \\| | |       | |_) | |  | | (___ | |      | | |  \\| | |__   ");
			gotoXY_BORDER ( 40, 9) ; printf ( " | |\\/| | . ` | |       |  _ <| |  | |\\___ \\| |      | | | . ` |  __|  ");
			gotoXY_BORDER ( 40, 10) ; printf ( " | |  | | |\\  | |____   | |_) | |__| |____) | |____ _| |_| |\\  | |____ ");
			gotoXY_BORDER ( 40, 11) ; printf ( " |_|  |_|_| \\_|______|  |____/ \\____/|_____/|______|_____|_| \\_|______|");
		
		SetConsoleTextAttribute ( hConsole, 3 );
		
			gotoXY_BORDER ( 49, 14 ) ; printf( " _____  _  ____  _  __ _____ _____  _  _      _____");
			gotoXY_BORDER ( 49, 15 ) ; printf( "/__ __\\/ \\/   _\\/ |/ //  __//__ __\\/ \\/ \\  /|/  __/");
			gotoXY_BORDER ( 49, 16 ) ; printf( "  / \\  | ||  /  |   / |  \\    / \\  | || |\\ ||| |  _");
			gotoXY_BORDER ( 49, 17 ) ; printf( "  | |  | ||  \\_ |   \\ |  /_   | |  | || | \\||| |_//");
			gotoXY_BORDER ( 49, 18 ) ; printf( "  \\_/  \\_/\\____/\\_|\\_\\\\____\\  \\_/  \\_/\\_/  \\|\\____\\");
			
			gotoXY_BORDER ( 47, 19 ) ; printf( " ____  _  _      _     _     ____  _____  _  ____  _     ");
			gotoXY_BORDER ( 47, 20 ) ; printf( "/ ___\\/ \\/ \\__/|/ \\ /\\/ \\   /  _ \\/__ __\\/ \\/  _ \\/ \\  /|");
			gotoXY_BORDER ( 47, 21 ) ; printf( "|    \\| || |\\/||| | ||| |   | / \\|  / \\  | || / \\|| |\\ ||");
			gotoXY_BORDER ( 47, 22 ) ; printf( "\\___ || || |  ||| \\_/|| |_/\\| |-||  | |  | || \\_/|| | \\||");
			gotoXY_BORDER ( 47, 23 ) ; printf( "\\____/\\_/\\_/  \\|\\____/\\____/\\_/ \\|  \\_/  \\_/\\____/\\_/  \\|");
		
		SetConsoleTextAttribute ( hConsole, 14) ;
		
		for( int BORDER_X_axis = 30 ; BORDER_X_axis < 121 ; BORDER_X_axis++ ) // horizontal
		{
			gotoXY_BORDER ( BORDER_X_axis , 5 ) ; printf ( "%c", 205 );
			gotoXY_BORDER ( BORDER_X_axis , 25 ) ; printf ( "%c", 205 );
		}
		
		for( int BORDER_Y_axis = 6 ; BORDER_Y_axis < 26 ; BORDER_Y_axis++ ) // vertical
		{
			gotoXY_BORDER ( 30 , BORDER_Y_axis ) ; printf ( "%c", 186 );
			gotoXY_BORDER ( 120, BORDER_Y_axis ) ; printf ( "%c", 186 );
		}
		
		// edges
			gotoXY_BORDER ( 30 , 5 ) ; printf( "%c", 201);
			gotoXY_BORDER ( 30 , 25) ; printf( "%c", 200);
			gotoXY_BORDER ( 120, 25 ) ; printf( "%c", 188 );
			gotoXY_BORDER ( 120, 5 ) ; printf ( "%c", 187 );
		
		SetConsoleTextAttribute ( hConsole, 15 );
		
		for( int BORDER_X_axis = 35 ; BORDER_X_axis < 116 ; BORDER_X_axis++ )
		{
			gotoXY_BORDER ( BORDER_X_axis , 13 ) ; printf( "%c", 196 );
		}
	}
	
	
	CLOUDS_CITY: // ========================================================================================= CLOUD AND CITY DESIGN
	{
		// left cloud 1
		SetConsoleTextAttribute ( hConsole, 15 );
		
			gotoXY_STRING ( 6 , 6 ) ; printf( "   _  _" );
			gotoXY_STRING ( 6 , 7 ) ; printf( "  ( `   )_" );
			gotoXY_STRING ( 6 , 8  ); printf( " (    )    `)" );
			gotoXY_STRING ( 6 , 9) ; printf( "(_   (_ .  _) _)" );
			
		// left cloud 2
		SetConsoleTextAttribute ( hConsole, 8 );
			gotoXY_STRING ( 20 , 9 ) ; printf( "   _ .");
			gotoXY_STRING ( 20 , 10 ) ; printf( " (  _ )_" );
			gotoXY_STRING ( 20 , 11 ) ; printf( "(_  _(_ ,)" );
			
		// left cloud 3
		SetConsoleTextAttribute ( hConsole, 7 );
			gotoXY_STRING ( 6 , 14 ) ; printf( "   _  _" );
			gotoXY_STRING ( 6 , 15 ) ; printf( "  ( `   )_" );
			gotoXY_STRING ( 6 , 16 ) ; printf( " (    )    `)" );
			gotoXY_STRING ( 6 , 17) ; printf( "(_   (_ .  _) _)" );
			
		// left cloud 4
		SetConsoleTextAttribute ( hConsole, 8 );
			gotoXY_STRING ( 17 , 21 ) ; printf( "   _ .");
			gotoXY_STRING ( 17 , 22 ) ; printf( " (  _ )_" );
			gotoXY_STRING ( 17 , 23 ) ; printf( "(_  _(_ ,)" );	
			
		// right cloud 1
		SetConsoleTextAttribute ( hConsole, 15 );
			gotoXY_STRING ( 130 , 7 ) ; printf( "   _" );
			gotoXY_STRING ( 130 , 8 ) ; printf( "  (  )" );
			gotoXY_STRING ( 130 , 9 ) ; printf( " ( `  ) . )" );
			gotoXY_STRING ( 130 , 10 ) ; printf( "(_, _(  ,_)_)" );
			
		// right cloud 2
		SetConsoleTextAttribute ( hConsole, 8 );
			gotoXY_STRING ( 122 , 13 ) ; printf( "   _ ." );
			gotoXY_STRING ( 122 , 14 ) ; printf( " (  _ )" );
			gotoXY_STRING ( 122 , 15 ) ; printf( "(_  _(_ ,)" );
			
		// right cloud 3
		SetConsoleTextAttribute ( hConsole, 7 );
			gotoXY_STRING ( 126 , 18 ) ; printf( "   _  _" );
			gotoXY_STRING ( 126 , 19 ) ; printf( "  ( `   )_" );
			gotoXY_STRING ( 126 , 20 ) ; printf( " (    )    `)" );
			gotoXY_STRING ( 126 , 21 ) ; printf( "(_   (_ .  _) _)" );
		
		
		// city
		SetConsoleTextAttribute ( hConsole, 6 );
			gotoXY_STRING ( 6 , 26 ) ; printf( "                                                 ..======.                                  ..======." );
			gotoXY_STRING ( 6 , 27 ) ; printf( "    .====.,                                 .~.===: : : :|   ..===.                    .~.===: : : :|   ..===.         .====.," );
			gotoXY_STRING ( 6 , 28 ) ; printf( "    |.::'||      .=====.,     .=======.~,   |\"|: :|::::::|   ||:::|=====|.=======.~,   |\"|: :|::::::|   ||:::|=====|   |.::'||" );
			gotoXY_STRING ( 6 , 29 ) ; printf( " ___| :::|!__.,  |:::::|!_,   |: :: ::|\"|l_l|\"|:: |:;;:::|___!| ::|: : :||: :: ::|\"|l_l|\"|:: |:;;:::|___!| ::|: : :| __| :::|!__.," );
			gotoXY_STRING ( 6 , 30 ) ; printf( "|:::| _::|: :|:::|:===:|::|:::|:===F=:|\"!/|\\!\"|::F|:====:|::_:|: :|::__:||:===F=:|\"!/|\\!\"|::F|:====:|::_:|: :|::__:||:::| _::|: :|" );
			gotoXY_STRING ( 6 , 31 ) ; printf( "!_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\\\![]I![_][_]!_[_]![]_!_[__]!![_][I_]!//_:_\\\\![]I![_][_]!_[_]![]_!_[__]!!_[]![_]_!_[]!" );
	}
	
	
	MOVING_BUS: // ========================================================================================= MOVING BUS ANIMATION
	{
		SetConsoleTextAttribute ( hConsole, 7 );
		
		int BUS_X_axis = 4, BUS_Y_axis = 4;
		

		
		gotoXY_BUS ( 5, 40 ) ; printf( "____________________________________________________________________________________________________________________________________________" );
		gotoXY_BUS ( 5, 46 ) ; printf( "______________              _______________             _______________              _______________              _______________           " );
		
		STOPLIGHT:
		{
		
			for ( BUS_Y_axis = 28 ; BUS_Y_axis <= 31 ; BUS_Y_axis++ )	// vertical line for stoplight box
			{
				gotoXY_BUS ( 137 , BUS_Y_axis ) ; printf( "%c", 179 );
				gotoXY_BUS ( 143 , BUS_Y_axis ) ; printf( "%c", 179 );
			}
			
			for ( BUS_X_axis = 137 ; BUS_X_axis <= 143 ; BUS_X_axis++ )	// horizontal line for stoplight box
			{
				gotoXY_BUS ( BUS_X_axis , 32 ) ; printf( "%c", 196 );
				gotoXY_BUS ( BUS_X_axis , 27 ) ; printf( "%c", 196 );
				
				gotoXY_BUS ( 137 , 27 ) ; printf( "%c", 218 );
				gotoXY_BUS ( 143 , 27 ) ; printf( "%c", 191 );
				
				gotoXY_BUS ( 137 , 32 ) ; printf( "%c", 192 );
				gotoXY_BUS ( 143 , 32 ) ; printf( "%c", 217 );
			}
		
			for ( BUS_Y_axis = 32 ; BUS_Y_axis <= 40 ; BUS_Y_axis++ )	// stand for stoplight
			{
				gotoXY_BUS ( 140 , BUS_Y_axis ) ; printf( "%c", 179 );
				gotoXY_BUS ( 140 , 32 ) ; printf( "%c", 194 );
			}
			
			// ========================= STOPLIGHT COLORS
			
			// green
			SetConsoleTextAttribute ( hConsole, 2 ) ; gotoXY_BUS ( 139 , 28 ) ; printf( "%c%c%c", 219, 219, 219 );
			gotoXY_BUS ( 139 , 29 ) ; printf( "%c%c%c", 219, 219, 219 );
			
			// red
			SetConsoleTextAttribute ( hConsole, 4 ) ; gotoXY_BUS ( 139 , 30 ) ; printf( "%c%c%c", 219, 219, 219 );
			gotoXY_BUS ( 139 , 31 ) ; printf( "%c%c%c", 219, 219, 219 );
			
		}

		
		gotoXY_STRING ( 50 , 27 );
			SetConsoleTextAttribute ( hConsole, 112 );
			printf( "             Press [ENTER] to Continue...           ") ; cin.ignore(std::numeric_limits<streamsize>::max(),'\n') ;
			gotoXY_STRING ( 50 , 27 );
			SetConsoleTextAttribute ( hConsole, 6 ) ; printf ( ".~.===: : : :|   ..===.                    .~.===: :");
		
		// ========================= STOPLIGHT COLORS
		
			// green
				SetConsoleTextAttribute ( hConsole, 2 ) ; gotoXY_BUS ( 139 , 28 ) ; printf( "%c%c%c", 219, 219, 219 );
				gotoXY_BUS ( 139 , 29 ) ; printf( "%c%c%c", 219, 219, 219 );
		
			// red
				SetConsoleTextAttribute ( hConsole, 8 ) ; gotoXY_BUS ( 139 , 30 ) ; printf( "%c%c%c", 219, 219, 219 );
				gotoXY_BUS ( 139 , 31 ) ; printf( "%c%c%c", 219, 219, 219 );
		
		
		SetConsoleTextAttribute ( hConsole, 15 );
		
		for ( BUS_X_axis = 6 , BUS_Y_axis = 32 ; BUS_X_axis < 64 ; BUS_X_axis++ )  
		{
		   	gotoXY_BUS ( BUS_X_axis, 32 );
			   	SetConsoleTextAttribute ( hConsole, 12 ) ; printf( "      Bus is moving, mind the ", '\r');
			  	SetConsoleTextAttribute ( hConsole, 10 ) ; printf( "stoplight", '\r');
			  	SetConsoleTextAttribute ( hConsole, 12 ) ; printf( "!", 'r' );
			  	
		  	SetConsoleTextAttribute ( hConsole, 15 );
			    gotoXY_BUS ( BUS_X_axis, 33 ) ; printf( " ===============================================================================" , '\r');
			    gotoXY_BUS ( BUS_X_axis, 34 ) ; printf( " =---__---------------------__--__-----------------=          =-------         -" , '\r');
				gotoXY_BUS ( BUS_X_axis, 35 ) ; printf( " =- |  |   _________     __| _/|__| ____         --=          =-------         -" , '\r');
				gotoXY_BUS ( BUS_X_axis, 36 ) ; printf( " =- |  |  /  _ \\__  \\   / __ | |  |/    \\  / ___\\--=          =-------         -" , '\r');
				gotoXY_BUS ( BUS_X_axis, 37 ) ; printf( " =- |  |_(  <_> ) __ \\_/ /_/ | |  |   |  \\/  /_/ /-=          =-------         -" , '\r');
				gotoXY_BUS ( BUS_X_axis, 38 ) ; printf( " =- |____/\\____(____  /\\____ | |__|___|  /\\___  /  /\\  /\\  /\\ =-------         -" , '\r');
				gotoXY_BUS ( BUS_X_axis, 39 ) ; printf( " =-                 \\/      \\/         \\/_____/    \\/  \\/  \\/ =-------         -" , '\r');
				gotoXY_BUS ( BUS_X_axis, 40 ) ; printf( "_=-------------------------------------------------=          =----------------=" , '\r');
				gotoXY_BUS ( BUS_X_axis, 41 ) ; printf( " =--========---------------------------------------=          =------========--=" , '\r');
				gotoXY_BUS ( BUS_X_axis, 42 ) ; printf( " =-=        =--------------------------------------=----------=-----=        =-=" , '\r');
				gotoXY_BUS ( BUS_X_axis, 43 ) ; printf( " =-=        =--------------------------------------=          =-----=        =-=" , '\r');
				gotoXY_BUS ( BUS_X_axis, 44 ) ; printf( " ===        =========================================================        ===" , '\r');
				gotoXY_BUS ( BUS_X_axis, 45 ) ; printf( "    ========                                                         ========   ", '\r');
				  
			if ( BUS_X_axis == 63 ) // end of loading
			{
				gotoXY_BUS ( BUS_X_axis, 32 );
					SetConsoleTextAttribute ( hConsole, 10 ) ; printf( "      We have arrived! ", '\r');
			   		SetConsoleTextAttribute ( hConsole, 11 ) ; printf( "Please proceed after 4 seconds...", '\r');
		   		
		   		SetConsoleTextAttribute ( hConsole, 15 );
					gotoXY_BUS ( BUS_X_axis, 34 ) ; printf ( " =-------_--------------------_--------------------=          =-------         -" , '\r');
				  	gotoXY_BUS ( BUS_X_axis, 35 ) ; printf ( " =-     | |     -            | |           --------=          =-------         -" , '\r');
				  	gotoXY_BUS ( BUS_X_axis, 36 ) ; printf ( " =-   __| | ___ -_ __   ___  | |           --------=          =-------         -" , '\r');
				  	gotoXY_BUS ( BUS_X_axis, 37 ) ; printf ( " =-  / _` |/ _ \\| '_ \\ / _ \\ | |           --------=          =-------         -" , '\r');
				  	gotoXY_BUS ( BUS_X_axis, 38 ) ; printf ( " =- | (_| | (_) | | | |  __/ |_|           --------=          =-------         -" , '\r');
				  	gotoXY_BUS ( BUS_X_axis, 39 ) ; printf ( " =-  \\__,_|\\___/|_| |_|\\___| (_)           --------=          =-------         -" , '\r');
	      		
		    	// ========================= STOPLIGHT COLORS
					
					// green
						SetConsoleTextAttribute ( hConsole, 8 ) ; gotoXY_BUS ( 139 , 28 ) ; printf( "%c%c%c", 219, 219, 219 );
						gotoXY_BUS ( 139 , 29 ) ; printf( "%c%c%c", 219, 219, 219 );
						
					// red
						SetConsoleTextAttribute ( hConsole, 4 ) ; gotoXY_BUS ( 139 , 30 ) ; printf( "%c%c%c", 219, 219, 219 );
						gotoXY_BUS ( 139 , 31 ) ; printf( "%c%c%c", 219, 219, 219 );
		      		
	      		Sleep ( 4000 );
	      		system( "cls" );
		   }
			    
		   	Sleep(50);
		}
	}
	
	
	NOTICE: // ============================================================================================= NOTICE AFTER LOADING
	{
		//						BORDERS
		
		gotoXY_STRING ( 60 , 4 ) ; SetConsoleTextAttribute ( hConsole, 11 ) ; printf( "-     -     N O T I C E     -     -" );
		
		Sleep ( 1000 );
		
		int BORDER_X_axis = 0, BORDER_Y_axis = 0;
		
		SetConsoleTextAttribute ( hConsole, 15 );
		
		for( BORDER_X_axis = 30 ; BORDER_X_axis < 125 ; BORDER_X_axis++ ) 
		{
			gotoXY_BORDER ( BORDER_X_axis, 5 ) ; printf( "%c", 196 ); 	// up
			gotoXY_BORDER ( BORDER_X_axis, 39 ) ; printf( "%c", 196 ); 	// down
		}
		
		for( BORDER_Y_axis = 5 ; BORDER_Y_axis < 40 ; BORDER_Y_axis++ )
		{
			gotoXY_BORDER ( 30 , BORDER_Y_axis ) ; printf( "%c", 179 ); 	// left side
			gotoXY_BORDER ( 124, BORDER_Y_axis ) ; printf( "%c",179 );		// right side
			
			gotoXY_BORDER ( 30 , 5 ) ; printf( "%c", 218 );		// top left
			gotoXY_BORDER ( 124 , 5 ) ; printf( "%c", 191 );	// top right
			gotoXY_BORDER ( 30 , 39 ) ; printf( "%c", 192 );	// bottom left
			gotoXY_BORDER ( 124 , 39 ) ; printf( "%c", 217 );	// bottom right
		}
		
		//						NOTICE
		
		Sleep ( 1000 );
		
			gotoXY_STRING ( 59 , 8 ) ; SetConsoleTextAttribute ( hConsole, 10 ) ; printf( "MNL GOJO BUSLINE | TICKETING SIMULATION" );
			gotoXY_STRING ( 40 , 10 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( "A program dedicated for") ; SetConsoleTextAttribute ( hConsole, 13 ) ; printf ( " bus ticketing" );
			SetConsoleTextAttribute ( hConsole, 15 ) ; printf ( ". It's purpose is to allow the user to " );
			gotoXY_STRING ( 34 , 11 ) ; printf( "experience booking in a rather unique sequence. The program will ask you for mandatory " );
			gotoXY_STRING ( 43 , 12 ) ; printf( "aspects such as " ) ; SetConsoleTextAttribute ( hConsole, 11 ) ; printf( "Type of Bus, Destination, Passenger(s) Details, etc." );
			gotoXY_STRING ( 36 , 13 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( "Within a few parts of the program, you may notice a few addons to make booking or " );
			gotoXY_STRING ( 43 , 14 ) ; printf( "reserving interesting.") ; SetConsoleTextAttribute ( hConsole, 6 ) ; printf( " There may also be a few easter eggs for fun." );
		
		Sleep ( 2200 );
		
			gotoXY_STRING ( 64 , 17 ) ; SetConsoleTextAttribute ( hConsole, 4 ) ; printf( "! FREQUENT BUG ENCOUNTERS !" );
			gotoXY_STRING ( 54 , 19 ) ; SetConsoleTextAttribute ( hConsole, 12 ) ; printf ( "Please AVOID clicking anything in the program." );
			gotoXY_STRING ( 45 , 20 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf ( "-> There will be instructions on specific parts as you go on." );
			gotoXY_STRING ( 65 , 22 ) ; SetConsoleTextAttribute ( hConsole, 12 ) ; printf ( "Do NOT resize the window." );
			gotoXY_STRING ( 49 , 23 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf ( "-> If the default window size does not fit the screen, " );
			gotoXY_STRING ( 41 , 24 ) ; printf ( "consider maximizing the window by pressing the box icon on the top right." );
			gotoXY_STRING ( 54 , 25 ) ; SetConsoleTextAttribute ( hConsole, 12 ) ; printf ( "PLEASE REFRAIN from making any further changes " );
			gotoXY_STRING ( 53 , 26 ) ; printf ( "related to resizing the window AFTER MAXIMIZING. ");
		
		Sleep ( 2200 );
		
			gotoXY_STRING ( 70 , 29 ) ; SetConsoleTextAttribute ( hConsole, 11 ) ; printf ( "DESIGN AND CREDIT" );
			gotoXY_STRING ( 40 , 31 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf ( "All of the art related objects belong to their respective owners and sites. " );
			gotoXY_STRING ( 34 , 33 ) ; SetConsoleTextAttribute ( hConsole, 3 ) ; printf ( "The links towards the sources may not be pasted here, as anti-viruses have flagged them " );
			gotoXY_STRING ( 47 , 34 ) ; printf ( "as malicious and may install unwanted files in your computer." );
			gotoXY_STRING ( 34 , 36 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf ( "This is to prevent other people from making the same mistake as one of the coders did." );		//	(yes, I almost installed a virus	~ alexa)
			
		Sleep ( 2200 );
		
			gotoXY_STRING ( 55 , 39 ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf ( "|          Press any key to proceed...         |" );
			WaitKey();
	}
	
							/*															END OF TITLE SCREEN																*/
	
	
}
