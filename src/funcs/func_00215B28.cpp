extern void* D_00392068;
extern char D_0038F600[];
extern "C" bool func_001E87B8(void* params, char* name);
extern "C" void func_002A1970(void* p, bool b);

extern "C" bool func_00215B28(void* params, void* script)
{
    void* p = D_00392068;
    func_002A1970(p, !func_001E87B8(params, D_0038F600));
    return true;
}
