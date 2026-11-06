struct Keys_00113F88 {
    int m0;
    int m4;
    int count;
    unsigned short keys[1];
};

extern Keys_00113F88 D_003BD7C8;

extern "C" int func_00113F88(int unused, char* out)
{
    int n = 0;
    for (int i = 0; i < D_003BD7C8.count; i++) {
        unsigned int k = D_003BD7C8.keys[i];
        if (k & 0x8000) {
            switch (k) {
            case 0x803A: out[n++] = 0x1B; break;
            case 0x803B: out[n++] = 0x1C; break;
            case 0x803C: out[n++] = 0x1D; break;
            case 0x803D: out[n++] = 0x1E; break;
            case 0x804F: out[n++] = 0x15; break;
            case 0x8050: out[n++] = 0x14; break;
            case 0x8051: out[n++] = 0x17; break;
            case 0x8052: out[n++] = 0x16; break;
            case 0x8029: out[n++] = 0x1A; break;
            default: continue;
            }
        } else {
            unsigned int c = k & 0xFF;
            if (k & 0x4000) {
                if (c == 10) out[n++] = 0x19;
                else goto plain;
            } else {
                if (c == 0) continue;
                if (c == 10) out[n++] = 0x19;
                else if (c == 9) continue;
                else if (c == 8) out[n++] = 0x18;
                else {
                plain:
                    out[n++] = k;
                }
            }
        }

    }
    return n;
}
