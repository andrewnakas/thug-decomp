typedef int qword_00221200 __attribute__((mode(TI)));

struct Vec_00221200 {
    union {
        qword_00221200 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Obj_00221200 {
    char pad0[0x50];
    Vec_00221200 m_pos;
};

struct Script_00221200 {
    char pad0[0x18];
    void* m_params;
    char pad1C[0xA0];
    Obj_00221200* m_obj;
};

extern char D_0038F8C8[];
extern char D_0038F8D0[];
extern char D_0038F8D8[];

extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_00221200(void* params, Script_00221200* script)
{
    Obj_00221200* o = script->m_obj;
    if (o) {
        Vec_00221200 p = o->m_pos;
        float x = p.f.x;
        float y = p.f.y;
        float z = p.f.z;
        func_001E7268(script->m_params, D_0038F8C8, (int)x);
        func_001E7268(script->m_params, D_0038F8D0, (int)y);
        func_001E7268(script->m_params, D_0038F8D8, (int)z);
        return true;
    }
    return false;
}
