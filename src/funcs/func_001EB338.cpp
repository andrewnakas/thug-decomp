extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" int func_001EC7A0(unsigned char* p);

extern "C" unsigned char* func_001EB338(unsigned char* p)
{
    switch (*p) {
    case 22:
    case 23:
    case 24:
    case 26:
        p += 5;
        break;
    case 31:
        p += 9;
        break;
    case 30:
        p += 13;
        break;
    case 27:
    case 28:
        p += func_001EC7A0(p + 1) + 5;
        break;
    case 3: {
        int depth = 1;
        do {
            p = func_001EB070(p);
            if (*p == 3) {
                depth++;
            } else if (*p == 4) {
                depth--;
            }
        } while (depth);
        p++;
        break;
    }
    case 5: {
        int depth = 1;
        do {
            p = func_001EB070(p);
            if (*p == 5) {
                depth++;
            } else if (*p == 6) {
                depth--;
            }
        } while (depth);
        p++;
        break;
    }
    }
    return p;
}
