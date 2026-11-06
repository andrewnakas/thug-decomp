extern void* D_0038C7B0;
extern void* D_00389A30;

class Obj_0018A560 {
public:
    char pad0[0x8];
    virtual void V0();
    virtual void V1(void* script);
};

extern "C" unsigned int func_0012E438(void* p, void* script, unsigned int name);
extern "C" Obj_0018A560* func_001895B0(void* mgr, unsigned int key);

bool func_0018A560(void* script)
{
    func_001895B0(D_0038C7B0, func_0012E438(D_00389A30, script, 0x40C698AF))->V1(script);
    return true;
}
