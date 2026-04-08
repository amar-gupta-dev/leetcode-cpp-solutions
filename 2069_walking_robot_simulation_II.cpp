// Leetcode 2069
// Problem: walking robot simulation II
// Topic: design, simulation, senior
// Diff: medium

class Robot {
private:
        int width, height;
        int x, y;
        int dir; // 0 = East, 1 = North, 2 = West, 3 = South
        vector<string> directions = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        dir = 0; // initially facing 
    }
    
    void step(int num) {
        int perimeter = 2*(width + height) - 4;
        num %= perimeter;

        while(num > 0)  {
            if(dir == 0) {
                // east
                int move = min(num, width - 1 - x);
                x += move;
                num -= move;
                if(num > 0) dir = 1;
            }
            else if (dir == 1) {
                // north
                int move = min(num, height - 1 - y);
                y += move;
                num -= move;
                if(num > 0) dir = 2;
            }
            else if (dir == 2) {
                // west
                int move = min(num, x);
                x -= move;
                num -= move;
                if(num > 0) dir = 3;
            }
            else {
                // south
                int move = min(num, y);
                y -= move;
                num -= move;
                if(num > 0) dir = 0;
            }
        }
        // special case: if we end at (0,0) after full cycle
         if(x == 0 && y == 0 && num == 0) {
                    dir = 3; // south
         }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return directions[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
