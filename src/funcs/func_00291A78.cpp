extern "C" int func_0010FC30();

struct Flag_00291A78 {
    int m0;
    bool m4;
    int m8;
    void Set(bool b)
    {
        if (m4 != b) {
            m4 = b;
            m8 = func_0010FC30();
        }
    }
};

struct Comp_00291A78 {
    char pad0[0x30];
    Flag_00291A78 m30;
};

extern "C" Comp_00291A78* func_00185578(void* obj, unsigned int name);

struct Obj_00291A78 {
    char pad0[0xC];
    void* mC;
    void Toggle();
};

extern "C" void func_00291AD8(Obj_00291A78* o);

void Obj_00291A78::Toggle()
{
    Flag_00291A78* f = &func_00185578(mC, 0x43686585)->m30;
    f->Set(!f->m4);
    func_00291AD8(this);
}
