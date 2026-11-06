extern "C" int func_001E7DE8(void* params, unsigned int id, unsigned int* out, int req);

struct Fog_00145C80 {
    char pad[0x40];
    unsigned char m40;
    unsigned char m41;
    unsigned char m42;
    unsigned char m43;
    bool Load(void* params);
};

bool Fog_00145C80::Load(void* params)
{
    unsigned int c = 0x80808080;
    func_001E7DE8(params, 0, &c, 0);
    m40 = c;
    m41 = c >> 8;
    m42 = c >> 16;
    m43 = c >> 24;
    return true;
}
