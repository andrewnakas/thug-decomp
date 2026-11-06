class Obj_00143018 {
public:
    int m_0;
    int m_stride;
    char m_data[1];
    char* GetEntry(int i);
};

char* Obj_00143018::GetEntry(int i)
{
    return &m_data[i * m_stride];
}
