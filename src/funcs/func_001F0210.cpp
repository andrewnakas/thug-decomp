struct Heap_001F0210 {
    char m_pad[0xEC];
    int m_EC;
};

struct Entry_001F0210 {
    char m_0[2];
    unsigned char m_type;
    char m_3[0xC - 3];
    int (*m_fn)(void* params, void* script);
};

struct VEntry_001F0210 {
    short m_delta;
    short m_pad;
    int (*m_fn)(void* self, int name, void* params, void* script);
};

struct Obj_001F0210 {
    char m_pad[0x8];
    VEntry_001F0210* m_vtbl;
};

extern Heap_001F0210* D_00388A70;
extern "C" Entry_001F0210* func_001E5040(int name);
extern "C" void func_001F0140(int name, void* params, Obj_001F0210* obj);
extern "C" void func_0010A950(void* heap, int a);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001EE8C8(void* script, int name, void* params, Obj_001F0210* obj);
extern "C" int func_001EFDC0(void* script);
extern "C" void func_001EE4D8(void* script, int flags);

extern "C" void func_001F0210(int name, void* params, Obj_001F0210* obj, int flag)
{
    Entry_001F0210* e = func_001E5040(name);
    if (e && (unsigned int)(e->m_type - 7) < 3) {
        if (flag) {
            func_001F0140(name, params, obj);
        }
        switch (e->m_type) {
        case 8:
            e->m_fn(params, 0);
            break;
        case 9: {
            VEntry_001F0210* v = &obj->m_vtbl[3];
            v->m_fn((char*)obj + v->m_delta, name, params, 0);
            break;
        }
        case 7: {
            func_0010A950(D_00388A70, D_00388A70->m_EC);
            void* s = func_001EE428(func_00121960(0xF4));
            func_001EE8C8(s, name, params, obj);
            func_0010A9B0(D_00388A70);
            while (func_001EFDC0(s)) {
            }
            if (s) {
                func_001EE4D8(s, 3);
            }
            break;
        }
        }
    }
}
