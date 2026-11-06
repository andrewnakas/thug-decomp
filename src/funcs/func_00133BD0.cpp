typedef int qword __attribute__((mode(TI)));

extern "C" void func_001022D8(void* sub);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_00207DC0(void* cell);
extern "C" void func_00207F98(void* grid, void* box);
extern void* D_00388A70;

struct Box_00133BD0 {
    qword a;
    qword b;
};

static inline void CopyQ_00133BD0(qword* d, const qword* s)
{
    *d = *s;
}

struct Cell_00133BD0 {
    char pad[0x30];
    Cell_00133BD0() { func_00207DC0(this); }
};

struct Base_00133BD0 {
    char m0[0x30];
    Base_00133BD0() { func_001022D8(this); }
};

struct Grid_00133BD0 : Base_00133BD0 {
    Cell_00133BD0 m30[20][20];
    static void* operator new(unsigned int size, void* heap) { return func_0010A638(heap, size, 1, 0); }
};

struct C_00133BD0 {
    char pad[0x88];
    int m88;
    char pad8C[0x24];
    Box_00133BD0 mB0;
    char padD0[4];
    Grid_00133BD0* mD4;
    bool Setup(Box_00133BD0* box);
};

bool C_00133BD0::Setup(Box_00133BD0* box)
{
    if (!m88)
        return false;
    CopyQ_00133BD0(&mB0.a, &box->a);
    CopyQ_00133BD0(&mB0.b, &box->b);
    Grid_00133BD0* g = new (D_00388A70) Grid_00133BD0;
    mD4 = g;
    func_00207F98(g, &mB0);
    return true;
}
