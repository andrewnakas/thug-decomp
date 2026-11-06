struct Data_001350B8 {
    int m0;
    unsigned short m_flags;
};

extern "C" bool func_0013C590(void* model);

class Obj_001350B8 {
public:
    char pad0[0x20];
    void* m_model;
    Data_001350B8* m_data;
    bool IsVisible();
};

bool Obj_001350B8::IsVisible()
{
    if (m_model) {
        return func_0013C590(m_model);
    }
    return !((m_data->m_flags >> 2) & 1);
}
