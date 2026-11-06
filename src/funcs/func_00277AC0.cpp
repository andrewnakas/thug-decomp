extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, char** out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_002392B8(void* p);
extern "C" int func_0023A100(void* p);
extern "C" void func_00237A30(void* p, int v);
extern "C" bool func_00239D68(void* p, unsigned int name, int a, int b, int c);
extern "C" bool func_00239C08(void* p, unsigned int name, int a, int b, int c);

struct Data_00277AC0 {
    char pad[0xC];
    int mC;
    char pad2[0x18 - 0x10];
    int m18;
    char pad3[0x5C - 0x1C];
    int m5C;
    char pad4[0x6C - 0x60];
    int m6C;
};

struct Script_00277AC0 {
    char pad[0x18];
    void* m18;
};

struct Obj_00277AC0 {
    char pad[0x1C];
    Data_00277AC0* m1C;
    int Dispatch(unsigned int name, void* params, Script_00277AC0* script);
};

int Obj_00277AC0::Dispatch(unsigned int name, void* params, Script_00277AC0* script)
{
    switch (name) {
    case 0xE0112AAB: {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return v < m1C->m18;
    }
    case 0x3C445A82: {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return m1C->m18 < v;
    }
    case 0x8BF43831: {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return v < func_002392B8(m1C);
    }
    case 0xDF14BD98: {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return func_002392B8(m1C) < v;
    }
    case 0xD19BDB50: {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return v < m1C->mC * m1C->m5C;
    }
    case 0x8F2FE3D3:
        {
            void* out = script->m18;
            func_001E7200(out, 0xEE5B2B48, func_002392B8(m1C));
        }
        return 1;
    case 0x56645FC6: {
        int v;
        func_001E7DE8(params, 0, &v, 1);
        return m1C->mC * m1C->m5C < v;
    }
    case 0xC068EA59:
        {
            void* out = script->m18;
            func_001E7200(out, 0xFFE7E02C, func_0023A100(m1C));
        }
        break;
    case 0x5589B902:
        return m1C->m6C != 0;
    case 0xBE3E5463: {
        int v = 0;
        func_001E7DE8(params, 0, &v, 0);
        func_00237A30(m1C, v);
        break;
    }
    case 0x2877B61A: {
        unsigned int id;
        if (func_001E8398(params, 0x95E16467, &id, 0)) {
            int angle = 0;
            if (func_001E7DE8(params, 0xEDF5DB70, &angle, 0))
                angle = angle / 180;
            int flag = 1;
            func_001E7DE8(params, 0xC82CF71B, &flag, 0);
            if (func_00239D68(m1C, id, angle, 0, flag))
                return 1;
            return 0;
        }
        char* str;
        if (func_001E7C80(params, 0x3EAFA520, &str, 0)) {
            int angle = 0;
            if (func_001E7DE8(params, 0xEDF5DB70, &angle, 0))
                angle = angle / 180;
            int flag = 1;
            func_001E7DE8(params, 0xC82CF71B, &flag, 0);
            if (func_00239C08(m1C, func_001F0D78(str), angle, 0, flag))
                return 1;
            return 0;
        }
        return 2;
    }
    default:
        return 2;
    }
    return 1;
}
