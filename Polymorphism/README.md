Kamil Gumienny  

This project deals with polymorphism in the form of a predator-prey game. A simulation is played out between doodlebugs and ants where ants are programmed to go after doodlebugs whereas doodlebugs look to escape ants. 

FUNCTION HEADERS
-----------------------------------------------
/*
 * main first goes through the command line arguments and
 * changes the default parameters. A new board is then made
 * and every location is made Null. Then Ants and DoodleBugs are
 * placed thoughout the board randomly. Then, all the NULL spaces
 * are replaced with Organisms. The move vector is then created
 * and the play function is called.
 */
int main(int argc, char *argv[])

// if an instance of Doodlebug is on the board, an "x" is printed
void Doodlebug::print()

//function returns 2 when an instance of Doodlebug is on the board
int Doodlebug::type()

//returns a non 0 integer when a Doodlebug's timer is greater than 8
int Doodlebug::time_to_bread()

/*
 * first the moves are shuffled and an cell with an ant is located.
 * if the ant hasn't been eaten yet on the newBoard, the doodleBug
 * is out over the Ant's place on the newBoard.
 */
pair<int,int> Doodlebug::findAnt(Organism*** curBoard, Organism*** newBoard)

/*
 * First the function checks to see if there is an Ant that
 * can be eaten by the doodleBug. If there is, the function ends.
 * otherwise, the moves are shuffled so a random direction is chosen
 * and the location is checked on the new and old Boards and if there
 * it is available, the doodleBug will move there and its eat counter will
 * be incremented. The new location of the doodleBug is returned.
 */
pair<int,int> Doodlebug::move(Organism*** curBoard, Organism*** newBoard)

/*
 * first the move vector is shuffled and so a random
 * direction is selected. If an empty location is found,
 * a new doodleBug is put in on the board.
 */
void Doodlebug::breed(Organism*** curBoard, Organism*** newBoard)

/*
 * a constructor for a doodleBug from an existing
 * doodleBug.
 */
Organism* Doodlebug::getnew()

/*
 * If the eatCounter is greater than 3, an
 * Organism replaces the doodleBug on the new
 * Board, which is essentially an empty space.
 */
void Doodlebug::starvation(Organism*** newBoard)

//constuctor for an ant that takes in coordinates.
Ant::Ant(int X,int Y)

//For every instance of an ant, a "o" is printed.
void Ant::print()

//Used for checking what is in a cell
int Ant::type()

/*
 * function looks at the cells around the ant and finds an
 * empty cell. Once it finds an empty cell in both the new,
 * and old boards, it creates a new ant in the newBoard and
 * increments its times. Returns the x and y coordinates of
 * the new position.
 */
pair<int,int> Ant::move(Organism*** oldBoard, Organism*** newBoard)

/*
 * generates a new Ant
 */
Organism* Ant::getnew()

/*
 * returns an int specifying whether it's time to breed or not.
 */
int Ant::timeBreed()

/*
 * first the move vector is shuffled and so a random
 * direction is selected. If an empty location is found,
 * a new ant is put in on the board.
 */
void Ant::breed(Organism*** oldBoard, Organism*** newBoard)

/*
 * function looks at a coordinate and checks to see if it exists on
 * the board. returns 0 if false, 1 if true.
 */
int check(int x, int y)

/*
 * Goes through the entire board and calls the print
 * function of the organism in that location.
 */
void printStep(int gridsize, Organism*** a)

/*
 * The function first checks to see if it should be done. It then
 * generates a newBoard to be the same size as the oldBoard.
 * It then places an organism in each of the spaces on the board.
 * A loop then runs and assigns the organisms their coordinates
 * so organisms can track where they are on the board. A loop is ran
 * on the oldBoard that locates Doodlebugs and makes them move.
 * The same is then done for the Ants. A loop is then ran to check
 * whether a doodleBug is starving. Lastly all the cells are checked
 * to see if the organism is ready to breed and if it is, it breeds.
 * Finally, the board is printed, the oldBoard is freed, and the
 * function calls itself recursively.
 */
void play(int gridsize, Organism*** oldBoard, int time_steps, int count = 1)
-----------------------------------------------

VARIABLE DESCRIPTIONS
-----------------------------------------------
//aBoard is the game Board
Organism*** aBoard;
//vestor for all the possible moves
vector<pair<int, int> > moves;
//the default grid size, 20
int gridSize = 20;
// the default number of doodleBugs, 5
int doodlebugNum = 5;
//the default number of Ants, 100
int antNum = 100;
//the default number of turns, 1000
int turnNum = 1000;
//The seed is stored here.
int seed;
//the default pause is set to false.
int pause = 0;

-----------------------------------------------

TEST OUTPUTS
-----------------------------------------------

/PA6 5 2 5 10

.....
.....
.....
.....
....o

/PA6 6 5 20 5

oooo.o
.xo..o
oo.oxo
ooo.xx
.oxoo.
.oo..o

-----------------------------------------------

Worked with a friend, nadellicarpini, on the program although we did not register as partners.
Used resources such as cplusplus.com, stackoverflow, lecture notes, and absolute c++.
