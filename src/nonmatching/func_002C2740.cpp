/* fuzzy: 88.0 */
struct Obj_002C2740 {
    unsigned char x;
    unsigned char m1;
    unsigned char y;
    unsigned char w;
    unsigned char m4;
    unsigned char h;
};

struct Node_002C2740 {
    int m0;
    int m4;
    Obj_002C2740* m8;
    Node_002C2740* mC;
};

extern "C" void func_002C44D0(Node_002C2740* n);

struct Grid_002C2740 {
    char pad[0x98];
    Node_002C2740* cells[1][58];
    void Remove(Obj_002C2740* o);
};

void Grid_002C2740::Remove(Obj_002C2740* o)
{
    for (int i = 0; i < o->w; i++) {
        for (int j = 0; j < o->h; j++) {
            Node_002C2740* prev = 0;
            Node_002C2740* n = cells[i + o->x][j + o->y];
            if (n) {
            top:
                if (n->m8 == o) {
                    if (prev)
                        prev->mC = n->mC;
                    else
                        cells[i + o->x][j + o->y] = n->mC;
                    func_002C44D0(n);
                    continue;
                }
                prev = n;
                n = n->mC;
                if (n)
                    goto top;
            }
        }
    }
}
