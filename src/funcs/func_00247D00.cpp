struct Array_00247D00 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Goal_00247D00 {
    char m_pad[0x20];
    void* m_params;
};

extern char D_003738E8[];
extern char D_003739D8[];
extern char D_003739F8[];
extern char D_00373A10[];
extern char D_003738A8[];
extern char D_00373A30[];
extern char D_00373A48[];
extern char D_00373A58[];
extern char D_00373A70[];

extern "C" bool func_001E82B8(void* params, const char* name, Array_00247D00** out, int required);
extern "C" bool func_001E86D0(void* params, const char* name);
extern "C" bool func_001E7D18(void* params, const char* name, const char** out, int required);
extern "C" void func_001E7138(void* params, const char* name, const char* value);
extern "C" void func_001E76D8(void* params, const char* name, Array_00247D00* value);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_00122CF8(int size);
extern "C" Array_00247D00* func_001E8DD0(void* mem);
extern "C" void func_001E8DE8(Array_00247D00* array, int flags);
extern "C" void func_001E8E98(Array_00247D00* array, int size, int type);
extern "C" void func_001E6518(Array_00247D00* array);
extern "C" bool func_00247850(Array_00247D00* combos, Array_00247D00* a, Array_00247D00* b, int index);
extern "C" void func_00247AF8(const char* src, char* dst, Array_00247D00* a, Array_00247D00* b, int size);
extern "C" const char* func_001E91C0(Array_00247D00* array, int index);
extern "C" const char* func_001E4DE0(const char* s);
extern "C" void func_001E9058(Array_00247D00* array, int index, const char* s);

static inline Array_00247D00* NewArray_00247D00()
{
    return func_001E8DD0(func_00122CF8(0x10));
}

static inline void DeleteArray_00247D00(Array_00247D00* array)
{
    if (array) {
        func_001E8DE8(array, 3);
    }
}

bool func_00247D00(Goal_00247D00* self)
{
    Array_00247D00* combos = 0;
    if (!func_001E82B8(self->m_params, D_003738E8, &combos, 0)) {
        return false;
    }

    if (!func_001E86D0(self->m_params, D_003739D8)) {
        const char* desc;
        Array_00247D00* descs;
        if (func_001E7D18(self->m_params, D_003739F8, &desc, 0)) {
            func_001E7138(self->m_params, D_003739D8, desc);
        } else if (func_001E82B8(self->m_params, D_003739F8, &descs, 1)) {
            func_001E76D8(self->m_params, D_003739D8, descs);
        }
    }
    if (!func_001E86D0(self->m_params, D_00373A10)) {
        const char* text;
        if (func_001E7D18(self->m_params, D_003738A8, &text, 0)) {
            func_001E7138(self->m_params, D_00373A10, text);
        }
    }
    if (!func_001E86D0(self->m_params, D_00373A30)) {
        const char* text;
        if (func_001E7D18(self->m_params, D_00373A48, &text, 0)) {
            func_001E7138(self->m_params, D_00373A30, text);
        }
    }
    if (!func_001E86D0(self->m_params, D_00373A58)) {
        const char* text;
        if (func_001E7D18(self->m_params, D_00373A70, &text, 0)) {
            func_001E7138(self->m_params, D_00373A58, text);
        }
    }

    int index = -1;
    if (func_001E8708(self->m_params, 0x8E6014F6)) {
        func_001E7DE8(self->m_params, 0x0B502200, &index, 1);
    }

    Array_00247D00* keys = NewArray_00247D00();
    Array_00247D00* names = NewArray_00247D00();
    int num = combos->m_size;
    func_001E8E98(keys, num, 3);
    func_001E8E98(names, num, 3);
    if (!func_00247850(combos, keys, names, index)) {
        func_001E6518(keys);
        func_001E6518(names);
        DeleteArray_00247D00(keys);
        DeleteArray_00247D00(names);
        return false;
    }

    char buf[0x200];
    const char* text;
    Array_00247D00* descs = 0;
    if (func_001E7D18(self->m_params, D_003739D8, &text, 0)) {
        func_00247AF8(text, buf, keys, names, 0x200);
        func_001E7138(self->m_params, D_003739F8, text);
    } else if (func_001E82B8(self->m_params, D_003739D8, &descs, 1)) {
        int count = descs->m_size;
        Array_00247D00* out = NewArray_00247D00();
        func_001E8E98(out, count, 3);
        for (int i = 0; i < count; i++) {
            text = func_001E91C0(descs, i);
            func_00247AF8(text, buf, keys, names, 0x200);
            func_001E9058(out, i, func_001E4DE0(buf));
        }
        func_001E76D8(self->m_params, D_003739F8, out);
        func_001E6518(out);
        DeleteArray_00247D00(out);
    }
    if (func_001E7D18(self->m_params, D_00373A10, &text, 0)) {
        func_00247AF8(text, buf, keys, names, 0x200);
        func_001E7138(self->m_params, D_003738A8, buf);
    }
    if (func_001E7D18(self->m_params, D_00373A30, &text, 0)) {
        func_00247AF8(text, buf, keys, names, 0x200);
        func_001E7138(self->m_params, D_00373A48, buf);
    }
    if (func_001E7D18(self->m_params, D_00373A58, &text, 0)) {
        func_00247AF8(text, buf, keys, names, 0x200);
        func_001E7138(self->m_params, D_00373A70, buf);
    }
    func_001E6518(keys);
    func_001E6518(names);
    DeleteArray_00247D00(keys);
    DeleteArray_00247D00(names);
    return true;
}
