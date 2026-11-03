struct Mgr_002D94C0 {
    char pad0[0x10];
    void* m10;
};

extern Mgr_002D94C0* D_00392068;
extern "C" void func_002D9378(void* p);

bool Cmd_002D94C0(void* params, void* script)
{
    func_002D9378(D_00392068->m10);
    return true;
}
