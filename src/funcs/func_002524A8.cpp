extern unsigned int D_00354DC0[];
extern "C" bool func_001E8708(void* params, unsigned int name);

struct Obj_002524A8 {
    char pad[0x438];
    unsigned int m438;
    bool Fn(void* params);
};

bool Obj_002524A8::Fn(void* params)
{
    for (int i = 0; D_00354DC0[i]; i++) {
        if (func_001E8708(params, D_00354DC0[i])) return m438 == D_00354DC0[i];
    }
    return false;
}
