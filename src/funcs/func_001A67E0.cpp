struct Sub_001A67E0 {
    char pad[0x70];
    int m70;
};
struct Obj_001A67E0 {
    char pad[0x1C];
    int m1C;
    char pad2[0x21C - 0x20];
    Sub_001A67E0* m21C;
    int Get();
};

int Obj_001A67E0::Get()
{
    if (!(m1C & 0x10)) return -1;
    Sub_001A67E0* s = m21C;
    if (!s) return -1;
    return s->m70;
}
