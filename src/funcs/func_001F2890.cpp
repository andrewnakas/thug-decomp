extern char D_00366048[];
struct Ent_001F2890 {
    int m0;
    int m4;
};
struct Obj_001F2890 {
    char pad[0x148];
    Ent_001F2890 m148[20];
    int m1E8;
    int m1EC;
    void Push(int v);
};
extern "C" void func_001F13F8(Obj_001F2890* self, char* msg);

void Obj_001F2890::Push(int v)
{
    int n = ++m1E8;
    if (n >= 20) {
        func_001F13F8(this, D_00366048);
        return;
    }
    m148[n].m0 = v;
    m148[m1E8].m4 = 0;
    m1EC = 1;
}
