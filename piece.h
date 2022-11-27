class piece{
        bool filled;
        char c;
        size_t x;
        size_t y;
    public:
        piece(size_t x, size_t y, char c, bool filled);
        bool getFiled();
        void setFilled();
        char getC();
        void getC();
        size_t getX();
        size_t getY();
};