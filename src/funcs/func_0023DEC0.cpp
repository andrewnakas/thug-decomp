extern "C" int func_0023C040(void* self);
extern "C" void* func_00243C18(void* list, int* idx, int* out);
extern "C" int func_00246C38(void* o);
extern "C" int func_002458B8(void* o);
extern "C" void func_002458C0(void* o);

struct Obj_0023DEC0 {
    int m0;
    char m_4[0x3C];
    int m_40;
    void Run();
};

void Obj_0023DEC0::Run()
{
    m_40 = 1;
    for (int i = 0; i < func_0023C040(this); i++) {
        int tmp;
        void* o = func_00243C18(m_4, &i, &tmp);
        if (func_00246C38(o) && func_002458B8(o)) {
            func_002458C0(o);
        }
    }
}
