extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

struct Obj_002488D0 {
    unsigned int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Obj_002488D0(void* params);
};

Obj_002488D0::Obj_002488D0(void* params)
{
    func_001E8398(params, 0x9982E501, &m0, 1);
    m4 = 0;
    m8 = 0;
    mC = 0;
    m10 = 0;
}
