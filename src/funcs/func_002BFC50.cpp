struct Rect_002BFC50 {
    unsigned char x;
    unsigned char m1;
    unsigned char y;
    unsigned char w;
    unsigned char m4;
    unsigned char h;
    unsigned char GetX() { return x; }
    unsigned char GetY() { return y; }
    unsigned char GetW() { return w; }
    unsigned char GetH() { return h; }
};

struct Cell_002BFC50 {
    int h;
    int m4;
    int m8;
    int mC;
};

struct Grid_002BFC50 {
    char pad[0x3538];
    Cell_002BFC50** rows;
    int MaxHeight(Rect_002BFC50* r, int* flat);
};

int Grid_002BFC50::MaxHeight(Rect_002BFC50* r, int* flat)
{
    int best = -10000;
    if (flat)
        *flat = 1;
    int ref = rows[r->GetX()][r->GetY()].h;
    for (int x = r->GetX(); x < r->GetX() + r->GetW(); x++) {
        for (int y = r->GetY(); y < r->GetY() + r->GetH(); y++) {
            if (flat && rows[x][y].h != ref)
                *flat = 0;
            int v = rows[x][y].h;
            if (best < v)
                best = v;
        }
    }
    return best;
}
