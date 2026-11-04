struct Box_002BFA78 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Piece_002BFA78 {
    Box_002BFA78 box;
    char pad6[2];
    int m8;
};

struct Node_002BFA78 {
    char pad[0xC];
    Node_002BFA78* mC;
};

extern "C" void* func_002BC5A0(Node_002BFA78* n);
extern "C" Piece_002BFA78* func_002BAB80(void* p);

struct Grid_002BFA78 {
    char pad[0x80];
    Node_002BFA78* m80;
    bool Overlaps(Box_002BFA78* r);
};

bool Grid_002BFA78::Overlaps(Box_002BFA78* r)
{
    for (Node_002BFA78* n = m80; n; n = n->mC) {
        Piece_002BFA78* p = func_002BAB80(func_002BC5A0(n));
        Box_002BFA78 b = p->box;
        unsigned char rx = r->x;
        unsigned char bx = b.x;
        if (bx < rx) goto check;
        {
            unsigned char bz = b.z;
            unsigned char rz = r->z;
            if (bz < rz || bx + b.w > rx + r->w || bz + b.d > rz + r->d)
                goto check;
        }
        continue;
        check:
        {
            int f = p->m8;
            if ((f >> 3) & 1)
                continue;
            if ((f >> 8) & 1)
                continue;
            if (f & 4)
                return true;
        }
    }
    return false;
}
