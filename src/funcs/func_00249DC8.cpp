struct Obj_00249DC8;
struct Target_00249DC8 {
    int m0;
    int m4;
    virtual void Va(int a);
};

extern void* D_0038C608;
extern "C" void* func_00249FE0(Obj_00249DC8* self);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Target_00249DC8* func_00187B48(void* mgr, unsigned int id);

struct Obj_00249DC8 {
    void Fn();
};

void Obj_00249DC8::Fn()
{
    void* p = func_00249FE0(this);
    unsigned int id = 0;
    func_001E8398(p, 0x02D7E03D, &id, 0);
    if (id) {
        Target_00249DC8* t = func_00187B48(D_0038C608, id);
        if (t) t->Va(3);
    }
}
