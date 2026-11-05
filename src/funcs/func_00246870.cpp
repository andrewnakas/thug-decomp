extern "C" void* func_0022DD38(void* mgr);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern void* D_0038FC78;

struct Obj_00246870 {
    char pad[0x20];
    void* m20;
    void Fn();
};

void Obj_00246870::Fn()
{
    char* o = (char*)func_00185578(func_0022DD38(D_0038FC78), 0x43686585);
    func_001E7200(m20, 0xC07D8D60, (int)*(float*)(o + 0x184));
}
