extern int* D_0038B53C;

int func_0015F958(unsigned char* c)
{
    int* t = D_0038B53C;
    int r = c[0], g = c[1], b = c[2], a = c[3];
    return (t[r >> 3] << 3) | (t[g >> 3] << 2) | (t[b >> 3] << 1) | t[a >> 3];
}
