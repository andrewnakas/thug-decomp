struct Rect_002C2618 {
    unsigned char x;
    unsigned char m1;
    unsigned char y;
    unsigned char w;
    unsigned char m4;
    unsigned char h;
};

struct Node_002C2618 {
    int m0;
    int m4;
    Rect_002C2618* m8;
    Node_002C2618* mC;
};

extern void* D_00388A70;
extern "C" int func_002B74E0(void* p);
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" Node_002C2618* func_002C48E0(int size);

struct Grid_002C2618 {
    void* m0;
    char pad[0x94];
    Node_002C2618* cells[1][58];
    void Insert(Rect_002C2618* r);
};

void Grid_002C2618::Insert(Rect_002C2618* r)
{
    for (int i = 0; i < r->w; i++) {
        for (int j = 0; j < r->h; j++) {
            void* heap = D_00388A70;
            func_0010A950(heap, func_002B74E0(m0));
            Node_002C2618* n = func_002C48E0(0x10);
            func_0010A9B0(D_00388A70);
            n->m8 = r;
            n->mC = cells[i + r->x][j + r->y];
            cells[i + r->x][j + r->y] = n;
        }
    }
}
