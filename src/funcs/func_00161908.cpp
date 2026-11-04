struct A_00161908 {
    unsigned short m_flags;
    unsigned short m_2;
    unsigned short m_4;
    unsigned short m_6;
};

struct B_00161908 {
    int m_flags;
    int m_4;
    int m_8;
    int m_C;
};

struct R_00161908 {
    unsigned char m_kind;
    unsigned char m_1;
    unsigned char m_count;
    unsigned char m_type;
};

struct H_00161908 {
    unsigned short m_count;
};

extern "C" R_00161908* func_00164D20(R_00161908* r);

int CountFree_00161908(H_00161908* h)
{
    int count = 0;
    R_00161908* r = (R_00161908*)((char*)h + 8);
    R_00161908* end = (R_00161908*)((char*)h + (h->m_count * 16 + 16));
    do {
        if ((r->m_type & 0x7F) == 5 && r->m_kind == 1) {
            r = func_00164D20(r);
            int n = r->m_count;
            if (r->m_type & 1) {
                A_00161908* a = (A_00161908*)((char*)r + 0xA);
                for (int i = 0; i < n; i++, a++) {
                    if (!(a->m_flags & 0x8000)) {
                        count++;
                    }
                }
            } else {
                B_00161908* b = (B_00161908*)((char*)r + 0x10);
                for (int i = 0; i < n; i++, b++) {
                    if (!(b->m_flags & 0x8000)) {
                        count++;
                    }
                }
            }
        }
        r = func_00164D20(r);
    } while (r < end);
    return count;
}
