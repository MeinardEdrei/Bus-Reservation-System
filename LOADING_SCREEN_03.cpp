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

void gotoXY_BUS ( int BUS_X_axis, int BUS_Y_axis ) 
{ 
	CursorPosition.X = BUS_X_axis; // Locates column
	CursorPosition.Y = BUS_Y_axis; // Locates Row
	SetConsoleCursorPosition( console, CursorPosition ); // Sets position for next thing to be printed (where cursor is loading)
	
}

void gotoXY_LOADING ( int XLOAD_axis, int YLOAD_axis ) 
{ 
	CursorPosition.X = XLOAD_axis; // Locates column
	CursorPosition.Y = YLOAD_axis; // Locates Row
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

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


main(){
	
	system( "title MNL GOJO BUSLINE" ); // ==================================================================== TITLE OF THE PROGRAM
    ShowConsoleCursor(false);	// hide cursor
    
    int STRING_X_axis = 0, STRING_Y_axis = 0;
    
    WINDOW_SIZE: // ========================================================================================= FIXED WINDOW SIZE
	{
		SMALL_RECT rect;
	    COORD coord;
	    coord.X = 150; // Defining our X and
	    coord.Y = 51;  // Y size for buffer.
	
	    rect.Top = 0;
	    rect.Left = 0;
	    rect.Bottom = coord.Y-1; // height for window
	    rect.Right = coord.X-1;  // width for window
	
	    HANDLE hwnd = GetStdHandle( STD_OUTPUT_HANDLE ); // get handle
	    SetConsoleScreenBufferSize( hwnd, coord );       // set buffer size
	    SetConsoleWindowInfo( hwnd, TRUE, &rect );       // set window size
	}
	
	// =================================================================================== LOADING SCREEN
	
	int i = 0;
	int XLOAD_AXIS = 0 , YLOAD_AXIS = 0;
	
	for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
	    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	}
	
	Color(13); gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	
	Sleep(500);
	
	do {
		
		i++;
		
		for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
		
		//cyan
	    Color(11); gotoXY_LOADING ( 40 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
        gotoXY_LOADING ( 40 , 24 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 40 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 40 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 42 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 42 , 24 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 42 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 42 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 44 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 44 , 24 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 44 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 44 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
	    
	    //magenta
	    Color(13); gotoXY_LOADING ( 51 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 51 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 51 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 51 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 54 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 54 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 54 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 54 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 56 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 56 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 56 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 56 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
	    
	    //cyan
	    Color(11); gotoXY_LOADING ( 59 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
        gotoXY_LOADING ( 59 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 59 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 59 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 61 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 61 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 61 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 61 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 63 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 63 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 63 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 63 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
	    
	    //magenta
	    Color(13); gotoXY_LOADING ( 65 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 65 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 65 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 65 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 68 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 68 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 68 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 68 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 69 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 69 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 69 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 69 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
	    
	    //cyan
	    Color(11); gotoXY_LOADING ( 74 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
        gotoXY_LOADING ( 74 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 74 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 74 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 77 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 77 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 77 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 77 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 78 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 78 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 78 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 78 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
	    
	    //magenta
	    Color(13); gotoXY_LOADING ( 82 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 82 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 82 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 82 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 85 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 85 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 85 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 85 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 86 , 20 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 86 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(13); gotoXY_LOADING ( 86 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 86 , 21 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    for ( XLOAD_AXIS = 32 ; XLOAD_AXIS <= 110 ; XLOAD_AXIS++ ){
		
		    Color(15); gotoXY_LOADING ( XLOAD_AXIS , 26 ); printf( "%c" , 205 );
	    }
	    
	    //cyan
	    Color(11); gotoXY_LOADING ( 93 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
        gotoXY_LOADING ( 93 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 93 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 93 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 95 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 95 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 95 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 95 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 97 , 22 ) ; printf( "%c%c%c", 219, 219, 219 ); // up
	    gotoXY_LOADING ( 97 , 22 ) ; printf( "%c%c%c", 219, 219, 219 );
	    Color(11); gotoXY_LOADING ( 97 , 24 ) ; printf( "%c%c%c", 219, 219, 219 ); // down
	    gotoXY_LOADING ( 97 , 23 ) ; printf( "%c%c%c", 219, 219, 219 );
	    
	    gotoXY_LOADING ( 62 , 28 ); printf( " L O A D I N G " );
	    
	    Sleep(300);
	    system("cls");
	    
	    
	} while ( i <= 3 );
	
	
	return 0;
}