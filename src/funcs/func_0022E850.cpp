extern void* D_00392068;

extern "C" void func_0022E0F8(void* self);
extern "C" void func_00211D68(int a, int b);
extern "C" void* func_0022E048(void* self);
extern "C" void func_00266370(void* p);
extern "C" void* func_00240850();
extern "C" bool func_002A19A8(void* net);
extern "C" void func_0023C4F8(void* game);
extern "C" void func_0023E2D8(void* game);
extern "C" void func_0023C588(void* game);
extern "C" void func_0023FFF8(void* game);

struct Mgr_0022E850 {
    char pad0[0x68];
    int m_68;

    void Reset();
};

void Mgr_0022E850::Reset()
{
    void* net = D_00392068;
    func_0022E0F8(this);
    func_00211D68(0, 0);
    m_68 = 0;
    func_00266370(func_0022E048(this));
    void* game = func_00240850();
    if (func_002A19A8(net)) {
        func_0023C4F8(game);
        func_0023E2D8(game);
    } else {
        func_0023C588(game);
    }
    func_0023FFF8(game);
}
