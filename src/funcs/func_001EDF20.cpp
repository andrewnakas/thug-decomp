extern "C" int func_001EC7A0(unsigned char* p);
extern "C" unsigned char* func_001EB070(unsigned char* p);

extern "C" bool func_001EDF20(unsigned char* p, int name)
{
    for (; *p != 0x24;) {
        switch (*p) {
        case 0x16:
            p++;
            if (func_001EC7A0(p) == name)
                return true;
            p += 4;
            break;
        default:
            p = func_001EB070(p);
            break;
        }
    }
    return false;
}
