extern char D_0037AB38[];
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002CA650(void* p);
extern "C" void func_002CA540(void* p);
extern "C" void func_002C6B08(void* self);
extern "C" void func_002C8FA0(void* p, int b);
extern "C" void func_002C9DD0(void* p);
extern "C" void func_002C6B80(void* self);

struct Menu_002C6A40 {
    char pad0[0x7C];
    int m7C;
};

struct Obj_002C6A40 {
    char pad0[0xA0];
    Menu_002C6A40* mA0;
    void* mA4;
    char padA8[0x8];
    int mB0;
    void SetPaused(int v);
};

void Obj_002C6A40::SetPaused(int v)
{
    mB0 = v;
    if (mA4) {
        if (v) {
            func_001F0370(D_0037AB38, 0, 0, 0);
            func_002CA650(mA4);
        } else {
            func_002CA540(mA4);
            func_002C6B08(this);
        }
    }
    if (mA0) {
        bool b = mA0->m7C == 6;
        if (b || v) func_002C8FA0(mA0, 0);
        else func_002C8FA0(mA0, 1);
        func_002C9DD0(mA0);
    }
    func_002C6B80(this);
}
