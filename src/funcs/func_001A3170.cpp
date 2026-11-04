extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);

struct C_001A3170 {
    int m_pad[7];
    unsigned int m1C[9];
    void SetSlot(int slot, unsigned int id)
    {
        if (slot < 9 && slot != -1) m1C[slot] = id;
    }
    void Assign(void* params);
};

void C_001A3170::Assign(void* params)
{
    int slot = -1;
    unsigned int id = 0;
    func_001E7DE8(params, 0x7321A8D6, &slot, 0);
    func_001E8398(params, 0, &id, 0);
    if (slot != -1 && id) SetSlot(slot, id);
}
