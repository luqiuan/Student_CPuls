/*
 Snake Game, implemented in c++11 and OpenGL.
 How to play: g-Start game; e,s,d,f for direction control; q to quit.
 
 The most important rules for this game:
 1. Game over if go out of bound, or move into body of the snake;
 2. Lengthen snake body if it eat food;
 3. Move forward if nothing in front.
 
 @autor "Lan, Tian"<lantian_bupt@163.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GLUT/GLUT.h> // For linux & windows, please include <GL/glut.h>
#include <list>

using std::list;

const int TimerInterval = 400;

struct Position{
    int r, c; // row and column
    Position(int r=0, int c=0): r(r), c(c) {}
    bool operator==(const Position& other) const { return r==other.r && c==other.c; }
};

// Backend code of the game
class SnakeGame {
public:
    enum {MAX_ROW=10, MAX_COL=MAX_ROW};
    enum EnumDirection {Up, Down, Left, Right};
    enum EnumStatus {NotStarted, Started, GameOver};
    
    bool gameOver() const { return _status == GameOver; }
    bool notStarted() const { return _status == NotStarted; }
    void start() { _status = Started; }
    
    const list<Position>& getSnake() const { return _snake; }
    const Position& getFoodPos() const { return _foodPos; }
    
    SnakeGame(): _status(NotStarted), _currentDir(Right) {
        srand(time(NULL));
        generateFood();
        _snake.insert(_snake.begin(), {{0,2}, {0,1}, {0,0}});
    }
    void setDirection(EnumDirection dir) { _currentDir = dir; }
    bool move() {
        Position headPos = tryMove(_currentDir);
        if (outOfBound(headPos) || touchSelf(headPos)) {
            _status = GameOver;
        } else if (headPos == _foodPos) {
            _snake.push_front(headPos);
            generateFood();
        } else {
            _snake.push_front(headPos);
            _snake.pop_back();
        }
        return _status != GameOver;
    }
private:
    Position tryMove(EnumDirection dir) {
        Position headPos = _snake.front();
        if      (dir == Up)      headPos.r--;
        else if (dir == Down)    headPos.r++;
        else if (dir == Left)    headPos.c--;
        else  /*(dir == Right)*/ headPos.c++;
        return headPos;
    }
    bool outOfBound(const Position& headPos) {
        return headPos.r < 0 || headPos.r >= MAX_ROW ||
        headPos.c < 0 || headPos.c >= MAX_COL;
    }
    bool touchSelf(const Position& headPos) {
        for(const Position& pos: _snake)
            if (headPos == pos)
                return true;
        return false;
    }
    void generateFood() {
        do {
            _foodPos.r = rand() % MAX_ROW;
            _foodPos.c = rand() % MAX_COL;
        } while (touchSelf(_foodPos));
    }
private:
    list<Position> _snake;
    Position       _foodPos;
    EnumDirection  _currentDir;
    EnumStatus     _status;
} gSnakeGame;

//========= OpenGL for UI and interaction =========

void drawBlock(const Position& pos) {
    static const GLfloat BlockSize = 2.0f / SnakeGame::MAX_ROW;
    static const GLfloat Padding = BlockSize * 0.1f;
    GLfloat x = pos.c * BlockSize - 1.0f, y = 1.0f - pos.r * BlockSize;
    glRectf(x+Padding, y-Padding, x+BlockSize-Padding, y-BlockSize+Padding);
}

void display()  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Snake body
    glColor3f(0.9f, 0.9f, 0.9f);
    for(auto& pos: gSnakeGame.getSnake()) { drawBlock(pos); }
    // Snake head
    glColor3f(0.3f, 0.9f, 0.3f);
    drawBlock(gSnakeGame.getSnake().front());
    // Food
    glColor3f(1.0f, 0.2f, 0.2f);
    drawBlock(gSnakeGame.getFoodPos());
    
    glFlush();
}

void timer(int timerId) {
    if (timerId == 1) {
        if (gSnakeGame.move()) {
            display();
            glutTimerFunc(TimerInterval, timer, 1);
        } // if (gSnakeGame...
    } // if (timerId...
}

void keypress(unsigned char key, int x, int y) {
    if (key == 'q') { exit(0); } // Response to 'q' even after game over
    if (gSnakeGame.gameOver()) { return; }
    if (gSnakeGame.notStarted()) {
        if (key == 'g') { gSnakeGame.start(); glutTimerFunc(TimerInterval, timer, 1); }
    } else /*SnakeGame started*/ {
        if      (key == 'e') { gSnakeGame.setDirection(SnakeGame::Up); }
        else if (key == 'd') { gSnakeGame.setDirection(SnakeGame::Down); }
        else if (key == 's') { gSnakeGame.setDirection(SnakeGame::Left); }
        else if (key == 'f') { gSnakeGame.setDirection(SnakeGame::Right); }
    }
}

int main(int argc, char ** argv)  {
    printf("How to play:\n g-Start Game;\n e,s,d,f for direction control;\n q to quit.\n");
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("g-Start | e,d,s,f-Directions | q-Quit");
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    glutMainLoop();
    return 0;
}
