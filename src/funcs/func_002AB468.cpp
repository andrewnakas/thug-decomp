extern "C" void* func_002977B0();
extern "C" char* func_00295598(void* p, int id, void* buf, int size);

struct Obj_002AB468 {
    char pad[0x1B4];
    int m1B4;
    char m1B8[0x1924 - 0x1B8];
    char* m1924;
    int m1928;
    void SetId(int id);
};

void Obj_002AB468::SetId(int id)
{
    m1928 = id;
    m1B4 = id;
    m1924 = func_00295598(func_002977B0(), id, m1B8, 6000) + 4;
}
