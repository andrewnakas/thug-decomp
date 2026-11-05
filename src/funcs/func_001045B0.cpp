extern "C" int func_001045B0(const char* p)
{
    int r = 0;
    if ((unsigned char)*p >= '0' && (unsigned char)*p <= '9') {
        r = *p - '0';
    } else if ((unsigned char)*p >= 'a' && (unsigned char)*p <= 'v') {
        r = *p - 'a' + 10;
    } else if ((unsigned char)*p >= 'A' && (unsigned char)*p <= 'V') {
        r = *p - 'A' + 10;
    }
    return r;
}
