struct Rec_00141368 {
    char pad[0x1C8];
    int m_1C8;
};

extern "C" Rec_00141368* func_00141250(int id);

void Set_00141368(int id)
{
    func_00141250(id)->m_1C8 = 1;
}
