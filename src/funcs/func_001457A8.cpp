extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

class Fx_001457A8 {
public:
    char pad[0x48];
    virtual ~Fx_001457A8();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4(unsigned int id, int n);
    bool Cmd(void* params);
};

bool Fx_001457A8::Cmd(void* params)
{
    unsigned int id = 0;
    if (!func_001E8398(params, 0, &id, 0))
        return false;
    int n = 32;
    func_001E7DE8(params, 0, &n, 0);
    V4(id, n);
    return true;
}
