struct Item_00239C08 {
    char pad[0x1C];
    signed char m_1C;
};

struct Obj_00239C08 {
    char pad[0x44];
    char m_44[0x14];
    int m_58;
    bool Check(unsigned int name, int angle, int strict, int depth);
};

extern "C" Item_00239C08* func_0023AFE8(void* list, int index);
extern "C" void* func_001E5548(unsigned int name, int create);
extern "C" void* func_001E55B8(unsigned int name, int create);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7D70(void* params, unsigned int name, char** out, int required);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" bool func_00239930(Obj_00239C08* self, int index, unsigned int name, int angle, int strict);

bool Obj_00239C08::Check(unsigned int name, int angle, int strict, int depth)
{
    int i = m_58;
    do {
        if (i <= 0) {
            return false;
        }
        i--;
    } while (!func_0023AFE8(m_44, i)->m_1C);
    if (depth >= 2) {
        void* p;
        unsigned int parent;
        char* s;
        func_001E8180(func_001E5548(name, 1), 0x7031F10C, &p, 1);
        int n = depth;
        do {
            func_001E8398(p, 0x6E855102, &parent, 0);
            n--;
            func_001E8180(func_001E9378(func_001E55B8(parent, 1), 0), 0x7031F10C, &p, 1);
        } while (n >= 2);
        func_001E7D70(p, 0xA1DC81F9, &s, 1);
        name = func_001F0D78(s);
    }
    return func_00239930(this, i, name, angle, strict);
}
