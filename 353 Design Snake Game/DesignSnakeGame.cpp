class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->food=food;
        head=make_pair(0,0);
        w=width;
        h=height;
        q.push(head);
        m.insert(head);
        index=0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int x=head.first;
        int y=head.second;
        if (direction=="R") y++;
        else if (direction=="L") y--;
        else if (direction=="U") x--;
        else if (direction=="D") x++;
        else return -1;
        if (x<0 || x>=h || y<0 || y>=w) return -1;
        if (make_pair(x,y)==food[index]) index++;
        else {
            m.erase(q.front());
            q.pop();
            if (m.find(make_pair(x,y))!=m.end()) return -1;
        }
        head=make_pair(x,y);
        q.push(head);
        m.insert(head);
        return q.size()-1;
    }
private:
    vector<pair<int,int> > food;
    int w,h;
    queue<pair<int,int> > q;
    pair<int,int> head;
    set<pair<int,int> > m;
    int index;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */