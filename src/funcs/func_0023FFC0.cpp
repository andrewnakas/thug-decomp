struct Mgr_0023FFC0 {
    unsigned int GetId(void* params, int required);
};

extern "C" bool func_001E8A30(void* params, unsigned int name, unsigned int* out, int required);

unsigned int Mgr_0023FFC0::GetId(void* params, int required)
{
    unsigned int id = 0;
    func_001E8A30(params, 0xA1DC81F9, &id, required);
    return id;
}
