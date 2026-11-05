struct Vec_0011C508 {
    float x, y, z, w;
    Vec_0011C508(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct C_0011C508;

extern "C" int func_001E8918(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8A30(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8A50(void* params, char* name, unsigned int* out, int req);
extern char D_003893D8[];
extern "C" void func_0011BF30(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011BF90(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011BFF0(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C0A8(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C050(C_0011C508* self, unsigned int name, bool b);
extern "C" void func_0011C108(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C190(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C218(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C278(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C2D8(C_0011C508* self, unsigned int name, bool b);
extern "C" void func_0011C330(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C390(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C3F0(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C450(C_0011C508* self, unsigned int name, Vec_0011C508* v);
extern "C" void func_0011C4B0(C_0011C508* self, unsigned int name, bool b);

struct C_0011C508 {
    int CallMember(unsigned int id, void* params, void* script);
};

int C_0011C508::CallMember(unsigned int id, void* params, void* script)
{
    switch (id) {
    case 0x02565BD1: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011BF30(this, name, &v);
        break;
    }
    case 0x3E5B6488: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011BF90(this, name, &v);
        break;
    }
    case 0xC85B9AC0: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011BFF0(this, name, &v);
        break;
    }
    case 0x5EE9D5BD: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C0A8(this, name, &v);
        break;
    }
    case 0x5661FB72: {
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        int on;
        func_001E88D8(params, 0, &on, 1);
        func_0011C050(this, name, on != 0);
        break;
    }
    case 0xA47767F2: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C108(this, name, &v);
        break;
    }
    case 0x987A58AB: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C190(this, name, &v);
        break;
    }
    case 0x599D3707: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C218(this, name, &v);
        break;
    }
    case 0x7235DAA7: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C278(this, name, &v);
        break;
    }
    case 0x53F06ACC: {
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        int on;
        func_001E88D8(params, 0, &on, 1);
        func_0011C2D8(this, name, on != 0);
        break;
    }
    case 0xC6889E91: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C330(this, name, &v);
        break;
    }
    case 0xFA85A1C8: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C390(this, name, &v);
        break;
    }
    case 0xD32C2724: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C3F0(this, name, &v);
        break;
    }
    case 0xD12B3713: {
        Vec_0011C508 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E8918(params, 0x7323E97C, &v.x, 0);
        func_001E8918(params, 0x0424D9EA, &v.y, 0);
        func_001E8918(params, 0x9D2D8850, &v.z, 0);
        unsigned int name;
        func_001E8A30(params, 0xCAB94088, &name, 1);
        func_0011C450(this, name, &v);
        break;
    }
    case 0xF11DAAAE: {
        unsigned int name;
        func_001E8A50(params, D_003893D8, &name, 1);
        int on;
        func_001E88D8(params, 0, &on, 1);
        func_0011C4B0(this, name, on != 0);
        break;
    }
    default:
        return 2;
    }
    return 1;
}
