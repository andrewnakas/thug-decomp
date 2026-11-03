struct R_00162040 {
    unsigned char m_kind;
    unsigned char m_1;
    unsigned char m_count;
    unsigned char m_type;
    int m_data[1];
};

struct H_00162040 {
    unsigned short m_count;
};

extern "C" R_00162040* func_00164D20(R_00162040* r);

void Unpack_00162040(H_00162040* h, int* out)
{
    R_00162040* r = (R_00162040*)((char*)h + 8);
    R_00162040* end = (R_00162040*)((char*)h + (h->m_count * 16 + 16));
    do {
        if ((*(unsigned int*)r & 0x7E000000) == 0x64000000) {
            int n = ((unsigned char)(r->m_count - 1) + 1) * 2;
            if ((r->m_type & 0x7F) == 100) {
                int* src = r->m_data;
                for (int i = 0; i < n; i++) {
                    *out++ = *src++;
                }
            } else {
                short* src = (short*)r->m_data;
                for (int i = 0; i < n; i++) {
                    *out++ = *src++;
                }
            }
        }
        r = func_00164D20(r);
    } while (r < end);
}
