struct Obj_001BE3C8;
extern void* D_0038C608;
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void func_001BEBE8(Obj_001BE3C8* o, void* obj);

struct Obj_001BE3C8 {
    void Method(void* params);
};

void Obj_001BE3C8::Method(void* params)
{
    unsigned int id;
    if (func_001E8398(params, 0xC4E311FA, &id, 0))
        func_001BEBE8(this, func_00187B48(D_0038C608, id));
}
