extern void* D_00388A70;
extern int D_00392824;
extern char D_0037AE48[];
extern "C" void func_002BE958(void* self, void* p, int f);
extern "C" void func_002C7318(void* self);
extern "C" void func_002BA9E0();
extern "C" void func_0010A8D8(void* pool, void* p);

struct Piece_002C7288 {
    char pad0[0x8];
    int m8;
};

struct Obj_002C7288 {
    char pad0[0x8];
    void* m8;
    void* mC;
    char pad10[0x40];
    Piece_002C7288* m50;
    void Destroy(int flags);
};

void Obj_002C7288::Destroy(int flags)
{
    if (m50) {
        m50->m8 &= ~0x200;
        func_002BE958(m8, m50, 0);
    }
    func_002C7318(this);
    D_00392824 = 0;
    mC = D_0037AE48;
    func_002BA9E0();
    if (flags & 1) func_0010A8D8(D_00388A70, this);
}
