struct Mgr_002A9BB0 {
    int m0;
    void* m4;
};

extern Mgr_002A9BB0* D_00392068;
extern "C" void* func_002D3D30(void* p);
extern "C" int func_003056E0(void* p);

extern "C" bool func_002A9BB0()
{
    void* p = func_002D3D30(D_00392068->m4);
    return p && func_003056E0(p);
}
