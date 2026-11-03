struct Color_00214250 {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    Color_00214250(unsigned char rr, int gg, int bb, int aa)
    {
        r = rr;
        g = gg;
        b = bb;
        a = aa;
    }
    ~Color_00214250() {}
};

extern "C" bool func_001E88D8(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(void* s, void* obj);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* man, unsigned int id);
extern "C" void func_00134F28(void* obj, Color_00214250 c);

bool Cmd_SetColor_00214250(void* obj, void* params)
{
    unsigned int rgb = 0x808080;
    func_001E88D8(params, 0x99A9B716, &rgb, 1);
    Color_00214250 color(rgb, rgb >> 8, rgb >> 16, 0x80);
    void* s = func_001E9378(func_001E55B8(0xC472ECC5, 0), obj);
    unsigned int type = 0;
    func_001E8398(s, 0x12B4E660, &type, 0);
    if (type != 0xBF4D3536) {
        return false;
    }
    unsigned int id = 0;
    if (func_001E8398(s, 0xA1DC81F9, &id, 0)) {
        void* sprite = func_00132FD0(func_00131E48(), id);
        func_00134F28(sprite, color);
    }
    return true;
}
