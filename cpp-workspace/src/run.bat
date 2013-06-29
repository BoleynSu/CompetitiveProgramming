:loop
@g++ main.cpp -o core -DDEBUG
@g++ 1.cpp -o 1
@g++ 2.cpp -o 2
@core game.cfg 1 2 json.txt
pause
@goto loop