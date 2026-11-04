struct Entry_00295CC8 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[2];
    int m2A8;
    char pad3[0x350 - 0x2AC];
};
struct Obj_00295CC8;
extern "C" int func_001E8398(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E7C80(void* p, unsigned int key, char** out, int req);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" Entry_00295CC8* func_00295C38(Obj_00295CC8* self, int id);
extern "C" Entry_00295CC8* func_00295B98(Obj_00295CC8* self, char* name);
extern "C" int func_00291EC0();

struct Obj_00295CC8 {
    char pad0[0x20];
    Entry_00295CC8 m20[50];
    Entry_00295CC8* mA5C0;
    Entry_00295CC8* Get(void* params);
};

Entry_00295CC8* Obj_00295CC8::Get(void* params)
{
    int id = 0;
    if (func_001E8398(params, 0x9982E501, &id, 0)) return func_00295C38(this, id);
    char* name = 0;
    if (func_001E7C80(params, 0xBFECC45B, &name, 0)) return func_00295B98(this, name);
    int v = 0;
    if (func_001E7DE8(params, 0x474A6A7F, &v, 0)) {
        int key = func_00291EC0();
        int i = 0;
        for (Entry_00295CC8* e = m20; i < 50; i++, e++) {
            if (e->m2A5 && e->m0 == key && e->m2A8 == v) return &m20[i];
        }
        return 0;
    }
    return mA5C0;
}
