extern char D_0038F880[];
extern char D_0038F888[];
extern char D_0038F890[];
extern char D_003717F8[];
extern char D_00371808[];
extern char D_00371818[];
extern char D_0038F898[];

struct MemMgr_0021FE30 {
    char m_pad[0x3EC];
    void* m3EC;
};

struct Mgr_0021FE30 {
    char m_pad[0x394];
    void* m394;
};

extern MemMgr_0021FE30* D_00388A70;
extern Mgr_0021FE30* D_0038FC78;

extern "C" bool func_001E7F50(void* params, const char* name, float* out, int assert_);
extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_0010A950(MemMgr_0021FE30* self, void* context);
extern "C" void func_0010A9B0(MemMgr_0021FE30* self);
extern "C" void func_00250C20(void* self, int value);
extern "C" void func_00250CA0(void* self, float a, float b, float c, float d, float e, float f, float g);

bool func_0021FE30(void* params)
{
    float a;
    float b;
    float c;
    float gold;
    float silver;
    float bronze;
    float g;
    func_001E7F50(params, D_0038F880, &a, 0);
    func_001E7F50(params, D_0038F888, &b, 0);
    func_001E7F50(params, D_0038F890, &c, 0);
    func_001E7F50(params, D_003717F8, &gold, 0);
    func_001E7F50(params, D_00371808, &silver, 0);
    func_001E7F50(params, D_00371818, &bronze, 0);
    func_001E7F50(params, D_0038F898, &g, 0);
    int extra = 0;
    func_001E8180(params, 0xA61DC9A4, &extra, 0);
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    if (extra) {
        func_00250C20(D_0038FC78->m394, extra);
    }
    func_00250CA0(D_0038FC78->m394, c, b, a, bronze, silver, gold, g);
    func_0010A9B0(D_00388A70);
    return true;
}
