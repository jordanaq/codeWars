#include <iostream>

#include <vector>

// getPos needed in struct definition
int getPos(std::vector<std::vector<int>> &, int, int);



struct neighbors {
    // flags: diagonalNeighbor, neighborUp, neighborDown, neighborLeft, neighborRight
    int flags : 5;

    // Constructors, one empty constructor and one based on a vector and coords
    // neighbors is trivial copy constructable
    neighbors() =default;
    neighbors(const neighbors & o) =default;
    neighbors(std::vector<std::vector<int>> &field, int x, int y) : flags {
                    // Cardinal positions
        /*up:*/     (getPos(field, x, y-1)<<3) +
        /*down:*/   (getPos(field, x, y+1)<<2) +
        /*left:*/   (getPos(field, x-1, y)<<1) +
        /*right:*/  (getPos(field, x+1, y)<<0) +

                    // Diagonal positions. All have the same effect and share a flag
        /*topL:*/   ((getPos(field, x-1, y-1)|
        /*topR:*/     getPos(field, x+1, y-1)|
        /*botL:*/     getPos(field, x-1, y+1)|
        /*botR:*/     getPos(field, x+1, y+1))<<4)
        } { }


    // Checks if two neighbors' flags are equal or if they are in a straight line
    bool operator==(const neighbors &o) const {
        return flags == o.flags || (flags == 0b1100 && o.flags == 0b0100) || (flags == 0b0011 && o.flags == 0b0001);
    }

    // Explicitly declared as it is required
    bool operator!=(const neighbors &o) const { return !(*this==o); };

    // To be used in if statements
    // Returns true when there are no diagonal neighbors
    explicit operator bool() const { return flags != 0b10000; }

};



// returns the value in field[y][x] or 0 if out of range
// std::optional<int> is a potential replacement with better code but is slightly less performant
int getPos(std::vector<std::vector<int>> &field, int x, int y) {
    try {
        return field.at(y).at(x);
    } catch (...) {
        return 0;
    }
}



// Pure recursive function. Returns the length of a ship
__attribute((pure)) char shipLen (std::vector<std::vector<int>> &field, int x, int y) {//}), neighbors prev) {
    // If the function reached the end of the board or a empty space
    if (y < 0 || y > field.size() || x < 0 || x > field[y].size() || !field[y][x]) return 0;

    // Generate flags for current position
    neighbors curr{ field, x, y };


    switch (curr.flags) {
        // Diagonal or edge case
        default:
            return INT8_MIN;

        // case when current position is the end of a ship
        case 0: case 0b1000: case 0b0010:
            return 1;

        // case when current position is an up/down ship
        case 0b0100: case 0b1100:
            return 1 + shipLen(field, x, y+1);//), curr);

        // case when current position is a left/right ship
        case 0b0001: case 0b0011:
            return 1 + shipLen(field, x+1, y);//, curr);
    }
}



// Determines if field is a legal battlefield board
bool validate_battlefield(std::vector< std::vector<int> > field) {
    // Empty char array to hold the count of the four possible ship lengths
    char ships[] { 0, 0, 0, 0 };

    // Two for loops iterate over every possible x and y value combination
    for (int y = 0; y < field.size(); y++) {
        for (int x = 0; x < field[y].size(); x++) {

            // Checks if current position is a 1
            if(field[y][x]) {

                // Creates a neighbors struct and checks for diagonal neighbor
                if (neighbors curr { field, x, y }; (bool) curr) {

                    // Checks if the current position has already been processed
                    if (auto f = curr.flags; f==0b1000 || f==0b0010 || f==0b1100 || f==0b0011) continue;

                    // Increments ships[len-1] when len=(0,4] with early return
                    else if (auto len = shipLen(field, x, y); len <= 0 || len > 4) return false;
                    else ships[len-1]++;

                // returns false if a diagonal neighbor exists
                } else return false;
            }
        }
    }

    // Returns true only if it hasn't returned by this point and if all ships exist
    return ships[0]==4 && ships[1]==3 && ships[2]==2 && ships[3]==1;
}


// Test case
int main() {
    std::cout <<
        validate_battlefield(std::vector< std::vector<int> > {
            std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            std::vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            std::vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            std::vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            std::vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            std::vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}         }) << std::endl;
}