typedef int qword_00211B10 __attribute__((mode(TI)));

struct Vec_00211B10 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_00211B10 q;
    };
    Vec_00211B10() {}
    Vec_00211B10(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};


struct Obj_00211B10 {
    char m_pad[0xB0];
    Vec_00211B10 m_color;
};

struct Script_00211B10 {
    char m_pad[0xBC];
    Obj_00211B10* m_obj;
};

extern char D_0038F408[];
extern char D_0038F478[];
extern char D_0038F480[];
extern char D_0038F488[];
extern char D_0038F490[];
extern char D_00370520[];
extern char D_0038F498[];
extern char D_0038F4A0[];
extern char D_0038F4A8[];
extern char D_00370530[];
extern void* D_0038FC78;

extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" bool func_001E8938(void* params, const char* name, float* out, int required);
extern "C" int func_0022EF38(void* p);
extern "C" void func_00143EA0(Vec_00211B10* color, float a, float b, float c, float d, float e, float f);
extern "C" bool func_002118A8(void* params, void* script, int mode);

bool ScriptCmd_00211B10(void* params, Script_00211B10* script)
{
    Vec_00211B10 color;
    float scale = 1.0f;
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    float d = 0.0f;
    float e = 0.0f;
    float f = 0.0f;
    if (func_001E8708(params, 0x9F98989E)) {
        func_001E7F50(params, D_0038F408, &scale, 0);
        Obj_00211B10* o = script->m_obj;
        color.q = Vec_00211B10(o->m_color.x * scale, o->m_color.y * scale, o->m_color.z * scale, o->m_color.w * scale).q;
    } else {
        func_001E8938(params, D_0038F478, &color.x, 1);
        func_001E8938(params, D_0038F480, &color.y, 1);
        func_001E8938(params, D_0038F488, &color.z, 1);
        color.w = 0.0f;
    }
    func_001E7F50(params, D_0038F490, &a, 0);
    func_001E7F50(params, D_00370520, &b, 0);
    func_001E7F50(params, D_0038F498, &c, 0);
    func_001E7F50(params, D_0038F4A0, &d, 0);
    func_001E7F50(params, D_0038F4A8, &e, 0);
    func_001E7F50(params, D_00370530, &f, 0);
    float minDist = 2000.0f;
    if (func_0022EF38(D_0038FC78)) {
        minDist = 5000.0f;
    }
    if (a < minDist) {
        a = minDist;
    }
    func_00143EA0(&color, a, b, c, d, e, f);
    return func_002118A8(params, script, 4);
}
