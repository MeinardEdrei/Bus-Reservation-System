#include <ctime>
#include <limits>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

// wwd / month / date / time in 24 hour format (hour/min/secs) / year

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY( int STRINGX_AXIS , int STRINGY_AXIS ){
	
	CursorPosition.X = STRINGX_AXIS;
	CursorPosition.Y = STRINGY_AXIS;
	SetConsoleCursorPosition( console , CursorPosition );
	
}

void gotoXY_BORDER( int STRINGX_AXIS , int STRINGY_AXIS ){
	
	CursorPosition.X = STRINGX_AXIS;
	CursorPosition.Y = STRINGY_AXIS;
	SetConsoleCursorPosition( console , CursorPosition );
	
}

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoXY_STRING ( int STRING_X_axis, int STRING_Y_axis )
{
	CursorPosition.X = STRING_X_axis;
	CursorPosition.Y = STRING_Y_axis;
	SetConsoleCursorPosition( console, CursorPosition );
}


main(){
	
	system("title MNL GOJO BUSLINE");
	
	// DECLARATION FOR DESTINATION
	string DestinationLocation;
	int SelectDestination = 0;
	
	ShowConsoleCursor(false);
	
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
	} // window size end
	
	
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
	
	SEGMENT_BORDERS:
	{
		int STRINGX_AXIS , STRINGY_AXIS;
		
		for( STRINGX_AXIS = 7 ; STRINGX_AXIS <= 141 ; STRINGX_AXIS++ ){
			
			Color(12);
			gotoXY_BORDER( STRINGX_AXIS , 3 ); printf( "%c" , 220 );
			gotoXY_BORDER( STRINGX_AXIS , 46 ); printf( "%c" , 220 );
			
		}
		
		for( STRINGY_AXIS = 4 ; STRINGY_AXIS <= 46 ; STRINGY_AXIS++ ){
			
			Color(12);
			gotoXY_BORDER( 7 , STRINGY_AXIS ); printf( "%c" , 219 );
			gotoXY_BORDER( 141 , STRINGY_AXIS ); printf( "%c" , 219 );
			
		}
		
	}
	
	
	Color(14);
	gotoXY( 13 , 6  ); 
	gotoXY( 13 , 7  ); 
	gotoXY( 13 , 8  ); 
	gotoXY( 13 , 9  );
	gotoXY( 13 , 10  ); 
	gotoXY( 13 , 11  ); 
	gotoXY( 13 , 12  );
	gotoXY( 13 , 13  ); 
	gotoXY( 13 , 14  );
	
	
	DESTINATION_BORDER:
	{
		int STRINGX_AXIS , STRINGY_AXIS;
		
	    Color(13);
		for( STRINGX_AXIS = 12 ; STRINGX_AXIS <= 55 ; STRINGX_AXIS++ ){
			
			gotoXY_BORDER( STRINGX_AXIS , 16 ); printf( "%c" , 205 ); // top
			gotoXY_BORDER( STRINGX_AXIS , 44 ); printf( "%c" , 205 ); // bottom
			
		}
		
		for( STRINGY_AXIS = 17 ; STRINGY_AXIS <= 43 ; STRINGY_AXIS++ ){
			
			gotoXY_BORDER( 12 , STRINGY_AXIS ); printf( "%c" , 186 ); // sides
			gotoXY_BORDER( 56 , STRINGY_AXIS ); printf( "%c" , 186 ); // sides
			
			EDGES1:
			gotoXY_BORDER( 12 , 16 ); printf( "%c" , 201 ); // top left side
			gotoXY_BORDER( 56 , 16 ); printf( "%c" , 187 ); // top right side
			gotoXY_BORDER( 12 , 44 ); printf( "%c" , 200 ); // left bottom side
			gotoXY_BORDER( 56 , 44 ); printf( "%c" , 188 ); // right bottom side
			
		}
		
	}
	
	DESTINATION_SELECTION:
	{
		
		int STRINGX_AXIS , STRINGY_AXIS;
		bool DestinationRunning = true;
		
		for( STRINGX_AXIS = 16 ; STRINGX_AXIS <= 51 ; STRINGX_AXIS++ ){
			
			Color(14);
			gotoXY_STRING( 18 , 20 ); printf( " %c                            %c" , 16 , 17 );
			
			Color(3);
			gotoXY_BORDER( STRINGX_AXIS , 18 ); printf( "%c" , 205 );
			gotoXY_BORDER( STRINGX_AXIS , 23 ); printf( "%c" , 205 );
			
			Color(7);
			gotoXY_BORDER( STRINGX_AXIS , 27 ); printf( "%c" , 196 );
			gotoXY_BORDER( STRINGX_AXIS , 32 ); printf( "%c" , 196 );
			
			gotoXY_BORDER( STRINGX_AXIS , 34 ); printf( "%c" , 196 );
			gotoXY_BORDER( STRINGX_AXIS , 39 ); printf( "%c" , 196 );
			
		}
		
		for( STRINGY_AXIS = 19 ; STRINGY_AXIS <= 22 ; STRINGY_AXIS++ ){
			
			Color(3);
			gotoXY_BORDER( 16 , STRINGY_AXIS ); printf( "%c" , 186 );
			gotoXY_BORDER( 51 , STRINGY_AXIS ); printf( "%c" , 186 );
			
			gotoXY_BORDER( 16 , 18 ); printf( "%c" , 201 ); // top left side
		    gotoXY_BORDER( 51 , 18 ); printf( "%c" , 187 ); // top right side
		    gotoXY_BORDER( 16 , 23 ); printf( "%c" , 200 ); // left bottom side
		    gotoXY_BORDER( 51 , 23 ); printf( "%c" , 188 ); // right bottom side
			
		}
		
		for( STRINGY_AXIS = 28 ; STRINGY_AXIS <= 31 ; STRINGY_AXIS++ ){
			
			Color(7);
			gotoXY_BORDER( 16 , STRINGY_AXIS ); printf( "%c" , 179 );
			gotoXY_BORDER( 51 , STRINGY_AXIS ); printf( "%c" , 179 );
			
			gotoXY_BORDER( 16 , 27 ); printf( "%c" , 201 ); // top left side
		    gotoXY_BORDER( 51 , 27 ); printf( "%c" , 187 ); // top right side
		    gotoXY_BORDER( 16 , 32 ); printf( "%c" , 200 ); // left bottom side
		    gotoXY_BORDER( 51 , 32 ); printf( "%c" , 188 ); // right bottom side
			
		}
		
		for( STRINGY_AXIS = 35 ; STRINGY_AXIS <= 38 ; STRINGY_AXIS++ ){
			
			Color(7);
			gotoXY_BORDER( 16 , STRINGY_AXIS ); printf( "%c" , 179 );
			gotoXY_BORDER( 51 , STRINGY_AXIS ); printf( "%c" , 179 );
			
			gotoXY_BORDER( 16 , 34 ); printf( "%c" , 201 ); // top left side
		    gotoXY_BORDER( 51 , 34 ); printf( "%c" , 187 ); // top right side
		    gotoXY_BORDER( 16 , 39 ); printf( "%c" , 200 ); // left bottom side
		    gotoXY_BORDER( 51 , 39 ); printf( "%c" , 188 ); // right bottom side
			
		}
		
		Color(15); gotoXY( 15 , 42 ); printf( "%c Use " ); Color(2); printf( "%c" , 25 ) ; 
		Color(15); printf( " and " ); Color(2); printf( "%c", 24 ); Color(15); printf( " arrow keys and press "); 
		Color(2); printf( "ENTER" );
		
		Color(7);
		gotoXY( 26 , 20 ); printf("  I L O C O S   ");
		gotoXY( 26 , 29 ); printf("P A M P A N G A ");
		gotoXY( 26 , 36 ); printf("Z A M B A L E Z ");
		
		
		while(DestinationRunning){
			
			system("pause>null");
			
			if(GetAsyncKeyState(VK_DOWN) && SelectDestination != 9){
				
				SelectDestination++;
				
				switch(SelectDestination){
					case 1:
						gotoXY_STRING( 26 , 20 ); printf("P A M P A N G A       ");
						break;
					case 2:
						gotoXY_STRING( 26 , 20 ); printf("Z A M B A L E Z       ");
						break;
					case 3:
						gotoXY_STRING( 26 , 20 ); printf("  B A G U I O         ");
						break;
					case 4:
						gotoXY_STRING( 26 , 20 ); printf("   A P A R I          ");
						break;
					case 5:
						gotoXY_STRING( 25 , 20 ); printf(" L A - U N I O N      ");
						break;
					case 6:
						gotoXY_STRING( 23 , 20 ); printf(" N U E V A  E C I J A ");
						break;
					case 7:
						gotoXY_STRING( 23 , 20 ); printf("  T U G E G A R A O   ");
						break;
					case 8:
						gotoXY_STRING( 25 , 20 ); printf("     L A O G          ");
						break;
					case 9:
						gotoXY_STRING( 23 , 20 ); printf(" P A N G A S I N A N   ");
						break;
				}
				
				switch(SelectDestination){ // boxes below
					case 1:
						gotoXY_STRING( 26 , 29 ); printf("Z A M B A L E Z          ");
						gotoXY_STRING( 26 , 36 ); printf("  B A G U I O            ");
						break;
					case 2:
						gotoXY_STRING( 26 , 29 ); printf("  B A G U I O            ");
						gotoXY_STRING( 26 , 36 ); printf("   A P A R I             ");
						break;
					case 3:
						gotoXY_STRING( 26 , 29 ); printf("   A P A R I             ");
						gotoXY_STRING( 23 , 36 ); printf("   L A - U N I O N       ");
						break;
					case 4:
						gotoXY_STRING( 25 , 29 ); printf(" L A - U N I O N         ");
						gotoXY_STRING( 22 , 36 ); printf("  N U E V A  E C I J A   ");
						break;
					case 5:
						gotoXY_STRING( 23 , 29 ); printf(" N U E V A  E C I J A    ");
						gotoXY_STRING( 22 , 36 ); printf("   T U G E G A R A O     ");
						break;
					case 6:
						gotoXY_STRING( 22 , 29 ); printf("   T U G E G A R A O     ");
						gotoXY_STRING( 23 , 36 ); printf("      L A O G            ");
						break;
					case 7:
						gotoXY_STRING( 23 , 29 ); printf("      L A O G            ");
						gotoXY_STRING( 22 , 36 ); printf("  P A N G A S I N A N    ");
						break; 
					case 8:
						gotoXY_STRING( 22 , 29 ); printf("  P A N G A S I N A N    ");
						gotoXY_STRING( 22 , 36 ); printf("                         ");
						break;
					case 9:
						gotoXY_STRING( 22 , 29 ); printf("                         ");
						gotoXY_STRING( 22 , 36 ); printf("                         ");
						break;
					
				} // switch select down end
				
			} // select down key end 
			
			
			
			if(GetAsyncKeyState(VK_UP) && SelectDestination >= 1){
				
				SelectDestination--;
				
				switch(SelectDestination){
					case 0:
						gotoXY_STRING( 23 , 20 ); printf("     I L O C O S      ");
						break;
					case 1:
						gotoXY_STRING( 26 , 20 ); printf("P A M P A N G A       ");
						break;
					case 2:
						gotoXY_STRING( 26 , 20 ); printf("Z A M B A L E Z       ");
						break;
					case 3:
						gotoXY_STRING( 26 , 20 ); printf("  B A G U I O         ");
						break;
					case 4:
						gotoXY_STRING( 26 , 20 ); printf("   A P A R I          ");
						break;
					case 5:
						gotoXY_STRING( 22 , 20 ); printf("    L A - U N I O N   ");
						break;
					case 6:
						gotoXY_STRING( 22 , 20 ); printf("  N U E V A  E C I J A");
						break;
					case 7:
						gotoXY_STRING( 23 , 20 ); printf("  T U G E G A R A O   ");
						break;
					case 8:
						gotoXY_STRING( 24 , 20 ); printf("      L A O G         ");
						break;
					case 9:
						gotoXY_STRING( 23 , 20 ); printf("  P A N G A S I N A N ");
						break;
				} // switch select up end
				
				switch(SelectDestination){ // boxes below
				    case 0:
				    	gotoXY_STRING( 26 , 29 ); printf("P A M P A N G A          ");
				    	gotoXY_STRING( 26 , 36 ); printf("Z A M B A L E Z          ");
				        break;
					case 1:
						gotoXY_STRING( 26 , 29 ); printf("Z A M B A L E Z          ");
						gotoXY_STRING( 26 , 36 ); printf("  B A G U I O            ");
						break;
					case 2:
						gotoXY_STRING( 26 , 29 ); printf("  B A G U I O            ");
						gotoXY_STRING( 26 , 36 ); printf("   A P A R I             ");
						break;
					case 3:
						gotoXY_STRING( 26 , 29 ); printf("   A P A R I             ");
						gotoXY_STRING( 23 , 36 ); printf("   L A - U N I O N       ");
						break;
					case 4:
						gotoXY_STRING( 24 , 29 ); printf("  L A - U N I O N        ");
						gotoXY_STRING( 22 , 36 ); printf("  N U E V A  E C I J A   ");
						break;
					case 5:
						gotoXY_STRING( 23 , 29 ); printf(" N U E V A  E C I J A    ");
						gotoXY_STRING( 22 , 36 ); printf("   T U G E G A R A O     ");
						break;
					case 6:
						gotoXY_STRING( 22 , 29 ); printf("   T U G E G A R A O     ");
						gotoXY_STRING( 23 , 36 ); printf("      L A O G            ");
						break;
					case 7:
						gotoXY_STRING( 23 , 29 ); printf("      L A O G            ");
						gotoXY_STRING( 22 , 36 ); printf("  P A N G A S I N A N    ");
						break; 
					case 8:
						gotoXY_STRING( 22 , 29 ); printf("  P A N G A S I N A N    ");
						gotoXY_STRING( 22 , 36 ); printf("                         ");
						break;
					case 9:
						gotoXY_STRING( 22 , 29 ); printf("                         ");
						gotoXY_STRING( 22 , 36 ); printf("                         ");
						break;
					
				} // switch select down end
				
			} // select up key end
			
			if(GetAsyncKeyState(VK_RETURN)){
				
				switch(SelectDestination){
					case 0:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "ILOCOS";
						DestinationRunning = false;
						break;
					case 1:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "PAMPANGA";
						DestinationRunning = false;
						break;
					case 2:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "ZAMBALEZ";
						DestinationRunning = false;
						break;
					case 3:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "BAGUIO";
						DestinationRunning = false;
						break;
					case 4:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "APARI";
						DestinationRunning = false;
						break;
					case 5:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "LA UNION";
						DestinationRunning = false;
						break;
					case 6:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "NUEVA ECIJA";
						DestinationRunning = false;
						break;
					case 7:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "TUGEGARAO";
						DestinationRunning = false;
						break;
					case 8:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "LAOG";
						DestinationRunning = false;
						break;
					case 9:
						Color(10); gotoXY_STRING( 28 , 25 ); printf(" RESERVED! ");
						Color(7);
						DestinationLocation = "PANGASINAN";
						DestinationRunning = false;
						break;
				}
				
			} // return key end
			
			
		} // while destination running end
		
	} // destination selection end
	
	TRIVIA_BORDERS:
	{
		
		int STRINGX_AXIS , STRINGY_AXIS;
		bool TriviaRunning = true;
		
		for( STRINGX_AXIS = 65 ; STRINGX_AXIS <= 132 ; STRINGX_AXIS++ ){
			
			Color(15);
			gotoXY_BORDER( STRINGX_AXIS , 16 ); printf( "%c" , 205 );
			gotoXY_BORDER( STRINGX_AXIS , 25 ); printf( "%c" , 205 );
			
		}
		
		for( STRINGY_AXIS = 17 ; STRINGY_AXIS <= 24 ; STRINGY_AXIS++ ){
			
			gotoXY_BORDER( 65 , STRINGY_AXIS ); printf( "%c" , 186 );
			gotoXY_BORDER( 132 , STRINGY_AXIS ); printf( "%c" , 186 );
			
			EDGES2:
			gotoXY_BORDER( 65 , 16 ); printf( "%c" , 201 ); // top left side
			gotoXY_BORDER( 132 , 16 ); printf( "%c" , 187 ); // top right side
			gotoXY_BORDER( 65 , 25 ); printf( "%c" , 200 ); // left bottom side
			gotoXY_BORDER( 132, 25 ); printf( "%c" , 188 ); // right bottom side
			
		}
		
		switch(SelectDestination){
			case 0:
				Color(11);
		        gotoXY_STRING( 90 , 18 ); printf(" I L O C O S ");
		        Color(7);
		        gotoXY_STRING( 70 , 21 ); printf("%c Famous for it's preserved Spanish colonial city of Vigan" , 6);
		        gotoXY_STRING( 70 , 22 ); printf("%c Its provinces are famous for agro-industrial businesses" , 6);
		        break;
		    case 1:
		    	Color(11);
		        gotoXY_STRING( 90 , 18 ); printf(" P A M P A N G A ");
		        Color(7);
		        gotoXY_STRING( 70 , 21 ); printf("%c Considered to be the Culinary capital of the Philippines" , 6);
		        gotoXY_STRING( 67 , 22 ); printf("%c The word pampang, the province's name origin, means river bank" , 6);
		        break;
		    case 2:
				Color(11);
		        gotoXY_STRING( 90 , 18 ); printf(" Z A M B A L E Z ");
		        Color(7);
		        gotoXY_STRING( 76 , 21 ); printf("%c The second largest province in Central Luzon" , 6);
		        gotoXY_STRING( 69 , 22 ); printf("%c Coves in Zambales are unique because they have agoho trees" , 6);
		        gotoXY_STRING( 74 , 23 ); printf(" that grew after the Mt. Pinatubo erupted in 1991. ");
		        break;
		    case 3:
				Color(11);
		        gotoXY_STRING( 91 , 18 ); printf(" B A G U I O ");
		        Color(7);
		        gotoXY_STRING( 73 , 21 ); printf("%c Came from the Ibaloi word Bagiw which means Moss" , 6);
		        gotoXY_STRING( 70 , 22 ); printf("%c Best known as the Summer Capital of the Philippines, with" , 6);
		        gotoXY_STRING( 74 , 23 ); printf(" its cool climate making this a spot to relax");
		        break;
		    case 4:
				Color(11);
		        gotoXY_STRING( 92 , 18 ); printf(" A P A R I ");
		        Color(7);
		        gotoXY_STRING( 69 , 21 ); printf("%c Known for its foods such as the bulung-unas, or Ribbon Fish" , 6);
		        gotoXY_STRING( 73 , 22 ); printf("%c It sits at the mouth of the Cagayan River, the " , 6);
		        gotoXY_STRING( 80 , 23 ); printf(" longest river in the Philippines");
		        break;
		    case 5:
				Color(11);
		        gotoXY_STRING( 90 , 18 ); printf("L A  U N I O N ");
		        Color(7);
		        gotoXY_STRING( 73 , 20 ); printf("%c Without a doubt, is known as a surfing destination" , 6);
		        gotoXY_STRING( 66 , 21 ); printf("%c It has plenty of surfing spots and waves that can reach 10 feet!" , 6);
		        gotoXY_STRING( 69 , 22 ); printf("Many of its visitors make their way here to enjoy its waters ");
		        break;
		    case 6:
				Color(11);
		        gotoXY_STRING( 87 , 18 ); printf(" N U E V A  E C I J A ");
		        Color(7);
		        gotoXY_STRING( 76 , 21 ); printf("%c Is known as the Rice Bowl of the Philippines" , 6);
		        gotoXY_STRING( 68 , 22 ); printf("%c The province was named after the old city of Ecija in Spain" , 6);
		        break;
		    case 7:
				Color(11);
		        gotoXY_STRING( 88 , 18 ); printf(" T U G E G A R A O ");
		        Color(7);
		        gotoXY_STRING( 72 , 21 ); printf("%c Is noted for being the warmest city in the Philippines" , 6);
		        gotoXY_STRING( 69 , 22 ); printf("%c Dubbed as the Gateway to the Ilocandia and the Cordilleras" , 6);
		        break;
		    case 8:
				Color(11);
		        gotoXY_STRING( 93 , 18 ); printf(" L A O G ");
		        Color(7);
		        gotoXY_STRING( 76 , 20 ); printf("%c Is known as the Jewel of Ilocos Norte and" , 6);
		        gotoXY_STRING( 66 , 21 ); printf(" offers majestic sand dunes along the Ilocos coastline, galvanic");
		        gotoXY_STRING( 70 , 22 ); printf(" natural rock formations, and centuries-old stone churches");
		        break;
		    case 9:
				Color(11);
		        gotoXY_STRING( 87 , 18 ); printf(" P A N G A S I N A N ");
		        Color(7);
		        gotoXY_STRING( 67 , 21 ); printf("%c Translates to Place of Salt as it is a major producer of salt" , 6);
		        gotoXY_STRING( 67 , 22 ); printf("%c It boasts of stretches of white, sandy beaches, and many more!" , 6);
		        break;
		}
		
		
	} // trivia segment end
	
	TRIP_BORDERS:
	{
		
		int STRINGX_AXIS , STRINGY_AXIS;
		int TripSelect = 0;
		bool TripRunning = true;
		string DestinationTrip;
		
		Color(15);
		for( STRINGX_AXIS = 65 ; STRINGX_AXIS <= 132 ; STRINGX_AXIS++ ){
			
			gotoXY_BORDER( STRINGX_AXIS , 28 ); printf( "%c" , 205 ); 
			gotoXY_BORDER( STRINGX_AXIS , 30 ); printf( "%c" , 205 ); 
			gotoXY_BORDER( STRINGX_AXIS , 44 ); printf( "%c" , 205 ); 
			
		}
		
		for( STRINGY_AXIS = 29 ; STRINGY_AXIS <= 43 ; STRINGY_AXIS++ ){
			
			gotoXY_BORDER( 65 , STRINGY_AXIS ); printf( "%c" , 186 ); // sides
			gotoXY_BORDER( 132 , STRINGY_AXIS ); printf( "%c" , 186 ); // sides
			
			EDGES3:
			gotoXY_BORDER( 65 , 28 ); printf( "%c" , 201 );
			gotoXY_BORDER( 132 , 28 ); printf( "%c" , 187 );
			gotoXY_BORDER( 65 , 44 ); printf( "%c" , 200 );
			gotoXY_BORDER( 132 , 44 ); printf( "%c" , 188 );
			
		}
		
		Color(7);
		for( STRINGX_AXIS = 73 ; STRINGX_AXIS <= 123 ; STRINGX_AXIS++ ){
			
			gotoXY_BORDER( STRINGX_AXIS , 33 ); printf( "%c" , 196 );
			gotoXY_BORDER( STRINGX_AXIS , 40 ); printf( "%c" , 196 );
			
		}
		
		for( STRINGY_AXIS = 34 ; STRINGY_AXIS <= 39 ; STRINGY_AXIS++ ){
			
			gotoXY_BORDER( 73 , STRINGY_AXIS ); printf( "%c" , 179 );
			gotoXY_BORDER( 123 , STRINGY_AXIS ); printf( "%c" , 179 );
			
			EDGES4:
			gotoXY_BORDER( 73 , 33 ); printf( "%c" , 218 ); // top left side
		    gotoXY_BORDER( 123 , 33 ); printf( "%c" , 191 ); // top right side
		    gotoXY_BORDER( 73 , 40 ); printf( "%c" , 192 ); // left bottom side
		    gotoXY_BORDER( 123 , 40 ); printf( "%c" , 217 ); // right bottom side
			
		}
		
		gotoXY( 88 , 33 ); printf("DO YOU WISH TO AVAIL?");
		
		Color(15); gotoXY( 78 , 42 ); printf( "%c Use " ); Color(2); printf( "%c" , 17 ); 
		Color(15); printf( " and " ); Color(2); printf( "%c" , 16 ); Color(15); printf( " arrow keys and press "); 
		Color(2); printf( "ENTER" );
		
		gotoXY( 79 , 36 ); Color(13); printf( "%c%c " , 254 , 254 ); Color(7); printf("ONE WAY TRIP");
		gotoXY( 104 , 36 ); Color(7); printf( " %c%c " , 254 , 254 ); Color(7); printf("ROUND TRIP");
		
		while(TripRunning){
			
			system("pause>null");
			
			if(GetAsyncKeyState(VK_RIGHT) && STRINGX_AXIS != 105 && TripSelect != 1){
				
				TripSelect++;
				gotoXY_STRING( 78 , 36 ); Color(7); printf( " %c%c " , 254 , 254 );
				gotoXY_STRING( 104 , 36 ); Color(13); printf( " %c%c " , 254 , 254 );
				
			}
			
			if(GetAsyncKeyState(VK_LEFT) && STRINGX_AXIS != 78 && TripSelect > 0){
				
				TripSelect--;
				gotoXY_STRING( 78 , 36 ); Color(13); printf( " %c%c " , 254 , 254 );
				gotoXY_STRING( 104 , 36 ); Color(7); printf( " %c%c " , 254 , 254 );
				
			}
			
			if(GetAsyncKeyState(VK_RETURN)){
				
				switch(TripSelect){
					case 1:
						DestinationTrip = "ROUND TRIP";
						gotoXY( 94 , 38 ); Color(10); printf("RESERVED!");
						TripRunning = false;
						break;
					case 0:
						DestinationTrip = "ONE WAY TRIP";
						gotoXY( 94 , 38 ); Color(10); printf("RESERVED!");
						TripRunning = false;
						break;
				}
				
				
			} // enter key end
			
			Color(7);
			
		} // while trip end
		
		
	} // trip borders end
	
	
	
	
	
	
	
	
	
	
	
	
	
	// DAYS DECLARATION & POINTERS
	int WeekDayDigit;
	string WeekDayString;
	time_t CurrentTimeForDays;
	
	CurrentTimeForDays = time(NULL);
	tm *LocalTimeForDays = localtime(&CurrentTimeForDays); 
	WeekDayDigit = LocalTimeForDays->tm_wday;
	
	// MONTH DECLARATION & POINTERS
	int MonthDigit;
	string Month;
	time_t CurrentTimeForMonth;
	
	CurrentTimeForMonth = time(0);
	tm *LocalTimeForMonth = localtime(&CurrentTimeForMonth);
	MonthDigit = 1 + LocalTimeForMonth->tm_mon;
	
	// DATE DECLARATIONS & POINTERS
	int LocalDay;
	time_t CurrentTimeForDDay;
	
	CurrentTimeForDDay = time(0);
	tm *LocalTimeForDDay = localtime(&CurrentTimeForDDay);
	LocalDay = LocalTimeForDDay->tm_mday;
	
	// 24 HOUR FORMAT TIME DECLARATIONS
	int LocalHour;
	int LocalMinutes;
	int LocalYear;
	time_t TimeHour;
	time_t TimeMinutes;
	time_t TimeYear;
	
	// HOURS
	TimeHour = time(0);
	tm *LocalTimeForHours = localtime(&TimeHour);
	LocalHour = LocalTimeForHours->tm_hour; 
	
	// MINUTES
	TimeMinutes = time(0);
	tm *LocalTimeForMinutes = localtime(&TimeMinutes);
	LocalMinutes = LocalTimeForMinutes->tm_min; 
	
	// YEAR
	TimeYear = time(0);
	tm *LocalTimeForYear = localtime(&TimeYear);
	// plus 1900 because of the pointer of a time_t object stored seconds since jan 1, 1900
	LocalYear = 1900 + LocalTimeForYear->tm_year; 
	
	
	switch(WeekDayDigit){
		case 1:
			WeekDayString = "Monday";
			break;
		case 2:
			WeekDayString = "Tuesday";
			break;
		case 3:
			WeekDayString = "Wednesday";
			break;
		case 4:
			WeekDayString = "Thursday";
			break;
		case 5:
			WeekDayString = "Friday";
			break;
		case 6:
			WeekDayString = "Saturday";
			break;
		case 7:
			WeekDayString = "Sunday";
			break;
	}
	
	switch(MonthDigit){
		case 1:
			Month = "January";
			break;
		case 2:
			Month = "February";
			break;
		case 3:
			Month = "March";
			break;
		case 4:
			Month = "April";
			break;
		case 5:
			Month = "May";
			break;
		case 6:
			Month = "June";
			break;
		case 7:
			Month = "July";
			break;
		case 8:
			Month = "August";
			break;
		case 9:
			Month = "September";
			break;
		case 10:
			Month = "October";
			break;
		case 11:
			Month = "November";
			break;
		case 12:
			Month = "December";
			break;
	}
	/*
	cout << "\nWeekDay: " << WeekDayDigit << " " << WeekDayString << endl;
	cout << "Month: " << MonthDigit << " " << Month << endl;
	cout << "Day: " << LocalDay << endl;
	cout << "Time: HOURS: " << LocalHour << " : MINUTES: " << LocalMinutes << endl;
	cout << "Year: " << LocalYear << endl;
	
	// RESERVED DATE AND TIME EXAMPLE SELECTION OF USER
	int reservationWeekDay = 6; 
	int reservationMonth = 11; 
	int reservationDDay = 27;
	int reservationHour = 18;
	int reservationMinutes; // minutes not included in reservation
	int reservationYear = 2021;
	
	if(reservationWeekDay <= WeekDayDigit && reservationMonth <= MonthDigit && reservationHour <= LocalHour && reservationDDay <= LocalDay){
		cout << "\nNEW SEATS AVAILABLE!";
	}
	*/
	return 0;
}
