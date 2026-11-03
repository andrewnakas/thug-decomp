extern "C" int func_001E7200(void* params, unsigned int name, int def);

struct Obj_0024F3A0 {
    int m_0;
    int m_params[4];
    int Get(int def);
};

int Obj_0024F3A0::Get(int def)
{
    return func_001E7200(m_params, 0xC1F5864B, def);
}
