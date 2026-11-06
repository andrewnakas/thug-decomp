// Blends dst towards src by t (4 bytes per pixel); the pointer pair lives in a local array.
extern "C" void func_00147DE8(unsigned char* src, unsigned char* dst, unsigned short n1, unsigned short n2, float t, int, int useSecond)
{
    float s = 1.0f - t;
    unsigned char* p[2] = { src, dst };
    int n = useSecond == 0 ? n1 : n2;
    for (int i = 0; i < n; i++) {
        p[1][0] = (int)(t * p[0][0] + s * p[1][0]);
        p[1][1] = (int)(t * p[0][1] + s * p[1][1]);
        p[1][2] = (int)(t * p[0][2] + s * p[1][2]);
        p[1][3] = (int)(t * p[0][3] + s * p[1][3]);
    }
}
