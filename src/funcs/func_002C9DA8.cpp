struct Obj_002C9DA8;
extern "C" void func_002C9DD0(Obj_002C9DA8* o);

struct Obj_002C9DA8 {
    char pad0[0x7C];
    int m7C;
    void SetMode(int m);
};

void Obj_002C9DA8::SetMode(int m)
{
    if (m7C != m) {
        m7C = m;
        func_002C9DD0(this);
    }
}
