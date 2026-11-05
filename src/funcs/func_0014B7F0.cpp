struct Obj_0014B7F0 {
    int m0[7];
    unsigned int* m_1C;
    unsigned int GetMaster();
};

unsigned int Obj_0014B7F0::GetMaster()
{
    return *m_1C & 1;
}
