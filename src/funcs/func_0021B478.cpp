struct Array_0021B478 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

struct Game_0021B478 {
    char pad[0x24];
    void* m_goals;
};

struct Script_0021B478 {
    char pad[0x18];
    void* m_params;
};

extern Game_0021B478* D_0038FC78;
extern char D_0038F7D0[];
extern char D_003714E8[];
extern char D_00371500[];

extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00263AD8(void* goals);
extern "C" int func_00263B58(void* goals);
extern "C" Array_0021B478* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(Array_0021B478* arr, unsigned int i);
extern "C" bool func_001E8708(void* s, unsigned int name);
extern "C" bool func_001E7DE8(void* s, unsigned int name, int* out, int required);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, const char* value);

bool Cmd_0021B478(void* params, Script_0021B478* script)
{
    char buf[0x70];
    void* goals = D_0038FC78->m_goals;
    func_003331D0(buf, D_0038F7D0);
    int have_goals = func_00263AD8(goals);
    int have_medals = func_00263B58(goals);
    Array_0021B478* levels = func_001E55B8(0x1D8F1A7E, 0);
    for (unsigned int i = 0; i < levels->m_size; i++) {
        void* level = func_001E9378(levels, i);
        int need_goals = 0;
        int need_medals = 0;
        if (func_001E8708(level, 0x38DBE1D0) || func_001E8708(level, 0x032314D1)) {
            func_001E7DE8(level, 0, &need_goals, 0);
        }
        if (func_001E8708(level, 0x56907F8B) || func_001E8708(level, 0x23BBA846)) {
            func_001E7DE8(level, 0, &need_medals, 0);
        }
        if (have_goals < need_goals) {
            func_003331D0(buf, D_003714E8, need_goals - have_goals);
            break;
        }
        if (have_medals < need_medals) {
            func_003331D0(buf, D_00371500, need_medals - have_medals);
            break;
        }
    }
    func_001E7A30(script->m_params, 0xAF2305A6, 3, buf);
    return true;
}
