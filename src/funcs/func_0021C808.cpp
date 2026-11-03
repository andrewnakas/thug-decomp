extern "C" void* func_00230490(void* params, int a);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, const char* value);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" int func_00336228(const char* a, const char* b);
extern "C" void func_00203068(void* goals, unsigned int name, void* params);
extern "C" void func_001E6AE8(void* p, int flags);

extern char D_0038F810[];
extern char D_0038F800[];
extern char D_00371640[];
extern char D_00371620[];
extern char D_00371650[];
extern char D_00371660[];
extern char D_00371678[];
extern char D_0038F818[];
extern char D_0038F820[];

bool Cmd_0021C808(void* params, void* script)
{
    void* goals = func_00230490(params, 1);
    const char* text;
    const char* type;
    func_001E8890(params, D_0038F810, &text, 1);
    func_001E8890(params, D_0038F800, &type, 1);
    void* p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_00371640), 3, text);
    unsigned int checksum = 0;
    func_001E84E8(params, D_00371620, &checksum, 0);
    func_001E7A68(p, func_001F0D78(D_00371620), 13, checksum);
    if (func_00336228(type, D_00371650) == 0 || func_00336228(type, D_00371660) == 0) {
        int time;
        func_001E7E58(params, D_0038F818, &time, 0);
        func_001E7A68(p, func_001F0D78(D_0038F818), 1, time);
    }
    if (func_00336228(type, D_00371678) == 0) {
        int score;
        if (!func_001E7E58(params, D_0038F820, &score, 0)) {
            func_001E7E58(params, D_0038F818, &score, 1);
            score *= 1000;
        }
        func_001E7A68(p, func_001F0D78(D_0038F820), 1, score);
    }
    func_00203068(goals, func_001F0D78(type), p);
    if (p) {
        func_001E6AE8(p, 3);
    }
    return true;
}
