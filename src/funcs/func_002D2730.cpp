struct Addr_002D2730 {
    unsigned char b[16];
};

extern char D_004532C8[];
extern Addr_002D2730 D_00453AC8;
extern int D_00392B1C;
extern int D_00392B18;
extern "C" void* func_00331404(void* d, const void* s, int n);

void Recv_002D2730(unsigned char* data, int size, Addr_002D2730* from)
{
    if (data[0] == 0xFE && data[1] == 0xFD) {
        func_00331404(D_004532C8, data, size);
        D_00453AC8 = *from;
        D_00392B1C = size;
        D_00392B18 = 1;
    } else {
        if (size < 6)
            return;
        if (data[0] != 0xFD || data[1] != 0xFC || data[2] != 0x1E || data[3] != 0x66 || data[4] != 0x6A ||
            data[5] != 0xB2)
            return;
        func_00331404(D_004532C8, data, size);
        D_00453AC8 = *from;
        D_00392B1C = size;
        D_00392B18 = 2;
    }
}
