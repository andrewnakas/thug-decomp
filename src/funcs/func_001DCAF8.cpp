struct Mgr_001DCAF8 {
    char m_pad[0x38];
    int m_38;
};

extern int D_00389F30;
extern Mgr_001DCAF8* D_00390828;

bool func_001DCAF8()
{
    if (D_00389F30) {
        return true;
    }
    return D_00390828->m_38 != 0;
}
