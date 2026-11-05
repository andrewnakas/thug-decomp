extern "C" int func_001E7E58(void* params, char* name, unsigned int* out, int req);
extern char D_0038A788[];
extern char D_0038A790[];

struct Fog_00145870 {
    char pad[0x10];
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    unsigned char m13;
    unsigned char m14;
    unsigned char m15;
    unsigned char m16;
    unsigned char m17;
    bool Load(void* params);
};

bool Fog_00145870::Load(void* params)
{
    unsigned int c = 0;
    func_001E7E58(params, D_0038A788, &c, 0);
    m10 = c;
    m11 = c >> 8;
    m12 = c >> 16;
    m13 = c >> 24;
    c = 0xFFFFFFFF;
    func_001E7E58(params, D_0038A790, &c, 0);
    m14 = c;
    m15 = c >> 8;
    m16 = c >> 16;
    m17 = c >> 24;
    return true;
}
