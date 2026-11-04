extern "C" int func_0031BCE0(int sema);
extern "C" int func_0031BCC0(int sema);

struct Ring_001F5D68 {
    char* m_buffer;
    int pad4;
    int m_numSectors;
    int m_readSector;
    int m_usedSectors;
    int m_offset;
    int m_size;
    char pad1C[0x24];
    int m_sema;

    void GetWriteRegion(char** p1, int* n1, char** p2, int* n2);
};

void Ring_001F5D68::GetWriteRegion(char** p1, int* n1, char** p2, int* n2)
{
    func_0031BCE0(m_sema);
    int end = m_usedSectors + 2;
    int avail = ((m_numSectors - end) << 11) - m_offset;
    int pos = (((m_readSector + m_usedSectors) << 11) + m_offset) % m_size;
    if (m_size - pos >= avail) {
        *p1 = m_buffer + pos;
        *n1 = avail;
        *p2 = 0;
        *n2 = 0;
    } else {
        *p1 = m_buffer + pos;
        *n1 = m_size - pos;
        *p2 = m_buffer;
        *n2 = avail - (m_size - pos);
    }
    func_0031BCC0(m_sema);
}
