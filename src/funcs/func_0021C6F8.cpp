extern "C" void* func_00230490(void* params, int a);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void* func_00202EF8(void* goals, unsigned int name);
extern "C" bool func_00203168(void* goals, unsigned int index, unsigned int name, bool hidden);

extern char D_0038F800[];
extern char D_00371610[];
extern char D_00371620[];
extern char D_0038F808[];
extern char D_00371630[];

bool Cmd_0021C6F8(void* params, void* script)
{
    void* goals = func_00230490(params, 1);
    unsigned int name;
    if (!func_001E84E8(params, D_0038F800, &name, 0)) {
        const char* text;
        func_001E8890(params, D_0038F800, &text, 1);
        name = func_001F0D78(text);
    }
    unsigned int select;
    if (func_001E84E8(params, D_00371610, &select, 0)) {
        unsigned int checksum;
        func_001E8A50(func_00202EF8(goals, name), D_00371620, &checksum, 1);
    } else {
        unsigned int index;
        func_001E8A50(params, D_0038F808, &index, 1);
        int mask = func_001E87B8(params, D_00371630);
        func_00203168(goals, index, name, mask != 0);
    }
    return true;
}
