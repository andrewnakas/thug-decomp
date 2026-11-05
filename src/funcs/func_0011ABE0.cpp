extern "C" int func_001E8398(void* params, unsigned int name, void* out, int req);

struct Obj_0011ABE0 {
    int m0[4];
    int m_10;
    int Read(void* params);
};

int Obj_0011ABE0::Read(void* params)
{
    return func_001E8398(params, 0x40C698AF, &m_10, 0);
}
