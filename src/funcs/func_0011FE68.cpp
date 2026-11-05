extern "C" int func_001E8180(void* s, int name, int* out, int req);

struct Obj_0011FE68 {
    char pad[0x48];
    char m_48[4];
    int Get(int name);
};

int Obj_0011FE68::Get(int name)
{
    int v = 0;
    func_001E8180(m_48, name, &v, 0);
    return v;
}
