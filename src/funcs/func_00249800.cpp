extern void* D_0038FC78;
extern void* D_0038C608;
extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void func_001F0E98(void* obj, unsigned int name);
extern "C" void func_001DEF68(unsigned int p);

struct Obj_00249800 {
    char pad[0xC];
    unsigned int mC;
    unsigned int m10;
    void Fn();
};

void Obj_00249800::Fn()
{
    if (m10) {
        if (mC) {
            void* o;
            if (mC == 0x5B8AB877) o = func_0022DD38(D_0038FC78);
            else o = func_00187B48(D_0038C608, mC);
            func_001F0E98(o, 0x5376A011);
        }
        func_001DEF68(m10);
        m10 = 0;
    }
}
