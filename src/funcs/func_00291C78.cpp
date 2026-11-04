struct Script_00291C78 {
    char pad0[0x18];
    void* m18;
};

extern "C" int func_001E8A30(void* p, unsigned int key, unsigned int* out, int flag);
extern "C" void func_001E7200(void* p, unsigned int key, int v);

struct Obj_00291C78 {
    char pad0[0x138];
    int m138;
    int m13C;
    int CallMember(unsigned int id, void* params, Script_00291C78* script);
    int SetA(unsigned int v);
    void SetB(unsigned int v);
};

extern "C" int func_00291DA0(Obj_00291C78* o, unsigned int v);
extern "C" void func_00291E18(Obj_00291C78* o, unsigned int v);

int Obj_00291C78::CallMember(unsigned int id, void* params, Script_00291C78* script)
{
    switch (id) {
    case 0x58AD903F:
        return m138 != 0;
    case 0xB07AC662: {
        unsigned int v;
        func_001E8A30(params, 0, &v, 1);
        return func_00291DA0(this, v) != 0;
    }
    case 0x0E11B7CA: {
        unsigned int v;
        func_001E8A30(params, 0, &v, 1);
        func_00291E18(this, v);
        break;
    }
    case 0x44BA5FCE:
        func_001E7200(script->m18, 0x3789AC4E, m13C);
        break;
    default:
        return 2;
    }
    return 1;
}
