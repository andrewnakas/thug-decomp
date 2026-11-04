extern char D_0038F550[];
extern char D_0038F560[];
extern char D_00370798[];

extern "C" void* func_00230490(void* params, int a);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_00202EF8(void* table, unsigned int id);

bool func_00212EC8(void* params)
{
    void* table = func_00230490(params, 1);
    unsigned int key;
    unsigned int expected;
    unsigned int value;
    func_001E8A50(params, D_0038F550, &key, 1);
    func_001E8A50(params, D_0038F560, &expected, 1);
    func_001E8A50(func_00202EF8(table, key), D_00370798, &value, 1);
    return expected == value;
}
