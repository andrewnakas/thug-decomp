extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" void* func_001412A0(unsigned int name, unsigned int texture, int max, int streams, unsigned int type,
                               unsigned int blend, int fix, int segments, float split, int history, int dummy);
extern "C" void func_00140360(void* sys, unsigned int script, void* params);
extern "C" void func_00140400(void* sys, unsigned int script, void* params);

extern char D_0038F590[];
extern char D_0038F688[];
extern char D_00370DF8[];
extern char D_0038F690[];
extern char D_00370E08[];
extern char D_0038F698[];
extern char D_0038F6A0[];
extern char D_00370E18[];
extern char D_0038F6A8[];
extern char D_0038F6B0[];
extern char D_0038F6B8[];
extern char D_0038F558[];
extern char D_00370E28[];
extern char D_00370E38[];

bool Cmd_00217F28(void* params, void* script)
{
    unsigned int name = 0;
    func_001E84E8(params, D_0038F590, &name, 0);
    int max = 256;
    func_001E7E58(params, D_0038F688, &max, 0);
    int streams = 2;
    func_001E7E58(params, D_00370DF8, &streams, 0);
    unsigned int type = 0;
    func_001E84E8(params, D_0038F690, &type, 0);
    unsigned int blend = 0x515E298E;
    func_001E84E8(params, D_00370E08, &blend, 0);
    unsigned int texture = 0xAAB555BB;
    func_001E84E8(params, D_0038F698, &texture, 0);
    int fix = 0;
    func_001E7E58(params, D_0038F6A0, &fix, 0);
    int segments = 8;
    func_001E7E58(params, D_00370E18, &segments, 0);
    float split = 0.5f;
    func_001E7F50(params, D_0038F6A8, &split, 0);
    int history = 1;
    func_001E7E58(params, D_0038F6B0, &history, 0);
    int dummy = 0;
    func_001E7E58(params, D_0038F6B8, &dummy, 0);
    void* sys = func_001412A0(name, texture, max, streams, type, blend, fix, segments, split, history, dummy);
    void* sparams = 0;
    func_001E81F0(params, D_0038F558, &sparams, 0);
    unsigned int emit = 0;
    if (func_001E84E8(params, D_00370E28, &emit, 0)) {
        func_00140360(sys, emit, sparams);
    }
    unsigned int update = 0;
    if (func_001E84E8(params, D_00370E38, &update, 0)) {
        func_00140400(sys, update, sparams);
    }
    return true;
}
