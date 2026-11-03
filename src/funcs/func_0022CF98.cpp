extern char D_00372B10[];
extern char D_00372B38[];

struct Node_0022CF98 {
    char m_pad[0xC];
    Node_0022CF98* m_next;
    Node_0022CF98* m_prev;
};

struct SkaterBase_0022CF98 {
    int m0;
    int m4;
    virtual ~SkaterBase_0022CF98();
};

struct Skater_0022CF98 : SkaterBase_0022CF98 {
    int mC;
    int m10;
    int m14;
    int m_id;
    char m_pad1C[0x31C - 0x1C];
    int m_local;
    int m320;
};

extern void* D_0038C608;
extern void* D_0038FC80;
extern void* D_0038FC84;

extern "C" void* func_00187B48(void* self, unsigned int id);
extern "C" void func_00184950(void* obj);
extern "C" void func_001876A8(void* self);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00206A60(Skater_0022CF98* self, void* params);
extern "C" void func_00206CB0(Skater_0022CF98* self, void* params);
extern "C" Node_0022CF98* func_00206918(Skater_0022CF98* self);

void func_0022CF98(void* self, Skater_0022CF98* skater)
{
    void* obj = func_00187B48(D_0038C608, skater->m_id + 0x884EF81B);
    if (obj) {
        func_00184950(obj);
        func_001876A8(D_0038C608);
    }
    if (!skater->m_local) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7360(p, 0x5B24FAAA, skater->m_id);
        func_001F0210(0x5B3FDCCB, p, 0, 0, 0);
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
    if (skater->m_local && !skater->m320) {
        if (D_0038FC80) {
            func_001E6AE8(D_0038FC80, 3);
            D_0038FC80 = 0;
        }
        func_00103F28(D_00372B10);
        D_0038FC80 = func_001E6978(func_001190D0(8));
        func_00206A60(skater, D_0038FC80);
        if (D_0038FC84) {
            func_001E6AE8(D_0038FC84, 3);
            D_0038FC84 = 0;
        }
        func_00103F28(D_00372B38);
        D_0038FC84 = func_001E6978(func_001190D0(8));
        func_00206CB0(skater, D_0038FC84);
    }
    Node_0022CF98* node = func_00206918(skater);
    node->m_prev->m_next = node->m_next;
    node->m_next->m_prev = node->m_prev;
    node->m_next = node;
    node->m_prev = node;
    delete skater;
}
