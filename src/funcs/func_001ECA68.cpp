struct State_001ECA68 {
    int m0;
    int m4;
    unsigned char* m8;
    unsigned short mC;
    unsigned short mE;
    int m10;
    unsigned short m14;
    unsigned char m16[0x42];
    int m58;
};

extern "C" int func_001EC7A0(unsigned char*);
extern "C" int func_001EC7E0(unsigned char*);
extern "C" int func_00100030(int);
extern "C" int func_00100080(int);
extern "C" State_001ECA68* func_001EC688(unsigned char*, int, int);
extern "C" State_001ECA68* func_001EC720();
extern "C" int func_001EE408();
extern "C" void func_001EC940(State_001ECA68*);
extern "C" void func_001EC980(State_001ECA68*, int);

unsigned char* func_001ECA68(unsigned char* p)
{
    for (;;) {
        int stop = 0;
        unsigned char op = *p;
        switch (op) {
        case 0x2F:
        case 0x37: {
            p++;
            int total = 0;
            unsigned int n = func_001EC7A0(p);
            p += 4;
            unsigned char* q = p;
            for (unsigned int i = 0; i < n; i++) {
                total += (short)func_001EC7E0(q);
                q += 2;
            }
            int r;
            if (op == 0x2F)
                r = func_00100030(total);
            else
                r = func_00100080(total);
            int i = 0;
            q = p;
            for (;;) {
                r -= (short)func_001EC7E0(q);
                q += 2;
                if (r < 0)
                    break;
                i++;
            }
            int j = i * 4;
            p += n * 2;
            p += j;
            goto jump;
        }
        case 0x40: {
            p++;
            int n = func_001EC7A0(p);
            p += 4;
            p += n * 2;
            State_001ECA68* s = func_001EC688(p, 0x40, n);
            if (!s) {
                s = func_001EC720();
                s->m8 = p;
                s->mC = n;
                s->m10 = 0x40;
                s->m58 = func_00100030(n);
            }
            s->m4 = func_001EE408();
            unsigned short r = func_00100030(n);
            if (r == s->m58) {
                int k = 1;
                do {
                    r = func_00100030(n);
                    if (r != s->m58)
                        break;
                    k++;
                } while (k < 101);
            }
            s->m58 = r;
            p += r * 4;
            goto jump;
        }
        case 0x41: {
            p++;
            int n = func_001EC7A0(p);
            p += 4;
            p += n * 2;
            State_001ECA68* s = func_001EC688(p, 0x41, n);
            if (!s) {
                s = func_001EC720();
                s->mC = n;
                s->m8 = p;
                s->m14 = 0;
                s->m10 = 0x41;
                func_001EC940(s);
                func_001EC980(s, 0);
            }
            s->m4 = func_001EE408();
            s->m14++;
            if (s->m14 >= s->mC) {
                func_001EC980(s, 1);
                s->m14 = 0;
            }
            p += s->m16[s->m14] * 4;
            goto jump;
        }
        case 0x2E:
            p++;
        jump:
            {
                int off = func_001EC7A0(p);
                p += 4;
                p += off;
            }
            break;
        default:
            stop = 1;
            break;
        }
        if (stop)
            break;
    }
    return p;
}
