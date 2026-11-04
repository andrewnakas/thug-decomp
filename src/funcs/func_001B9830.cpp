extern char D_00362F00[];
extern char D_00362F10[];
extern char D_00362F20[];
extern char D_00362F30[];
extern char D_00362F40[];
extern "C" int func_001E7F50(void* params, const char* name, float* out, int req);
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct C_001B9830 {
    void Set(float a, float b, float c, float d, float e);
    void Start(int id, float blend);
    int Call(unsigned int name, void* params);
};

int C_001B9830::Call(unsigned int name, void* params)
{
    switch (name) {
    case 0x75A516D3: {
        float a = 0.0f;
        float b = 0.0f;
        float c = 0.0f;
        float d = 0.0f;
        float e = 0.0f;
        func_001E7F50(params, D_00362F00, &a, 0);
        func_001E7F50(params, D_00362F10, &b, 0);
        func_001E7F50(params, D_00362F20, &c, 0);
        func_001E7F50(params, D_00362F30, &d, 0);
        func_001E7F50(params, D_00362F40, &e, 0);
        Set(a, b, c, d, e);
        break;
    }
    case 0xD7867FFE: {
        int id = 0;
        func_001E88D8(params, 0x6835B854, &id, 1);
        Start(id, 1.0f);
        break;
    }
    default:
        return 2;
    }
    return 1;
}
