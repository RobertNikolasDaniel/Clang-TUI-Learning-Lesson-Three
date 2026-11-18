#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>


//C++ TUI Lesson Three
//Building Upon Concepts of Time, Randomness




//---VOID FUNCTIONS---

//pauseSeconds, pauses the screen for an input of seconds
void pauseSeconds( int s ) {
	std::this_thread::sleep_for( std::chrono::seconds( s ) );
}

//pauseMiliseconds, same thing but for milliseconds
void pauseMilliseconds( int m ) {
	std::this_thread::sleep_for( std::chrono::milliseconds( m ) );
}

//setColor, sets color for outputs
void setColor( int color ) {
	std::cout << "\033[" << color << "m";
}

//clearScreen, clears screen, clears terminal, and resets home
void clearScreen() {
	std::cout << "\033[2J";
	std::cout << "\033[3J";
	std::cout << "\033[H";
}

//moveTo, moves position and cursor 
void moveTo( int row, int col ) {
	std::cout << "\033[" << row << ";" << col << "H";
}

//clearLine, clears a line cursor is on
void clearLine() {
	std::cout << "\033[2K";
} 

//hideCursor, hides cursor for clean UI
void hideCursor() {
	std::cout << "\033[?25l";
}

//showCursor, brings cursor back
void showCursor() {
	std::cout << "\033[?25h";
}

//enterScreen, enters an alternate screen
void enterScreen() {
	std::cout << "\033[?1049h";
}

//exitScreen, exits the alternate screen
void exitScreen() {
	std::cout << "\033[?1049l";
}








//---STRUCTURE DATA---

//Quote Structure
struct Quote {
	std::string name;
	int price;
};










//---MAIN---
int main() {
	//---UI ENTER VOIDS---
	enterScreen();
	clearScreen();
	hideCursor();




	//---PRICES DATA---


	//moves vector
	std::vector<int> moves = { 0, 0, 0 };

	//Quote ladder VECTOR
	std::vector<Quote> ladder {
		{ "2Y", 100 },
		{ "5Y", 99 },
		{ "10Y", 98 }
	};






	//---USING CTIME---

	//Generating the Time in Seconds SINCE 1970
	//nullptr is the ammount of seconds since 1970 which is super cool
	int sTime = time( nullptr );
	


	//Telling the Time, USES UTC TIME NOT LOCAL

	//seconds today, takes the remainder of a division of the total seconds in a 24hr day
	int secondsToday = sTime % 86400;

	//hours today, divides integer seconds  by 3600 which is seconds in an hour
	int hoursToday = secondsToday / 3600;

	//minutes today, divides the remainder of hours by 60 to get minutes
	int minutesToday = ( secondsToday % 3600 ) / 60;

	//OUTPUT TIME LIKE A CLOCK
	//std::cout << "\nUTC TIME\n" << hoursToday << " : " << minutesToday << "\n" << std::endl;
	

	//Using Time as a Random Seed Generator
	srand( sTime );










	//---PAUSE AND TICKS, WORKING WITH RANDOMNESS---

	//---FOR OUTPUT LOOP---
	for ( int tick = 1; tick <= 6; tick++ ) {


		//---TIME CLOCK---
		
		//UTC CLOCK
		moveTo( 1, 1);
		clearLine();
		std::cout << hoursToday << " : ";
		if ( minutesToday < 10 ) {
			std::cout << "0" << minutesToday;
		} else {
			std::cout << minutesToday;
		}
			


		//---OUTPUT VECTORS---

		
		//Apply Move To Prices, and store move into moves vector
		for ( int h = 0; h < ladder.size(); h++ ) {
			//new random move
			int rowMove = ( rand() % 7 ) - 3;
			//store into moves vector
			moves[h] = rowMove;
			//update price
			ladder[h].price += rowMove;
		}
	
		//print vector, with color updates on move
		for ( int g = 0; g < ladder.size(); g++ ) {
			//position it
			moveTo( ( 3 + g), 1 );
			//clear line makes output clean
			clearLine();
			//setColor shows price change color based on moves vector
			if ( moves[g] > 0 ) {
				setColor( 32 );
			} else if ( moves[g] < 0 ) {
				setColor( 31 );
			} else {
				setColor( 0 );
			}
			//print price
			std::cout << ladder[g].name << " " << ladder[g].price;
		}
		//return color after loop
		setColor( 0 );
		






		//---END OF LOOP STUFF---

		std::cout << "\n";

		//tick pause
		pauseMilliseconds( 500 );

	
	}






	
	//---UI EXIT VOIDS---
	
	//showCursor
	showCursor();
	//exit screen
	exitScreen();

	//print final values
	for ( int p = 0; p < ladder.size(); p++ ) {
		std::cout << ladder[p].name << " " << ladder[p].price << std::endl;
	}





	//Return 0
	return 0;
}
