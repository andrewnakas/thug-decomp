struct Mgr_002AACD8;
extern Mgr_002AACD8* D_00392068;
extern "C" void func_002A3510(Mgr_002AACD8* m);
extern "C" void func_002A8250(Mgr_002AACD8* m, int v);

bool func_002AACD8(void* params, void* script)
{
    Mgr_002AACD8* m = D_00392068;
    func_002A3510(m);
    func_002A8250(m, 9);
    return true;
}
