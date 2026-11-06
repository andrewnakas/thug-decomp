struct Item_0023A5D8 {
    char pad[8];
    int m_8;
    int m_C;
    unsigned int m_10;
    int m_14;
    unsigned int m_18;
};

struct Obj_0023A5D8 {
    char pad[0x44];
    char m_44[0x14];
    int m_58;
    int Count(unsigned int name, int angle, int depth);
};

extern "C" Item_0023A5D8* func_0023AFE8(void* list, int index);
extern "C" void* func_001E5548(unsigned int name, int create);
extern "C" void* func_001E55B8(unsigned int name, int create);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7D70(void* params, unsigned int name, char** out, int required);
extern "C" unsigned int func_001F0D78(char* s);

int Obj_0023A5D8::Count(unsigned int name, int angle, int depth)
{
    if (depth >= 2) {
        void* p;
        unsigned int parent;
        char* s;
        int n = depth;
        func_001E8180(func_001E5548(name, 1), 0x7031F10C, &p, 1);
        do {
            func_001E8398(p, 0x6E855102, &parent, 0);
            n--;
            func_001E8180(func_001E9378(func_001E55B8(parent, 1), 0), 0x7031F10C, &p, 1);
        } while (n >= 2);
        func_001E7D70(p, 0xA1DC81F9, &s, 1);
        name = func_001F0D78(s);
    }
    int count = 0;
    int last = 0;
    for (int i = 0; i < m_58; i++) {
        if (func_0023AFE8(m_44, i)->m_10 == name) {
            if (!angle) {
                count++;
                last = 1;
            } else if (angle == func_0023AFE8(m_44, i)->m_8) {
                count++;
                last = 1;
            }
        } else if (!(func_0023AFE8(m_44, i)->m_18 & 0x10) || !last) {
            last = 0;
        }
    }
    return count - last;
}
