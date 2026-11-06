extern "C" int func_001E7DE8(void* params, unsigned int id, unsigned int* out, int req);

struct Fog_001459D8 {
    char pad[0x24];
    unsigned char m24;
    unsigned char m25;
    unsigned char m26;
    unsigned char m27;
    bool Load(void* params);
};

bool Fog_001459D8::Load(void* params)
{
    unsigned int c = 0x80808080;
    func_001E7DE8(params, 0, &c, 0);
    m24 = c;
    m25 = c >> 8;
    m26 = c >> 16;
    m27 = c >> 24;
    return true;
}
