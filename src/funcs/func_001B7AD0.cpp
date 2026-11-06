extern char D_0038D2F8[];
extern "C" int func_001E87B8(void* params, void* key);

struct Obj_001B7AD0 {
    char pad[0x1C];
    int m1C;
    int Method(unsigned int name, void* params);
};

int Obj_001B7AD0::Method(unsigned int name, void* params)
{
    if (name == 0xC38CCE3B) {
        m1C = func_001E87B8(params, D_0038D2F8) == 0;
        return 1;
    }
    return 2;
}
