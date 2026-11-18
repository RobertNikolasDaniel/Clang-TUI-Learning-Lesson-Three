# Clang-TUI-Learning-Lesson-Three
This is lesson three in my C++ terminal UI (TUI) series, written by hand while learning C++ for a career in fixed income. It builds on the screen-control tools from the first two lessons and adds time and randomness. The program shows a UTC clock on the top row and a three-row US Treasury ladder (2Y, 5Y, 10Y) that updates in place, with each price taking its own random step up or down every half second.

Along the way it covers sleeping with <thread> and <chrono>, seeding rand() with the current time, turning raw seconds into hours and minutes with integer division and modulo, and storing data in a Quote struct inside a std::vector. Each row is colored green or red by that tick's move using ANSI escape codes, and the program runs on the terminal's alternate screen so your normal PowerShell history is left untouched. When it exits, the final price of each quote is printed.

To run it on Windows, compile with g++ -std=c++17 practicethree.cpp -o practicethree and then start it with ./practicethree. The prices are random numbers for practice and are not real market data.
