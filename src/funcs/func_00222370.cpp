extern "C" void* func_0022E050(void* game);
extern "C" bool func_002A19A8(void* net);
extern "C" void* func_0022DD38(void* game);
extern "C" void* func_002629A8(void* profiles, int index);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001AB7C0(void* comp, void* profile);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022DE70(void* game, int index);

extern void* D_0038FC78;
extern void* D_00392068;

bool Cmd_RefreshSkaterModel_00222370(void* params, void* script)
{
    void* game = D_0038FC78;
    void* net = D_00392068;
    void* profiles = func_0022E050(game);
    if (func_002A19A8(net)) {
        void* skater = func_0022DD38(game);
        void* profile = func_002629A8(profiles, 0);
        func_001AB7C0(func_00185578(skater, 0x270F56E1), profile);
    } else {
        int index;
        func_001E7DE8(params, 0x5B8AB877, &index, 1);
        void* skater = func_0022DE70(game, index);
        void* profile = func_002629A8(profiles, index);
        if (skater && profile) {
            func_001AB7C0(func_00185578(skater, 0x270F56E1), profile);
        }
    }
    return true;
}
