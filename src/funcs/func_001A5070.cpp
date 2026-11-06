extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_001A5070 {
    char pad0[0x48];
    bool m48;
    int Fn(unsigned int key, void* params);
};

int Obj_001A5070::Fn(unsigned int key, void* params)
{
    switch (key) {
    case 0xA2331896: {
        int v = 0;
        func_001E7DE8(params, 0, &v, 0);
        m48 = v != 0;
        break;
    }
    default:
        return 2;
    }
    return 1;
}
