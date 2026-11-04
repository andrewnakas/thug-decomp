struct Node_00293380 {
    float x;
    float y;
    float z;
    float w;
    float a;
    float b;
    char pad18[0x30 - 0x18];
};

struct Obj_00293380 {
    int m0;
    char m4[0x36 - 0x4];
    char m36[0x4B - 0x36];
    char m4B[0xAF - 0x4B];
    char mAF[0x114 - 0xAF];
    int m114;
    char pad118[0x130 - 0x118];
    Node_00293380 m130[7];
    char pad[0x2A1 - 0x130 - 0x30 * 7];
    unsigned char m2A1;
    char pad2A2[2];
    unsigned char m2A4;
    char pad2A5[3];
    int m2A8;
    int m2AC;
    int m2B0;
    void Save(void* p);
};

extern "C" void func_001E7360(void* s, unsigned int name, int v);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E72B0(void* p, unsigned int key, float v);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);
extern "C" int func_00292748(Obj_00293380* o);
extern "C" int func_00292090(int v, int w);
extern "C" void func_00294240(Obj_00293380* o, void* p, int v);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* a, int n, int t);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);

void Obj_00293380::Save(void* p)
{
    func_001E7360(p, 0, 0x981D3AD0);
    func_001E7360(p, 0x651533EC, m0);
    func_001E7200(p, 0x60CE75AE, m2A8);
    func_001E7360(p, 0x9982E501, func_00292748(this));
    func_001E7200(p, 0xC51BF6E3, m2AC);
    func_001E7200(p, 0x14938611, m2A4);
    func_001E7360(p, 0x81CFF663, m2B0);
    func_001E70C0(p, 0x4BC5229D, m4);
    func_001E70C0(p, 0x0C5D7E6B, m4B);
    func_001E70C0(p, 0x5DE57284, mAF);
    func_001E70C0(p, 0xB9426608, m36);
    func_001E7360(p, 0x6D11ED74, m114);
    func_001E7360(p, 0x71FC348B, func_00292090(m2A8, 0));
    func_00294240(this, p, 0);
    if (m2A1) {
        void* arr = func_001E8DD0(func_00122CF8(0x10));
        func_001E8E98(arr, m2A1, 10);
        for (unsigned int i = 0; i < m2A1; i++) {
            void* s = func_001E6978(func_001190D0(8));
            Node_00293380* n = &m130[i];
            func_001E7410(s, 0x7F261953, n->x, n->y, n->z);
            func_001E72B0(s, 0x0AB21AF0, n->a);
            func_001E72B0(s, 0xFF7EBAF6, n->b);
            func_001E9170(arr, i, s);
        }
        func_001E7720(p, 0x32DF12E0, arr);
    }
}
