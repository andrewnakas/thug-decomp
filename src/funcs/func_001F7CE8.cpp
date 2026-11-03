struct Hdr_001F7CE8 {
    int m0;
    char m4[0x28];
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};

void func_001F7CE8(Hdr_001F7CE8* h, int* addr0, int* size0, int* addr1, int* size1)
{
    if (h->m0 == 0) {
        *addr0 = (int)&h->m4[h->m2C];
        *size0 = 0x28 - h->m2C;
        *addr1 = h->m30;
        *size1 = h->m3C;
        return;
    }
    int avail = h->m3C - h->m38;
    if (h->m3C - h->m34 >= avail) {
        *addr0 = h->m30 + h->m34;
        *size0 = avail;
        *addr1 = 0;
        *size1 = 0;
    } else {
        *addr0 = h->m30 + h->m34;
        *size0 = h->m3C - h->m34;
        *addr1 = h->m30;
        *size1 = avail - (h->m3C - h->m34);
    }
}
