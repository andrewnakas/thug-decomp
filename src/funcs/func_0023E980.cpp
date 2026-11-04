struct Goal_0023E980 {
    char m_pad[0x30];
    int* m30;
};

struct Mgr_0023E980 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023C040(Mgr_0023E980* self);
extern "C" Goal_0023E980* func_00243C18(void* table, int* key, int* out);
extern "C" void func_00247D00(Goal_0023E980* goal);
extern "C" void func_00246D18(Goal_0023E980* goal, const char** out);
extern "C" bool func_00246C60(Goal_0023E980* goal);
extern "C" bool func_00246740(Goal_0023E980* goal);
extern "C" void func_002A9C08(int a, int b);
extern "C" bool func_002463A0(Goal_0023E980* goal);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned int func_00246258(Goal_0023E980* goal);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E70C0(void* params, unsigned int name, const char* value);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);

void func_0023E980(Mgr_0023E980* self, int flag)
{
    for (int i = 0; i < func_0023C040(self); i++) {
        int out;
        Goal_0023E980* goal = func_00243C18(self->m_table, &i, &out);
        const char* text = 0;
        func_00247D00(goal);
        func_00246D18(goal, &text);
        if (text && !func_00246C60(goal) && !func_00246740(goal) && !*goal->m30) {
            func_002A9C08(0, 0);
            if (!flag || func_002463A0(goal)) {
                void* p = func_001E6978(func_001190D0(8));
                func_001E7360(p, 0x9982E501, func_00246258(goal));
                func_001E7360(p, 0xC2719FB0, 0x4D49AC0A);
                func_001E70C0(p, 0xC4745838, text);
                func_001E7360(p, 0x2F6BF72D, 0x8ABA15EC);
                func_001E7200(p, 0x13B9DA7B, 0);
                if (flag) {
                    func_001F0210(0xE704C86C, p, 0, 0, 0);
                } else {
                    func_001F0210(0x6790AC11, p, 0, 0, 0);
                }
                if (p) {
                    func_001E6AE8(p, 3);
                }
            }
        }
    }
}
