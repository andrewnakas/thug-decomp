struct Cell_002BC9E0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Pair_002BC9E0 {
    int a;
    int b;
};

struct Entry_002BC9E0 {
    int m0;
    char* m4;
    Pair_002BC9E0 pairs[40];
    int m148;
    int m14C;
    unsigned char m150;
    unsigned char m151;
};

struct Arr_002BC9E0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Pool_002BC9E0 {
    char pad[0xD8];
    int mD8;
};

struct Piece_002BC9E0 {
    char pad[0x34];
    int m34;
};

struct Park_002BC9E0;
extern "C" void* func_0010A638(Pool_002BC9E0* pool, unsigned int size, int a, int b);
extern "C" void* func_002CBDC0(void* mem, Park_002BC9E0* p);
inline void* operator new[](unsigned int size, Pool_002BC9E0* p) { return func_0010A638(p, size, 1, 0); }
extern Pool_002BC9E0* D_00388A70;
extern char D_0037A4B8[];
extern char D_0037A4C8[];
extern char D_0037A4D8[];
extern char D_0037A4E8[];
extern char D_0037A4F8[];
extern char D_0037A510[];
extern char D_0037A520[];
extern char D_00392758[];
extern char D_00392760[];
extern char D_00392768[];
extern "C" void func_0010A950(Pool_002BC9E0* p, int v);
extern "C" void func_0010A9B0(Pool_002BC9E0* p);
extern "C" void func_002C4580(int n, char* name);
extern "C" void func_002C4608();
extern "C" void func_002C4640(int n, char* name);
extern "C" void func_002C46C8(int n, char* name);
extern "C" int func_002BD248(Park_002BC9E0* p);
extern "C" void func_002B7988(void* p, int a, int b, int c, int d);
extern "C" void func_002B8BA8(void* p);
extern "C" void func_002C2880(Park_002BC9E0* p);
extern "C" void func_002C41A0(Park_002BC9E0* p);
extern "C" void func_002C4108(Park_002BC9E0* p);
extern "C" void func_002BD628(Park_002BC9E0* p, int v);
extern "C" Arr_002BC9E0* func_001E55F8(char* name, int v);
extern "C" void* func_001E9378(Arr_002BC9E0* a, int i);
extern "C" bool func_001E8890(void* s, char* name, char** out, int a);
extern "C" int func_001F0D78(char* s);
extern "C" bool func_001E84E8(void* s, char* name, int* out, int a);
extern "C" void* func_002BE5F0(Park_002BC9E0* self, int key, int* out);
extern "C" Piece_002BC9E0* func_002BE678(Park_002BC9E0* self, int idx);
extern "C" bool func_001E7D90(void* s, char* name, int* out, int a);
extern "C" bool func_001E8708(void* s, unsigned int crc);
extern "C" int func_001E5488(unsigned int id, int v);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" bool func_001E87B8(void* s, char* name);

struct Park_002BC9E0 {
    void* m0;
    int m4;
    char pad8[0x3538 - 0x8];
    Cell_002BC9E0** m3538;
    Entry_002BC9E0 m353C[1];
    char pad3690[0x6A5C - 0x3690];
    int m6A5C;
    char pad6A60[0x6B00 - 0x6A60];
    void* m6B00;
    void Init();
};

void Park_002BC9E0::Init()
{
    char buf[0x70];
    int crc;
    int start;
    if (m4 != 0) return;
    m4 = 1;
    func_0010A950(D_00388A70, D_00388A70->mD8);
    func_002C4580(0x3E80, D_0037A4B8);
    func_002C4608();
    func_002C4640(0x3E8, D_0037A4C8);
    func_002C46C8(6, D_0037A4D8);
    func_0010A9B0(D_00388A70);
    func_002B7988(m0, 0x38, 0x10, 0x38, func_002BD248(this));
    func_002B8BA8(m0);
    func_002C2880(this);
    func_002C41A0(this);
    m3538 = new (D_00388A70) Cell_002BC9E0*[0x3A];
    for (int i = 0; i < 0x3A; i++) {
        m3538[i] = new (D_00388A70) Cell_002BC9E0[0x3A];
        for (int j = 0; j < 0x3A; j++) {
            m3538[i][j].m8 = 0;
            m3538[i][j].mC = 0;
        }
    }
    func_002C4108(this);
    m6B00 = func_002CBDC0(func_0010A638(D_00388A70, 0x108, 1, 0), this);
    func_002BD628(this, 0);
    Arr_002BC9E0* a = func_001E55F8(D_0037A4E8, 1);
    m6A5C = a->mC;
    Arr_002BC9E0* b = func_001E55F8(D_0037A4F8, 1);
    int end = b->mC;
    for (int n = m6A5C - 1; n >= 0; n--) {
        void* s = func_001E9378(a, n);
        m353C[n].m4 = 0;
        func_001E8890(s, D_00392758, &m353C[n].m4, 1);
        m353C[n].m0 = func_001F0D78(m353C[n].m4);
        m353C[n].m14C = 0;
        m353C[n].m148 = 0;
        if (func_001E84E8(s, D_00392760, &crc, 0)) {
            start = 0;
            func_002BE5F0(this, crc, &start);
            m353C[n].m148 = end - start;
            end = start;
            int idx = start;
            for (int k = 0; k < m353C[n].m148; idx++, k++) {
                m353C[n].pairs[k].a = func_002BE678(this, idx)->m34;
                if (!func_001E7D90(func_001E9378(b, idx), D_0037A510, &m353C[n].pairs[k].b, 0))
                    m353C[n].pairs[k].b = 0;
            }
        }
        m353C[n].m151 = 0;
        if (func_001E8708(s, 0x45C6C158)) {
            m353C[n].m151 = 1;
            m353C[n].m148 = 6;
            int id = func_001E5488(0x4E677220, 0);
            for (int k = 0; k < 6; k++) {
                func_003331D0(buf, D_0037A520, k);
                m353C[n].pairs[k].b = id;
                m353C[n].pairs[k].a = func_001F0D78(buf);
            }
        }
        m353C[n].m150 = !func_001E87B8(s, D_00392768);
    }
}
