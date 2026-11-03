struct Color_00214DA0 {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    Color_00214DA0() {}
    Color_00214DA0(const Color_00214DA0& o) { *this = o; }
};

struct Skater_00214DA0 {
    char pad[0x320];
    int m_id;
};

struct Script_00214DA0 {
    char pad[0xBC];
    Skater_00214DA0* m_skater;
};

extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_00143690(int id, Color_00214DA0 c1, Color_00214DA0 c2, int flags, float duration,
                              float scale, const char* text);

extern char D_003709A8[];
extern char D_0038F5A0[];
extern char D_0038F420[];
extern char D_0038F5A8[];
extern char D_0038F5B0[];
extern char D_0038F5B8[];
extern char D_0038F5C0[];
extern char D_0038F5C8[];
extern char D_0038F5D0[];
extern char D_0038F5D8[];
extern char D_0038F5E0[];
extern char D_0038F5E8[];

bool Cmd_00214DA0(void* params, Script_00214DA0* script)
{
    Color_00214DA0 c1;
    Color_00214DA0 c2;
    float duration;
    const char* text;
    float scale;
    int id;
    int value;

    id = -1;
    duration = 0.0f;
    scale = 0.0f;
    text = 0;
    func_001E7F50(params, D_003709A8, &duration, 0);
    if (duration > 0.0f) {
        func_001E8890(params, D_0038F5A0, &text, 0);
        func_001E7F50(params, D_0038F420, &scale, 0);
        int flags = func_001E8708(params, 0x70FFC649) != 0;
        if (func_001E8708(params, 0x19C43CF6)) {
            flags |= 2;
        } else if (func_001E8708(params, 0x387C9ED6)) {
            flags |= 4;
        }
        func_001E7E58(params, D_0038F5A8, &id, 0);
        if (id == -1) {
            id = script->m_skater->m_id;
        }
        if (func_001E8708(params, 0xDF6436D2)) {
            flags |= 8;
        }
        value = 0;
        func_001E7E58(params, D_0038F5B0, &value, 0);
        c1.r = value;
        func_001E7E58(params, D_0038F5B8, &value, 0);
        c1.g = value;
        func_001E7E58(params, D_0038F5C0, &value, 0);
        c1.b = value;
        func_001E7E58(params, D_0038F5C8, &value, 0);
        c1.a = value;
        func_001E7E58(params, D_0038F5D0, &value, 0);
        c2.r = value;
        func_001E7E58(params, D_0038F5D8, &value, 0);
        c2.g = value;
        func_001E7E58(params, D_0038F5E0, &value, 0);
        c2.b = value;
        func_001E7E58(params, D_0038F5E8, &value, 0);
        c2.a = value;
        func_00143690(id, c1, c2, flags, duration, scale, text);
    }
    return true;
}
