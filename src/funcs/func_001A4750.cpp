extern void* D_0038C6D4;
extern void* D_0038FC78;
extern void* D_0038C608;
extern "C" int func_0022DD38(void* p);
extern "C" void* func_00187B48(void* mgr, unsigned int id);

struct Obj_001A4750 {
    char pad0[0x1C];
    unsigned int m1C;
    void* m20;
    void Fn();
};

extern "C" int func_00184D70(void* owner, Obj_001A4750* self);

void Obj_001A4750::Fn()
{
    if (m20 != D_0038C6D4)
        func_00184D70(m20, this);
    else {
        unsigned int key = m1C;
        if (key == 0x5B8AB877)
            func_0022DD38(D_0038FC78);
        else
            func_00187B48(D_0038C608, key);
    }
}
