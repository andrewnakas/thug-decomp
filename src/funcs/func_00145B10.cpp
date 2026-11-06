extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

struct Fog_00145B10 {
    char pad[0x34];
    int m34;
    bool Load(void* params);
};

bool Fog_00145B10::Load(void* params)
{
    m34 = 254;
    func_001E7DE8(params, 0, &m34, 0);
    if (m34 < 0)
        m34 = 0;
    if (m34 >= 255)
        m34 = 254;
    return true;
}
