extern void* D_00392068;
extern char D_003730E8[];
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_002A58F8(void* a);
extern "C" void func_002A3870(void* a);

int Handle_002338B8(void* msg)
{
    void* mgr = D_00392068;
    func_001F0370(D_003730E8, 0, 0, 0);
    func_002A58F8(mgr);
    func_002A3870(mgr);
    return 2;
}
