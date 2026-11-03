struct Node_002BF948 {
    char pad[0xC];
    Node_002BF948* mC;
};

struct Rect_002BF948 {
    unsigned char x;
    unsigned char m1;
    unsigned char y;
    unsigned char w;
    unsigned char m4;
    unsigned char h;
};

struct Grid_002BF948 {
    char pad[0x98];
    Node_002BF948* cells[1][58];
    int Count(Rect_002BF948* r);
};

extern "C" void* func_002BC5A0(Node_002BF948* n);
extern "C" void func_002C24E0(Grid_002BF948* g, void* p, int* count);

int Grid_002BF948::Count(Rect_002BF948* r)
{
    int count = 0;
    int xe = r->x + r->w;
    for (int x = r->x; x < xe; x++) {
        int ye = r->y + r->h;
        for (int y = r->y; y < ye; y++) {
            for (Node_002BF948* n = cells[x][y]; n; n = n->mC)
                func_002C24E0(this, func_002BC5A0(n), &count);
        }
    }
    return count;
}
