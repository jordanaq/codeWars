#include <iostream>

#include <vector>
#include <array>

struct neighbors {
    // UpLeft,
    int flags : 6;

    bool operator==(const neighbors o) const {
        return flags == o.flags || (flags == 0b1100 && o.flags == 0b0100) || (flags == 0b0011 && o.flags == 0b0001);
    }

    /*bool validNeighbors() const {
        return (flags == 0     ) ||
               (flags == 0b1000) ||
               (flags == 0b0100) ||
               (flags == 0b0010) ||
               (flags == 0b0001) ||
               (flags == 0b1100) ||
               (flags == 0b0011);
    }*/

    explicit operator bool() const { return (flags == 0     ) ||
                                            (flags == 0b1000) ||
                                            (flags == 0b0100) ||
                                            (flags == 0b0010) ||
                                            (flags == 0b0001) ||
                                            (flags == 0b1100) ||
                                            (flags == 0b0011);      }
};

int getPos(std::vector<std::vector<int>> &field, int x, int y) {
    try {
        return field.at(y).at(x);
    } catch (...) {
        return 0;
    }
}

neighbors getNeighbors(std::vector<std::vector<int>> &field, int x, int y) {
    return {
                // Cardinals
    /*up:*/     (getPos(field, x, y-1)<<3) +
    /*down:*/   (getPos(field, x, y+1)<<2) +
    /*left:*/   (getPos(field, x-1, y)<<1) +
    /*right:*/  (getPos(field, x+1, y)<<0) +

                // Diagonals
    /*topL:*/   ((getPos(field, x-1, y-1)|
    /*topR:*/     getPos(field, x+1, y-1)|
    /*botL:*/     getPos(field, x-1, y+1)|
    /*botR:*/     getPos(field, x+1, y+1))<<4)
    };
}


int validShip (std::vector<std::vector<int>> &field, int x, int y){//}), neighbors prev) {
    if (y < 0 || y > field.size() || x < 0 || x > field[y].size() || !field[y][x]) return 0;

    neighbors curr = getNeighbors(field, x, y);
    //if (curr == (neighbors){ 0 }) return 1;

    switch (curr.flags) {
        default:

        case 0b10000:
            return INT32_MIN;
        case 0: case 0b1000:
            return 1;
        case 0b0100: case 0b1100:
            return 1 + validShip(field, x, y+1);//), curr);
        case 0b0010:
            return 1;
        case 0b0001: case 0b0011:
            return 1 + validShip(field, x+1, y);//, curr);
    }
}



bool validate_battlefield(std::vector< std::vector<int> > field) {
    std::vector<char> ships { 0, 0, 0, 0 };

    auto curr = getNeighbors(field, -1, -1);
    for (int y = 0; y < field.size(); y++) {
        for (int x = 0; x < field[y].size(); x++) {

            if(field[y][x]) {
                if ((bool) (curr = getNeighbors(field, x, y))) {
                    std::cout << '(' << x << ',' << -y << ')' << "\tf: " << curr.flags << "\tl: " << validShip(field, x, y)<<std::endl;//, {~0}) << std::endl;
                    if (auto f = curr.flags; f==0b1000 || f==0b0010 || f==0b1100 || f==0b0011) continue;
                    else if (auto len = validShip(field, x, y); f == 0 || (len <= 4 && len > 0)) {
                        if ((++ships[len - 1]) > (5 - len)) return false;
                    }
                } else return false;
            }
        }
    }

    std::cout << ships[0] << " " << ships[1] << " " << ships[2] << " " << ships[3] << std::endl ;
    return ships[0]==4 && ships[1]==3 && ships[2]==2 && ships[3]==1;
}

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