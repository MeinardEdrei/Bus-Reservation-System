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

int main() {
	
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
	
	
	INTERFACE_BORDERS_BUS_MENU: // =================================================================================== INTERFACE BORDERS (menu screen)
	{
		int BORDER_X_axis = 0, BORDER_Y_axis = 0;
		
		for( BORDER_X_axis = 4 ; BORDER_X_axis < 146 ; BORDER_X_axis++ ) 
		{
			gotoXY_BORDER ( BORDER_X_axis, 2 ) ; printf( "%c", 223 );
			gotoXY_BORDER ( BORDER_X_axis, 48 ) ; printf( "%c", 220 );
			
		}
		
		for( BORDER_Y_axis = 2 ; BORDER_Y_axis < 49 ; BORDER_X_axis++, BORDER_Y_axis++ )
		{
			gotoXY_BORDER ( 2 , BORDER_Y_axis ) ; printf( "%c", 219 ); // left side
			gotoXY_BORDER ( 4 , BORDER_Y_axis ) ; printf( "%c", 222);
			
			gotoXY_BORDER ( 147 , BORDER_Y_axis ) ; printf( "%c",219 ); // right side
			gotoXY_BORDER ( 145 , BORDER_Y_axis ) ; printf( "%c", 221 );
			
			gotoXY_BORDER ( 55 , BORDER_Y_axis ) ; printf( "%c", 221 );
			gotoXY_BORDER ( 56 , BORDER_Y_axis ) ; printf( "%c", 222);
		}
		
		gotoXY_STRING ( 18 , 4 ) ; printf( " _____________________ " ); 
		gotoXY_STRING ( 18 , 5 ) ; printf( "|  MNL GOJO BUSLINE   |-" ); SetConsoleTextAttribute ( hConsole, 160 ) ; printf( "G" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 6 ) ; printf( "|=(o)=(o)=====(o)=(o)=|-" ); SetConsoleTextAttribute ( hConsole, 160 ) ; printf( "O" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 7 ) ; printf( "|_____________________|" );
		gotoXY_STRING ( 18 , 8 ) ; printf( "|______    |   _______|-" ); SetConsoleTextAttribute ( hConsole, 112 ) ; printf( "F" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 9 ) ; printf( "|      |___|__|  ___  |-" ); SetConsoleTextAttribute ( hConsole, 112 ) ; printf( "O" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 10 ) ; printf( "|______| __|__| | O/| |-" ); SetConsoleTextAttribute ( hConsole, 112 ) ; printf( "R" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 11 ) ; printf( "|_______|__|____|_|_|_|" );
		gotoXY_STRING ( 18 , 12 ) ; printf( "|        _____        |-" ); SetConsoleTextAttribute ( hConsole, 96 ) ; printf( "J" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 13 ) ; printf( "| [  ]  | | | |  [  ] |-" ); SetConsoleTextAttribute ( hConsole, 96 ) ; printf( "O" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 18 , 14 ) ; printf( "|=====================|-" ); SetConsoleTextAttribute ( hConsole, 96 ) ; printf( "Y" ); SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 5 , 15 ) ; printf( "_____________|  |_______________|  |______________" ); 
		gotoXY_STRING ( 18 , 16 ) ; printf( "|__|               |__|" );
		gotoXY_STRING ( 5 , 20 ) ; printf( "__________________________________________________" ); 
		
		gotoXY_STRING ( 7 , 46 ) ; printf( "%c Use the ", 4 ) ; SetConsoleTextAttribute ( hConsole, 2 ) ; printf( "%c", 24 ) ; 
		SetConsoleTextAttribute ( hConsole, 15 ) ; printf( " and " ); SetConsoleTextAttribute ( hConsole, 2 ) ; printf( "%c", 25 ) ; 
		SetConsoleTextAttribute ( hConsole, 15 ) ; printf( " arrow keys and press ") ; SetConsoleTextAttribute ( hConsole, 2 ) ; printf( "[ENTER]" );
				
		SetConsoleTextAttribute ( hConsole, 15 );
		gotoXY_STRING ( 8 , 47 ) ; printf( "%c Use the ", 4 ) ; SetConsoleTextAttribute ( hConsole, 2 ) ; printf( "%c" , 26 ) ; 
		SetConsoleTextAttribute ( hConsole, 15 ) ; printf( " and " ); SetConsoleTextAttribute ( hConsole, 2 ) ; printf( "%c", 27 ) ; 
		SetConsoleTextAttribute ( hConsole, 15 ) ; printf( " arrow keys for ") ; SetConsoleTextAttribute ( hConsole, 2 ) ; printf( "horizontal" );
	}
	
	MAIN_MENU_BORDER: // ======================================================================================= MAIN MENU BORDERS
	{
		
		//gotoXY_STRING( 18 , 20 ); printf( "Main Menu" );
		
				
		SetConsoleTextAttribute ( hConsole, 15 );	
		for( int BORDER_X_axis = 14 ; BORDER_X_axis < 47 ; BORDER_X_axis++ ) // horizontal
		{
			gotoXY_BORDER ( BORDER_X_axis , 23 ) ; printf ( "%c", 205 );	// 1st line
			gotoXY_BORDER ( BORDER_X_axis , 27 ) ; printf ( "%c", 205 );	// 2nd
			gotoXY_BORDER ( BORDER_X_axis , 31 ) ; printf ( "%c", 205 );	// 3rd
			gotoXY_BORDER ( BORDER_X_axis , 35 ) ; printf ( "%c", 205 );	// 4th
			gotoXY_BORDER ( BORDER_X_axis , 39 ) ; printf ( "%c", 205 );	// 5th
			gotoXY_BORDER ( BORDER_X_axis , 43 ) ; printf ( "%c", 205 );	// last
			
			gotoXY_BORDER ( 14 , 23 ) ; printf ( "%c", 201 );	// top corners
			gotoXY_BORDER ( 46 , 23 ) ; printf ( "%c", 187 );
			gotoXY_BORDER ( 14 , 43 ) ; printf ( "%c", 200 );	// bottom corners
			gotoXY_BORDER ( 46 , 43 ) ; printf ( "%c", 188 );			
		}
				
		for( int BORDER_Y_axis = 24 ; BORDER_Y_axis < 43 ; BORDER_Y_axis++ )
		{
			gotoXY_BORDER ( 14 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// left
			gotoXY_BORDER ( 46 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// right
					
			gotoXY_BORDER ( 14 , 27 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 46 , 27 ) ; printf ( "%c", 185 );
			gotoXY_BORDER ( 14 , 31 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 46 , 31 ) ; printf ( "%c", 185 );
			gotoXY_BORDER ( 14 , 35 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 46 , 35 ) ; printf ( "%c", 185 );
			gotoXY_BORDER ( 14 , 39 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 46 , 39 ) ; printf ( "%c", 185 );	
		}		

	}
	
	
	MAIN_MENU_OPTIONS: // ======================================================================================= MAIN MENU OPTIONS
	{
		int OPTION_select = 0, run, STRING_Y_axis = 25;
		bool MAIN_run = true , QUIT_run = false , START_run = false , NOTICE_run = false;	
		
			SetConsoleTextAttribute ( hConsole, 3 );
			gotoXY_STRING( 17 , STRING_Y_axis ); printf( "%c", 16 );
			gotoXY_STRING( 43 , STRING_Y_axis ); printf( "%c", 17 );
			
			
			SetConsoleTextAttribute ( hConsole, 15 );
			gotoXY_STRING ( 28 , 25)  ; printf( "START" );
			gotoXY_STRING ( 27 , 29 ) ; printf( "NOTICE" );
			gotoXY_STRING ( 28 , 33 ) ; printf( "TIME" );
			gotoXY_STRING ( 23 , 37 ) ; printf( "BUS DESCRIPTION" );
			gotoXY_STRING ( 28 , 41 ) ; printf( "EXIT" );

			
			while( MAIN_run )	// while MAIN_run is true	||	while arrow keys are controllable
			{
				system("pause>nul"); // the >nul bit causes it the print no message
					
				if( GetAsyncKeyState(VK_DOWN) && STRING_Y_axis != 41 ) // down button pressed
					{
						SetConsoleTextAttribute ( hConsole, 3 );
						gotoXY_STRING( 17 , STRING_Y_axis ); printf( " " );
						gotoXY_STRING( 43 , STRING_Y_axis ); printf( " " );
						STRING_Y_axis += 4;	
							
						SetConsoleTextAttribute ( hConsole, 3 );
						gotoXY_STRING( 17 , STRING_Y_axis ); printf( "%c", 16 );
						gotoXY_STRING( 43 , STRING_Y_axis ); printf( "%c", 17 );
						OPTION_select++; 
						continue;
					}
						
				if( GetAsyncKeyState(VK_UP) && STRING_Y_axis != 25 ) // up button pressed
					{
						SetConsoleTextAttribute ( hConsole, 3 );
						gotoXY_STRING( 17 , STRING_Y_axis ); printf( " " );
						gotoXY_STRING( 43 , STRING_Y_axis ); printf( " " );
						STRING_Y_axis -= 4;	
							
						SetConsoleTextAttribute ( hConsole, 3 );
						gotoXY_STRING( 17 , STRING_Y_axis ); printf( "%c", 16 );
						gotoXY_STRING( 43 , STRING_Y_axis ); printf( "%c", 17 );
						OPTION_select--;
						continue;
					}
					
				
					
				if( GetAsyncKeyState( VK_RETURN ) )	// enter key pressed
				{ 
					switch( OPTION_select )
					{
							
						case 0: 	// if the menu_item 's value is 0, you chose the first option
						{			
							gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
							gotoXY_STRING( 21 , 18 ) ; SetConsoleTextAttribute ( hConsole, 10 ) ; printf( "%c Start Booking %c" , 174 , 175 );
							
							gotoXY_STRING( 17 , STRING_Y_axis ) ; printf( " " ) ; gotoXY_STRING( 43 , STRING_Y_axis ) ; printf( " " );
							MAIN_run = false ; int STRING_X_axis = 11,  OPTION_select = 1; 
							
							SetConsoleTextAttribute ( hConsole, 2 ) ; for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
							{
								gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                    " );	// clears the previous ascii arts
							}
								
								gotoXY_STRING( 74 , 6 ) ; printf( "      ___    _____    ___     ___    _____" );
								gotoXY_STRING( 74 , 7 ) ; printf( "     / __|  |_   _|  /   \\   | _ \\  |_   _|" );
								gotoXY_STRING( 74 , 8 ) ; printf( "     \\__ \\    | |    | - |   |   /    | |" );
								gotoXY_STRING( 74 , 9 ) ; printf( "     |___/____|_|____|_|_|___|_|_\\____|_|" );
								gotoXY_STRING( 74 , 10 ) ; printf( "     |==========|_|==========|_|==========| " );
								gotoXY_STRING( 74 , 11 ) ; printf( "      -0-0---0-0- -0-0---0-0-  -0-0---0-0-" );
								gotoXY_STRING( 74 , 12 ) ; printf( "   ___     ___     ___    _  __    ___    _  _     ___" );
								gotoXY_STRING( 74 , 13 ) ; printf( "  | _ )   / _ \\   / _ \\  | |/ /   |_ _|  | \\| |   / __| " );
								gotoXY_STRING( 74 , 14 ) ; printf( "  | _ \\  | (_) | | (_) | | ' <     | |   | .` |  | (_ |  " );
								gotoXY_STRING( 74 , 15 ) ; printf( "  |___/___\\___/___\\___/__|_|\\_\\___|___|__|_|\\_|___\\___|  " );
								gotoXY_STRING( 74 , 16 ) ; printf( "   |==========|_|==========|_|==========| |==========|     " );
								gotoXY_STRING( 74 , 17 ) ; printf( "    -0-0---0-0-  -0-0---0-0-  -0-0---0-0-  -0-0---0-0-" );
								
							SetConsoleTextAttribute ( hConsole, 15 );
							
							// BIG BORDERS
								for( int BORDER_X_axis = 75 ; BORDER_X_axis < 130 ; BORDER_X_axis++ ) // horizontal
								{
									gotoXY_BORDER ( BORDER_X_axis , 20 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 30 ) ; printf ( "%c", 196 );	// last		
								}
										
								for( int BORDER_Y_axis = 20 ; BORDER_Y_axis < 31 ; BORDER_Y_axis++ )
								{
									gotoXY_BORDER ( 75 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 129 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									
									gotoXY_BORDER ( 75 , 20 ) ; printf ( "%c", 201 );	// top corners
									gotoXY_BORDER ( 129 , 20 ) ; printf ( "%c", 187 );
									gotoXY_BORDER ( 75 , 30 ) ; printf ( "%c", 200 );	// bottom corners
									gotoXY_BORDER ( 129 , 30 ) ; printf ( "%c", 188 );	
								}		
							
							// SMALL BORDERS
								for( int BORDER_X_axis = 75 ; BORDER_X_axis < 100 ; BORDER_X_axis++ ) // horizontal left
								{
									gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 196 );	// last		
								}
								
								for( int BORDER_X_axis = 105 ; BORDER_X_axis < 129 ; BORDER_X_axis++ ) // horizontal right
								{
									gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 196 );	// last		
								}	
							
								for( int BORDER_Y_axis = 32 ; BORDER_Y_axis < 37 ; BORDER_Y_axis++ )
								{
									gotoXY_BORDER ( 75 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 99 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									gotoXY_BORDER ( 105 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 129 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									
								// LEFT
									gotoXY_BORDER ( 75 , 32 ) ; printf ( "%c", 201 ) ; gotoXY_BORDER ( 99 , 32 ) ; printf ( "%c", 187 );	// top corners
									gotoXY_BORDER ( 75 , 36 ) ; printf ( "%c", 200 ) ; gotoXY_BORDER ( 99 , 36 ) ; printf ( "%c", 188 );	// bottom corners
									
								// RIGHT
									gotoXY_BORDER ( 105 , 32 ) ; printf ( "%c", 201 ) ; gotoXY_BORDER ( 129 , 32 ) ; printf ( "%c", 187 );	// top corners
									gotoXY_BORDER ( 105 , 36 ) ; printf ( "%c", 200 ) ; gotoXY_BORDER ( 129 , 36 ) ; printf ( "%c", 188 );	// bottom corners
								}	
								
								
							gotoXY_STRING ( 91 , 24 ) ; printf( "Proceeding to booking." ) ;
							gotoXY_STRING ( 95 , 26 ) ; printf( "Are you sure?" ) ;
							
							gotoXY_STRING ( 86 , 34 ) ; printf( "YES" ) ;
							gotoXY_STRING ( 117 , 34 ) ; printf( "NO" ) ;
							
							SetConsoleTextAttribute ( hConsole, 11 );
							gotoXY_STRING ( 80 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 94 , 34 ) ; printf( "%c" , 17 ) ;
							
							getch();
								
							START_run = true;
								
							while( START_run )
							{
									
								if( GetAsyncKeyState(VK_LEFT) && STRING_X_axis != 11 )
								{	
									SetConsoleTextAttribute ( hConsole, 11 ); 
									OPTION_select = 1;
									STRING_X_axis++;
									gotoXY_STRING ( 111 , 34 ) ; printf( " " ) ; gotoXY_STRING ( 124 , 34 ) ; printf( " " ) ;
									gotoXY_STRING ( 80 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 94 , 34 ) ; printf( "%c" , 17 ) ;
								}
									
								if( GetAsyncKeyState(VK_RIGHT) && STRING_X_axis != 12 )
								{
									SetConsoleTextAttribute ( hConsole, 12 );
									OPTION_select = 2;
									STRING_X_axis--;
									gotoXY_STRING ( 80 , 34 ) ; printf( " " ) ; gotoXY_STRING ( 94 , 34 ) ; printf( " " ) ;
									gotoXY_STRING ( 111 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 124 , 34 ) ; printf( "%c" , 17 ) ;
								}
									
									
								if( GetAsyncKeyState( VK_RETURN ) ) 
								{
									switch ( OPTION_select ) 
									{
										case 1: 
										{
											SetConsoleTextAttribute ( hConsole, 10 );
											gotoXY_STRING ( 83 , 27 ) ; printf( "Redirecting in 3 seconds, please wait..." );
											Sleep( 3000 );
											START_run = false;	// for now
											break;
										}
										
										case 2: 
										{
											// clearing step
											gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
												for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
												{
													gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                   " );	// clears the previous ascii arts
												}
											
											goto MAIN_MENU_OPTIONS;
											break;
										}
									}
								}
							}
							
							break;
						}
								
								
						case 1: 	// if the menu_item 's value is 1, you chose notice
						{
							gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
							gotoXY_STRING( 25 , 18 ) ; SetConsoleTextAttribute ( hConsole, 1 ) ; printf( "%c Notice %c" , 174 , 175 );
								
							gotoXY_STRING( 17 , STRING_Y_axis ) ; printf( " " ) ; gotoXY_STRING( 43 , STRING_Y_axis ) ; printf( " " );
							int STRING_X_axis = 11 , OPTION_select = 1;
							
							SetConsoleTextAttribute ( hConsole, 9 ) ; for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
							{
								gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                    " );	// clears the previous ascii arts
							}
								
								gotoXY_STRING( 79 , 8 ) ; printf( "      _      ____  _____  _  ____  _____" );
								gotoXY_STRING( 79 , 9 ) ; printf( "     / \\  /|/  _ \\/__ __\\/ \\/   _\\/  __/" );
								gotoXY_STRING( 79 , 10 ) ; printf( "     | |\\ ||| / \\|  / \\  | ||  /  |  \\  " );
								gotoXY_STRING( 79 , 11 ) ; printf( "     | | \\||| \\_/|  | |  | ||  \\__|  /_ " );
								gotoXY_STRING( 79 , 12 ) ; printf( "     \\_/  \\|\\____/  \\_/  \\_/\\____/\\____\\" );
								gotoXY_STRING( 79 , 13 ) ; printf( "     ===================================" );
								
							SetConsoleTextAttribute ( hConsole, 15 );
							// BIG BORDERS
								for( int BORDER_X_axis = 75 ; BORDER_X_axis < 130 ; BORDER_X_axis++ ) // horizontal
								{
									gotoXY_BORDER ( BORDER_X_axis , 20 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 30 ) ; printf ( "%c", 196 );	// last		
								}
										
								for( int BORDER_Y_axis = 20 ; BORDER_Y_axis < 31 ; BORDER_Y_axis++ )
								{
									gotoXY_BORDER ( 75 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 129 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									
									gotoXY_BORDER ( 75 , 20 ) ; printf ( "%c", 201 );	// top corners
									gotoXY_BORDER ( 129 , 20 ) ; printf ( "%c", 187 );
									gotoXY_BORDER ( 75 , 30 ) ; printf ( "%c", 200 );	// bottom corners
									gotoXY_BORDER ( 129 , 30 ) ; printf ( "%c", 188 );	
								}		
							
							// SMALL BORDERS
								for( int BORDER_X_axis = 75 ; BORDER_X_axis < 100 ; BORDER_X_axis++ ) // horizontal left
								{
									gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 196 );	// last		
								}
								
								for( int BORDER_X_axis = 105 ; BORDER_X_axis < 129 ; BORDER_X_axis++ ) // horizontal right
								{
									gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 196 );	// last		
								}	
							
								for( int BORDER_Y_axis = 32 ; BORDER_Y_axis < 37 ; BORDER_Y_axis++ )
								{
									gotoXY_BORDER ( 75 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 99 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									gotoXY_BORDER ( 105 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 129 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									
								// LEFT
									gotoXY_BORDER ( 75 , 32 ) ; printf ( "%c", 201 ) ; gotoXY_BORDER ( 99 , 32 ) ; printf ( "%c", 187 );	// top corners
									gotoXY_BORDER ( 75 , 36 ) ; printf ( "%c", 200 ) ; gotoXY_BORDER ( 99 , 36 ) ; printf ( "%c", 188 );	// bottom corners
									
								// RIGHT
									gotoXY_BORDER ( 105 , 32 ) ; printf ( "%c", 201 ) ; gotoXY_BORDER ( 129 , 32 ) ; printf ( "%c", 187 );	// top corners
									gotoXY_BORDER ( 105 , 36 ) ; printf ( "%c", 200 ) ; gotoXY_BORDER ( 129 , 36 ) ; printf ( "%c", 188 );	// bottom corners
								}	
								
								
							gotoXY_STRING ( 85 , 24 ) ; printf( "You will be redirected back to Notice." ) ; gotoXY_STRING ( 95 , 26 ) ; printf( "Are you sure?" ) ;
							gotoXY_STRING ( 86 , 34 ) ; printf( "YES" ) ; gotoXY_STRING ( 117 , 34 ) ; printf( "NO" ) ;
							SetConsoleTextAttribute ( hConsole, 11 ) ; gotoXY_STRING ( 80 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 94 , 34 ) ; printf( "%c" , 17 ) ;
							
							
							getch() ; NOTICE_run = true ; while( NOTICE_run )
							{
									
								if( GetAsyncKeyState(VK_LEFT) && STRING_X_axis != 11 )
								{	
									SetConsoleTextAttribute ( hConsole, 11 ) ; OPTION_select = 1 ; STRING_X_axis++;
									gotoXY_STRING ( 111 , 34 ) ; printf( " " ) ; gotoXY_STRING ( 124 , 34 ) ; printf( " " ) ;
									gotoXY_STRING ( 80 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 94 , 34 ) ; printf( "%c" , 17 ) ;
								}
									
								if( GetAsyncKeyState(VK_RIGHT) && STRING_X_axis != 12 )
								{
									SetConsoleTextAttribute ( hConsole, 12 ) ; OPTION_select = 2 ; STRING_X_axis--;
									gotoXY_STRING ( 80 , 34 ) ; printf( " " ) ; gotoXY_STRING ( 94 , 34 ) ; printf( " " ) ;
									gotoXY_STRING ( 111 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 124 , 34 ) ; printf( "%c" , 17 ) ;
								}
									
									
								if( GetAsyncKeyState( VK_RETURN ) ) 
								{
									switch ( OPTION_select ) 
									{
										case 1: 
										{
											SetConsoleTextAttribute ( hConsole, 13 ) ; gotoXY_STRING ( 83 , 27 ) ; printf( "Redirecting in 3 seconds, please wait..." );
											Sleep( 3000 ) ; NOTICE_run = false;
											//	system ("cls");
											//	goto NOTICE;
											break;
										}
										
										case 2: 
										{
											gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
												for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
												{
													gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                   " );	// clears the previous ascii arts
												}
											
											goto MAIN_MENU_OPTIONS;
											break;
										}
									}
								}
							}
							
							break;
						}
								
								
						case 2: 	// if the menu_item 's value is 2, you chose time
						{
							gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
							gotoXY_STRING( 19 , 18 ) ; SetConsoleTextAttribute ( hConsole, 3 ) ; printf( "%c Time of Departure %c" , 174 , 175 );
							
							SetConsoleTextAttribute ( hConsole, 11 ) ; for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
							{
								gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                   " );	// clears the previous ascii arts
							}
								
								gotoXY_STRING( 70 , 5 ) ; printf( "    _____ ________  ___ _____           __              " );
								gotoXY_STRING( 70 , 6 ) ; printf( "   |_   _|_   _|  \\/  ||  ___|         / _|             " );
								gotoXY_STRING( 70 , 7 ) ; printf( "     | |   | | | .  . || |__      ___ | |_              " );
								gotoXY_STRING( 70 , 8 ) ; printf( "     | |   | | | |\\/| ||  __|    / _ \\|  _|             " );
								gotoXY_STRING( 70 , 9 ) ; printf( "     | |  _| |_| |  | || |___   | (_) | |               " );
								gotoXY_STRING( 70 , 10 ) ; printf( "     \\_/  \\___/\\_|  |_/\\____/    \\___/|_|               " );
								gotoXY_STRING( 70 , 11 ) ; printf( "______ ___________  ___  ______ _____ _   _______ _____ " );
								gotoXY_STRING( 70 , 12 ) ; printf( "|  _  \\  ___| ___ \\/ _ \\ | ___ \\_   _| | | | ___ \\  ___|" );
								gotoXY_STRING( 70 , 13 ) ; printf( "| | | | |__ | |_/ / /_\\ \\| |_/ / | | | | | | |_/ / |__  " );
								gotoXY_STRING( 70 , 14 ) ; printf( "| | | |  __||  __/|  _  ||    /  | | | | | |    /|  __| " );
								gotoXY_STRING( 70 , 15 ) ; printf( "| |/ /| |___| |   | | | || |\\ \\  | | | |_| | |\\ \\| |___ " );
								gotoXY_STRING( 70 , 16 ) ; printf( "|___/ \\____/\\_|   \\_| |_/\\_| \\_| \\_/  \\___/\\_| \\_\\____/ " );
								
								
									SetConsoleTextAttribute ( hConsole, 11 );	
									for( int BORDER_X_axis = 65 ; BORDER_X_axis < 136 ; BORDER_X_axis++ ) // horizontal
									{
										gotoXY_BORDER ( BORDER_X_axis , 20 ) ; printf ( "%c", 205 );	// 1st line
										gotoXY_BORDER ( BORDER_X_axis , 24 ) ; printf ( "%c", 205 );	// 2nd
										gotoXY_BORDER ( BORDER_X_axis , 28 ) ; printf ( "%c", 205 );	// 3rd
										gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 205 );	// 4th
										gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 205 );	// 5th
										gotoXY_BORDER ( BORDER_X_axis , 40 ) ; printf ( "%c", 205 );	// last
										
										gotoXY_BORDER ( 65 , 20 ) ; printf ( "%c", 201 );	// top corners
										gotoXY_BORDER ( 135 , 20 ) ; printf ( "%c", 187 );
										gotoXY_BORDER ( 65 , 40 ) ; printf ( "%c", 200 );	// bottom corners
										gotoXY_BORDER ( 135 , 40 ) ; printf ( "%c", 188 );	
									}
											
									for( int BORDER_Y_axis = 21 ; BORDER_Y_axis < 40 ; BORDER_Y_axis++ )
									{
										gotoXY_BORDER ( 65 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// left
										gotoXY_BORDER ( 82 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// boundary
										gotoXY_BORDER ( 135 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// right
												
										gotoXY_BORDER ( 65 , 24 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 24 ) ; printf ( "%c", 185 );
										gotoXY_BORDER ( 65 , 28 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 28 ) ; printf ( "%c", 185 );
										gotoXY_BORDER ( 65 , 32 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 32 ) ; printf ( "%c", 185 );
										gotoXY_BORDER ( 65 , 36 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 36 ) ; printf ( "%c", 185 );
										
										gotoXY_BORDER ( 82 , 20 ) ; printf ( "%c", 203 );	// boundary	top
										gotoXY_BORDER ( 82 , 24 ) ; printf ( "%c", 206 );	// 2nd boundary
										gotoXY_BORDER ( 82 , 28 ) ; printf ( "%c", 206 );	// 3rd boundary
										gotoXY_BORDER ( 82 , 32 ) ; printf ( "%c", 206 );	// 4th boundary
										gotoXY_BORDER ( 82 , 36 ) ; printf ( "%c", 206 );	// 5th boundary
										gotoXY_BORDER ( 82 , 40 ) ; printf ( "%c", 202 );	// boundary bottom
									}	
									
							break;
						}
								
								
						case 3: 	// if the menu_item 's value is 3, you chose bus description
						{
							gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
							gotoXY_STRING( 20 , 18 ) ; SetConsoleTextAttribute ( hConsole, 6 ) ; printf( "%c Bus Description %c" , 174 , 175 );
							
							SetConsoleTextAttribute ( hConsole, 14 ) ; for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
							{
								gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                   " );	// clears the previous ascii arts
							}
								
								gotoXY_STRING( 70 , 5 ) ; printf( "     ____   __ __  _____         " );
								gotoXY_STRING( 70 , 6 ) ; printf( "    |    \\ |  |  |/ ___/         " );
								gotoXY_STRING( 70 , 7 ) ; printf( "    |  o  )|  |  (   \\_          " );
								gotoXY_STRING( 70 , 8 ) ; printf( "    |     ||  |  |\\__  |         " );
								gotoXY_STRING( 70 , 9 ) ; printf( "    |  O  ||  :  |/  \\ |         " );
								gotoXY_STRING( 70 , 10 ) ; printf( "    |_____| \\__,_|\\____|   " );
								gotoXY_STRING( 65 , 11 ) ; printf( " ___      ___  _____   __  ____   ____  ____  ______  ____  ___   ____  " );
								gotoXY_STRING( 65 , 12 ) ; printf( "|   \\    /  _]/ ___/  /  ]|    \\ |    ||    \\|      ||    |/   \\ |    \\ " );
								gotoXY_STRING( 65 , 13 ) ; printf( "|    \\  /  [_(   \\_  /  / |  D  ) |  | |  o  )      | |  ||     ||  _  |" );
								gotoXY_STRING( 65 , 14 ) ; printf( "|  D  ||    _]\\__  |/  /  |    /  |  | |   _/|_|  |_| |  ||  O  ||  |  |" );
								gotoXY_STRING( 65 , 15 ) ; printf( "|     ||   [_ /  \\ /   \\_ |    \\  |  | |  |    |  |   |  ||     ||  |  |" );
								gotoXY_STRING( 65 , 16 ) ; printf( "|_____||_____|\\____|\\____||__|\\_||____||__|    |__|  |____|\\___/ |__|__|" );
							
							
									SetConsoleTextAttribute ( hConsole, 14 );	
									for( int BORDER_X_axis = 65 ; BORDER_X_axis < 136 ; BORDER_X_axis++ ) // horizontal
									{
										gotoXY_BORDER ( BORDER_X_axis , 20 ) ; printf ( "%c", 205 );	// 1st line
										gotoXY_BORDER ( BORDER_X_axis , 24 ) ; printf ( "%c", 205 );	// 2nd
										gotoXY_BORDER ( BORDER_X_axis , 28 ) ; printf ( "%c", 205 );	// 3rd
										gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 205 );	// 4th
										gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 205 );	// 5th
										gotoXY_BORDER ( BORDER_X_axis , 40 ) ; printf ( "%c", 205 );	// last
										
										gotoXY_BORDER ( 65 , 20 ) ; printf ( "%c", 201 );	// top corners
										gotoXY_BORDER ( 135 , 20 ) ; printf ( "%c", 187 );
										gotoXY_BORDER ( 65 , 40 ) ; printf ( "%c", 200 );	// bottom corners
										gotoXY_BORDER ( 135 , 40 ) ; printf ( "%c", 188 );	
									}
											
									for( int BORDER_Y_axis = 21 ; BORDER_Y_axis < 40 ; BORDER_Y_axis++ )
									{
										gotoXY_BORDER ( 65 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// left
										gotoXY_BORDER ( 82 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// boundary
										gotoXY_BORDER ( 135 , BORDER_Y_axis ) ; printf ( "%c", 186 );	// right
												
										gotoXY_BORDER ( 65 , 24 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 24 ) ; printf ( "%c", 185 );
										gotoXY_BORDER ( 65 , 28 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 28 ) ; printf ( "%c", 185 );
										gotoXY_BORDER ( 65 , 32 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 32 ) ; printf ( "%c", 185 );
										gotoXY_BORDER ( 65 , 36 ) ; printf ( "%c", 204 ) ; gotoXY_BORDER ( 135 , 36 ) ; printf ( "%c", 185 );
										
										gotoXY_BORDER ( 82 , 20 ) ; printf ( "%c", 203 );	// boundary	top
										gotoXY_BORDER ( 82 , 24 ) ; printf ( "%c", 206 );	// 2nd boundary
										gotoXY_BORDER ( 82 , 28 ) ; printf ( "%c", 206 );	// 3rd boundary
										gotoXY_BORDER ( 82 , 32 ) ; printf ( "%c", 206 );	// 4th boundary
										gotoXY_BORDER ( 82 , 36 ) ; printf ( "%c", 206 );	// 5th boundary
										gotoXY_BORDER ( 82 , 40 ) ; printf ( "%c", 202 );	// boundary bottom
									}	
							
							// titles
								SetConsoleTextAttribute ( hConsole, 15 ) ;
								gotoXY_STRING( 69 , 21 ) ; printf( "Bus Type" ) ; gotoXY_STRING( 67 , 23 ) ; printf( "Number of Seats" ) ;
								gotoXY_STRING( 104 , 22 ) ; printf( "Description" ) ;
								
							// class A
								SetConsoleTextAttribute ( hConsole, 10 ) ; gotoXY_STRING( 70 , 25 ) ; printf( "Class A" ) ; gotoXY_STRING( 69 , 27 ) ; printf( "seats: 35" ); 
								SetConsoleTextAttribute ( hConsole, 15 ) ; gotoXY_STRING( 84 , 25 ) ; printf( "All of the other features with a few addons! The" );
								SetConsoleTextAttribute ( hConsole, 10 ) ; gotoXY_STRING( 84 , 26 ) ; printf( "adjustable chairs, 1 extra bathroom ") ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( "and the" );
								SetConsoleTextAttribute ( hConsole, 10 ) ; gotoXY_STRING( 84 , 27 ) ; printf( "foodpacks" ) ; SetConsoleTextAttribute ( hConsole, 15 ) ;  printf(" makes this class the ") ; SetConsoleTextAttribute ( hConsole, 10 ) ; printf( "most comfortable." );
							
							// class B
								SetConsoleTextAttribute ( hConsole, 11 ) ; gotoXY_STRING( 70 , 29 ) ; printf( "Class B" ) ; gotoXY_STRING( 69 , 31 ) ; printf( "seats: 45" ) ;
								SetConsoleTextAttribute ( hConsole, 15 ) ; gotoXY_STRING( 84 , 29 ) ; printf( "Includes Ordinary and Class C features with " ) ; SetConsoleTextAttribute ( hConsole, 11 ) ; printf( "one" );
								gotoXY_STRING( 84 , 30 ) ; printf( "bathroom and lesser passengers") ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( ". This bus class is" );
								gotoXY_STRING( 84 , 31 ) ; SetConsoleTextAttribute ( hConsole, 11 ) ; printf( "fitting and comfortable" ) ; SetConsoleTextAttribute ( hConsole, 15 ) ;  printf( " for most passengers." );
							
							// class C
								SetConsoleTextAttribute ( hConsole, 13 ) ; gotoXY_STRING( 70 , 33 ) ; printf( "Class C" ) ; gotoXY_STRING( 69 , 35 ) ; printf( "seats: 50" ) ;
								SetConsoleTextAttribute ( hConsole, 15 ) ; gotoXY_STRING( 84 , 33 ) ; printf( "Similar to Ordinary, but with a few changes." );
								gotoXY_STRING( 84 , 34 ) ; printf( "Class C includes" ) ; SetConsoleTextAttribute ( hConsole, 13 ) ; printf(" Air Conditioners and lesser" );
								gotoXY_STRING( 84 , 35 ) ; printf( "passengers" ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( ". Vendors are still allowed for food!" );
							
							// ordinary
								SetConsoleTextAttribute ( hConsole, 9 ); gotoXY_STRING( 70 , 37 ) ; printf( "Ordinary" ) ; gotoXY_STRING( 69 , 39 ) ; printf( "seats: 65" ) ; //	bizzare how 65 people can fit in one car
								SetConsoleTextAttribute ( hConsole, 15 ); gotoXY_STRING( 84 , 37 ) ; printf( "The basic bus class with the") ; SetConsoleTextAttribute ( hConsole, 9 ) ; printf( " most seats" ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf("!") ;
								SetConsoleTextAttribute ( hConsole, 9 ); gotoXY_STRING( 84 , 38 ) ; printf( "Vendors are allowed") ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( " to sell food inside so" );
								gotoXY_STRING( 84 , 39 ) ; printf( "the passengers ") ; SetConsoleTextAttribute ( hConsole, 9 ) ; printf("may eat during the trip" ) ; SetConsoleTextAttribute ( hConsole, 15 ) ; printf( "." );
							
							break;
						}
							
								
						case 4: 	// if the menu_item 's value is 4, you chose to end program
						{
							gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
							gotoXY_STRING( 22 , 18 ) ; SetConsoleTextAttribute ( hConsole, 4 ) ; printf( "%c Exit Program %c" , 174 , 175 );
							
								SetConsoleTextAttribute ( hConsole, 15 );
								gotoXY_STRING( 17 , STRING_Y_axis ) ; printf( " " ) ; gotoXY_STRING( 43 , STRING_Y_axis ) ; printf( " " );
								int STRING_X_axis = 11 ; OPTION_select = 1;
								
							MAIN_run = false;
								
							SetConsoleTextAttribute ( hConsole, 12 ) ; for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
							{
								gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                   " );	// clears the previous ascii arts
							}

								gotoXY_STRING( 87 , 8 ) ; printf( "   ____  _    _ _____ _______ " );
								gotoXY_STRING( 87 , 9 ) ; printf( "  / __ \\| |  | |_   _|__   __|" );
								gotoXY_STRING( 87 , 10 ) ; printf( " | |  | | |  | | | |    | |   " );
								gotoXY_STRING( 87 , 11 ) ; printf( " | |  | | |  | | | |    | |   " );
								gotoXY_STRING( 87 , 12 ) ; printf( " | |__| | |__| |_| |_   | |   " );
								gotoXY_STRING( 87 , 13 ) ; printf( "  \\___\\_\\\\____/|_____|  |_|   " );
								gotoXY_STRING( 87 , 14 ) ; printf( "============================== " );
								
							SetConsoleTextAttribute ( hConsole, 15 );
							
							// BIG BORDERS
								for( int BORDER_X_axis = 75 ; BORDER_X_axis < 130 ; BORDER_X_axis++ ) // horizontal
								{
									gotoXY_BORDER ( BORDER_X_axis , 20 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 30 ) ; printf ( "%c", 196 );	// last		
								}
										
								for( int BORDER_Y_axis = 20 ; BORDER_Y_axis < 31 ; BORDER_Y_axis++ )
								{
									gotoXY_BORDER ( 75 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 129 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									
									gotoXY_BORDER ( 75 , 20 ) ; printf ( "%c", 201 );	// top corners
									gotoXY_BORDER ( 129 , 20 ) ; printf ( "%c", 187 );
									gotoXY_BORDER ( 75 , 30 ) ; printf ( "%c", 200 );	// bottom corners
									gotoXY_BORDER ( 129 , 30 ) ; printf ( "%c", 188 );	
								}		
							
							// SMALL BORDERS
								for( int BORDER_X_axis = 75 ; BORDER_X_axis < 100 ; BORDER_X_axis++ ) // horizontal left
								{
									gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 196 );	// last		
								}
								
								for( int BORDER_X_axis = 105 ; BORDER_X_axis < 129 ; BORDER_X_axis++ ) // horizontal right
								{
									gotoXY_BORDER ( BORDER_X_axis , 32 ) ; printf ( "%c", 196 );	// 1st line
									gotoXY_BORDER ( BORDER_X_axis , 36 ) ; printf ( "%c", 196 );	// last		
								}	
							
								for( int BORDER_Y_axis = 32 ; BORDER_Y_axis < 37 ; BORDER_Y_axis++ )
								{
									gotoXY_BORDER ( 75 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 99 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									gotoXY_BORDER ( 105 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// left
									gotoXY_BORDER ( 129 , BORDER_Y_axis ) ; printf ( "%c", 179 );	// right
									
								// LEFT
									gotoXY_BORDER ( 75 , 32 ) ; printf ( "%c", 201 ) ; gotoXY_BORDER ( 99 , 32 ) ; printf ( "%c", 187 );	// top corners
									gotoXY_BORDER ( 75 , 36 ) ; printf ( "%c", 200 ) ; gotoXY_BORDER ( 99 , 36 ) ; printf ( "%c", 188 );	// bottom corners
									
								// RIGHT
									gotoXY_BORDER ( 105 , 32 ) ; printf ( "%c", 201 ) ; gotoXY_BORDER ( 129 , 32 ) ; printf ( "%c", 187 );	// top corners
									gotoXY_BORDER ( 105 , 36 ) ; printf ( "%c", 200 ) ; gotoXY_BORDER ( 129 , 36 ) ; printf ( "%c", 188 );	// bottom corners
								}	
								
							gotoXY_STRING ( 90 , 24 ) ; printf( "This will end the program." ) ; gotoXY_STRING ( 95 , 26 ) ; printf( "Are you sure?" ) ;
							
							gotoXY_STRING ( 86 , 34 ) ; printf( "YES" ) ; gotoXY_STRING ( 117 , 34 ) ; printf( "NO" ) ;
							
							SetConsoleTextAttribute ( hConsole, 12 ) ; gotoXY_STRING ( 80 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 94 , 34 ) ; printf( "%c" , 17 ) ;
							
							getch() ; QUIT_run = true ; while( QUIT_run )
							{
									
								if( GetAsyncKeyState(VK_LEFT) && STRING_X_axis != 11 )
								{	
									SetConsoleTextAttribute ( hConsole, 12 ) ; OPTION_select = 1 ; STRING_X_axis++;
									gotoXY_STRING ( 111 , 34 ) ; printf( " " ) ; gotoXY_STRING ( 124 , 34 ) ; printf( " " ) ;
									gotoXY_STRING ( 80 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 94 , 34 ) ; printf( "%c" , 17 ) ;
								}
									
								if( GetAsyncKeyState(VK_RIGHT) && STRING_X_axis != 12 )
								{
									SetConsoleTextAttribute ( hConsole, 11 ) ; OPTION_select = 2 ; STRING_X_axis--;
									gotoXY_STRING ( 80 , 34 ) ; printf( " " ) ; gotoXY_STRING ( 94 , 34 ) ; printf( " " ) ;
									gotoXY_STRING ( 111 , 34 ) ; printf( "%c" , 16 ) ; gotoXY_STRING ( 124 , 34 ) ; printf( "%c" , 17 ) ;
								}
									
									
								if( GetAsyncKeyState( VK_RETURN ) ) 
								{
									switch ( OPTION_select ) 
									{
										case 1: 
										{
											SetConsoleTextAttribute ( hConsole, 13 ) ; gotoXY_STRING ( 83 , 27 ) ; printf( "Thank you for using MNL GOJO BUSLINE! %c" , 3 );
											Sleep( 4500 ) ; QUIT_run = false;
											break;
										}
										
										case 2: 
										{
											// clearing step
											gotoXY_STRING( 10 , 18 ) ; printf( "                                  " );
												for ( int ASCII_Y_axis = 5 ; ASCII_Y_axis <= 46 ; ASCII_Y_axis++ )
												{
													gotoXY_STRING( 60 , ASCII_Y_axis ) ; printf( "                                                                                   " );	// clears the previous ascii arts
												}
											
											goto MAIN_MENU_OPTIONS;
											break;
										}
									}
								}
							}
							
							
						}
					
					}		
				}
						
							
			}
			
		}
	
	
	gotoXY_STRING(20,21);
	return 0;
	
}
