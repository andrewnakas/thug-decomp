extern void* D_00392068;
extern char D_003921A0[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_002A52F0(void* table, unsigned short id);
extern "C" bool func_002B22B8(void* player);

bool Cmd_002A8C50(void* params, void* script)
{
    void* net = D_00392068;
    int id;
    func_001E7E58(params, D_003921A0, &id, 0);
    void* p = func_002A52F0(net, id);
    if (!p)
        return true;
    return func_002B22B8(p);
}
