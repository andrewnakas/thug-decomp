extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

struct Fog_00145700 {
    int m0;
    int m4;
    bool Load(void* params);
};

bool Fog_00145700::Load(void* params)
{
    m4 = 40;
    func_001E7DE8(params, 0, &m4, 0);
    if (m4 < 0)
        m4 = 0;
    if (m4 >= 255)
        m4 = 254;
    return true;
}
