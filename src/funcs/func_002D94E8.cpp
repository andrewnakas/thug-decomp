struct Mgr_002D94E8 {
    char pad0[0x10];
    void* m10;
};

extern Mgr_002D94E8* D_00392068;
extern "C" void func_002D9468(void* p);

bool Cmd_002D94E8(void* params, void* script)
{
    func_002D9468(D_00392068->m10);
    return true;
}
