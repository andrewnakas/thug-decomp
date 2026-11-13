/* cflags: -fno-gcse */
/* fuzzy: 92.1 */
struct Heap_001EDBA8 {
    char pad[0xEC];
    int mEC;
};

struct Entry_001EDBA8 {
    unsigned int m0;
    char* m4;
    Entry_001EDBA8* m8;
};

struct Comp_001EDBA8 {
    char pad0[2];
    unsigned char m2;
    char pad3[9];
    int* mC;
};

extern Heap_001EDBA8* D_00388A70;
extern Entry_001EDBA8* D_0038E6F8;
extern unsigned int D_0038E6E8;
extern char D_00365498[];
extern char D_003654E8[];
extern "C" void func_001EDA20(char* name, unsigned char* data, int a, int b);
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010BDE0(int size);
extern "C" unsigned int func_001EC7A0(unsigned char* p);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void func_001E60C8(unsigned int crc, char* s);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" unsigned int func_00105520(char* s);
extern "C" unsigned char* func_001EC880(unsigned char* p);
extern "C" unsigned char* func_001EC3E8(unsigned char* p, char* name, int a);
extern "C" unsigned char* func_001ECD40(unsigned char* p);
extern "C" int func_001ECDB8(unsigned char* p);
extern "C" Comp_001EDBA8* func_001E4FC8(unsigned int crc);
extern "C" void func_001ED8D0(Comp_001EDBA8* c);
extern "C" void func_001EC2A0(unsigned int crc, int x, unsigned char* p, int len, char* name);

void Load_001EDBA8(char* name, unsigned char* data, int a, int b)
{
    unsigned char* p = data;
    func_001EDA20(name, data, a, b);
    int done = 0;
    if (b) {
        func_0010A950(D_00388A70, D_00388A70->mEC);
        D_0038E6F8 = (Entry_001EDBA8*)func_0010BDE0(0xC000);
        func_0010A9B0(D_00388A70);
        for (unsigned int i = 0; i < 0x1000; i++) {
            D_0038E6F8[i].m0 = 0;
            D_0038E6F8[i].m4 = 0;
            D_0038E6F8[i].m8 = 0;
        }
    }
    bool ok = a == 0;
    do {
        switch (*p) {
        case 0x2B: {
            p++;
            unsigned int crc = func_001EC7A0(p);
            char* s = (char*)p + 4;
            if (b) {
                Entry_001EDBA8* e = &D_0038E6F8[crc & 0xFFF];
                if (e->m4) {
                    Entry_001EDBA8* n = (Entry_001EDBA8*)func_0010BDE0(12);
                    n->m0 = crc;
                    n->m4 = (char*)func_0010BDE0(func_00331BB8(s) + 1);
                    func_00331A9C(n->m4, s);
                    n->m8 = e->m8;
                    e->m8 = n;
                } else {
                    e->m0 = crc;
                    e->m4 = (char*)func_0010BDE0(func_00331BB8(s) + 1);
                    func_00331A9C(e->m4, s);
                    e->m8 = 0;
                }
            }
            func_001E60C8(crc, s);
            p += 4;
            while (*p++);
            break;
        }
        case 0:
            done = 1;
            break;
        case 2:
            if (!ok) {
                func_00103F28(D_00365498);
                func_00103F28(D_003654E8, name);
                while (1);
            }
        default:
            p = func_001EB070(p);
            break;
        }
    } while (!done);
    p = data;
    unsigned int key = func_00105520(name);
    done = 0;
    func_001E60C8(key, name);
    D_0038E6E8 = func_00105520(name);
    func_0010A950(D_00388A70, D_00388A70->mEC);
    do {
        p = func_001EC880(p);
        switch (*p) {
        case 0:
            done = 1;
            break;
        case 0x16:
            p = func_001EC3E8(p, name, a);
            break;
        case 0x23: {
            p += 2;
            unsigned int crc = func_001EC7A0(p);
            p += 4;
            unsigned char* start = p;
            p = func_001ECD40(start);
            int x = func_001ECDB8(start);
            int len = p - start;
            Comp_001EDBA8* c = func_001E4FC8(crc);
            if (c) {
                if (c->m2 == 7 && x == *c->mC) break;
                func_001ED8D0(c);
            }
            func_001EC2A0(crc, x, start, len, name);
            break;
        }
        case 0x2B:
            p = func_001EB070(p);
            break;
        }
    } while (!done);
    func_0010A9B0(D_00388A70);
    D_0038E6E8 = 0;
}
