extern "C" unsigned char* func_001EB070(unsigned char* p)
{
    switch (*p) {
    case 0:
    case 16:
    case 25:
    case 29:
    case 42:
    case 49:
        break;
    case 2:
    case 22:
    case 23:
    case 24:
    case 26:
    case 46:
    case 67:
    case 68:
        p += 5;
        break;
    case 30:
        p += 13;
        break;
    case 31:
        p += 9;
        break;
    case 27:
    case 28: {
        p++;
        int b0 = *p++;
        int b1 = *p++;
        int b2 = *p++;
        int b3 = *p++;
        p += b0 + (b1 << 8) + (b2 << 16) + (b3 << 24);
        break;
    }
    case 43:
        p += 5;
        while (*p) {
            p++;
        }
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 44:
    case 45:
    case 48:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 66:
        p++;
        break;
    case 47:
    case 55:
    case 64:
    case 65: {
        p++;
        int b0 = *p++;
        int b1 = *p++;
        int b2 = *p++;
        int b3 = *p++;
        p += (b0 + (b1 << 8) + (b2 << 16) + (b3 << 24)) * 6;
        break;
    }
    }
    return p;
}
