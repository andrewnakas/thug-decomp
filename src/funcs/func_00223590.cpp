struct Script_00223590 {
    char pad[0x18];
    void* m_params;
};

struct Array_00223590 {
    char pad[0xC];
    unsigned int m_size;
};

struct Comp_00223590 {
    unsigned char pad0;
    unsigned char m_type;
    unsigned short pad2;
    unsigned int m_name;
    union {
        int i;
        float f;
    } m_val;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" bool func_001E8180(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int key, float* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int key, Array_00223590** out, int required);
extern "C" Comp_00223590* func_001E6E90(void* params, Comp_00223590* prev);
extern "C" unsigned int func_001E9300(Array_00223590* a, unsigned int i);
extern "C" bool func_002234A8(Array_00223590* a, unsigned int key);
extern "C" float func_00223530(float a);
extern "C" void func_001E7200(void* params, unsigned int key, int value);
extern "C" void func_001E72B0(void* params, unsigned int key, float value);
extern "C" void func_001E78A8(void* params, unsigned int key, void* value);

bool func_00223590(void* params, Script_00223590* script)
{
    void* out = func_001E6978(func_001190D0(8));
    void* from = 0;
    func_001E8180(params, 0x174841BC, &from, 1);
    void* to = 0;
    func_001E8180(params, 0x8E411006, &to, 1);
    float t = 0.0f;
    func_001E7EB0(params, 0x404E690D, &t, 0);
    Array_00223590* ignore = 0;
    func_001E8248(params, 0xF277291D, &ignore, 0);
    Array_00223590* angles = 0;
    func_001E8248(params, 0x9D2D0915, &angles, 0);

    Comp_00223590* c = func_001E6E90(from, 0);
    while (c) {
        bool found = false;
        if (ignore) {
            for (unsigned int i = 0; i < ignore->m_size; i++) {
                if (c->m_name == func_001E9300(ignore, i)) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            unsigned int name = 0;
            float start = 0.0f;
            bool isInt = true;
            if (c->m_type == 1) {
                start = (float)c->m_val.i;
                name = c->m_name;
            } else if (c->m_type == 2) {
                name = c->m_name;
                isInt = false;
                start = c->m_val.f;
            }
            if (name) {
                bool got = false;
                float target = 0.0f;
                int iv = 0;
                if (func_001E7DE8(to, name, &iv, 0)) {
                    got = true;
                    target = (float)iv;
                } else if (func_001E7EB0(to, name, &target, 0)) {
                    got = true;
                    isInt = false;
                }
                if (got) {
                    float r;
                    if (func_002234A8(angles, name)) {
                        float d = func_00223530(target - start);
                        if (d > 180.0f)
                            d -= 360.0f;
                        r = func_00223530(start + t * d);
                    } else {
                        r = start + t * (target - start);
                    }
                    if (isInt)
                        func_001E7200(out, name, (int)r);
                    else
                        func_001E72B0(out, name, r);
                }
            }
        }
        c = func_001E6E90(params, c);
    }
    func_001E78A8(script->m_params, 0xFF6F3872, out);
    return true;
}
