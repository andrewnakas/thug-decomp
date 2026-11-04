extern "C" void func_002A4C10(void* p);
extern "C" void func_002A2C60(void* p);
extern "C" void func_002A4C78(void* p);

struct Obj_002A18E8 {
    char pad[0x3C];
    int m3C;
    void SetMode(int mode);
};

void Obj_002A18E8::SetMode(int mode)
{
    if (mode == m3C)
        return;
    m3C = mode;
    switch (mode) {
    case 0:
        break;
    case 1:
        func_002A4C10(this);
        func_002A2C60(this);
        break;
    case 2:
        func_002A4C10(this);
        func_002A4C78(this);
        break;
    }
}
