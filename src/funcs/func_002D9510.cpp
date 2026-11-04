struct Mgr_002D9510 {
    char pad0[0x10];
    void* m10;
};

extern Mgr_002D9510* D_00392068;
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_002D9ED0(void* p, bool v);

bool func_002D9510(void* params, void* script)
{
    Mgr_002D9510* m = D_00392068;
    func_002D9ED0(m->m10, func_001E8708(params, 0x132AA339));
    return true;
}
