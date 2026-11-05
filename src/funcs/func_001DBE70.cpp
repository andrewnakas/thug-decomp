struct Info_001DBE70 {
    int m0;
    char pad[0x14];
    float m18;
    float m1C;
};

extern void* D_0038E0A0;
extern "C" void func_001DBCB0(void* p, Info_001DBE70* out);
extern "C" void func_001DD030(void* g, int a, int b, float x, float y, float z);

extern "C" void func_001DBE70(void* p)
{
    Info_001DBE70 info;
    func_001DBCB0(p, &info);
    func_001DD030(D_0038E0A0, info.m0, 0, 0.0f, info.m18, info.m1C);
}
