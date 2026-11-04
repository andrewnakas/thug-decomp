extern void* D_0038C608;

struct Obj_00217DB8 {
    char pad[0x14];
    Obj_00217DB8* m_next;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Obj_00217DB8* func_00187278(void* mgr, unsigned int type);
extern "C" void func_001BBC90(Obj_00217DB8* obj, unsigned int anim, bool loop, float speed);

bool Cmd_00217DB8(void* params, void* script)
{
    unsigned int anim = 0;
    func_001E8398(params, 0, &anim, 0);
    if (!anim)
        return true;
    float speed = 1.0f;
    func_001E7EB0(params, 0x906B67BA, &speed, 0);
    int loop = 0;
    func_001E7DE8(params, 0x1A4E0EF9, &loop, 0);
    for (Obj_00217DB8* obj = func_00187278(D_0038C608, 0x27D7CD28); obj; obj = obj->m_next)
        func_001BBC90(obj, anim, loop != 0, speed);
    return true;
}
